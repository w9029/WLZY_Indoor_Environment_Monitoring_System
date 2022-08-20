package com.lkc.service.impl;

import com.lkc.entity.Device;
import com.lkc.entity.RetDevice;
import com.lkc.entity.UserCompDev;
import com.lkc.repository.DeviceRepository;
import com.lkc.repository.UcompDRepository;
import com.lkc.service.DeviceService;
import com.lkc.tool.TimeFormat;
import net.sf.json.JSONArray;
import net.sf.json.JSONObject;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.IOException;
import java.io.OutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

@Service
public class DeviceServiceImpl implements DeviceService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());
    @Autowired
    private DeviceRepository deviceRepository;
    @Autowired
    private UcompDRepository ucompDRepository;

    //添加
    @Override
    public void save(Device device){
        deviceRepository.save(device);
    }

    //设置状态 （通过mac来设置状态）
    @Override
    public Integer updateByMac(String mac, Integer status){
        return deviceRepository.updateByMac(mac,status);
    }

    //查找 （通过mac来查）
    @Override
    public Device findByMac(String mac) {
        return deviceRepository.findByMac(mac);
    }

    //查找ip（通过mac来查）
    @Override
    public String findUrlByMac(String mac) {
        return deviceRepository.findUrlByMac(mac);
    }

    //设置ip
    @Override
    public void updateUrl(String url, String mac) {
        deviceRepository.updateUrl(url,mac);
    }

    //控制视频开关
    @Override
    public void videoControll(String mac,String controll) {
        logger.trace("视频开关：" + controll);
        String url = deviceRepository.findUrlByMac(mac);
        logger.trace("mac:" + mac + "controll:" + controll );
        try{
            //建立连接转发controll信号
            Socket socket = new Socket(url,8881);
            OutputStream outputStream = socket.getOutputStream();
            outputStream.write(controll.getBytes());
            socket.close();
            logger.debug("视频开关信息：" + controll + " 发送成功！");
        } catch (IOException e){
            logger.error("视频socket连接错误！");
            e.printStackTrace();
        }
    }

    //重启设备
    @Override
    public String rebootControll(String mac,String controll){
        logger.trace("重启设备：" + mac);
        String url = deviceRepository.findUrlByMac(mac);
        try{
            //建立连接转发reboot信号
            Socket socket = new Socket(url,8881);
            OutputStream outputStream = socket.getOutputStream();
            outputStream.write(controll.getBytes());
            socket.close();
            logger.debug("重启信号发送成功！");
            return "success";
        } catch (IOException e){
            logger.error("重启socket连接错误！");
            e.printStackTrace();
            return "failed";
        }
    }
    //查看所有设备
    @Override
    public String findDevice(String name) {
        List<UserCompDev> list = ucompDRepository.findByName(name);
        List<RetDevice> ret = new ArrayList<RetDevice>();

        if (list.isEmpty()){
            logger.warn(name + " 该用户没有设备！");
            return "null";
        }

        RetDevice retDevice;
        for(UserCompDev ucd : list){
            String MAC = ucd.getMac();
            Device dev = deviceRepository.findByMac(MAC);

            retDevice = new RetDevice();
            retDevice.setNumber(ucd.getNumber());
            retDevice.setMac(MAC);
            retDevice.setStatus(dev.getStatus());

            //若设备没有最后运行时间
            if (null == dev.getLasttime()) {
                retDevice.setLasttime("0");
            }else{
                retDevice.setLasttime(TimeFormat.secondToTime(String.valueOf(dev.getLasttime())));
            }
            ret.add(retDevice);
        }
        retDevice = null;
        list = null;

        JSONArray array = JSONArray.fromObject(ret);
        String jsonstr = array.toString();
        return jsonstr;
    }
}
