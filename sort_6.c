/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_6.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 13:45:03 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/24 16:55:29 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_rest_to_a(p_a *ps)
{
	int x;
	int stop;

	x = 0;
	stop = ps->len_b;
	while (x < stop)
	{
		push_a(ps);
		x++;
	}
}

static void		sort_3_3_or_3_2_b(p_a *ps)
{
	if (ps->len_b == 3)
	{
		if (find_unordered_descending(ps->b, 3) == 0)
			return push_rest_to_a(ps);
		else if (ps->b[0] < ps->b[1] && ps->b[0] < ps->b[2] && ps->b[2] < ps->b[1])
			check_rotate(ps, 'b');
		else if (ps->b[1] < ps->b[0] && ps->b[1] < ps->b[2] && ps->b[0] < ps->b[2])
			check_r_rotate(ps, 'b');
		else
			check_swap(ps, 'b');
		sort_3_3_or_3_2_b(ps);
	}
	else if (ps->len_b == 2)
	{
		if (find_unordered_descending(ps->b, 2) == 0)
			return push_rest_to_a(ps);
		if (ps->b[0] < ps->b[1])
			check_swap(ps, 'b');
		return (sort_3_3_or_3_2_b(ps));
	}
}

static void		sort_3_3_or_3_2_a(p_a *ps)
{
	if (ps->len_a == 3)
	{
		if (find_unordered_ascending(ps->a, 3) == 0)
			return sort_3_3_or_3_2_b(ps);
		else if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2] && ps->a[2] > ps->a[1])
			check_rotate(ps, 'a');
		else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2] && ps->a[0] > ps->a[2])
			check_r_rotate(ps, 'a');
		else
			check_swap(ps, 'a');
		sort_3_3_or_3_2_a(ps);
	}
	else if (ps->len_a == 2)
	{
		if (find_unordered_ascending(ps->a, 2) == 0)
			return sort_3_3_or_3_2_b(ps);
		if (ps->a[0] > ps->a[1])
			check_swap(ps, 'a');
		return (sort_3_3_or_3_2_b(ps));
	}
}

static int	how_many_left_to_push(p_a *ps, int median, int x)
{
	int result;

	result = 0;
	while (x >= 0)
	{
		if (ps->a[x] <= median)
			result++;
		x--;
	}
	return (result);
}

static void		push_half_to_b(p_a *ps)
{
	int median;
	int closest;
	int x;

	median = find_median(ps->a, ps->size);
	ft_printf("median: %d\n", median);
	x = ps->size;
	while (x >= 0)
	{
		if (how_many_left_to_push(ps, median, x) == 0)
			break;
		if (ps->a[0] <= median)
			push_b(ps);
		else
			rotate_a(ps);
		x--;
	}
}

void			sort_6(p_a *ps)
{
	int x;

	if (find_unordered_ascending > 0)
	{
		x = 0;
		push_half_to_b(ps);
		sort_3_3_or_3_2_a(ps);
	}
}