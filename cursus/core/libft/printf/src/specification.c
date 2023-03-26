/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specification.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:36:05 by fcorri            #+#    #+#             */
/*   Updated: 2023/03/22 19:50:40 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_reset_specification(void)
{
	g_specification->flags = 0;
	g_specification->width = 0;
	g_specification->precision = -1;
}
