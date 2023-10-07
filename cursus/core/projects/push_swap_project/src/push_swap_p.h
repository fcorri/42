/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/10/07 17:24:28 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_P_H
# define PUSH_SWAP_P_H

# include "libft/libft.h"
# include <limits.h>

typedef struct bvector
{
	int	x;
	int	y;
}	t_bvector;

typedef struct stack
{
	t_int_dlist	*head;
	int			n;
	t_bvector	min_max;
}	t_stack;

typedef struct vars
{
	t_stack	*a;
	t_stack	*b;
}	t_vars;

void		ft_exit(int error);
int			ft_free_and_exit(t_vars *vars, int exit);
int			ft_min(int first, int second);
int			ft_max(int first, int second);

int			ft_init(int argc, char **argv, t_vars *vars);
void		ft_order(t_vars *vars, int n);

int			ft_isdigit_decorator_ps(char *param);
t_int_dlist	*ft_atol_decorator_ps(t_vars *vars, t_stack *a, char *input);
void		ft_split_decorator_ps(char **argv, t_vars *vars, t_stack *a);

t_stack		*ft_new_stack(void);
int			ft_is_ordered(t_stack *stack);
void		ft_push(t_stack *stack, t_int_dlist *node);
t_int_dlist	*ft_pop(t_stack *stack);
int			ft_find_index_min(t_stack *stack);

void		ft_sa(t_vars *vars, int print);
void		ft_sb(t_vars *vars, int print);
void		ft_pa(t_vars *vars);
void		ft_pb(t_vars *vars);
void		ft_ra(t_vars *vars, int print);
void		ft_rb(t_vars *vars, int print);
void		ft_rr(t_vars *vars);
void		ft_rra(t_vars *vars, int print);
void		ft_rrb(t_vars *vars, int print);
void		ft_rrr(t_vars *vars);

void		ft_ss(t_vars *vars);

void		ft_push_min_ops(t_vars *vars);
t_bvector	ft_update_r_a_b_best_min_max(t_stack *a, int input,
				t_bvector r_a_b, t_bvector r_a_b_best);

void		ft_print(t_vars *vars);
void		ft_print_queue(t_vars *vars);
void		ft_check(t_vars *vars);

#endif
