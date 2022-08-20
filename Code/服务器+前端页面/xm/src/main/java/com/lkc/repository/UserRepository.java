package com.lkc.repository;

import com.lkc.entity.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.transaction.annotation.Transactional;

public interface UserRepository extends JpaRepository<User,String> {

    //查找
    User findByName(String name);

    //查找注册时间
    @Query("select regtime from User user where name = :name")
    Integer findRegtimeByName(@Param("name") String name);

    //更新
    @Transactional
    @Modifying
    @Query("update User as c set c.password = :password where c.name= :name")
    int updatePasswordByName(@Param("name") String name, @Param("password") String password);
    //删除（预留）
    void delete(User user);
}
