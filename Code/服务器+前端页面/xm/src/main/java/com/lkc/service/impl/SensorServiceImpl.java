package com.lkc.service.impl;

import com.lkc.entity.Sensor;
import com.lkc.repository.SensorRepository;
import com.lkc.service.SensorService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class SensorServiceImpl implements SensorService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());

    @Autowired
    private SensorRepository sensorRepository;

    //添加
    @Override
    public void save(Sensor sensor){
        sensorRepository.save(sensor);
    }

    //查询历史记录（自定义）
    @Override
    public List<Sensor> findByCustom(Integer second,Integer start,String mac) {
        List<Sensor> retList = new ArrayList<Sensor>();
        int historytime = start;
        int count = second;
        //每小时一条数据  共24条
        Sensor sensor;
        for(int i=0; i<24; i++){
            sensor = sensorRepository.findByTimeAndMac(historytime,historytime+count,mac);
            if (null != sensor) {
                retList.add(sensor);
            }
            historytime = historytime + count;
        }
        sensor = null;
        return retList;
    }

    //查询历史记录（默认）
    @Override
    public List<Sensor> findByDefault(Integer needtime,Integer nowtime,String mac){
        logger.trace("查询过去" + needtime + "小时的数据");
        List<Sensor> retList = new ArrayList<Sensor>();
        int t1,t2;
        int count = 900;

        if (needtime == 6){
            count = 900;                //过去6小时  900s（15分钟递增）
        }else if (needtime == 12){
            count = 1800;               //过去12小时 1800s（30分钟递增）
        }else if (needtime == 24){
            count = 3600;               //过去24小时 3600s（60分钟递增）
        }

        int historytime = nowtime - needtime*3600;                      //最远历史时间
        int historynext = historytime + count - historytime % count;    //最远历史时间的下一个整点
        int nownext = nowtime + count - nowtime%count - 1;              //当前时间的下一个整点

        //整点查 共24条
        Sensor sensor;
        for(int tmp=historynext; tmp<nownext; tmp=tmp+count){
            t1 = tmp;
            t2 = tmp + count -1;
            sensor = sensorRepository.findByTimeAndMac(t1,t2,mac);
            if (null != sensor) {
                retList.add(sensor);
            }
        }
        sensor = null;
        return retList;
    }

    //实时查询
    @Override
    public Sensor findLastTimeByMac(String mac){
       return sensorRepository.findLastTimeByMac(mac);
    }

    //大数据历史信息（3小时）（固定3小时）
    @Override
    public List<Sensor> findAllByMacAndTime(String mac, Integer lasttime) {
        logger.trace("查询" + "mac号为 "+mac + " 的过去3小时的数据");
        return sensorRepository.findAllByMacAndTime(mac,lasttime,lasttime+10800);
    }
}
