package com.lkc.service.impl;

import com.lkc.entity.User;
import com.lkc.repository.UserRepository;
import com.lkc.service.MailService;
import com.lkc.service.UserService;
import com.lkc.tool.TimeFormat;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;

@Service
public class UserServiceImpl implements UserService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());

    @Autowired
    private UserRepository userRepository;
    @Autowired
    private MailService mailService;

    //注册
    @Override
    public String addUser(String name,String password, String email){
        //查找是否有用户名
        User user = userRepository.findByName(name);
        if (user != null){
            logger.trace("注册： " + name + " 已存在！");
            return "Has";
        }else{
            User us = new User();
            //注册时间
            long currentTime = new Date().getTime();
            String timestr = String.valueOf(currentTime/1000);
            Integer time = Integer.valueOf(timestr);
            us.setName(name);
            us.setPassword(password);
            us.setRegtime(time);
            userRepository.save(us);
            us = null;

            //添加邮箱
            mailService.addMail(name,email);

            //设置关闭使用邮箱功能
            mailService.setEmailFunction(name,"off");

            logger.trace("注册： " + name + " 注册成功！");

            //发送邮件
            Thread emailThread = new Thread(){
                @Override
                public void run() {
                    String title = "注册了沃基环境监测系统账号";
                    String setText = "成功注册！";
                    mailService.sendMail(title,setText,email);
                    logger.trace("给"+email+"发送注册邮件成功！");
                }
            };
            emailThread.start();

            return "success";
        }
    }

    //登录
    @Override
    public String login(String name,String password){
        User user = userRepository.findByName(name);

        if (user == null){
            logger.trace("登录： " + name + " 用户名不存在！");
            user = null;
            return "name_error"; //用户名不存在
        }else if (user.getPassword().equals(password)){
            logger.trace("登录： " + name + " 登录成功！");
            user = null;
            return "success";   //密码符合
        }else{
            logger.trace("登录：" + name + " 密码错误！");
            user = null;
            return "password_error"; //密码错误
        }
    }

    //查找注册时间
    @Override
    public String findRegtime(String name) {
        Integer time = userRepository.findRegtimeByName(name);
        return TimeFormat.secondToTime(String.valueOf(time));
    }

    //修改密码
    @Override
    public String changePassword(String name, String newpassword){
        int i = userRepository.updatePasswordByName(name,newpassword);
        if (i != 0){
            logger.trace("修改密码： " + name + " 修改密码成功！");
            return "success";
        }else{
            logger.trace("修改密码： " + name + " 修改密码失败！");
            return "update error";
        }
    }
}
