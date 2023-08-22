/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:03:46 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/21 19:37:09 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

static void	ft_print(t_int_dlist *node)
{
	int	index = 1;
	if (!node)
		ft_error("FT_PRINT", "PARAMETER NODE is NULL");
	while (node)
	{
		ft_printf("%d:\t%d\n", index++, node->content);
		node = node->next;
	}
	ft_printf("\n");
}

int main(void)
{
	int	content = 0;
	t_int_dlist	*head = ft_int_dlst_new(content++);
	ft_int_dlst_add_back(&head, ft_int_dlst_new(content++));
	ft_int_dlst_add_front(&head, ft_int_dlst_new(content++));
	ft_print(head);
	printf("%zu\n", ft_int_dlst_size(head));
	return (0);
}

