/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:42:30 by fcorri            #+#    #+#             */
/*   Updated: 2023/07/31 14:34:20 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_p.h"

void    ft_print_map_matrix(t_vars *vars)
{
        int     row = 0;
        int     col = 0;

        while (col < vars->map->dim.y)
                ft_printf("\t%d", col++);
        ft_printf("\n");
        while (row < vars->map->dim.x)
        {
                col = 0;
                ft_printf("%d", row);
                while (col++ < vars->map->dim.y)
                        ft_printf("\t%d", (int)vars->map->matrix[row][col]);
                ft_printf("\n");
                row++;
        }
        ft_printf("\n\n");
}

void    ft_print_camera_matrix(t_vars *vars)
{
        int     row = 0;
        int     col = 0;

        while (col < vars->map->dim.y)
                ft_printf("\t\t%d", col++);
        ft_printf("\n");
        while (row < vars->map->dim.x)
        {
                col = 0;
                ft_printf("%d", row);
                while (col++ < vars->map->dim.y)
                        ft_printf("\t\t%x", vars->camera->matrix[row][col].color);
                ft_printf("\n");
                row++;
        }
        ft_printf("\n\n");
}
