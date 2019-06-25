/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_by_median.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 12:03:38 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/25 14:12:13 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_by_med_b(p_a *ps)
{
	int loops;
	int x;
	int median;

	x = 0;
	loops = ps->len_b / 2;
	median = find_median(ps->b, ps->len_b);
	while (x < loops)
	{
		ft_printf("median: %d\n", median);
		if (lookahead_how_many_bigger(0, median, ps) == 0)
			break;
		if (ps->b[0] > median)
			push_a(ps);
		else if (ps->a[0] >= median)
			check_rotate(ps, 'b');
		x++;
	}
}
static void sort_by_med_a(p_a *ps)
{
	int loops;
	int x;
	int median;

	x = 0;
	loops = ps->len_a;
	median = find_median(ps->a, ps->len_a);
	while (x < loops)
	{
		ft_printf("median: %d\n", median);
		if (lookahead_how_many_smaller(0, median, ps) == 0)
			break;
		if (ps->a[0] < median)
			push_b(ps);
		else if (ps->a[0] >= median)
			check_rotate(ps, 'a');
		x++;
	}
}

void        sort_by_median(p_a *ps)
{
	int x;
	int loops;
	int median;

	sort_by_med_a(ps);
	while (ps->len_b > 3)
	{
		sort_by_med_b(ps);
	}
}
