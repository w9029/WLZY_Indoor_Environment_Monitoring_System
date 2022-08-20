package com.lkc.websocket;

import com.lkc.entity.Device;
import com.lkc.entity.Sensor;
import com.lkc.service.DeviceService;
import com.lkc.service.SensorService;
import net.sf.json.JSONObject;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;
import java.util.concurrent.CopyOnWriteArraySet;

//和客户端连接
@ServerEndpoint("/websocket")
//在外部tomcat上运行需要注释掉
//@Component
public class WebSocketService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());
    //存放连接进来的客户端
    private static CopyOnWriteArraySet<WebSocketService> webSocketSet = new CopyOnWriteArraySet<WebSocketService>();
    //连接进来的数量
    private static int onlineCount = 0;
    //通过session给客户端发数据
    private Session session;
    SendThread sendThread;

    @OnOpen
    public void OnOpen(Session session){
        this.session = session;
        webSocketSet.add(this);
        addOnlineCount();
        logger.info("websocket: " + " sessionid=" + session.getId() + " 连接成功！人数为："+getOnlineCount());
    }

    @OnError
    public void OnError(Session session, Throwable error){
        webSocketSet.remove(this);
        logger.warn("websocket: " + session.getId() + " 连接错误！");
        error.printStackTrace();
    }

    @OnClose
    public void OnClose(Session session){
        webSocketSet.remove(this);
        subOnlineCount();
        logger.info("websocket: " + session.getId() + " 连接关闭！剩余人数为："+getOnlineCount());
        sendThread.flg = false;
    }

    @OnMessage
    public synchronized void OnMessage(String msg, Session session){  //传过来 mac号

        String[] array = msg.split(" ");

        if (array[0].equals("mac")){           //收到正常请求 则开启发送线程
            sendThread = new SendThread();
            //初始化
            sendThread.session = session;
            sendThread.mac = array[1];
            //开启线程
            sendThread.start();

        }else if (msg.equals("close")){         //收到"close" 则关闭关闭线程
            if(sendThread != null){
                sendThread.flg = false;
                try{
                    sendThread.join();
                }catch (Exception e){
                    e.printStackTrace();
                    logger.error("websocket: " + session.getId() + " 发送线程终止失败！");
                }
            }
        }
    }
    //增加人数
    public static synchronized void addOnlineCount(){
        WebSocketService.onlineCount++;
    }
    //减少人数
    public static synchronized void subOnlineCount(){ WebSocketService.onlineCount--; }
    //查看连入人数
    public static synchronized int getOnlineCount(){
        return onlineCount;
    }

    //实时发送 线程
    @Component
    public static class SendThread extends Thread{
        //日志记录器
        Logger logger = LoggerFactory.getLogger(getClass());

        @Autowired
        private SensorService sensorService;    //正常引用service
        @Autowired
        private DeviceService deviceService;

        /*****************************************************/
        private static SendThread sendThread;   //关键一：将自己作为静态私有变量引入，使其在spring初始化之前就被创建
        @PostConstruct                          //关键二：通过该注解 实现初始化和销毁bean之前进行的操作
        public void init(){
            sendThread = this;
            sendThread.sensorService = this.sensorService;  //初始化时将已静态化的sensorService实例化
            sendThread.deviceService = this.deviceService;
        }
        /*****************************************************/
        private Session session;
        private String mac;          //需要查的设备的mac号
        private boolean flg = true;  //线程内循环的开始/关闭按钮
        SendThread(){}

        @Override
        public synchronized void run() {
            //设备当前状态
            int devstatus;
            //判断设备是否断开或没有数据
            boolean statusflg = true;

            while(flg){
                Sensor sensor = sendThread.sensorService.findLastTimeByMac(mac);  //关键三：使用sendThread.sensorService的方式使用service
                Device device = sendThread.deviceService.findByMac(mac);

                if (null == device){        //无该设备数据
                    statusflg = false;
                } else {
                    devstatus = device.getStatus();
                    if (devstatus == 0){        //该设备已关闭
                        statusflg = false;
                    }else{
                        statusflg = true;
                    }
                }

                //若设备为开启状态则返回数据
                if (statusflg){
                    JSONObject object = JSONObject.fromObject(sensor);
                    String jsonstr = object.toString();
                    sensor = null;
                    device = null;
                    try{
                        session.getBasicRemote().sendText(jsonstr);
                        sleep(500);
                    }catch (Exception e){
                        e.printStackTrace();
                        logger.error("实时发送失败！");
                    }
                }else{                  //若设备为关闭状态则返回"false"
                    sensor = null;
                    device = null;
                    try{
                        session.getBasicRemote().sendText("false");
                        logger.warn("设备：" + mac + " 已断开！");
                    }catch (IOException e){
                        e.printStackTrace();
                    }
                }
            }
            logger.debug("发送结束");
        }
    }
}
