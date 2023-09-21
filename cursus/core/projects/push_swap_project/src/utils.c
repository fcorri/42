/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:38:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/21 15:26:50 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_min(int first, int second)
{
	if (first < second)
		return (first);
	return (second);
}

int	ft_max(int first, int second)
{
	if (first < second)
		return (second);
	return (first);
}
