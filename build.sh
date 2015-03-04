#!/bin/bash

CURDIR=pwd

echo "current directory is $CURDIR"

if [ ! -d "build" ]; then
	echo "build directory does not exist - let's create it"
	mkdir build
fi
cd build
#rm -rf *
echo "current directory"
pwd
echo "start build"
cmake ..
make
