/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:34:28 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 01:34:29 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rotation_cost(t_stk *stk, t_stk *node)
{
	int	result;

	result = 0;
	if (stk->nbr == node->nbr)
	{
		return (result);
	}
	while (stk->nbr != node->nbr)
	{
		result++;
		stk = stk->next;
	}
	return (result);
}

int	get_rev_rotation_cost(t_stk *stk, t_stk *node)
{
	int	result;

	result = 0;
	if (stk->nbr == node->nbr)
	{
		return (result);
	}
	while (stk->nbr != node->nbr)
		stk = stk->next;
	while (stk)
	{
		result++;
		stk = stk->next;
	}
	return (result);
}

int	get_sync_cost(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev)
{
	int		rot_cost;
	int		rev_rot_cost;

	if (get_rot_cost(stk_a, node) > get_rot_cost(stk_b, prev))
	{
		rot_cost = get_rot_cost(stk_a, node);
	}
	else
	{
		rot_cost = get_rot_cost(stk_b, prev);
	}
	if (get_rev_rot_cost(stk_a, node) > get_rev_rot_cost(stk_b, prev))
	{
		rev_rot_cost = get_rev_rot_cost(stk_a, node);
	}
	else
	{
		rev_rot_cost = get_rev_rot_cost(stk_b, prev);
	}
	if (rot_cost < rev_rot_cost)
	{
		return (rot_cost);
	}
	return (rev_rot_cost);
}

int	get_unsync_cost(t_stk *stk_a, t_stk *stk_b, t_stk *node, t_stk *prev)
{
	int		node_cost;
	int		prev_cost;

	if (get_rot_cost(stk_a, node) < get_rev_rot_cost(stk_a, node))
	{
		node_cost = get_rot_cost(stk_a, node);
	}
	else
	{
		node_cost = get_rev_rot_cost(stk_a, node);
	}
	if (get_rot_cost(stk_b, prev) < get_rev_rot_cost(stk_b, prev))
	{
		prev_cost = get_rot_cost(stk_b, prev);
	}
	else
	{
		prev_cost = get_rev_rot_cost(stk_b, prev);
	}
	return (node_cost + prev_cost);
}

t_stk	*get_previous_node(t_stk *stk, t_stk *node)
{
	t_stk	*curr;
	t_stk	*previous;

	if (node->nbr > (stk_get_max(stk))->nbr)
		return (stk_get_max(stk));
	if (node->nbr < (stk_get_min(stk))->nbr)
		return (stk_get_max(stk));
	previous = stk_get_min(stk);
	curr = stk;
	while (curr)
	{
		if ((curr->nbr < node->nbr) && (curr->nbr > previous->nbr))
			previous = curr;
		curr = curr->next;
	}
	return (previous);
}
