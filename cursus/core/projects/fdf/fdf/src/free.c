/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:45:35 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/27 14:46:06 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

static void	ft_free_map_and_matrices(t_vars *vars)
{
	int		index;
	void	*matrix;

	index = vars->map->dim.x;
	matrix = vars->map->matrix;
	if (matrix)
	{
		while (index)
			free(((int **)matrix)[--index]);
		free(matrix);
	}
	if (vars->camera)
	{
		index = vars->map->dim.x;
		matrix = vars->camera->matrix;
		if (matrix)
		{
			while (index)
				free(((t_v3 **)matrix)[--index]);
			free(matrix);
		}
		free(vars->camera);
	}
	free(vars->map);
}

int	ft_free_and_return(t_vars *vars, int value)
{
	if (vars->image)
	{
		mlx_destroy_image(vars->mlx->this, vars->image->this);
		free(vars->image);
	}
	if (vars->mlx)
	{
		if (vars->mlx->win)
			mlx_destroy_window(vars->mlx->this, vars->mlx->win);
		mlx_destroy_display(vars->mlx->this);
		free(vars->mlx->this);
		free(vars->mlx);
	}
	if (vars->map)
		ft_free_map_and_matrices(vars);
	return (value);
}
