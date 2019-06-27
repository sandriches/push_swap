/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lookahead_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 12:15:57 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/27 19:13:16 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int		lookahead_how_many_bigger(int x, int median, p_a *ps, int amount_to_search)
{
	int y;
	int count;

	count = 0;
	y = 0;
	while (x < amount_to_search)
	{
		if (ps->b[y] > median)
			count++;
		x++;
		y++;
	}
	return (count);
}

int		lookahead_how_many_smaller(int x, int median, p_a *ps, int amount_to_search)
{
	int y;
	int count;

	count = 0;
	y = 0;
	while (x < amount_to_search)
	{
		if (ps->a[y] < median)
			count++;
		x++;
		y++;
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
