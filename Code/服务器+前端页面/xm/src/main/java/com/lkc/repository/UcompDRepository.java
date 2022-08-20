package com.lkc.repository;

import com.lkc.entity.Device;
import com.lkc.entity.UserCompDev;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

public interface UcompDRepository extends JpaRepository<UserCompDev,Integer> {
    //添加 （用自带方法）

    //查找用户的所有设备
    List<UserCompDev> findByName(String name);

    //查找设备对应的用户名
    List<UserCompDev> findByMac(String mac);

    //移除用户设备
    @Transactional
    @Modifying
    @Query("delete from UserCompDev where name=:name and mac=:mac")
    int deleteByNameAndMac(@Param("name") String name, @Param("mac") String mac);
}
