/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 20:11:14 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_P_H
# define FDF_P_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <math.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>

# include "libft/libft.h"

# define WIDTH			1500
# define HEIGHT			1000
# define TITLE			"fil de fer"

# define WHITE			0x00FFFFFF
# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLUE			0x000000FF
# define START_COLOR	0x0000FF84
# define END_COLOR		0x00FF4F00

# define DEF_TR		5
# define LEFT		(t_vector3){-DEF_TR, 0, 0}
# define UP			(t_vector3){0, -DEF_TR, 0}
# define RIGHT		(t_vector3){DEF_TR, 0, 0}
# define DOWN		(t_vector3){0, DEF_TR, 0}
# define DEF_ZOOM	1
# define ZOOM		(t_vector3){DEF_ZOOM, DEF_ZOOM, 0}
# define DEF_ANG	30

typedef struct s_vars		t_vars;

typedef struct vector2
{
	int	x;
	int	y;
}	t_vector2;

typedef struct vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct color
{
	uint8_t	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_color;

typedef struct point
{
	t_vector3	v;
	t_color		color;
}	t_point;

/*
typedef struct dvector
{
	int	mod;
	int	dir;
}	t_dvector;
*/

typedef struct matrix
{
	t_vector3	x;
	t_vector3	y;
	t_vector3	z;
}	t_matrix;

typedef struct quaternion
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_quaternion;

typedef struct mlx
{
	void	*this;
	void	*win;
}	t_mlx;

typedef struct map
{
	t_vector2	dim;
	int			**matrix;
	t_vector2	min_max;
	t_vector2	colors;
}	t_map;

typedef struct camera
{
	t_point	**matrix;
	char	*name;
	int		draw;
	int		(*ft_draw)(t_vars *vars);
}	t_camera;

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
	t_mlx		*mlx;
	t_map		*map;
	t_image		*image;
	t_camera	*camera;
};

int		ft_error(char *callee, char *with_message);
void	ft_swap(int *first, int *second);
int		ft_init_int_matrix(int ***p_matrix, int rows, int columns);
int		ft_init_point_matrix(t_point ***p_matrix, int rows, int columns);

t_color	ft_get_color(t_vars *vars, int s, int e, int step);
t_color	ft_add_color(t_color a, t_color b);

int		ft_init_map(char *filename, t_map **p_map);
int		ft_init_camera(t_vars *vars);
int		ft_init_mlx(t_mlx **p_mlx);
int		ft_init_image(t_mlx *mlx, t_image **p_image);

int		ft_set_camera(t_vars *vars, int (*ft_draw)(t_vars *vars), char *name);
int		ft_draw_map_as_isometric_projection(t_vars *vars);
int		ft_draw_map_as_orthogonal_projection(t_vars *vars);
int		ft_test_draw(t_vars *vars);
void	ft_draw_legend(t_vars *vars);

void	ft_put_line(t_image *image, t_point p0, t_point p1);

void	ft_vector2_swap_decorator(t_vector2 value, t_vector2 *to_be_checked);
size_t	ft_split_decorator_to_init_line_len(int *fd, t_map *map, char *filename);
t_vector2	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map);

void	ft_VVV_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 a, t_vector3 b), t_vector3 v);
void	ft_VVS_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 a, int k), int k);
void	ft_VVQ_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 point, t_vector3 axis, double deg), t_vector3 axis, double deg);

void	ft_translate(t_vars *vars, t_vector3 vector);
void	ft_zoom_on(t_vars *vars, int value);
void	ft_zoom_off(t_vars *vars, int value);
void	ft_to_center(t_vars *vars);

t_vector3	ft_add_vector(t_vector3 a, t_vector3 b);
t_vector3	ft_opposite(t_vector3 a);
t_vector3	ft_sub_vector(t_vector3 a, t_vector3 b);
t_vector3	ft_mul_scalar(t_vector3 a, float k);
t_vector3	ft_div_scalar(t_vector3 a, float k);
t_vector3	ft_mul_scalarXY(t_vector3 a, int k);
t_vector3	ft_div_scalarXY(t_vector3 a, int k);
t_vector3	ft_mul_row_col(t_matrix matrix, t_vector3 vector);

t_quaternion	ft_coniugate(t_quaternion q);
double			ft_magnitude(t_vector3 a);
t_vector3		ft_mul_quaternion(t_vector3 point, t_vector3 axis, double deg);
t_quaternion	ft_mul_quat(t_quaternion q1, t_quaternion q2);

void	ft_rot_x_cw(t_vars *vars);
void	ft_rot_y_cw(t_vars *vars);
void	ft_rot_z_cw(t_vars *vars);
void	ft_rot_x_ccw(t_vars *vars);
void	ft_rot_y_ccw(t_vars *vars);
void	ft_rot_z_ccw(t_vars *vars);

#endif
