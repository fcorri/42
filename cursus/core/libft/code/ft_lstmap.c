/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:17:54 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/08 17:17:18 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*last;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	last = head;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->next->content));
		if (!tmp)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		last->next = tmp;
		last = last->next;
		lst = lst->next;
	}
	return (head);
}
