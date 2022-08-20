count=`ps -a | grep /workspace/wp/build-interface-arm-Release/interface |wc -l`
if [ $count -eq 1 ]
then
	/workspace/wp/build-interface-arm-Release/interface&
else
	echo "Interface is already running!"
fi

