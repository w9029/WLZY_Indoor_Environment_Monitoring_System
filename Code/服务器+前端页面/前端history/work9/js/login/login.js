/* 
 * fnLogin()
 * 变量名			注释
 * oUname		用户名
 * oUpass		用户密码
 * oError		错误信息
 * 判断用户名为小写字母跟数字，不可出现非法字符，用户名及密码长度为6-20位字符
 * 
 * jQuery.ajax()
 * 变量名			赋值
 * type			"GET"
 * url			"http://192.168.100.136:8080/user/login"
 * data			ajaxParams
 * dataType		"text"
 * success		function(data)
 * 用服务器进行连接交互
 * 
 * function(data)
 * 返回值				注释
 * name_error		用户不存在
 * password_error	密码出错
 * success			登陆信息
 * 判断data返回值
 */
document.cookie = "username=; path=/; expires=Thu, 01 Jan 1970 00:00:00 GMT"
				
				
function fnLogin()
{
	var oUname = document.getElementById("uname_log")
	var oUpass = document.getElementById("upass_log")
	var oError = document.getElementById("error_box_log")
	var isError = true;
	
	if (oUname.value.length > 20 || oUname.value.length < 6)
	{
		oError.innerHTML = "用户名为6-20位字符";
		isError = false;
		return;
	}
	
	else for(var i=0;i<oUname.value.charCodeAt(i);i++)
	{
		if((oUname.value.charCodeAt(i)<48)||(oUname.value.charCodeAt(i)>57) && (oUname.value.charCodeAt(i)<97)||(oUname.value.charCodeAt(i)>122))
		{
			oError.innerHTML = "用户名只能由小写字母或数字组成";
			return;
		}
	}
	
	if (oUpass.value.length > 20 || oUpass.value.length < 6)
	{
		oError.innerHTML = "密码为6-20位字符"
		isError = false;
		return;
	}
	
	var ajaxParams={};
	ajaxParams['name']=oUname.value;//传字符串到String
	ajaxParams['password']=hex_md5(oUpass.value);//把数组转为字符串传到后台数组
	jQuery.ajax({
		type:"POST",
		url:"http://"+desip+":8080/user/login",
		data:ajaxParams,
		dataType:"text",
		success:function(data){
			toastr.options.positionClass = 'toast-top-center';
			if (data == "name_error"){
				toastr.warning("用户名不存在！");
			}else if(data == "password_error"){
				toastr.warning("密码错误！");
			}else{
				document.cookie="username="+ oUname.value+"; path=/";
				window.location = "../index.html"
			}
			
		}
	})
}

/* 
 * fnRegist()
 * 变量名			注释
 * oUname		用户名
 * oUpass		用户密码
 * oUpass_again	密码确认
 * oError		错误信息
 * 判断用户名为小写字母跟数字，不可出现非法字符，用户名及密码长度为6-20位字符
 * 
 * jQuery.ajax()
 * 变量名			赋值
 * type			"POST"
 * url			"http://192.168.100.136:8080/user"
 * data			ajaxParams
 * dataType		"text"
 * success		function(data)
 * 用服务器进行连接交互
 * 
 * function(data)
 * 返回值				注释
 * name_error		用户不存在
 * password_error	密码出错
 * success			登陆信息
 * 判断data返回值
 */
function fnRegist()
{
	var oUname = document.getElementById("uname_reg")
	var oUpass = document.getElementById("upass_reg")
	var oUpass_again = document.getElementById("upass_again")
	var oError = document.getElementById("error_box_reg")
	var isError = true;
	var uemail = document.getElementById("uemail");
	
	if (oUname.value.length > 20 || oUname.value.length < 6)
	{
		oError.innerHTML = "用户名请输入6-20位字符";
		isError = false;
		return;
	}
	else for(var i=0;i<oUname.value.charCodeAt(i);i++)
	{
		if((oUname.value.charCodeAt(i)<48)||(oUname.value.charCodeAt(i)>57) && (oUname.value.charCodeAt(i)<97)||(oUname.value.charCodeAt(i)>122))
		{
			oError.innerHTML = "必须为字母跟数字组成";
			return;
		}
	}
	
	if (oUpass.value.length > 20 || oUpass.value.length < 6 || oUpass_again.value.length > 20 || oUpass_again.value.length < 6)
	{
		oError.innerHTML = "密码请输入6-20位字符"
		isError = false;
		return;
	}
	if(oUpass.value != oUpass_again.value)
	{
//		document.getElementById()
		oError.innerHTML = "两次密码不相同"
		isError = false;
		return;
	}
	
	var ajaxParams={};
	ajaxParams['name']=oUname.value;//传字符串到String
	ajaxParams['password']=hex_md5(oUpass.value);//把数组转为字符串传到后台数组
	ajaxParams['email']=uemail.value;
	jQuery.ajax({
		type:"POST",
		url:"http://"+desip+":8080/user",
		data:ajaxParams,
		dataType:"text",
		success:function(data){
			toastr.options.positionClass = 'toast-top-center';
			if (data == "Has"){
				toastr.warning("该用户已注册！");
				/*window.location.href="regist.html"*/
			}else{
				toastr.success("注册成功！");
				document.getElementById("uname_reg").value=null;
				document.getElementById("upass_reg").value=null;
				document.getElementById("upass_again").value=null;
				chShift_b();
			}
			
		}
	})
}

/*
 * chShift_b()
 * 显示登陆界面，隐藏注册界面
 */
function chShift_b() {
	var box1 = document.getElementById("box_login");
	var box2 = document.getElementById("box_regist");
	box1.style.display= 'block';
	box2.style.display = 'none';
}

/*
 * chShift_n()
 * 显示注册界面，隐藏登陆界面
 */
function chShift_n() {
	var box1 = document.getElementById("box_login");
	var box2 = document.getElementById("box_regist");
	box1.style.display= 'none';
	box2.style.display = 'block';
}