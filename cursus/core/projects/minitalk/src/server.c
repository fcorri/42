/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:08:31 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/26 20:17:22 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_p.h"

#define LEN_IN_WORDS	8

char	*g_output;

static UL	ft_save_and_print_message(int print, UL word, size_t index,
	void *ucontext)
{
	(void) ucontext;
	*(UL *)(g_output + index - (index & (sizeof(word) - 1))) = word;
	if (print)
	{
		write(1, g_output, index + 1);
		write(1, "\n", 1);
	}
	return (0);
}

static size_t	ft_realloc_message(size_t len)
{
	char	*tmp;
	size_t	dlen;

	dlen = len * 2;
	tmp = ft_malloc_soul(dlen);
	ft_memcpy(tmp, g_output, len);
	free(g_output);
	g_output = tmp;
	return (dlen);
}

static void	ft_handling_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static UL		word;
	static size_t	len;
	static size_t	index;
	static int		iter;

	if (len == 0)
		len = sizeof(word) * LEN_IN_WORDS;
	if (index == len)
		len = ft_realloc_message(len);
	if (sig == SIGUSR2)
		word |= (0x1UL << (8 * index + iter++));
	else
		word &= ~(0x1UL << (8 * index + iter++));
	iter &= 7;
	if (!iter)
	{
		if (!(word & (0xFFUL << (8 * (index & (sizeof(word) - 1))))))
		{
			word = ft_save_and_print_message(1, word, index, ucontext);
			index = 0;
		}
		else if ((++index & (sizeof(word) - 1)) == 0)
			word = ft_save_and_print_message(0, word, index - 1, ucontext);
	}
	kill(info->si_pid, SIGUSR2);
}

static void	ft_handling_siginterrupt(int signum)
{
	ft_printf("\nTerminating due to signal number %d\nBye!\n", signum);
	free(g_output);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	size_t				len;
	struct sigaction	sigusr_action;
	struct sigaction	siginterrupt_action;

	if (argc != 1)
		return (ft_error("Error:\ttoo many arguments\nNormal usage:\tserver\n\
But your was:\t", argc, argv));
	len = sizeof(UL) * LEN_IN_WORDS;
	g_output = ft_malloc_soul(len);
	ft_printf("%d\n", getpid());
	ft_bzero(&sigusr_action, sizeof(sigusr_action));
	sigusr_action.sa_flags = SA_SIGINFO;
	sigusr_action.sa_sigaction = ft_handling_sigusr;
	sigaction(SIGUSR1, &sigusr_action, NULL);
	sigaction(SIGUSR2, &sigusr_action, NULL);
	ft_bzero(&siginterrupt_action, sizeof(siginterrupt_action));
	siginterrupt_action.sa_handler = ft_handling_siginterrupt;
	sigaction(SIGINT, &siginterrupt_action, NULL);
	sigaction(SIGTERM, &siginterrupt_action, NULL);
	while (pause() == -1)
	{
	}
	return (EXIT_FAILURE);
}
