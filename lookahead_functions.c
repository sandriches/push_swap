/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lookahead_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 12:15:57 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/05 16:46:46 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lookahead_how_many_bigger(int x, int median, p_a *ps, int amount_to_search)
{
	int count;

	count = 0;
	while (x < amount_to_search)
	{
		if (ps->b[x] > median)
			count++;
		x++;
	}
	return (count);
}

int		lookahead_how_many_smaller(int x, int median, p_a *ps, int amount_to_search)
{
	int count;

	count = 0;
	while (x < amount_to_search)
	{
		if (ps->a[x] <= median)
			count++;
		x++;
	}
	return (count);
}

int				find_unordered_descending(int *stack, int size)
{
	int x;
	int unordered;

	unordered = 0;
	x = 1;
	while (x < size)
	{
		if (stack[x - 1] < stack[x])
			unordered++;
		x++;
	}
	return (unordered);
}

int				find_first_unordered_ascending(int *stack, int size)
{
	int x;
	int	unordered;

	unordered = 0;
	x = 1;
	while (x < size)
	{
		if (stack[x - 1] > stack[x])
			return (x - 1);
		x++;
	}
	return (unordered);
}

int				find_unordered_ascending_from_one(int *stack, int size)
{
	int x;
	int unordered;

	x = 0;
	unordered = 0;
	while (stack[x] != 1 && x < size - 1)
		x++;
	while (x < size - 1)
	{
		if (stack[x] > stack[x + 1])
			return (stack[x + 1]);
		x++;
	}
	return (-1);
}

int				find_unordered_ascending(int *stack, int size)
{
	int x;
	int	unordered;

	unordered = 0;
	x = 1;
	while (x < size)
	{
		if (stack[x - 1] > stack[x])
			unordered++;
		x++;
	}
	return (unordered);
}

int				is_finished(p_a *ps)
{
	if (find_unordered_ascending(ps->a, ps->len_a) == 0 && ps->len_b == 0)
		return (1);
	return (0);
}
