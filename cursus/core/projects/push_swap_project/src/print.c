/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:17:08 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/22 17:29:07 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

void	ft_print_queue(VARS *vars)
{
	NODE	*node;

	node = vars->output->head;
	while (node)
	{
		ft_printf("%s\n", vars->names[node->content]);
		node = node->next;
	}
	write(1, "", 1);
}
