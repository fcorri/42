/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsafe_listsadd_back.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:43:24 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/06 09:56:10 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_unsafe_lstadd_back(t_list *node, t_list *next)
{
	node->next = next;
	return (node->next);
}
