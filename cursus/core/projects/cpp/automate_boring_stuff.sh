#!/bin/bash

clear

if [[ -z $1 ]]; then
	echo -e "Cartella dell'esercizio non specificata\nUtilizzo:\t./automate_boring_stuff.sh cppXX/exXX/"
	exit 1
fi

find $1build/inc/ -type f -name "copyOf*" -exec rm {} \;
find $1src/ -type f -name "copyOf*" -exec rm {} \;

for file in $1build/inc/*; do
	python3 automate_boring_stuff.py $file
done

exit 0
