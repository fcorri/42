#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define KILOBYTE	(1024llu)
#define MEGABYTE	(KILOBYTE * KILOBYTE)
#define GIGABYTE	(KILOBYTE * KILOBYTE * KILOBYTE)

#define MAXSTRING	100

typedef struct {
	clock_t	begin_clock, save_clock;
	time_t	begin_time, save_time;
} time_keeper;

static time_keeper tk;

void start_time(void)
{
	tk.begin_clock = tk.save_clock = clock();
	tk.begin_time = tk.save_time = time(NULL);
}

double prn_time(void)
{
	char	s1[MAXSTRING], s2[MAXSTRING];
	int		field_width, n1, n2;
	double	clocks_per_second = (double) CLOCKS_PER_SEC, user_time, real_time;

	user_time = (clock() - tk.save_clock) / clocks_per_second;
	real_time = difftime(time(NULL), tk.save_time);
	tk.save_clock = clock();
	tk.save_time = time(NULL);

	n1 = sprintf(s1, "%.10f", user_time);
	n2 = sprintf(s2, "%.10f", real_time);
	field_width = (n1 > n2) ? n1 : n2;

	printf("%s%*.10f%s\n%s%*.10f%s\n\n", 
			"User time: ", field_width, user_time, " seconds",
			"Real time: ", field_width, real_time, " seconds");
	return user_time;
}

int main(int argc, char **argv)
{
/*
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;
	int		arg;

	dest = src + 1;
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (dest != ft_memmove(dest, "consectetur", 5))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 2)
	{
		if (dest != ft_memmove(dest, "con\0sec\0\0te\0tur", 10))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 3)
	{
		if (dest != ft_memmove(dest, src, 8))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 4)
	{
		if (src != ft_memmove(src, dest, 8))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	else if (arg == 5)
	{
		if (src != ft_memmove(src, dest, 0))
			write(1, "dest's adress was not returned\n", 31);
		write(1, dest, 22);
	}
	return (0);

	size_t	size = GIGABYTE;
	char	*b1 = (char *)malloc(sizeof(char) * size);
	char	*b2 = (char *)malloc(sizeof(char) * size);

	for (int i=1; i <= 11; i++)
		b1[i] = i;
	ft_memmove(b2 + 2, b1 + 1, 11);

	start_time();
	memset(b1, 'A', size);
	printf("time 1: \n\n");
	prn_time();
	ft_memset(b2, 'A', size);
	printf("time 2: \n\n");
	prn_time();

	return (0);
*/
	void	*mem;
	int		arg;

	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 30);
	if ((arg = atoi(argv[1])) == 1)
	{
		if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	else if (arg == 2)
	{
		if (mem != ft_memcpy(mem, "zyxwvutst", 0))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	else if (arg == 3)
	{
		if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
			write(1, "dest's adress was not returned\n", 31);
		write(1, mem, 30);
	}
	return (0);

}
