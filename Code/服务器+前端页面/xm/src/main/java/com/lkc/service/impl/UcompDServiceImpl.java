package com.lkc.service.impl;

import com.lkc.entity.Device;
import com.lkc.entity.User;
import com.lkc.entity.UserCompDev;
import com.lkc.entity.UserMac;
import com.lkc.repository.UcompDRepository;
import com.lkc.repository.UserRepository;
import com.lkc.service.DeviceService;
import com.lkc.service.UcompDService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UcompDServiceImpl implements UcompDService {
    //日志记录器
    Logger logger = LoggerFactory.getLogger(getClass());

    @Autowired
    private UcompDRepository ucompDRepository;
    @Autowired
    private UserRepository userRepository;
    @Autowired
    private DeviceService deviceService;

    //添加
    @Override
    public String login(UserMac usermac) {
        String name = usermac.getName();
        String password = usermac.getPassword();
        String mac = usermac.getMac();
        User user = new User();
        user = userRepository.findByName(name);
        boolean flg = true;

        if (user == null){
            logger.trace("开发板登录： " + name + " 用户不存在！");
            return "name_error";
        } else if (user.getPassword().equals(password)){
            List<UserCompDev> ucdlist = ucompDRepository.findByName(name);

            //查看该设备是否已在用户名下
            for(UserCompDev ucd : ucdlist){
                if (ucd.getMac().equals(mac)){
                    flg = false;
                    break;
                }
            }

            //若用户名下不存在该设备则添加
            if (flg){
                //添加设备到对照表
                UserCompDev userCompDev = new UserCompDev();
                userCompDev.setName(name);
                userCompDev.setMac(mac);
                ucompDRepository.save(userCompDev);
                userCompDev = null;

                Device device = deviceService.findByMac(mac);
                //若设备不存在于设备表中时  表示该设备没有被开启 没有数据发到服务器
                //添加到设备表 状态设置为0 （关闭）
                if (device == null){
                    Device device1 = new Device();
                    device1.setMac(mac);
                    device1.setStatus(0);
                    deviceService.save(device1);
                    device1 = null;
                    logger.trace("开发板登录： " + name + "  mac号：" + mac + " 设备添加成功！");
                }
            }
            user = null;
            logger.trace("开发板登录： " + name + " 登录成功！");
            return "success";
        }
        user = null;
        logger.trace("开发板登录： " + name + " 密码错误！");
        return "password_error";
    }

    //查找用户的所有设备
    @Override
    public List<UserCompDev> findByName(String name) {
        return ucompDRepository.findByName(name);
    }

    //查找设备对应的用户名
    @Override
    public List<UserCompDev> findByMac(String mac) {
        return ucompDRepository.findByMac(mac);
    }

    //移除用户设备
    @Override
    public String deleteByNameAndMac(String name, String mac) {
        int row = ucompDRepository.deleteByNameAndMac(name,mac);
        if (row > 0){
            logger.trace("用户"+name+" 移除设备"+mac);
            return "success";
        }else{
            return "error";
        }
    }
}
