/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/27 17:33:24 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_P_H
# define PUSH_SWAP_P_H

# include "libft/libft.h"
# include <limits.h>

# define NODE	t_int_dlist
# define VECTOR	t_bvector
# define STACK	t_stack
# define VARS	t_vars

typedef struct bvector
{
	int	x;
	int	y;
}	t_bvector;

typedef struct stack
{
	NODE	*head;
	int		n;
	VECTOR	min_max;
}	t_stack;

typedef struct vars
{
	STACK	*a;
	STACK	*b;
}	t_vars;

void	ft_exit(void);
int		ft_free_and_return(VARS *vars, int output);
int		ft_min(int first, int second);
int		ft_max(int first, int second);

void	ft_init(int argc, char **argv, VARS *vars);
void	ft_order(VARS *vars, int n);

STACK	*ft_new_stack(void);
int		ft_is_ordered(STACK *stack);
void	ft_push(STACK *stack, NODE *node);
NODE	*ft_pop(STACK *stack);
int		ft_find_index_min(STACK *stack);

void	ft_sa(VARS *vars, int print);
void	ft_sb(VARS *vars, int print);
void	ft_pa(VARS *vars);
void	ft_pb(VARS *vars);
void	ft_ra(VARS *vars, int print);
void	ft_rb(VARS *vars, int print);
void	ft_rr(VARS *vars);
void	ft_rra(VARS *vars, int print);
void	ft_rrb(VARS *vars, int print);
void	ft_rrr(VARS *vars);

void	ft_ss(VARS *vars);

void	ft_push_min_ops(VARS *vars);
VECTOR	ft_update_r_a_b_best_min_max(STACK *a, int input,
			VECTOR r_a_b, VECTOR r_a_b_best);

void	ft_print(VARS *vars);
void	ft_print_queue(VARS *vars);
void	ft_check(VARS *vars);

#endif
