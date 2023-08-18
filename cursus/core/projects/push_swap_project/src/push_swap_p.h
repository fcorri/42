/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/18 15:43:50 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_P_H
# define PUSH_SWAP_P_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct stack
{
	int	*this;
	int	*head;
	int	n;
	int	max;
}	t_stack;

typedef struct vars
{
	t_stack	*a;
	t_stack	*b;
}	t_vars;

void	ft_error(void);
int		ft_free_and_return(t_vars *vars, int output);
int		*ft_prev(t_stack *stack);
int		*ft_next(t_stack *stack);

void	ft_init(int argc, char **argv, t_vars *vars);

void	ft_order_stack(t_vars *vars);

void	ft_sa(t_vars *vars);
void	ft_sb(t_vars *vars);
void	ft_ss(t_vars *vars);
void	ft_pa(t_vars *vars);
void	ft_pb(t_vars *vars);
void	ft_ra(t_vars *vars);
void	ft_rb(t_vars *vars);
void	ft_rr(t_vars *vars);
void	ft_rra(t_vars *vars);
void	ft_rrb(t_vars *vars);
void	ft_rrr(t_vars *vars);

void	ft_test_stack(t_vars *vars, void (*ft_to_test)(t_vars *vars));

void	ft_print(t_vars *vars);

#endif
