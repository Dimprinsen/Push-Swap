/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:01:46 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 02:01:48 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vec_size(const char *s, char c)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			result++;
			while (s[i] != c && s[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (result);
}

t_stk	*get_previous_in_a(t_stk *stk, t_stk *node)
{
	t_stk	*curr;
	t_stk	*previous;

	if (node->nbr > (stk_get_max(stk))->nbr)
		return (stk_get_min(stk));
	previous = stk_get_max(stk);
	curr = stk;
	while (curr)
	{
		if ((curr->nbr > node->nbr) && (curr->nbr < previous->nbr))
			previous = curr;
		curr = curr->next;
	}
	return (previous);
}

t_stk	*find_cheapest(t_stk *stk_a, t_stk *stk_b)
{
	t_stk	*cheapest;
	t_stk	*cur;
	int		cost;
	t_stk	*prev;

	cost = INT_MAX;
	cur = stk_a;
	while (cur)
	{
		prev = get_previous(stk_b, cur);
		if (get_sync_cst(stk_a, stk_b, cur, prev) < cost)
		{
			cost = get_sync_cst(stk_a, stk_b, cur, prev);
			cheapest = cur;
		}
		if (get_unsync_cst(stk_a, stk_b, cur, prev) < cost)
		{
			cost = get_unsync_cst(stk_a, stk_b, cur, prev);
			cheapest = cur;
		}
		cur = cur->next;
	}
	return (cheapest);
}
