/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_p.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/22 10:38:51 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include <errno.h>
# include <string.h>
# include <fcntl.h>

# include "libft/libft.h"

# define MLX_ERROR 1
# define WIDTH 1000
# define HEIGHT 500

typedef struct s_mlx
{
	void	*obj;
	void	*win;
}	t_mlx;

#endif
