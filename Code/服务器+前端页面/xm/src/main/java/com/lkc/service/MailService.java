package com.lkc.service;

import com.lkc.entity.Email;

public interface MailService {
    //发送邮件
    void sendMail(String title,String content,String email);

    //添加
    void addMail(String name,String email);

    //查找
    Email findByName(String name);

    //设置验证码（通过name和email）（忘记密码功能）
    String setCode(String name, String email);

    //验证发来的验证码（忘记密码功能）
    String checkcodeAndChg(String name, String code, String password);

    //设置是否开启邮件功能（on-off）
    String setEmailFunction(String name,String control);
}
