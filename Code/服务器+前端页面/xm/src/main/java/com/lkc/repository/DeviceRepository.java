package com.lkc.repository;

import com.lkc.entity.Device;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.PostMapping;

public interface DeviceRepository extends JpaRepository<Device,Integer> {
    //添加 （自带方法 save）

    //设置状态 （通过mac来设置状态）ok
    @Transactional
    @Modifying
    @Query("update Device as c set c.status = :status where c.mac= :mac")
    Integer updateByMac(@Param("mac") String mac, @Param("status") Integer status);

    //查找（通过mac来查）
    Device findByMac(String mac);

    //查找ip（通过mac来查）
    @Query("select url from Device device where mac = :mac")
    String findUrlByMac(@Param("mac") String mac);

    //设置ip
    @Transactional
    @Modifying
    @Query("update Device as c set c.url = :url where c.mac= :mac")
    void updateUrl(@Param("url")String url, @Param("mac")String mac);
}

