/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:24:13 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/22 21:06:34 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_p.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	t_vars	vars;
	char	input[3];

	if (argc == 1)
		ft_exit();
	ft_init(argc, argv, &vars);
	ft_printf("\n\nDIGITA UNA DELLE SEGUENTI OPERAZIONI PER MODIFICARE LO STACK:\nsa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr\n\nDOVRESTI SAPERE COME SI COMPORTANO! LA PILA E' LA SEGUENTE\n");
	ft_print(&vars);
	scanf("%[^\n]", input);
	getchar();
	while (ft_strlen(input))
	{
		if (!strcmp(input, "ra"))
			ft_ra(&vars);
		else if (!strcmp(input, "rb"))
			ft_rb(&vars);
		else if (!strcmp(input, "rr"))
			ft_rr(&vars);
		else if (!strcmp(input, "sa"))
			ft_sa(&vars);
		else if (!strcmp(input, "sb"))
			ft_sb(&vars);
		else if (!strcmp(input, "ss"))
			ft_ss(&vars);
		else if (!strcmp(input, "pa"))
			ft_pa(&vars);
		else if (!strcmp(input, "pb"))
			ft_pb(&vars);
		else if (!strcmp(input, "rra"))
			ft_rra(&vars);
		else if (!strcmp(input, "rrb"))
			ft_rrb(&vars);
		else if (!strcmp(input, "rrr"))
			ft_rrr(&vars);
		else
			ft_printf("INSERISCI UN'OPERAZIONE VALIDA! NON PERDERE TEMPO\n");
		ft_print(&vars);
		input[0] = '\0';
		scanf("%[^\n]", input);
		getchar();
	}
	return (ft_free_and_return(&vars, 0));
}
