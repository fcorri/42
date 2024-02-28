/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_p.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:42:25 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/31 19:41:44 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_P_H
# define PHILO_P_H

# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define LEN		1024
# define LEN_1		1023

# define T			"is thinking"
# define F			"has taken a fork"
# define E			"is eating"
# define S			"is sleeping"

typedef struct node
{
	int		id_philo;
	char	*message;
	time_t	timestamp;
}	t_node;

typedef struct queue
{
	pthread_mutex_t	mutex;
	t_node			*memory;
	int				read;
	int				write;
	int				counter;
}	t_queue;

typedef struct table
{
	time_t			start_dinner;
	int				number_of_philos;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				max_meals;
	pthread_mutex_t	*forks;
	t_queue			*queue;
	pthread_mutex_t	mutex;
	int				are_alive;
	int				finite_meals;
}	t_table;

typedef struct philo
{
	int				id;
	int				meals;
	pthread_mutex_t	mutex;
	time_t			last_meal;
	pthread_t		thread;
	t_table			*table;
}	t_philo;

typedef struct critical_section
{
	pthread_mutex_t	*mutex;
	int				*value;
}	t_cs;

typedef struct dvector
{
	int	x;
	int	y;
}	t_dvector;

typedef struct times
{
	time_t	sd;
	time_t	ct;
	time_t	ttd;
	time_t	lm;
}	t_times;

typedef struct table_forks
{
	t_table			*table;
	pthread_mutex_t	*forks;
}	t_tf;

int		ft_init_table(int argc, char **argv, t_table *table);
int		ft_init_queue_and_logger(t_table *table, pthread_t *logger);
int		ft_init_forks_checker_and_philos(t_philo **philos, \
	t_table *table, pthread_t *checker);

int		ft_error(char *string, size_t len);
int		ft_free_and_return(t_table *table, t_philo *philos, int output);
int		ft_atoi(char *str);
time_t	ft_time(void);
int		ft_enqueue(t_philo *philo, t_node node, time_t ttd);

void	ft_lock_and_set(pthread_mutex_t *mutex, int *value, int set);
void	ft_lock_and_set_time_t(pthread_mutex_t *mutex, time_t *value, \
	time_t set);
int		ft_lock_and_get(pthread_mutex_t *mutex, int *value);
int		ft_lock_get_and_decrease(pthread_mutex_t *mutex, int *value);

void	*ft_checking(void *philos);
void	*ft_logging(void *p_queue);
void	*ft_simposio(void *p_philo);

int		ft_take_sx_dx(t_philo *philo, t_dvector i_n, t_times times);
int		ft_take_dx_sx(t_philo *philo, t_dvector i_n, t_times times);
void	ft_leave_forks(t_philo *philo, t_dvector i_n);

#endif
