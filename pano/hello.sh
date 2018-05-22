#!/bin/bash

i=0;
ext='.jpg'

while true;
do
	#echo "$i.jpg"
	picname="${i}${ext}"	
        echo $picname	
	let i=i+1
done

