#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include "libft/libft.h"

#define MAXSTRING 100

typedef struct 
{
	clock_t	begin_clock, save_clock;
	time_t	begin_time, save_time;
} time_keeper;

static time_keeper tk;

void start_time(void)
{
	tk.begin_clock = tk.save_clock = clock();
	tk.begin_time = tk.save_time = time(NULL);
}

void prn_time(void)
{
	char	s1[MAXSTRING], s2[MAXSTRING];
	int	field_width, n1, n2;
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
}

int main(void)
{
	int reading = open("");
	start_time();
	prn_time();
	return (0);
}
