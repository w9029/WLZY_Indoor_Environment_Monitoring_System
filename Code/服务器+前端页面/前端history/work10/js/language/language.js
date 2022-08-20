function change_lan(value){
	if(value == "en-US"){
		document.getElementById("uname_log").setAttribute("placeholder","please enter your username");
		document.getElementById("upass_log").setAttribute("placeholder","please enter password");
		document.getElementById("uname_reg").setAttribute("placeholder","please enter your username");
		document.getElementById("upass_reg").setAttribute("placeholder","please enter password");
		document.getElementById("upass_again").setAttribute("placeholder","please enter password again");
		document.getElementById("uemail").setAttribute("placeholder","Please enter your mailbox");
	}else if(value == "zh-CN"){
		document.getElementById("uname_log").setAttribute("placeholder","请输入用户名");
		document.getElementById("upass_log").setAttribute("placeholder","请输入密码");
		document.getElementById("uname_reg").setAttribute("placeholder","请输入用户名");
		document.getElementById("upass_reg").setAttribute("placeholder","请输入密码");
		document.getElementById("upass_again").setAttribute("placeholder","再次输入密码");
		document.getElementById("uemail").setAttribute("placeholder","请输入邮箱");
	}
	
}
