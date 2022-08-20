package com.lkc.socket;

import com.lkc.entity.Device;
import com.lkc.entity.Sensor;
import com.lkc.entity.Threshold;
import com.lkc.entity.UserCompDev;
import com.lkc.service.*;
import com.lkc.tool.SendWarnMail;
import com.lkc.tool.TimeFormat;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class SocketService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());
    //端口号
    private static Integer port;

    public SocketService (Integer port){
        this.port = port;
    }

    public void SocketStart () throws IOException{
        ServerSocket serverSocket = new ServerSocket(port);
        logger.debug("服务器信息: "+serverSocket.getInetAddress()+" 端口: "+serverSocket.getLocalPort());

        while (true){
            //得到客户端
            Socket socket = serverSocket.accept();
            //创建并启动接收线程
            ReadThread readThread = new ReadThread(socket);
            readThread.start();
            try{
                readThread.join();
                logger.warn("接收线程结束");
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }
    //接收线程
    @Component
    public static class ReadThread extends Thread{
        //日志记录器
        Logger logger = LoggerFactory.getLogger(getClass());

        //用于存入数据库
        @Autowired
        private SensorService sensorService;
        //用于修改状态 查看设备是否存在于设备表
        @Autowired
        private DeviceService deviceService;

        private static ReadThread readThread;
        /************************************************/
        @PostConstruct
        public void init(){
            readThread = this;
            readThread.sensorService = this.sensorService;
            readThread.deviceService = this.deviceService;
        }

        /************************************************/

        private Socket socket;
        private int heartcount;
        private String MAC;
        private boolean heartflg = false;     //心跳标志位
        private boolean flg = true;           //设备状态设置标志位
        private static final int RUNING = 1;   //设备开启状态
        private static final int CLOSE = 0;    //设备关闭状态

        //构造函数
        ReadThread(){}
        ReadThread(Socket socket){
            this.socket = socket;
        }

        //心跳线程对象
        Thread heartThread = new Thread(){
            @Override
            public void run() {
                while(!isInterrupted()){
                    while(!heartflg){
                        try{
                            sleep(10);
                        }catch (InterruptedException e){
                            e.printStackTrace();
                        }
                    }
                    heartcount = 0;
                    //等待接收数据的超时时间
                    while(heartflg && heartcount < 50){
                        try{
                            sleep(100);
                            heartcount++;
                        }catch (InterruptedException e){
                            e.printStackTrace();
                        }
                    }
                    //超时
                    if (heartcount >= 50){
                        logger.warn("socket连接超时！连接断开！");
                        try{
                            socket.close();
                        }catch (Exception e){
                            e.printStackTrace();
                        }
                        readThread.deviceService.updateByMac(MAC,CLOSE);
                        interrupt();
                    }else {
                        readThread.deviceService.updateByMac(MAC, RUNING);
                    }
                }
            }
        };

        @Override
        public void run() {
            super.run();
            heartThread.start();
            logger.info("客户端信息: "+socket.getInetAddress() + " 端口: "+socket.getLocalPort());

            int warncount = 10;

            try{
                socket.setSoTimeout(5000);
                //获取输入流
                InputStream inputStream = socket.getInputStream();
                //获取输出流
                OutputStream outputStream = socket.getOutputStream();
                //用于接收收到的数据
                byte[] bytes;
                //用于保存所有数据并写入
                Sensor sensor;
                //用于保存分割后的所有字符串
                String[] strarray;
                //用于保存收到的数据（byte转换成string）
                String str;

                while(!isInterrupted()){
                    bytes = new byte[1024];
                    heartcount = 0;
                    heartflg = true;

                    if (inputStream.read(bytes,0,1024) != -1){
                        heartflg = false;

                        //将byte转换成string;
                        str = new String(bytes);
                        str = str.trim();
                        //以空格切割
                        strarray = str.split(" ");

                        //数据过滤
                        if (str.contains("heartbeat")){
                            logger.trace("收到 " + socket.getInetAddress() + " 发来的心跳包！");
                            outputStream.write("heartbeat".getBytes());
                            continue;
                        } else if (strarray.length != 5){
                            continue;
                        } else if (strarray[4].length() > 17){
                            continue;
                        } else if (strarray[0].length() > 17){
                            continue;
                        }

                        //将该设备的状态设为开启/关闭
                        if (flg){
                            MAC = strarray[0];
                            Device device = readThread.deviceService.findByMac(MAC);
                            //若设备已存在 则改变状态值
                            if (device != null){
                                //更改ip（若设备换网）
                                InetAddress address = socket.getInetAddress();
                                String url = String.valueOf(address).replace("/","");
                                readThread.deviceService.updateUrl(url,MAC);
                                //更改状态
                                readThread.deviceService.updateByMac(MAC, RUNING);
                            }else{   //若不存在 则添加到设备表
                                InetAddress address = socket.getInetAddress();
                                String url = String.valueOf(address);

                                Device device1 = new Device();
                                device1.setMac(MAC);
                                device1.setStatus(RUNING);
                                device1.setLasttime(Integer.valueOf(strarray[1]));
                                device1.setUrl(url.replace("/",""));
                                readThread.deviceService.save(device1);
                            }
                            flg = false;
                        }

                        //存入数据库
                        sensor = new Sensor();
                        sensor.setMac(MAC);
                        sensor.setTime(Integer.valueOf(strarray[1]));
                        sensor.setTemperature(Float.valueOf(strarray[2]));
                        sensor.setHumidity(Float.valueOf(strarray[3]));
                        sensor.setAmmonia(Float.valueOf(strarray[4]));
                        readThread.sensorService.save(sensor);

                        warncount--;
                        //超过阈值发邮件
                        if (0 == warncount){
                            InetAddress addr = InetAddress.getLocalHost();
                            String ip=addr.getHostAddress().toString();
                            new SendWarnMail(sensor,ip).start();
                            warncount = 10;
                        }

                    }else{
                        break;
                    }
                }
            }catch (Exception e){
                e.printStackTrace();
                readThread.deviceService.updateByMac(MAC,CLOSE);
                logger.error("与" + socket.getInetAddress() + " 连接异常断开!");
                heartThread.interrupt();
                this.heartThread = null;
            }
        }
    }
}
