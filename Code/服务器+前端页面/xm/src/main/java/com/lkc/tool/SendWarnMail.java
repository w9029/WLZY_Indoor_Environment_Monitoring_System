package com.lkc.tool;

import com.lkc.entity.Email;
import com.lkc.entity.Sensor;
import com.lkc.entity.Threshold;
import com.lkc.entity.UserCompDev;
import com.lkc.service.MailService;
import com.lkc.service.ThresholdService;
import com.lkc.service.UcompDService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import java.util.List;

@Component
public class SendWarnMail extends Thread {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());

    //用于查找设备对应的用户名
    @Autowired
    private UcompDService ucompDService;
    //用于查找用户对应的阈值
    @Autowired
    private ThresholdService thresholdService;
    //用于发送报警邮件
    @Autowired
    private MailService mailService;

    private Sensor sensor;
    private String ip;

    /******************************************************/
    private static SendWarnMail sendWarnMail;
    @PostConstruct
    public void init(){
        sendWarnMail = this;
        sendWarnMail.mailService = this.mailService;
        sendWarnMail.ucompDService = this.ucompDService;
        sendWarnMail.thresholdService = this.thresholdService;
    }

    /******************************************************/
    SendWarnMail(){};
    public SendWarnMail(Sensor sensor,String ip){
        this.sensor = sensor;
        this.ip = ip;
    }

    /*****************************************************/
    @Override
    public void run() {
        int time = sensor.getTime();
        float temp = sensor.getTemperature();
        float amm = sensor.getAmmonia();
        float hum = sensor.getHumidity();
        String mac = sensor.getMac();
        String title = "预警邮件";
        String email;
        String content="";
        boolean email_flg;      //是否达到阈值 标志位
        String name;
        List<UserCompDev> ucdList = sendWarnMail.ucompDService.findByMac(mac);

        if (ucdList != null){
            for(UserCompDev ucd : ucdList){
                email_flg = false;
                name = ucd.getName();
                Email usermail = sendWarnMail.mailService.findByName(name);

                if (usermail.getControl().equals("on")){
                    Threshold threshold = sendWarnMail.thresholdService.findByName(name);
                    email = usermail.getEmail();

                    if(threshold.getAmm_max() < amm){
                        content = content + "  氨气值为"+ amm + " 超过上限！\n";
                        email_flg = true;
                    }else if(threshold.getAmm_min() > amm){
                        content =  content + "  氨气值为"+ amm + " 低于下限！\n";
                        email_flg = true;
                    }

                    if(threshold.getHum_max() < hum){
                        content = content + "  湿度值为"+ hum + " 超过上限！\n";
                        email_flg = true;
                    }else if(threshold.getHum_min() > hum){
                        content =  content + "  湿度值为"+ hum + " 低于下限！\n";
                        email_flg = true;
                    }

                    if(threshold.getTemp_max() < temp){
                        content = content + "  温度值为"+ temp + " 超过上限！\n";
                        email_flg = true;
                    }else if(threshold.getTemp_min() > temp){
                        content =  content + "  温度值为"+ temp + " 低于下限！\n";
                        email_flg = true;
                    }
                    if (email_flg){
                        content = "您好，"+ name +":\n"+
                                "  您的"+ucd.getNumber()+"号设备"+ mac +" 于 "+TimeFormat.secondToTime(String.valueOf(time)) +" 发出报警：\n" +
                                content + "详情请查看该设备历史数据！\n" +
                                "请登录http://"+ip.replace("/","")+":8080/WLZY/login_web/login.html";
                        sendWarnMail.mailService.sendMail(title,content,email);
                        logger.info("预警邮件发送成功！ to："+email);
                    }
                    content = null;
                }
            }
        }

    }
}
