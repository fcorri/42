/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:04:58 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/30 18:52:22 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

int	ft_init_table(int argc, char **argv, t_table *table)
{
	int	i;
	int	arg[5];

	i = -1;
	while (++i < argc)
	{
		arg[i] = ft_atoi(argv[i]);
		if (arg[i] == -1)
			return (ft_error("ONE OF THE ARGUMENT IS INVALID\n", 31));
		else if (i == 0 && arg[i] == 0)
			return (ft_error("PHILOSOPHERS MUST BE MORE THAN 0\n", 33));
	}
	table->number_of_philos = arg[0];
	table->time_to_die = arg[1];
	table->time_to_eat = arg[2] * 1000;
	table->time_to_sleep = arg[3] * 1000;
	table->finite_meals = 0;
	if (argc == 5)
	{
		table->finite_meals = 1;
		table->max_meals = arg[4];
	}
	table->are_alive = 1;
	return (1);
}

int	ft_init_queue_and_logger(t_table *table, pthread_t *logger)
{
	t_queue	*queue;
	t_node	*memory;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (ft_error("ALLOCAZIONE DI CODA DI LOGGING NON RIUSCITA\n", 44));
	memory = malloc(sizeof(t_node) * LEN);
	if (!memory)
		return (ft_error("ALLOCAZIONE DELLA MEMORIA DI CODA NON RIUSCITA\n", \
			47));
	queue->memory = memory;
	queue->read = 0;
	queue->write = 0;
	queue->counter = 0;
	if (pthread_mutex_init(&queue->mutex, NULL) != 0)
		return (ft_error("MUTEX SU CODA DI LOGGING NON INIZIALIZZATO\n", 43));
	table->queue = queue;
	if (pthread_create(logger, NULL, &ft_logging, table) != 0)
		return (ft_error("LOGGER NON INIZIALIZZATO\n", 25));
	return (1);
}

static int	ft_init_forks(t_table *table, int number_of_philos)
{
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	if (!forks)
		return (ft_error("ALLOCAZIONE DI FORCHETTE NON RIUSCITA\n", 38));
	while (number_of_philos--)
		if (pthread_mutex_init(forks + number_of_philos, NULL) != 0)
			return (ft_error("MUTEX DI FORCHETTA NON INIZIALIZZATO\n", 37));
	table->forks = forks;
	return (1);
}

static int	ft_init_checker(t_philo *philos, \
	int number_of_philos, pthread_t *checker, t_table *table)
{
	philos += number_of_philos - 1;
	while (number_of_philos--)
	{
		philos->last_meal = 0;
		philos->table = table;
		if (pthread_mutex_init(&philos->mutex, NULL) != 0)
			return (ft_error("MUTEX DI UN FILOSOFO NON INIZIALIZZATO", 39));
		philos--;
	}
	table->start_dinner = ft_time();
	if (pthread_create(checker, NULL, &ft_checking, ++philos) != 0)
		return (ft_error("INIZIALIZZAZIONE DEL CHECKER NON RIUSCITA\n", 30));
	return (1);
}

int	ft_init_forks_checker_and_philos(t_philo **p_philos, \
	t_table *table, pthread_t *checker)
{
	t_dvector	i_n;
	t_philo		*philos;

	i_n = (t_dvector){1, table->number_of_philos};
	if (!ft_init_forks(table, i_n.y))
		return (0);
	philos = malloc(sizeof(t_philo) * i_n.y);
	if (!philos)
		return (ft_error("ALLOCAZIONE DI FILOSOFI NON RIUSCITA\n", 37));
	*p_philos = philos;
	if (!ft_init_checker(philos, i_n.y, checker, table))
		return (0);
	while (i_n.x <= i_n.y)
	{
		philos->id = i_n.x++;
		if (table->finite_meals)
			ft_lock_and_set(&philos->mutex, &philos->meals, table->max_meals);
		if (pthread_create(&philos->thread, NULL, &ft_simposio, philos) != 0)
			return (ft_error("UN FILOSOFO NON INIZIALIZZATO\n", 30));
		philos++;
	}
	return (1);
}
