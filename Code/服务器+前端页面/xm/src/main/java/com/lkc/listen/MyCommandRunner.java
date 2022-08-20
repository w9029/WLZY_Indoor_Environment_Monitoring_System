package com.lkc.listen;

import com.lkc.socket.SocketService;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

//当项目启动时自动运行
@Component
public class MyCommandRunner implements CommandLineRunner {

    @Override
    public void run(String... args) {
        Thread socketThread = new Thread(){
            @Override
            public void run() {
                SocketService socketService = new SocketService(8880);
                try{
                    socketService.SocketStart();
                }catch (Exception e){
                    socketService = null;
                    System.out.println("socket service 启动失败！"+e);
                }
            }
        };
        socketThread.start();
    }
}
