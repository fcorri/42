/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/02 14:49:32 by fcorri           ###   ########.fr       */
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
# include <float.h>

# include "libft/libft.h"

# define WIDTH			1920
# define HEIGHT			1080
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
# define DEF_ZOOM	2
# define ZOOM		(t_vector3){DEF_ZOOM, DEF_ZOOM, 0}
# define DEF_ANG	10

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

typedef struct quaternion
{
	float	a;
	float	b;
	float	c;
	float	d;
}	t_quaternion;

typedef struct point
{
	t_vector3	v;
	int			color;
}	t_point;

typedef struct colors
{
	t_vector3	start;
	t_vector3	step;
}	t_colors;


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
	t_point		**matrix;
	t_vector2	zoom;
	char		*name;
	void		(*ft_view)(t_vars *vars);
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
void	*ft_null_error(char *callee, char *with_message);
void	ft_swap(int *first, int *second);
int		ft_abs(int number);
int		ft_max(int first, int second);
void    ft_print_map_matrix(t_vars *vars);
void    ft_print_camera_matrix(t_vars *vars);

int		ft_alloc_map_matrix(int ***p_matrix, t_vector2 dim);

int		ft_init_fdf(t_vars *vars, char *filename);

int			ft_to_int(t_vector3 color);
t_vector3	ft_to_vector(int color);
void		ft_add_colors(t_colors *colors);
t_colors	ft_init_line_colors_with(int s, int e, float n);
int			ft_interpolate_colors(int s, int e, float i, float n);

int		ft_key_down(int keycode, t_vars *vars);

int		ft_free_and_return(t_vars *vars, int value);

int		ft_render(t_vars *vars);

int		ft_init_camera(t_vars *vars);
void	ft_set_camera(t_vars *vars, void (*ft_camera)(t_vars *vars), char *name);
int		ft_restore_camera(t_vars *vars);
void	ft_isometric(t_vars *vars);
void	ft_orthogonal(t_vars *vars);
void	ft_perspective(t_vars *vars);

void	ft_put_line(t_image *image, t_point p0, t_point p1);

void	ft_vector2_swap_decorator(t_vector2 value, t_vector2 *to_be_checked);
int		ft_split_decorator_to_init_map_cols(int fd, t_map *map, char *filename);
t_vector2	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map);

void	ft_VVV_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 a, t_vector3 b), t_vector3 v);
void	ft_VVS_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 a, int k), int k);
void	ft_VVQ_for_each_point_of(t_vars *vars, t_vector3 (*op)(t_vector3 p, t_vector3 axis, float deg), t_vector3 axis, float deg);

void	ft_translate(t_vars *vars, t_vector3 vector);
void	ft_to_center(t_vars *vars);
void	ft_to_origin(t_vars *vars);

void	ft_zoom_on(t_vars *vars, int value);
void	ft_zoom_off(t_vars *vars, int value);

t_vector3	ft_new_vector(double x, double y, double z);
t_vector3	ft_add_vector(t_vector3 a, t_vector3 b);
t_vector3	ft_opposite(t_vector3 a);
t_vector3	ft_mul_scalar(t_vector3 a, float k);
t_vector3	ft_div_scalar(t_vector3 a, float k);

t_vector3	ft_mul_quaternion(t_vector3 point, t_vector3 axis, float deg);

void	ft_rot(t_vars *vars, t_vector3 axis, float rad);
void	ft_rot_x_cw(t_vars *vars);
void	ft_rot_y_cw(t_vars *vars);
void	ft_rot_z_cw(t_vars *vars);
void	ft_rot_x_ccw(t_vars *vars);
void	ft_rot_y_ccw(t_vars *vars);
void	ft_rot_z_ccw(t_vars *vars);

#endif
