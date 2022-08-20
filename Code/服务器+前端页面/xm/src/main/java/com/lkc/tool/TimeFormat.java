package com.lkc.tool;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class TimeFormat {
    //秒数转换成格式化
    public static String secondToTime(String time){
        String dateStr="1970-1-1 08:00:00";
        SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        if (time.equals("0")) {
            return "";
        }
        Date miDate;
        String returnstr="";
        try {
            miDate = sdf.parse(dateStr);
            Object t1=miDate.getTime();
            long h1=Long.parseLong(time)*1000+Long.parseLong(t1.toString());
            returnstr=sdf.format(h1);
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return returnstr;
    }
}
