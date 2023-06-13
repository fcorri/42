/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:15:39 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/13 18:05:15 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ft_calloc.c	V
//ft_itoa.c		V
//ft_split.c	
//ft_strdup.c	
//ft_strmapi.c	
//ft_strndup.c	

#include <limits.h>
#include <stdio.h>
#include "libft/libft.h"

#define LEN	7

int main(void)
{
//	int		input[LEN] = {INT_MIN, -10, -1, 0, 1, 10, INT_MAX};
	char	*input = "1. Ciao come stai ? 2. Bene, te?";
	char	**output;
	char	*line;
	int		len;
	int		i = 0;

	output = ft_new_split(input, '\0');
	line = output[i++];
	ft_printf("ITER\tINPUT\tLEN\n");
	while(line)
	{
		len = ft_strlen(line);
		ft_printf("%d\t%s\t%d\n", i, line, len);
		free(line);
		line = output[i++];
	}
	free(output);
	return (0);
}
