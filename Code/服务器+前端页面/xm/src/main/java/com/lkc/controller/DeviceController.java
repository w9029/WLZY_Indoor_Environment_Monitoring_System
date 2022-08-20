package com.lkc.controller;

import com.lkc.service.DeviceService;
import com.lkc.service.UcompDService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DeviceController {
    @Autowired
    private DeviceService deviceService;
    @Autowired
    private UcompDService ucompDService;

    //查看所有设备（查看用户所有设备）
    @PostMapping("/dev/find")
    public String findDevice(@RequestParam("name") String name){
        return deviceService.findDevice(name);
    }

    //获取对应设备的Url
    @PostMapping("/dev/url")
    public String findUrl(@RequestParam("mac") String mac){
        return deviceService.findUrlByMac(mac);
    }

    //视频开关
    @PostMapping("/dev/video")
    public void videoControll (@RequestParam("mac") String mac,
                               @RequestParam("controll") String controll){
        deviceService.videoControll(mac,controll);
    }

    //重启板子
    @PostMapping("/dev/reboot")
    public String rebootControll (@RequestParam("mac") String mac,
                                  @RequestParam("controll") String controll){
        return deviceService.rebootControll(mac,controll);
    }
}
