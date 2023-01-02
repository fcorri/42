/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:29:04 by fcorri            #+#    #+#             */
/*   Updated: 2022/10/23 01:33:26 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free_and_return(t_list *lst, int ok)
{
	char	**output;
	size_t	index;
	t_list	*tmp;

	if (ok)
		output = malloc(sizeof(char *) * ((size_t)lst->content + 1));
	index = 0;
	tmp = lst->next;
	free(lst);
	lst = tmp;
	while (lst)
	{
		if (ok)
			output[index++] = lst->content;
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	if (!ok)
		return (NULL);
	output[index] = NULL;
	return (output);
}

static int	ft_lstadd_back_split(t_list **tail, t_list *node)
{
	if (!node)
		return (0);
	(**tail).next = node;
	*tail = (**tail).next;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	t_list	*head;
	t_list	*tail;
	char	*str;
	size_t	index;
	size_t	len;

	if (!s)
		return (NULL);
	head = ft_lstnew(NULL);
	tail = head;
	index = 0;
	while (s[index])
	{
		str = ft_strchr(s + index, c);
		if (str)
			len = str - (s + index);
		else
			len = ft_strlen(s + index);
		str = malloc(len + 1);
		if(!str)
			return (ft_free_and_return(head, 0));
		ft_strlcpy(str, s + index, len + 1);
		head->content = (int *)((size_t) head->content + 1);
		if (!ft_lstadd_back_split(&tail, ft_lstnew(str)))
			return (ft_free_and_return(head, 0));
		index += len + 1;
	}
	return (ft_free_and_return(head, 1));
}
