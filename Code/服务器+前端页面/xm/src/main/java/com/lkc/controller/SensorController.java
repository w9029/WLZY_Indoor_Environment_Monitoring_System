package com.lkc.controller;

import com.lkc.entity.Sensor;
import com.lkc.repository.SensorRepository;
import com.lkc.service.SensorService;
import net.sf.json.JSONArray;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class SensorController {
    @Autowired
    private SensorService sensorService;
    @Autowired
    private SensorRepository sensorRepository;

    //查询历史记录（传入 秒数（3600） 开始时间  设备mac号）
    @PostMapping("/find/custom")
    public String findByCustom(@RequestParam("sec") Integer second,
                               @RequestParam("start") Integer start,
                               @RequestParam("mac") String mac){
        List<Sensor> list = sensorService.findByCustom(second,start,mac);

        JSONArray array = JSONArray.fromObject(list);
        String jsonstr = array.toString();
        return jsonstr;
    }

    //传过来 客户端当前时间nowtime 和 需要查的时间段(过去6或12或24小时)） 和 mac地址
    @PostMapping("/find/default")
    public String findByDefault(@RequestParam("needtime") Integer needtime,
                                @RequestParam("nowtime") Integer nowtime,
                                @RequestParam("mac") String mac){
        List<Sensor> list = sensorService.findByDefault(needtime,nowtime,mac);

        JSONArray array = JSONArray.fromObject(list);
        String jsonstr = array.toString();
        return jsonstr;
    }

    //大数据历史信息（3小时）
    @PostMapping("/find/bigdata")
    public String findBigData(@RequestParam("lasttime") Integer lasttime,
                              @RequestParam("mac") String mac){
        List<Sensor> list = sensorService.findAllByMacAndTime(mac,lasttime);

        JSONArray array = JSONArray.fromObject(list);
        String jsonstr = array.toString();
        return jsonstr;
    }

}
