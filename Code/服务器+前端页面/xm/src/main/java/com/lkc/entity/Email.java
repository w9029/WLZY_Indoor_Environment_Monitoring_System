package com.lkc.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

//邮件表模型
@Entity
@Table(name = "email_info")
public class Email {
    @Id
    @Column(name = "name")
    private String name;
    @Column(name = "email")
    private String email;
    @Column(name = "code")
    private String code;
    @Column(name = "control")
    private String control;

    public String getControl() {
        return control;
    }

    public void setControl(String control) {
        this.control = control;
    }

    public String getName() {
        return name;
    }

    public String getCode() {
        return code;
    }

    public String getEmail() {
        return email;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
