/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:54 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/11 16:39:03 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int_list	*ft_int_lstmap(t_int_list *lst, int (*f)(int ), void (*del)(int ))
{
	t_int_list	*head;
	t_int_list	*last;
	t_int_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_int_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	last = head;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_int_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_int_lstclear(&head, del);
			return (NULL);
		}
		last->next = tmp;
		last = last->next;
		lst = lst->next;
	}
	return (head);
}
