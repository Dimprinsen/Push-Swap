/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttinnerh <ttinnerh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:40:25 by ttinnerh          #+#    #+#             */
/*   Updated: 2024/12/11 01:40:28 by ttinnerh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Basic function that check all chars are numbers.
t_bool	check_str(char *str)
{
	int	k;

	k = 0;
	if (str[k] == '\0')
		return (false);
	if (str[k] == '-' && str[k + 1] != '\0')
		k++;
	while (str[k] != '\0')
	{
		if (str[k] < 48 || str[k] > 58)
			return (false);
		k++;
	}
	return (true);
}

// Applies the check_str to each node
void	check_args(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (check_str(argv[i]) == false)
		{
			free_vector(argc, argv);
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}

// Goes through the linked list and checks for invalid numbers.
// Kills program if invalid
void	check_numbers(t_stk *stk)
{
	t_stk	*curr;
	t_stk	*compare;

	curr = stk;
	while (curr != NULL)
	{
		if (curr->nbr < INT_MIN || curr->nbr > INT_MAX)
		{
			write(2, "Error\n", 6);
			free_stk(stk);
			exit(0);
		}
		compare = curr->next;
		while (compare != NULL)
		{
			if (curr->nbr == compare->nbr)
			{
				write(2, "Error\n", 6);
				free_stk(stk);
				exit(0);
			}
			compare = compare->next;
		}
		curr = curr->next;
	}
}

// Function used to free any given linked list stk
t_bool	free_stk(t_stk *stk)
{
	t_stk	*cur;
	t_stk	*tmp;

	if (!stk)
		return (false);
	cur = stk;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
	return (true);
}

// Function used to free created vector in case of arg error.
void	free_vector(int argc, char *argv[])
{
	int	i;

	if (argv == NULL)
		return ;
	i = 0;
	while (i < argc)
	{
		argv[i] = NULL;
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	argv = NULL;
	free(argv);
	argv = NULL;
}
