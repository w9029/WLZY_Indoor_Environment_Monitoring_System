package com.lkc.service;

import com.lkc.entity.Sensor;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

public interface SensorService {

    //添加
    void save(Sensor sensor);

    //查询历史记录（自定义用）
    List<Sensor> findByCustom(Integer second,Integer start,String mac);

    //查询历史记录（数据断层用）
    List<Sensor> findByDefault(Integer needtime,Integer nowtime,String mac);

    //查找最后一条记录 （实时查询，通过mac来查）   ok
    Sensor findLastTimeByMac(String mac);

    //大数据历史信息（3小时）
    List<Sensor> findAllByMacAndTime(String mac,Integer lasttime);

}
