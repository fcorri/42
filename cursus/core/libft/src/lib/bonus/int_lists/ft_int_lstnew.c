/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:03 by fcorri            #+#    #+#             */
/*   Updated: 2022/11/08 15:18:04 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int_list	*ft_int_lstnew(int content)
{
	t_int_list	*output;

	output = malloc(sizeof(t_int_list));
	if (!output)
		return (NULL);
	output->content = content;
	output->next = NULL;
	return (output);
}
