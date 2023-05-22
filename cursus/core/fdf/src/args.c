/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:58:36 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/22 22:03:30 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

int	ft_check_args(int argc, char **argv)
{
	int errsv;
	int fd;

	errsv = 0;
	if (argc == 1)
		errsv = 22;
	else if (argc != 2)
		errsv = 7;
	if (errsv)
		return (ft_error(strerror(errsv)));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(strerror(errno)));
	return (fd);
}
