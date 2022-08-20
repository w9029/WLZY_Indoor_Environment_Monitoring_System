package com.lkc.service.impl;

import com.lkc.entity.Threshold;
import com.lkc.repository.ThresholdRepository;
import com.lkc.service.ThresholdService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class ThresholdServiceImpl implements ThresholdService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());

    @Autowired
    private ThresholdRepository thresholdRepository;

    //获取当前的阈值
    @Override
    public Threshold findByName(String name) {
        logger.trace("用户："+name+"  获取了阀值");
        Threshold threshold = thresholdRepository.findByName(name);

        return threshold;
    }

    //设置阈值
    @Override
    public String setThreshold(float tmax, float tmin, float hmax, float hmin, float amax, float amin, String name) {
        logger.trace("用户："+name+"  设置了阀值");
        int i = thresholdRepository.setThreshold(tmax,tmin,hmax,hmin,amax,amin,name);
        if ( i > 0){
            return "success";
        }else{
            return "error";
        }
    }
}
