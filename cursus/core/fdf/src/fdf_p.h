/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/22 22:06:08 by fcorri           ###   ########.fr       */
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
	t_list	points;
}	t_map;

int		ft_error(char *with_message);
int		ft_check_args(int argc, char **argv);
t_map	*ft_init_map(int with_fd);
t_mlx	*ft_init_mlx(void);
void	ft_init_hooks(t_mlx *mlx);


#endif
