/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lookahead_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 18:25:07 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/22 16:54:21 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_amount_left_to_push_b(t_ps *ps, int len, int x, int median)
{
	len -= x;
	x = 0;
	while (x < len)
	{
		if (ps->b[x] > median)
			return (1);
		x++;
	}
	return (0);
}

int		check_amount_left_to_push_a(t_ps *ps, int len, int x, int median)
{
	len -= x;
	x = 0;
	while (x < len)
	{
		if (ps->a[x] <= median)
			return (1);
		x++;
	}
	return (0);
}

int		find_unordered_descending(int *stack, int size)
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

int		find_unordered_ascending(int *stack, int size)
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
