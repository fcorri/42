/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/22 20:47:46 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_P_H
# define PUSH_SWAP_P_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define NODE	t_int_dlist	
# define STACK	t_stack
# define VARS	t_vars

typedef struct stack
{
	t_int_dlist	*head;
	int			n;
}	t_stack;

typedef struct vars
{
	t_stack	*a;
	t_stack	*b;
}	t_vars;

t_stack	*ft_new_stack_with_head(t_int_dlist *head, int n);
t_stack	*ft_new_stack(void);
int		ft_is_empty(t_stack *stack);
t_int_dlist	*ft_pop(t_stack *stack);
void	ft_push(t_stack *stack, t_int_dlist *node);

void	ft_exit(void);
int		ft_free_and_return(t_vars *vars, int output);

void	ft_init(int argc, char **argv, t_vars *vars);

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

void	ft_print(t_vars *vars);

#endif
