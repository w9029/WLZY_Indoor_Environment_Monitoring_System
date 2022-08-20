package com.lkc.repository;

import com.lkc.entity.Threshold;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.transaction.annotation.Transactional;

public interface ThresholdRepository extends JpaRepository<Threshold,String> {

    //查找
    Threshold findByName(String name);

    //设置（更新）
    @Transactional
    @Modifying
    @Query("update Threshold set temp_min=:tmin,temp_max=:tmax,hum_max=:hmax,hum_min=:hmin,amm_max=:amax,amm_min=:amin where name=:name")
    int setThreshold(@Param("tmax")float tmax,@Param("tmin")float tmin,
                     @Param("hmax")float hmax,@Param("hmin")float hmin,
                     @Param("amax")float amax,@Param("amin")float amin,
                     @Param("name")String name);
}
