package com.lkc.controller;

import com.lkc.entity.Email;
import com.lkc.entity.Threshold;
import com.lkc.service.MailService;
import com.lkc.service.ThresholdService;
import com.lkc.service.UserService;
import net.sf.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

@RestController
public class UserController {
    @Autowired
    private UserService userService;
    @Autowired
    private ThresholdService thresholdService;
    @Autowired
    private MailService mailService;

    //注册
    @PostMapping("/user")
    public String addUser(@RequestParam("name") String name,
                          @RequestParam("password") String password,
                          @RequestParam("email") String email){
        return userService.addUser(name,password,email);
    }

    //登陆
    @PostMapping("/user/login")
    public String login(@RequestParam("name") String name,
                        @RequestParam("password") String password){
        return userService.login(name,password);
    }

    //必须是登陆状态才能改密码
    @PostMapping("/user/chg")
    public String changePassword(@RequestParam("name") String name,
                                 @RequestParam("newpassword") String password){
        return userService.changePassword(name,password);
    }

    //获取注册时间
    @GetMapping("/user/regtime")
    public String findRegtime(@RequestParam("name") String name){
        return userService.findRegtime(name);
    }

    //获取用户的阀值（web用）
    @PostMapping("/user/getthd")
    public String findThreshold(@RequestParam("name")String name){
        Threshold threshold = thresholdService.findByName(name);
        JSONObject jsonObject = JSONObject.fromObject(threshold);
        String jsonstr = jsonObject.toString();

        return jsonstr;
    }

    //设置用户的阀值（web用）
    @PostMapping("/user/setthd")
    public String setThreshold(@RequestParam("tmax")float tmax,@RequestParam("tmin")float tmin,
                               @RequestParam("hmax")float hmax,@RequestParam("hmin")float hmin,
                               @RequestParam("amax")float amax,@RequestParam("amin")float amin,
                               @RequestParam("name")String name){
        return thresholdService.setThreshold(tmax,tmin,hmax,hmin,amax,amin,name);
    }

    //设置是否开启邮件功能（on-off）
    @PostMapping("/user/setmailfunc")
    public String setEmailFunction(@RequestParam("name")String name,
                                   @RequestParam("control")String control){
        return mailService.setEmailFunction(name,control);
    }

    //获取邮件功能值
    @PostMapping("/user/getmailfunc")
    public String getEmailFunction(@RequestParam("name")String name){
        return mailService.findByName(name).getControl();
    }

    //生成验证码并发送邮件（忘记密码功能）
    @PostMapping("/user/remember")
    public String setCode(@RequestParam("name")String name,
                          @RequestParam("email")String email){
        return mailService.setCode(name,email);
    }

    //验证发来的验证码（忘记密码功能）
    @PostMapping("/user/code")
    public String checkcodeAndChg(@RequestParam("name")String name,
                                  @RequestParam("code")String code,
                                  @RequestParam("password")String password){
        return mailService.checkcodeAndChg(name,code,password);
    }
}