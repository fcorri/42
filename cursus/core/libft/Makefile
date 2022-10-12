compile:
	gcc -Wall -Wextra -Werror -c *.c

libft: compile
	ar -crs libft.a *.o
	rm -f *.o

main: libft
	gcc -g ../main.c libft.a
