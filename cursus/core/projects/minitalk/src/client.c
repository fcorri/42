/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:21:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/26 20:15:48 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_p.h"

#define TIMEOUT	1000

static int	ft_atoi_decorator(char *input)
{
	char	c;
	char	*tmp;

	tmp = input;
	c = *tmp++;
	while (c && ft_isdigit(c))
		c = *tmp++;
	if (!c)
		return (ft_atoi(input));
	else
		return (0);
}

static pid_t	ft_init_server_id(int argc, char **argv)
{
	pid_t	server_id;

	if (argc != 3)
		return (ft_error("Error:\texpected 2 arguments\nNormal usage:\t\
client [SERVER_PID] [MESSAGE]\nBut your was:\t", argc, argv));
	server_id = ft_atoi_decorator(argv[1]);
	if (server_id < 1)
		return (ft_error("Error:\tinvalid server pid\nYour was:\t", 1, argv + 1));
	if (kill(server_id, 0))
	{
		if (errno == EPERM)
			return (ft_error("Error:\tyou don't have the right permissions to \
send signals to the specified process\nYour server pid was:\t", 1, argv + 1));
		else
			return (ft_error("Error:\tserver doesn't exist\nYour server pid \
was:\t", 1, argv + 1));
	}
	return (server_id);
}

static void	ft_handler(int signum)
{
	(void) signum;
}

static int	ft_send_message(pid_t server_id, char *message)
{
	char	character;
	int		iter;

	character = *message++;
	while (character)
	{
		iter = 8;
		while (iter--)
		{
			if (kill(server_id, SIGUSR1 + ((character & 0x1) << 1)))
				return (ft_error("Error:\tserver no more exists\n", 0, NULL));
			if (!usleep(TIMEOUT))
				return (ft_error("Error:\tserver too slow\n", 0, NULL));
			character >>= 1;
		}
		character = *message++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				server_id;
	struct sigaction	sigusr_action;
	int					iter;

	server_id = ft_init_server_id(argc, argv);
	if (server_id == 1)
		exit(EXIT_FAILURE);
	ft_bzero(&sigusr_action, sizeof(sigusr_action));
	sigusr_action.sa_handler = ft_handler;
	sigaction(SIGUSR2, &sigusr_action, NULL);
	if (ft_send_message(server_id, argv[2]))
		exit(EXIT_FAILURE);
	iter = 8;
	while (iter--)
	{
		if (kill(server_id, SIGUSR1))
			return (ft_error("Error:\tserver no more exists\n", 0, NULL));
		if (!usleep(TIMEOUT))
			return (ft_error("Error:\tserver too slow\n", 0, NULL));
	}
	return (0);
}
