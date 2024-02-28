/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:09:48 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/15 20:09:56 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_p.h"

int	ft_error(char *with_message, int argc, char **argv)
{
	int	index;

	index = 0;
	ft_printf("%s", with_message);
	while (index < argc - 1)
		ft_printf("%s ", argv[index++]);
	if (argv)
		ft_printf("%s\n", argv[index]);
	return (EXIT_FAILURE);
}
