/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/26 16:29:44 by fcorri           ###   ########.fr       */
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
# define LEFT		(t_vector){-DEF_TR, 0, 0}
# define UP			(t_vector){0, -DEF_TR, 0}
# define RIGHT		(t_vector){DEF_TR, 0, 0}
# define DOWN		(t_vector){0, DEF_TR, 0}
# define DEF_ZOOM	1
# define ZOOM		(t_vector){DEF_ZOOM, DEF_ZOOM, 0}
# define DEF_ANG	30

typedef struct s_vars		t_vars;

typedef struct vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct color
{
	int	x;
	int	y;
	int	z;
}	t_color;

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

typedef struct matrix
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
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
	t_bvector	dim;
	int			**matrix;
	t_bvector	min_max;
	t_bvector	colors;
}	t_map;

typedef struct camera
{
	t_vector	**matrix;
	char		*name;
	int			draw;
	int			(*ft_draw)(t_vars *vars);
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
void	ft_put_pixel(t_image *img, t_bvector v0, t_color color);
int		ft_init_int_matrix(int ***p_matrix, int rows, int columns);
int		ft_init_vector_matrix(t_vector ***p_matrix, int rows, int columns);
t_bvector	ft_calculate_colors(t_vars *vars, int z1, int z2);

int		ft_init_map(char *filename, t_map **p_map);
int		ft_init_camera(t_vars *vars);
int		ft_init_mlx(t_mlx **p_mlx);
int		ft_init_image(t_mlx *mlx, t_image **p_image);

int		ft_set_camera(t_vars *vars, int (*ft_draw)(t_vars *vars), char *name);
int		ft_draw_map_as_isometric_projection(t_vars *vars);
int		ft_draw_map_as_orthogonal_projection(t_vars *vars);
int		ft_test_draw(t_vars *vars);
void	ft_draw_legend(t_vars *vars);

void	ft_put_line(t_image *image, t_vector v0, t_vector v1, t_bvector colors);

void	ft_bvector_swap_decorator(t_bvector value, t_bvector *to_be_checked);
size_t	ft_split_decorator_to_init_line_len(int *fd, t_map *map, char *filename);
t_bvector	ft_split_decorator_to_init_map_matrix_with(char *line, t_map *map);
t_color ft_new_vector_color_decorator(int color);

void	ft_VVV_for_each_point_of(t_vars *vars, t_vector (*op)(t_vector a, t_vector b), t_vector v);
void	ft_VVS_for_each_point_of(t_vars *vars, t_vector (*op)(t_vector a, int k), int k);
void	ft_VVQ_for_each_point_of(t_vars *vars, t_vector (*op)(t_vector point, t_vector axis, double deg), t_vector axis, double deg);

void	ft_translate(t_vars *vars, t_vector vector);
void	ft_zoom_on(t_vars *vars, int value);
void	ft_zoom_off(t_vars *vars, int value);
void	ft_to_center(t_vars *vars);

t_vector	ft_add_vector(t_vector a, t_vector b);
t_vector	ft_opposite(t_vector a);
t_vector	ft_sub_vector(t_vector a, t_vector b);
t_vector	ft_mul_scalar(t_vector a, float k);
t_vector	ft_div_scalar(t_vector a, float k);
t_vector	ft_mul_scalarXY(t_vector a, int k);
t_vector	ft_div_scalarXY(t_vector a, int k);
t_vector	ft_mul_row_col(t_matrix matrix, t_vector vector);

t_quaternion	ft_coniugate(t_quaternion q);
double			ft_magnitude(t_vector a);
t_vector		ft_mul_quaternion(t_vector point, t_vector axis, double deg);
t_quaternion	ft_mul_quat(t_quaternion q1, t_quaternion q2);

void	ft_rot_x_cw(t_vars *vars);
void	ft_rot_y_cw(t_vars *vars);
void	ft_rot_z_cw(t_vars *vars);
void	ft_rot_x_ccw(t_vars *vars);
void	ft_rot_y_ccw(t_vars *vars);
void	ft_rot_z_ccw(t_vars *vars);

#endif
