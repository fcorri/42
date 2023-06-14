/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/14 22:00:34 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_P_H
# define FDF_P_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# include "libft/libft.h"

# define WIDTH	1000
# define HEIGHT	500
# define TITLE	"fil de fer"

typedef struct map
{
	int		rows;
	int		columns;
	int		**matrix;
}	t_map;

typedef struct image
{
	void	*this;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_image;

typedef struct mlx
{
	void	*this;
	void	*win;
	t_map	*map;
	t_image	*image;
	void	(*ft_draw)(struct mlx *mlx);
}	t_mlx;

typedef struct vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

int		ft_error(char *callee, char *with_message);
void	*ft_null_error(char *callee, char *with_message);

t_map	*ft_init_map(char *filename);

int		ft_init_image(t_mlx *mlx);
void	ft_draw_map_as_vertical_projection(t_mlx *mlx);

t_mlx	*ft_init_mlx(t_map *map);

size_t	ft_split_decorator_init_line_len(int fd, t_map *map);
void	ft_split_decorator_init_map_matrix(char *line, t_map *map);

#endif
