package com.lkc.entity;

import javax.persistence.*;

//传感器模型
@Entity
@Table(name = "sensor_info")
public class Sensor {
    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    @Column(name = "id")
    private Integer id;
    @Column(name = "time")
    private Integer time;        //当时时间
    @Column(name = "temperature")
    private float temperature;  //温度
    @Column(name = "humidity")
    private float humidity;     //湿度
    @Column(name = "ammonia")
    private float ammonia;      //氨气
    @Column(name = "mac")
    private String mac;         //设备地址

    public float getAmmonia() {
        return ammonia;
    }

    public void setAmmonia(float ammonia) {
        this.ammonia = ammonia;
    }

    public Integer getTime() {
        return time;
    }

    public void setTime(Integer time) {
        this.time = time;
    }

    public float getHumidity() {
        return humidity;
    }

    public void setHumidity(float humidity) {
        this.humidity = humidity;
    }

    public float getTemperature() {
        return temperature;
    }

    public void setTemperature(float temperature) {
        this.temperature = temperature;
    }

    public String getMac() {
        return mac;
    }

    public void setMac(String mac) {
        this.mac = mac;
    }
}
