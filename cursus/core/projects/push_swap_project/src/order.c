/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:55:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/04 19:26:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"

#define LIMIT	2
#define	FACT_4	24

/*

per ogni chiamata di funzione ricorsiva, salvati callables, prova a eseguire in ordine le operazioni permesse e se si ha successo, richiama la funzione ricorsiva, altrimenti prova un'altra configurazione di callables.

le mosse DEVONO essere eseguite solo in alcuni casi, tipo:
	- se si hanno due elementi in ordine si puo' eseguire 2ra

*/

static void	ft_init_vars(int arr[4][4])
{
	int	iter;
	int	index;

	iter = -1;
	while (iter++ < 2)
	{
		index = -1;
		while (index++ < 3)
		{
			arr[iter << 1][index] = index;
			arr[(iter << 1) + 1][index] = 0;
		}
	}
}

static void	ft_perm(int arr[4][4])
{
	int	largest;

	largest = ft_get_largest(arr);
	(void) arr;
}

int	ft_order(VARS *vars, int prev_index, int call)
{
	int			perm;
	int			index;
	int			arr[4][4];
	static int	(**ops)(t_vars *vars, int inv);

	if (ft_is_ordered(vars->a) && ft_is_empty(vars->b))
		return (1);
	if (call == LIMIT)
	{
		vars->callables &= ~(0b1 << prev_index);
		vars->inv[prev_index](vars, 1);
		return (0);
	}
	perm = FACT_4;
	if (!ops)
		ops = vars->ops;
	ft_init_vars(arr);
	while (perm--)
	{
		index = -1;
		while (index++ < 4)
			if (((vars->callables >> index) & 0b1) && ops[index](vars, 0) && ft_order(vars, index, call + 1))
				return (1);
		ft_perm(arr);
	}
	return (0);
}
