/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:40:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/31 19:22:51 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_p.h"

int	main(int argc, char **argv)
{
	t_philo		*philos;
	t_table		table;
	int			number_of_philos;
	pthread_t	logger;
	pthread_t	checker;

	if (--argc < 4 || argc > 5)
		return (ft_error("INVALID NUMBERS OF ARGUMENTS\n", 29));
	if (pthread_mutex_init(&table.mutex, NULL) != 0)
		return (ft_error("MUTEX ALIVE NON INIZIALIZZATO\n", 30));
	philos = NULL;
	memset(&table, 0, sizeof(table));
	if (!(ft_init_table(argc, ++argv, &table)
			&& ft_init_queue_and_logger(&table, &logger)
			&& ft_init_forks_checker_and_philos(&philos, &table, &checker)))
		return (ft_free_and_return(&table, philos, 1));
	number_of_philos = table.number_of_philos - 1;
	while (number_of_philos >= 0)
		pthread_join((philos + number_of_philos--)->thread, NULL);
	ft_lock_and_set(&table.mutex, &table.are_alive, 0);
	pthread_join(logger, NULL);
	pthread_join(checker, NULL);
	return (ft_free_and_return(&table, philos, 0));
}
