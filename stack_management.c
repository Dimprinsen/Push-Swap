/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:25:36 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 01:30:01 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*stk_get_last(t_stk *stk)
{
	if (!stk)
		return (NULL);
	while (stk->next != NULL)
		stk = stk->next;
	return (stk);
}

t_bool	stk_add_end(t_stk **stk, t_stk *new_node)
{
	t_stk	*curr;

	if (stk)
	{
		if (*stk)
		{
			curr = *stk;
			while (curr->next != NULL)
				curr = curr->next;
			curr->next = new_node;
			return (true);
		}
		else
		{
			*stk = new_node;
			return (true);
		}
	}
	return (false);
}

t_stk	*stk_get_min(t_stk *stk)
{
	t_stk	*min;

	min = stk;
	while (stk != NULL)
	{
		if (stk->nbr < min->nbr)
			min = stk;
		stk = stk->next;
	}
	return (min);
}

t_stk	*stk_get_max(t_stk *stk)
{
	t_stk	*max;

	max = stk;
	while (stk != NULL)
	{
		if (stk->nbr > max->nbr)
			max = stk;
		stk = stk->next;
	}
	return (max);
}

int	stk_cnt_nds(t_stk *stk)
{
	t_stk	*cur;
	int		result;

	cur = stk;
	result = 0;
	while (cur)
	{
		result++;
		cur = cur->next;
	}
	return (result);
}
