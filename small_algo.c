/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_algo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 16:46:40 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/17 17:33:43 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_rest_to_a(t_ps *ps)
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

static void		sort_3_3_or_3_2_b(t_ps *ps)
{
	if (ps->len_b == 3)
	{
		if (find_unordered_descending(ps->b, ps->len_b) == 0)
			return (push_rest_to_a(ps));
		else if (ps->b[1] < ps->b[0] && ps->b[1] < ps->b[2])
			check_r_rotate(ps, 'b');
		else if (ps->b[0] < ps->b[1] && ps->b[0] < ps->b[2])
			check_rotate(ps, 'b');
		else
			check_swap(ps, 'b');
		sort_3_3_or_3_2_b(ps);
	}
	else if (ps->len_b == 2)
	{
		if (find_unordered_descending(ps->b, ps->len_b) == 0)
			return (push_rest_to_a(ps));
		if (ps->b[0] < ps->b[1])
			check_swap(ps, 'b');
		return (sort_3_3_or_3_2_b(ps));
	}
}

static void		sort_3_3_or_3_2_a(t_ps *ps)
{
	if (ps->len_a == 3)
	{
		if (find_unordered_ascending(ps->a, ps->len_a) == 0)
			return (sort_3_3_or_3_2_b(ps));
		else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
			check_r_rotate(ps, 'a');
		else if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
			check_rotate(ps, 'a');
		else
			check_swap(ps, 'a');
		sort_3_3_or_3_2_a(ps);
	}
	else if (ps->len_a == 2)
	{
		if (find_unordered_ascending(ps->a, ps->len_a) == 0)
			return (sort_3_3_or_3_2_b(ps));
		if (ps->a[0] > ps->a[1])
			check_swap(ps, 'a');
		return (sort_3_3_or_3_2_b(ps));
	}
}

void			small_algo(t_ps *ps)
{
	if (find_unordered_ascending(ps->a, ps->len_a) > 0)
	{
		if (ps->size == 5)
			get_x_from_stack_a(ps, 2, ps->len_a, 0);
		else
			get_x_from_stack_a(ps, ps->size / 2, ps->len_a, 0);
		sort_3_3_or_3_2_a(ps);
	}
}
