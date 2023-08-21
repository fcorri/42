/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:19:52 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/08 15:15:52 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_lstdelone(t_int_list *lst, void (*del)(int ))
{
	t_int_list	*tmp;

	if (!lst || !del)
		return ;
	tmp = lst->next;
	del(lst->content);
	free(lst);
	lst = tmp;
}
