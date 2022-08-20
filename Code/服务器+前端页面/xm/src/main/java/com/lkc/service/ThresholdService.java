package com.lkc.service;

import com.lkc.entity.Threshold;
import org.springframework.data.repository.query.Param;

public interface ThresholdService {
    //查找
    Threshold findByName(String name);

    //设置
    String setThreshold(float tmax, float tmin, float hmax, float hmin, float amax, float amin, String name);
}
