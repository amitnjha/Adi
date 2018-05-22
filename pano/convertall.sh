#!/bin/bash
for f in *.jpg; do
  convert ./"$f" ./"${f%.jpg}.tga"
done

tar -cvf pano.tar *.tga

rm *.tga

