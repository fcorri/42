/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/03 18:18:29 by fcorri           ###   ########.fr       */
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

# define WHITE			0x00FFFFFF
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLUE			0x000000FF
# define START_COLOR	0x0000FF84
# define END_COLOR		0x00FF4F00

typedef struct s_vars		t_vars;

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

typedef struct bvector
{
	int	x;
	int	y;
}	t_bvector;

typedef struct mlx
{
	void	*this;
	void	*win;
}	t_mlx;

typedef struct map
{
	t_bvector	dim;
	int			**matrix;
	int			**points;
	t_bvector	colors;
	t_bvector	min_max_value;
	char		*name;
	int			draw;
	int			(*ft_draw)(t_vars *vars);
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

int		ft_error(char *callee, char *with_message);
void	ft_swap(int *first, int *second);

int		ft_init_map(char *filename, t_map **p_map);
int		ft_init_mlx(t_mlx **p_mlx);
int		ft_init_image(t_mlx *mlx, t_image **p_image);

int		ft_set_map(t_vars *vars, int (*ft_draw)(t_vars *vars));
int		ft_draw_map_as_isometric_projection(t_vars *vars);
int		ft_draw_map_as_vertical_projection(t_vars *vars);
int		ft_draw_test(t_vars *vars);
int		ft_draw_null(t_vars *vars);

void	ft_put_line(t_image *image, t_vector v0, t_vector v1, t_bvector colors);
void	ft_put_pixel(t_image *img, t_bvector v0, t_vector color);

void	ft_bvector_swap_decorator(t_bvector value, t_bvector *to_be_checked);
size_t	ft_split_decorator_to_init_line_len(int *fd, t_map *map, char *filename);
t_bvector	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map);
t_vector	ft_new_vector_color_decorator(int color);

t_vector	ft_new_vector(long x, long y, long z);
t_vector	ft_add_vector(t_vector a, t_vector b);
t_vector	ft_mul_scalar(t_vector a, double k);

#endif
