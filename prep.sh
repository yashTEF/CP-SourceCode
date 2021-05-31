#!/bin/sh
git add *
git commit -m "Commiting All the Files on git"
git push -u origin
git status
for i in a b c d e
do
	rm i*
done
for i in a b c d e
do
	subl i.cpp &
	cp template1.cpp i.cpp
done

echo "Previous Files and Binaries cleaned and new created on"
date



