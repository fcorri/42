/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:47:40 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/22 10:55:32 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static int	ft_error(char *with_message)
{
	ft_printf("ERROR: %s\n", with_message);
	return (1);
}

static int	ft_init_map(int with_fd)
{
	char	*line;

	line = get_next_line(with_fd);
	while (line)
	{
		ft_split();
		line = get_next_line(with_fd);
	}
	return (0);
}

static int	ft_check_args(int argc, char **argv)
{
	int	errsv;
	int	fd;

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
	return (ft_init_map(fd));
}

int main(int argc, char **argv)
{
//	t_mlx	mlx;

	// check args
	if (ft_check_args(argc, argv))
		exit(EXIT_FAILURE);
	// check map
	// init mlx
	// set mlx hooks
	// loop
	return (0);
}
