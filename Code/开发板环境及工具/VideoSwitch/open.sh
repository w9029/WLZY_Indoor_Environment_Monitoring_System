count=`ps -a|grep mjpg-streamer/start.sh|wc -l`
if [ $count -eq 1 ]
then
	/workspace/mjpg-streamer/start.sh
else
	echo "mjpg-streamer is already running!"
fi

