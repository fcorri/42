/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/15 11:32:36 by fcorri           ###   ########.fr       */
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

# define WIDTH			1000
# define HEIGHT			500
# define TITLE			"fil de fer"
# define START_COLOR	0x0000FF84
# define END_COLOR		0x00FF4F00

typedef struct map
{
	int		rows;
	int		columns;
	int		**matrix;
	int		start_color;
	int		end_color;
	int		max_z;
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

/*typedef struct vars
{
	void	*mlx;
	void	*map;
	void	*image;
}*/

typedef struct vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct point
{
	int	x;
	int	y;
}	t_point;

int		ft_error(char *callee, char *with_message);
void	*ft_null_error(char *callee, char *with_message);

t_map	*ft_init_map(char *filename);

int		ft_init_image(t_mlx *mlx);

void	ft_draw_map_as_isometric_projection(t_mlx *mlx);
void	ft_draw_map_as_vertical_projection(t_mlx *mlx);

void	ft_put_line(t_image image, t_point p0, t_point p1, int color);

t_mlx	*ft_init_mlx(t_map *map);

size_t	ft_split_decorator_init_line_len(int fd, t_map *map);
int		ft_split_decorator_init_map_matrix(char *line, t_map *map);
int		ft_put_pixel_decorator(t_image image, t_vector p, int color, int main);

void	ft_swap(int *first, int *second);
void	ft_put_pixel(t_image img, int x, int y, int color);

#endif
