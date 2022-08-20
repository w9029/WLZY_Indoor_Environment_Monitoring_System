package com.lkc.service.impl;

import com.lkc.entity.Email;
import com.lkc.repository.EmailRepository;
import com.lkc.repository.UserRepository;
import com.lkc.service.MailService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.stereotype.Service;

import java.util.Random;


@Service
public class MailServiceImpl implements MailService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());
    @Autowired
    private JavaMailSender mailSender;
    @Autowired
    private EmailRepository emailRepository;
    @Autowired
    private UserRepository userRepository;

    @Value("860990180@qq.com")
    private String from;

    //发送
    @Override
    public void sendMail(String title, String content, String email) {
            SimpleMailMessage message = new SimpleMailMessage();
            message.setFrom(from);
            message.setSubject(title);
            message.setTo(email);
            message.setText(content);
            mailSender.send(message);
    }

    //添加
    @Override
    public void addMail(String name, String email) {
        Email mail = new Email();
        mail.setName(name);
        mail.setEmail(email);
        emailRepository.save(mail);
    }

    //查找
    @Override
    public Email findByName(String name) {
        Email mail = emailRepository.findByName(name);
        return mail;
    }

    //设置验证码（忘记密码功能）
    @Override
    public String setCode(String name, String email) {
        Email user = emailRepository.findByNameAndAndEmail(name,email);
        if (user != null){
            String code = "";
            int tmp;

            //生成随机验证码
            Random random = new Random();
            for (int i=0; i<6; ++i) {
                switch (random.nextInt(3)) {
                    case 0:     //生成A-Z的字母
                        tmp = random.nextInt(26) + 65;
                        code = code + (char) tmp;
                        break;
                    case 1:     //生成a-z的字母
                        tmp = random.nextInt(26) + 97;
                        code = code + (char) tmp;
                    default:    //生成数字
                        tmp = random.nextInt(10);
                        code = code + String.valueOf(tmp);
                }
            }
            int i = emailRepository.setCode(name,code);
            logger.debug(name + "的验证码生成成功！");
            final String Code = code;
            code = null;

            //发送验证码邮件
            new Thread(){
                @Override
                public void run() {
                    String title = "沃基环境监测系统密码找回";
                    String content = "验证码为：" + Code;
                    sendMail(title,content,email);
                }
            }.start();

            return "success";
        }
        return "error";
    }

    //验证发来的验证码（忘记密码功能）
    @Override
    public String checkcodeAndChg(String name, String code, String password) {
        Email email = emailRepository.findByNameAndCode(name,code);
        if (email != null){
            userRepository.updatePasswordByName(name,password);
            logger.info(name + "成功找回密码！");
            return "success";
        }
        return "error";
    }

    //设置是否开启邮件功能（on-off）
    @Override
    public String setEmailFunction(String name, String control) {
        int i = emailRepository.setEmailFunction(control,name);
        if ( i > 0){
            return "success";
        }else{
            return "failed";
        }
    }
}
