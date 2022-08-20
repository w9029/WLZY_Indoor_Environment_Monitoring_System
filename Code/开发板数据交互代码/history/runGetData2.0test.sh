a=`ifconfig |grep 'HWaddr'|sed -n '1p' | grep -E -o '\w{0,2}:\w{0,2}:\w{0,2}:\w{0,2}:\w{0,2}:\w{0,2}'`
./GetData2.0test $a

