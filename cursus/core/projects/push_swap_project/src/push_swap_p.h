/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/08/30 13:32:53 by fcorri           ###   ########.fr       */
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
	NODE	*head;
	int		n;
}	t_stack;

typedef struct vars
{
	STACK	*a;
	STACK	*b;
	int		callables;
	char	*(*ops[8])(struct vars *vars);
}	t_vars;

void	ft_exit(void);
int		ft_free_and_return(VARS *vars, int output);

void	ft_init(int argc, char **argv, VARS *vars);
void	ft_order(VARS *vars);

STACK	*ft_new_stack(void);
int		ft_is_empty(STACK *stack);
int		ft_is_ordered(STACK *stack);
void	ft_push(STACK *stack, NODE *node);
NODE	*ft_pop(STACK *stack);

char	*ft_sa(VARS *vars);
char	*ft_sb(VARS *vars);
char	*ft_pa(VARS *vars);
char	*ft_pb(VARS *vars);
char	*ft_ra(VARS *vars);
char	*ft_rb(VARS *vars);
char	*ft_rra(VARS *vars);
char	*ft_rrb(VARS *vars);

char	*ft_ss(VARS *vars);
char	*ft_rr(VARS *vars);
char	*ft_rrr(VARS *vars);

void	ft_print(VARS *vars);

#endif
