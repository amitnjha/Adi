#!/bin/bash

pcount=`ps -ef|grep btcontroller|wc -l`


echo 'hello world'
if [ $pcount -lt 2 ] 
then	
	sudo python /usr/lib/cgi-bin/btcontroller.py > /dev/null 2>&1 &

fi


