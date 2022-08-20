package com.lkc.service;

import com.lkc.entity.UserCompDev;
import com.lkc.entity.UserMac;

import java.util.List;

public interface UcompDService {
    //添加
    String login(UserMac usermac);

    //查找用户所有设备（通过name）
    List<UserCompDev> findByName(String name);

    //查找设备对应的用户名
    List<UserCompDev> findByMac(String mac);

    //移除用户设备
    String deleteByNameAndMac(String name,String mac);
}
