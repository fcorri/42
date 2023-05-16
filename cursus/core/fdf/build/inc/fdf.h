/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:46:43 by fcorri            #+#    #+#             */
/*   Updated: 2023/05/15 11:52:05 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "libft/libft.h"
# include "printf/ft_printf.h"

# define MLX_ERROR 1
# define WIDTH 1000
# define HEIGHT 500


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

#endif

