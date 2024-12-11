/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:17:45 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 01:19:37 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stk **src, t_stk **dest)
{
	t_stk	*buf;

	if (!*src || !*dest)
		return ;
	buf = *src;
	*src = (*src)->next;
	buf->next = *dest;
	*dest = buf;
}

void	stack_swap(t_stk **stk)
{
	t_stk	*buf;

	buf = *stk;
	*stk = buf->next;
	buf->next = (*stk)->next;
	(*stk)->next = buf;
}

t_bool	stack_rotate(t_stk **stk)
{
	t_stk	*last;
	t_stk	*buf;

	if (!*stk || !(*stk)->next)
		return (false);
	buf = *stk;
	*stk = (*stk)->next;
	last = stk_get_last(buf);
	buf->next = NULL;
	last->next = buf;
	return (true);
}

t_bool	stack_rev_rotate(t_stk **stk)
{
	t_stk	*last;
	t_stk	*buf;

	if (!*stk || !(*stk)->next)
		return (false);
	last = stk_get_last(*stk);
	buf = *stk;
	while (buf->next != last)
		buf = buf->next;
	buf->next = NULL;
	last->next = *stk;
	*stk = last;
	return (true);
}

t_bool	stack_sync_rotate(t_stk **stk_a, t_stk **stk_b)
{
	if (!stk_a || !stk_b)
		return (false);
	if (stack_rotate(stk_a) == false || stack_rotate(stk_b) == false)
		return (false);
	return (true);
}
