/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:13:49 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 01:23:20 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	struct s_stack	*next;
}	t_stk;

typedef enum e_bool
{
	false,
	true
}	t_bool;

# define FALSE false
# define TRUE true

// stack_manipulation.c
void	stack_push(t_stk **src, t_stk **dest);
void	stack_swap(t_stk **stk);
t_bool	stack_rotate(t_stk **stk);
t_bool	stack_rev_rotate(t_stk **stk);
t_bool	stack_sync_rotate(t_stk **stk_a, t_stk **stk_b);

// rotation_cost.c
int		get_unsync_cost(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev);
int		get_sync_cost(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev);
int		get_rev_rotation_cost(t_stk *stk, t_stk *node);
int		get_rotation_cost(t_stk *stk, t_stk *node);
t_stk	*get_previous_node(t_stk *stk, t_stk *node);

// memory management.c
t_bool	free_stk(t_stk *stk);
void	free_vector(int argc, char *argv[]);
t_bool	check_str(char *str);
void	check_args(int argc, char *argv[]);
void	check_numbers(t_stk *stk);

// stack_management.c
t_bool	stk_add_end(t_stk **stk, t_stk *new_node);
t_stk	*stk_get_last(t_stk *stk);
t_stk	*stk_get_min(t_stk *stk);
t_stk	*stk_get_max(t_stk *stk);
int		stk_cnt_nds(t_stk *stk);

// synchronization.c
void	do_sync_rotate(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);
void	do_sync_r_rot(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);
t_bool	sync_r_or_rr(t_stk *stk_a, t_stk *stk_b, t_stk *nd_a, t_stk *nd_b);
void	sync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);
void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b);

// rotation.c
void	write_n_rotate(t_stk **stk, t_stk *node, int toggle);
void	write_n_rev_rotate(t_stk **stk, t_stk *node, int toggle);
t_bool	sync_rev_rotate(t_stk **stk_a, t_stk **stk_b);

// sorting.c
void	solve_three_elements(t_stk **stk);
void	push_to_stack_a(t_stk **stk_a, t_stk **stk_b);
void	push_to_stack_b(t_stk **stk_a, t_stk **stk_b);
void	order_stack_a(t_stk **stk_a, t_stk *min);
t_stk	*push_two_elements(t_stk **stk_a);

// main.c
t_stk	*initialize_stack(int argc, char **vec);
void	check_if_stack_ordered(t_stk *stk);
t_bool	exec_push_swap(t_stk **stk_a);

#endif
