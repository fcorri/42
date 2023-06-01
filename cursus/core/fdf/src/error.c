/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:05:47 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/23 19:36:47 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_error(char *with_message)
{
	ft_printf("ERROR: %s\n", with_message);
	return (1);
}

void	*ft_null_error(char *with_message)
{
	ft_error(with_message);
	return (NULL);
}
