
function localize(lng){
    var deferred = $.i18n.init({
        lng         : lng || 'zh-CN',      //翻译成的语言
        load        : 'current',           //加载当前设置的语言包
        getAsync    : false,               //是否异步调用语言包
        resGetPath  : './locale/__lng__/__ns__.json', // 加载资源的路径
        ns: { namespaces: ['language'], defaultNs: 'language'},             //加载的语言包
        localStorageExpirationTime: 86400000                                  // 有效周期，单位ms。默认1周
    });
    console.log(deferred);
    return deferred;
}
function change(data)
{
	localize(data).done(function(){ $('div.content').i18n();});
}
function func(){
 //获取被选中的option标签
 var vs = $('select  option:selected').val();
 /*change_lan(vs);*/
localStorage.setItem('localLan', vs);
 change(vs);
 location=location;
}
function localuser(){
	//获取cookie字符串
	var strCookie=document.cookie;
	//将多cookie切割为多个名/值对
	var arrCookie=strCookie.split("; ");
	var userId;
	//遍历cookie数组，处理每个cookie对
	for(var i=0;i<arrCookie.length;i++){
		var arr=arrCookie[i].split("=");
		//找到名称为userId的cookie，并返回它的值
		if("username"==arr[0]){
			userId=arr[1];
			break;
		}
	}
	return userId;
}
var localLanguage = localStorage.getItem('localLan');

