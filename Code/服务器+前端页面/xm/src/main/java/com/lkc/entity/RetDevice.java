package com.lkc.entity;

//获取设备 返回的模型 （前端显示模型）
public class RetDevice {
    private Integer number;
    private String mac;
    private Integer status;
    private String lasttime;

    public String getMac() {
        return mac;
    }

    public void setMac(String mac) {
        this.mac = mac;
    }

    public Integer getNumber() {
        return number;
    }

    public void setNumber(Integer number) {
        this.number = number;
    }

    public Integer getStatus() {
        return status;
    }

    public void setStatus(Integer status) {
        this.status = status;
    }

    public void setLasttime(String lasttime) {
        this.lasttime = lasttime;
    }

    public String getLasttime() {
        return lasttime;
    }
}
