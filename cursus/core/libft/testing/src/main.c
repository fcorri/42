/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:17:01 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/14 17:59:13 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int main(void)
{
	char	*tmp = "ciao  come  stai  ?";
	char	**output = ft_split(tmp, ' ');
	int		i = 0;
	tmp = output[i++];
	while (tmp)
	{
		ft_printf("%d:\t%s\n", i, tmp);
		free(tmp);
		tmp = output[i++];
	}
	free(output);
	return (0);
}
