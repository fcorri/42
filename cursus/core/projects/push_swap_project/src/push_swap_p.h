/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorri <fcorri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:12 by fcorri            #+#    #+#             */
/*   Updated: 2023/09/11 13:51:56 by fcorri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_P_H
# define PUSH_SWAP_P_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define NODE	t_int_dlist	
# define STACK	t_stack
# define QUEUE	t_queue
# define VARS	t_vars

typedef struct stack
{
	NODE	*head;
	int		n;
}	t_stack;

typedef struct queue
{
	NODE	*head;
	NODE	*tail;
	int		n;
}	t_queue;

typedef struct vars
{
	STACK	*a;
	STACK	*b;
	QUEUE	*output;
	void	(*ops[8])(struct vars *vars);
	char	*names[8];
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

QUEUE	*ft_new_queue(void);
void	ft_enqueue(QUEUE *queue, NODE *node);
NODE	*ft_dequeue(QUEUE *queue);
void	ft_remove(QUEUE *queue);

void	ft_sa(VARS *vars);
void	ft_sb(VARS *vars);
void	ft_pa(VARS *vars);
void	ft_pb(VARS *vars);
void	ft_ra(VARS *vars);
void	ft_rb(VARS *vars);
void	ft_rra(VARS *vars);
void	ft_rrb(VARS *vars);

void	ft_ss(VARS *vars);
void	ft_rr(VARS *vars);
void	ft_rrr(VARS *vars);

void	ft_print(VARS *vars);
void	ft_print_queue(VARS *vars);

#endif
