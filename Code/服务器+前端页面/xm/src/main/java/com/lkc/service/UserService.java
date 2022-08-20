package com.lkc.service;


public interface UserService {

    //注册
    String addUser(String name,String password,String email);
    //登陆
    String login(String name,String password);
    //查找注册时间
    String findRegtime(String name);
    //更新
    String changePassword(String name, String password);
}
