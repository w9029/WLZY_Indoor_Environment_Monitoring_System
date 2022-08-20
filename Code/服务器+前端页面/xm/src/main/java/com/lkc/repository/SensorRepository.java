package com.lkc.repository;

import com.lkc.entity.Sensor;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

import java.util.List;

public interface SensorRepository extends JpaRepository<Sensor,Integer> {
    //添加
    //用自带的save

    //查询历史记录
    //t1 为某个时间段开始时间
    //t2 为某个时间段结束时间
    @Query(value="select * from sensor_info where mac = :mac and time between :t1 and :t2 limit 1",nativeQuery = true)
    Sensor findByTimeAndMac(Integer t1,Integer t2,String mac);

    //查询实时记录（数据库最后一条数据）（成功）  ok
    @Query("select sensor from Sensor sensor where time = (select max(time) from Sensor where mac = :mac)")
    Sensor findLastTimeByMac(@Param("mac") String mac);

    //大数据历史信息（3小时）
    @Query("select sensor from Sensor sensor where mac = :mac and time between :t1 and :t2")
    List<Sensor> findAllByMacAndTime(@Param("mac") String mac, @Param("t1") Integer lasttime, @Param("t2") Integer nowtime);

}
