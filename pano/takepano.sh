#!/bin/bash

rm images/input/*.jpg
rm images/output/*.jpg

i=1
ext='.jpg'
while [ $i -le $1 ]
do
#picname=`date +"%Y%m%d%H%M%S.jpg"`
picname="${i}${ext}"

echo $picname

raspistill  -hf -vf --width 480 --height 640 -o images/input/$picname

#python sendmail.py $picname
sudo python testrobo_right.py
let i=i+1
#rm $picname
done

echo 'Stitching'

./stitching images/input $1 images/output




