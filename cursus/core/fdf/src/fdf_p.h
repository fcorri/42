/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/06 11:18:33 by fcorri           ###   ########.fr       */
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

# include "libft/libft.h"

# define WIDTH	1000
# define HEIGHT	500
# define TITLE	"fil de fer"

typedef struct mlx
{
	void	*this;
	void	*win;
	t_image	*image;
}	t_mlx;

typedef struct map
{
	int		width;
	int		height;
	t_list	*points;
}	t_map;

typedef struct image
{
	void	*this;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}	t_image;

typedef struct vector
{
	int	x;
	int	y;
	int	z;
}	t_vector;

int		ft_error(char *with_message);
void	*ft_null_error(char *with_message);
t_map	*ft_init_map(char *filename);
t_mlx	*ft_init_mlx(void);
void	ft_init_hooks(t_mlx *mlx);

#endif
