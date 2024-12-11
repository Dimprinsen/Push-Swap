/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:02:56 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 02:03:00 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_n_rotate(t_stk **stk, t_stk *node, int toggle)
{
	while (*stk != node)
	{
		if (toggle == 1)
			write(1, "ra\n", 3);
		if (toggle == 0)
			write(1, "rb\n", 3);
		rotate (stk);
	}
}

void	write_n_rev_rotate(t_stk **stk, t_stk *node, int toggle)
{
	while (*stk != node)
	{
		if (toggle == 1)
			write(1, "rra\n", 4);
		if (toggle == 0)
			write(1, "rrb\n", 4);
		rev_rotate (stk);
	}
}

t_bool	sync_rev_rotate(t_stk **stk_a, t_stk **stk_b)
{
	if (!stk_a || !stk_b)
		return (false);
	if (stack_rev_rotate(stk_a) == false || stack_rev_rotate(stk_b) == false)
		return (false);
	return (true);
}
