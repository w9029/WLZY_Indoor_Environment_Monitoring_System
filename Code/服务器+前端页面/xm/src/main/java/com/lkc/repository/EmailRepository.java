package com.lkc.repository;

import com.lkc.entity.Email;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.PostMapping;

public interface EmailRepository extends JpaRepository<Email,String> {
    //保存 （自带）

    //查找（通过name）
    Email findByName(String name);

    //设置是否开启邮件功能（on-off）
    @Transactional
    @Modifying
    @Query("update Email set control=:control where name=:name")
    int setEmailFunction(@Param("control")String control, @Param("name")String name);

    //查找（通过name和email）（忘记密码功能）
    Email findByNameAndAndEmail(String name,String email);

    //设置验证码 （忘记密码功能）
    @Transactional
    @Modifying
    @Query("update Email set code=:code where name=:name")
    int setCode(@Param("name")String name,@Param("code")String code);

    //核查验证码（通过name和code）（忘记密码功能）
    Email findByNameAndCode(String name,String code);

    //修改（保留功能）

}
