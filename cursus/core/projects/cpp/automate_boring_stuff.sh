#!/bin/bash

clear

if [[ -z $1 ]]; then
	echo "Cartella non specificata"
	exit 1
fi

for file in $1build/inc/*; do
	python3 automate_boring_stuff.py $file
	cat $file
	echo "-----------------------------------------------------------------------------------------"
	cat $1src/*
done

exit 0
