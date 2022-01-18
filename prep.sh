#!/bin/sh
#git add *
#git commit -m "Commiting All the Files on git"
#git push -u origin
#git status
echo "Welcome TheDarkKnight03"
echo "Preparing Files ..."
for i in a b c d e f
do
	rm $i*
done
for i in a b c d e f
do
	subl $i.cpp &
	cp template1.cpp $i.cpp
	
done

echo "Previous Files and Binaries cleaned and new created on"
date



