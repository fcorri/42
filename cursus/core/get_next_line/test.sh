#! /usr/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

rm output
touch output
clear

test=0
if [[ $# -eq 1 ]]; then
	gcc -g ../main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$1 -o get_next_line
	echo ./get_next_line $1
	./get_next_line $1
	if [[ $(diff lorem output) ]]; then
		echo -e "\nLOREM\n"
		cat -En lorem
		echo -e "\nOUTPUT\n"
		cat -En output
		echo -e "\n\n"
		diff lorem output
		echo -e "${RED}\nERROR IN TEST NUMBER $1\n${NC}"
		test=0
	else
		test=1
	fi
elif [[ $# -eq 2 ]]; then
	for BUFFER_SIZE in $(seq $1 $2)
	do
		rm output
		touch output
		gcc -g ../main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=$BUFFER_SIZE -o get_next_line
		echo ./get_next_line $BUFFER_SIZE
		./get_next_line $BUFFER_SIZE
		if [[ $(diff lorem output) ]]; then
			echo -e "\nLOREM\n"
			cat -En lorem
			echo -e "\nOUTPUT\n"
			cat -En output
			echo -e "\n\n"
			diff lorem output
			echo -e "${RED}\nERROR IN TEST NUMBER $BUFFER_SIZE\n${NC}"
			test=0
			break
		fi
	done
	test=1
fi

if [[ $test -eq 1 ]]; then
	echo -e "${GREEN}\nCONGRATULATIONS! ALL TESTS PASSED\n${NC}"
else
	echo -e "${RED}\nI\'M SORRY, AN ERROR OCCURRED: LET\'S DEBUG!\n${NC}"
fi
