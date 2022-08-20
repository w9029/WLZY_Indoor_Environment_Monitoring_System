a=`ifconfig |grep 'HWaddr'|sed -n '1p' | grep -E -o '\w{0,2}:\w{0,2}:\w{0,2}:\w{0,2}:\w{0,2}:\w{0,2}'`

count=`ps -a | grep /workspace/wjh/GetData |wc -l`
if [ $count -eq 1 ]
then
	/workspace/wjh/GetData7.0_47 /workspace/AirDataBase/AirData.db $a
else
        echo "GetData is already running!"
fi



