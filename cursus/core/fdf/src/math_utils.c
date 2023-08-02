/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:04:32 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/02 17:04:48 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

int	ft_max(int first, int second)
{
	if (first > second)
		return (first);
	return (second);
}
