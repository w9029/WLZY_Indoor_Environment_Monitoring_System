package com.lkc.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

//阀值模型
@Entity
@Table(name = "threshold_info")
public class Threshold {
    @Id
    @Column(name = "name")
    private String name;
    @Column(name = "temp_max")
    private float temp_max;
    @Column(name = "temp_min")
    private float temp_min;
    @Column(name = "hum_max")
    private float hum_max;
    @Column(name = "hum_min")
    private float hum_min;
    @Column(name = "amm_max")
    private float amm_max;
    @Column(name = "amm_min")
    private float amm_min;

    public String getName() {
        return name;
    }

    public float getAmm_max() {
        return amm_max;
    }

    public float getAmm_min() {
        return amm_min;
    }

    public float getHum_max() {
        return hum_max;
    }

    public float getHum_min() {
        return hum_min;
    }

    public float getTemp_max() {
        return temp_max;
    }

    public float getTemp_min() {
        return temp_min;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAmm_max(float amm_max) {
        this.amm_max = amm_max;
    }

    public void setAmm_min(float amm_min) {
        this.amm_min = amm_min;
    }

    public void setHum_max(float hum_max) {
        this.hum_max = hum_max;
    }

    public void setHum_min(float hum_min) {
        this.hum_min = hum_min;
    }

    public void setTemp_max(float temp_max) {
        this.temp_max = temp_max;
    }

    public void setTemp_min(float temp_min) {
        this.temp_min = temp_min;
    }
}
