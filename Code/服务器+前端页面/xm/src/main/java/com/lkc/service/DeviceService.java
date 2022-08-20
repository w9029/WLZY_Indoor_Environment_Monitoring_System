package com.lkc.service;

import com.lkc.entity.Device;

public interface DeviceService {

    //添加
    void save(Device device);

    //设置状态 （通过mac来设置状态）  ok
    Integer updateByMac(String mac, Integer status);

    //查找 （通过mac来查）
    Device findByMac(String mac);

    //查找ip（通过mac）
    String findUrlByMac(String mac);

    //设置ip
    void updateUrl(String url,String mac);

    //控制开关视频
    void videoControll(String mac,String controll);

    //查看所有设备
    String findDevice(String name);

    //重启设备
    String rebootControll(String mac,String controll);
}
