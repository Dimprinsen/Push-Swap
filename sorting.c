/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:56:56 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 01:56:57 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_three_elements(t_stk **stk)
{
	t_stk	*max;
	t_stk	*min;

	max = stk_get_max(*stk);
	min = stk_get_min(*stk);
	if (min->next == max)
	{
		write(1, "sa\n", 3);
		swap(stk);
	}
	if (*stk == max && max->next != min)
	{
		write(1, "sa\n", 3);
		swap(stk);
	}
}

void	push_to_stack_a(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*max_b;
	t_stk	*prev;
	int		sync;
	int		unsync;

	if (!*stk_b)
		return ;
	while (*stk_b)
	{
		max_b = stk_get_max(*stk_b);
		prev = get_previous_in_a(*stk_a, max_b);
		sync = get_sync_cst(*stk_a, *stk_b, prev, max_b);
		unsync = get_unsync_cst(*stk_a, *stk_b, prev, max_b);
		if (sync < unsync)
		{
			sync_to_top(stk_a, stk_b, prev, max_b);
		}
		else
		{
			unsync_to_top(stk_a, stk_b, prev, max_b);
		}
		write(1, "pa\n", 3);
		push(stk_b, stk_a);
	}
}

void	push_to_stack_b(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*cheapest;
	t_stk	*prev;
	int		sync;
	int		unsync;

	while (stk_cnt_nds(*stk_a) > 3)
	{
		cheapest = find_cheapest(*stk_a, *stk_b);
		prev = get_previous(*stk_b, cheapest);
		sync = get_sync_cst(*stk_a, *stk_b, cheapest, prev);
		unsync = get_unsync_cst(*stk_a, *stk_b, cheapest, prev);
		if (sync < unsync)
		{
			sync_to_top(stk_a, stk_b, cheapest, prev);
		}
		else
		{
			unsync_to_top(stk_a, stk_b, cheapest, prev);
		}
		write(1, "pb\n", 3);
		push(stk_a, stk_b);
	}
}

void	order_stack_a(t_stk **stk_a, t_stk *min)
{
	if (get_rot_cost(*stk_a, min) < get_rev_rot_cost(*stk_a, min))
	{
		write_n_rotate(stk_a, min, 1);
	}
	else
	{
		write_n_rev_rotate(stk_a, min, 1);
	}
}

t_stk	*push_two_elements(t_stk **stk_a)
{
	t_stk	*stk_b;

	if (stk_cnt_nds(*stk_a) > 3)
	{
		stk_b = *stk_a;
		*stk_a = (*stk_a)->next;
		stk_b->next = NULL;
		write(1, "pb\n", 3);
	}
	if (stk_cnt_nds(*stk_a) > 3)
	{
		push(stk_a, &stk_b);
		write(1, "pb\n", 3);
	}
	return (stk_b);
}
