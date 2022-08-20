package com.lkc.controller;

import com.lkc.entity.DevName;
import com.lkc.entity.DevSetth;
import com.lkc.entity.Threshold;
import com.lkc.entity.UserMac;
import com.lkc.service.ThresholdService;
import com.lkc.service.UcompDService;
import net.sf.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.repository.query.Param;
import org.springframework.web.bind.annotation.*;

@RestController
public class UcompDController {
    @Autowired
    private UcompDService ucompDService;
    @Autowired
    private ThresholdService thresholdService;

    //板子登录
    @PostMapping(value = "/dev/login")
    public String login(@RequestBody UserMac usermac) {
        return ucompDService.login(usermac);
    }

    //移除用户设备
    @PostMapping(value = "/dev/delete")
    public String deleteDevice(@Param("name")String name,@Param("mac")String mac){
        return ucompDService.deleteByNameAndMac(name,mac);
    }

    //获取用户的阀值（板子用）
    @PostMapping("/dev/getthd")
    public String findThreshold(@RequestBody DevName devName){
        Threshold threshold = thresholdService.findByName(devName.getName());
        JSONObject jsonObject = JSONObject.fromObject(threshold);
        String jsonstr = jsonObject.toString();

        return jsonstr;
    }

    //设置用户的阀值（板子用）
    @PostMapping("/dev/setthd")
    public String setThreshold(@RequestBody DevSetth devSetth){
        return thresholdService.setThreshold(devSetth.getTmax(),devSetth.getTmin(),
                                             devSetth.getHmax(),devSetth.getHmin(),
                                             devSetth.getAmax(),devSetth.getAmin(),
                                             devSetth.getName());
    }
}
