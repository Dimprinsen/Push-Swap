/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   synchronization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:44:26 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 01:44:28 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sync_rotate(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	while (*stk_a != nd_a && *stk_b != nd_b)
	{
		sync_rotate(stk_a, stk_b);
		write(1, "rr\n", 3);
	}
	while (*stk_a != nd_a)
	{
		rotate(stk_a);
		write(1, "ra\n", 3);
	}
	while (*stk_b != nd_b)
	{
		rotate(stk_b);
		write(1, "rb\n", 3);
	}
}

void	do_sync_r_rot(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	while (*stk_a != nd_a && *stk_b != nd_b)
	{
		sync_rev_rotate(stk_a, stk_b);
		write(1, "rrr\n", 4);
	}
	while (*stk_a != nd_a)
	{
		rev_rotate(stk_a);
		write(1, "rra\n", 4);
	}
	while (*stk_b != nd_b)
	{
		rev_rotate(stk_b);
		write(1, "rrb\n", 4);
	}
}

t_bool	sync_r_or_rr(t_stk *stk_a, t_stk *stk_b, t_stk *nd_a, t_stk *nd_b)
{
	int		rotation;
	int		rev_rotation;

	rotation = get_rot_cost(stk_a, nd_a);
	rev_rotation = get_rev_rot_cost(stk_a, nd_a);
	if (get_rot_cost(stk_b, nd_b) > rotation)
		rotation = get_rot_cost(stk_b, nd_b);
	if (get_rev_rot_cost(stk_b, nd_b) > rev_rotation)
		rev_rotation = get_rev_rot_cost(stk_b, nd_b);
	if (rotation < rev_rotation)
		return (true);
	return (false);
}

void	sync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	if (sync_r_or_rr(*stk_a, *stk_b, nd_a, nd_b) == true)
	{
		do_sync_rotate(stk_a, stk_b, nd_a, nd_b);
	}
	else
	{
		do_sync_r_rot(stk_a, stk_b, nd_a, nd_b);
	}
}

void	unsync_to_top(t_stk **stk_a, t_stk **stk_b, t_stk *nd_a, t_stk *nd_b)
{
	if (get_rot_cost(*stk_a, nd_a) < get_rev_rot_cost(*stk_a, nd_a))
	{
		write_n_rotate(stk_a, nd_a, 1);
	}
	else
	{
		write_n_rev_rotate(stk_a, nd_a, 1);
	}
	if (get_rot_cost(*stk_b, nd_b) < get_rev_rot_cost(*stk_b, nd_b))
	{
		write_n_rotate(stk_b, nd_b, 0);
	}
	else
	{
		write_n_rev_rotate(stk_b, nd_b, 0);
	}
}
