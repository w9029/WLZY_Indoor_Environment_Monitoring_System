
function firstFormConnect()
{
	var mdui = document.getElementById('demo-js');
	var now =new Date();
	
	var ajaxParams={};
	ajaxParams['needtime']=mdui.value;//传需要显示时间次数
	ajaxParams['nowtime']=Math.round(now.getTime()/1000);
	
	jQuery.ajax({
		type:"GET",
		url:"http://192.168.100.136:8080/find/default",
		data:ajaxParams,
		dataType:"text",
		success:function(data){
			alert(data.value);
            //alert(data.err); eval(data.err)//分解
/*			var html="<table>";
            for(var i=0;i<data.err.length;i++)
			{
				html+=“<tr><td>data.err[i].uid</td></tr>”;
			}
			html+="</table>";*/
		} 
	})
}





/*function secondFormConnect()
{
	
	var ajaxParams={};
	ajaxParams['sec']=oUname.value;//传字符串到String
	ajaxParams['start']=oUpass.value;//把数组转为字符串传到后台数组
	ajaxParams['finish']=
	jQuery.ajax({
		type:"POST",
		url:"http://192.168.100.136:8080/find/custom",
		data:ajaxParams,
		dataType:"text",
		success:function(data){
			if (data){
				alert("传输成功");
				//window.location.href="regist.html"
			}else{
				alert("注册成功！");
				document.getElementById("uname_reg").value=null;
				document.getElementById("upass_reg").value=null;
				document.getElementById("upass_again").value=null;
				chShift_b();
			}
			
			
		}
	})
}*/