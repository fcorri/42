/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:38:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/22 21:29:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

static void	ft_free_stack(STACK *stack)
{
	NODE	*head;
	NODE	*tmp;
	int		n;

	head = stack->head;
	n = stack->n;
	while (n--)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_free_and_return(t_vars *vars, int output)
{
	STACK	*stack;

	stack = vars->a;
	if (stack)
		ft_free_stack(stack);
	free(stack);
	stack = vars->b;
	if (stack)
		ft_free_stack(stack);
	free(stack);
	if (output)
		ft_exit();
	return (output);
}
