/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/06/01 19:46:41 by fcorri           ###   ########.fr       */
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

typedef struct s_mlx
{
	void	*instance;
	void	*window;
}	t_mlx;

typedef struct s_map
{
	int		x;
	int		y;
	t_list	*points;
}	t_map;

int		ft_error(char *with_message);
void	*ft_null_error(char *with_message);
t_map	*ft_check_args_and_init_map(int argc, char *filename);
t_map	*ft_init_map(char *filename);
t_mlx	*ft_init_mlx(void);
void	ft_init_hooks(t_mlx *mlx);

#endif
