package com.lkc.entity;

//板子设置阈值用
public class DevSetth {
    private String name;
    private float tmax;
    private float tmin;
    private float hmax;
    private float hmin;
    private float amax;
    private float amin;

    public String getName() {
        return name;
    }

    public float getAmax() {
        return amax;
    }

    public float getAmin() {
        return amin;
    }

    public float getHmax() {
        return hmax;
    }

    public float getHmin() {
        return hmin;
    }

    public float getTmax() {
        return tmax;
    }

    public float getTmin() {
        return tmin;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setAmax(float amax) {
        this.amax = amax;
    }

    public void setAmin(float amin) {
        this.amin = amin;
    }

    public void setHmax(float hmax) {
        this.hmax = hmax;
    }

    public void setHmin(float hmin) {
        this.hmin = hmin;
    }

    public void setTmax(float tmax) {
        this.tmax = tmax;
    }

    public void setTmin(float tmin) {
        this.tmin = tmin;
    }
}
