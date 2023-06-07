/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 22:10:26 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/06 11:24:21 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

t_map	*ft_init_map(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_null_error(strerror(errno)));
	map = malloc(sizeof(*map));
	if (!map)
		return(ft_null_error(strerror(errno)));
	ft_init_points(fd, map);
	return (map);
}
