/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/17 19:19:40 by fcorri           ###   ########.fr       */
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

typedef struct s_vars	t_vars;

typedef struct mlx
{
	void	*this;
	void	*win;
}	t_mlx;

typedef struct map
{
	int		rows;
	int		columns;
	int		**matrix;
	int		start_color;
	int		end_color;
	int		max_z;
	void	(*ft_draw)(t_vars *vars);
}	t_map;

typedef struct image
{
	void	*this;
	char	*addr;
	int		bpp;
	int		ll;
	int		end;
}	t_image;

struct s_vars
{
	t_mlx	*mlx;
	t_map	*map;
	t_image	*image;
};

typedef struct vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

typedef struct dvector
{
	int	mod;
	int	dir;
}	t_dvector;

typedef struct point
{
	int	x;
	int	y;
}	t_point;

int		ft_error(char *callee, char *with_message);
void	*ft_null_error(char *callee, char *with_message);

t_map	*ft_init_map(char *filename);

t_image	*ft_init_image(t_mlx *mlx);

void	ft_draw_map_as_isometric_projection(t_vars *vars);
void	ft_draw_map_as_vertical_projection(t_vars *vars);

void	ft_put_line(t_image *image, t_point p0, t_point p1, int color);

t_mlx	*ft_init_mlx(void);

size_t	ft_split_decorator_to_init_line_len(int fd, t_map *map);
int		ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map);
int		ft_put_pixel_decorator(t_image *image, t_point p, int color, int main);

void	ft_swap(int *first, int *second);
void	ft_put_pixel(t_image img, int x, int y, int color);

#endif
