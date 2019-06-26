/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_by_median.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 12:03:38 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/26 19:39:50 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_loops(int size)
{
	int x;
	float f_size;

	f_size = (float)size;
	x = 1;
	while (f_size > 2)
	{
		f_size /= 2;
		x++;
	}
	return (x);
}

static void		push_all_to_a(p_a *ps)
{
	int count;

	count = ps->len_b;
	while (count > 0)
	{
		push_a(ps);
		count--;
	}
}

static void		undo_rotates(p_a *ps, int count, char which_stack, int do_or_not)
{
	if (do_or_not == 0)
		return ;
	if (which_stack == 'a')
	{
		while (count > 0)
		{
			reverse_a(ps);
			count--;
		}
	}
	else
	{
		while (count > 0)
		{
			reverse_b(ps);
			count--;
		}
	}	
}

static void		sort_by_med_b(p_a *ps, int loops, int inoffensive)
{
	int x;
	int median;
	int rotated;

	x = 0;
	median = find_median(ps->b, loops);
	rotated = 0;
	while (x < loops)
	{
		ft_printf("median: %d\n", median);
		if (lookahead_how_many_bigger(0, median, ps, loops) == 0)
			return (undo_rotates(ps, rotated, 'b', inoffensive));
		if (ps->b[0] > median)
			push_a(ps);
		else if (ps->a[0] >= median)
		{
			check_rotate(ps, 'b');
			rotated++;
		}
		x++;
	}
	return (undo_rotates(ps, rotated, 'b', inoffensive));
}

static void		sort_by_med_a(p_a *ps, int loops, int inoffensive)
{
	int x;
	int median;
	int rotated;

	x = 0;
	median = find_median(ps->a, loops);
	rotated = 0;
	while (x < loops)
	{
		ft_printf("median: %d\n", median);
		if (lookahead_how_many_smaller(0, median, ps, loops) == 0)
			return (undo_rotates(ps, rotated, 'a', inoffensive));
		if (ps->a[0] <= median)
			push_b(ps);
		else if (ps->a[0] >= median)
		{
			check_rotate(ps, 'a');
			rotated++;
		}
		x++;
	}
	return (undo_rotates(ps, rotated, 'a', inoffensive));
}

void		sort_b_by_median(p_a *ps, int sorted_half, int loops)
{
	while (ps->len_a > 4)
	{
		sorted_half /= 2;
		sort_by_med_a(ps, sorted_half, 0);
	}
	sort_4_not_alone_a(ps);
	sort_by_med_b(ps, sorted_half, 0);
	sort_4_not_alone_a(ps);
	sorted_half *= 2;
	while (loops > 0)
	{
		sort_by_med_b(ps, sorted_half, 1);
		sorted_half /= 2;
		sort_by_med_a(ps, sorted_half, 1);
		sort_4_not_alone_a(ps);
		sorted_half *= 2;
		loops--;
	}
}

void			sort_a_by_median(p_a *ps, int sorted_half, int loops)
{
	int count;
	int x = 0;
	int y = 0;
	int z = 0;

	count = 2;
	while (ps->len_b > 4)
	{
		sorted_half /= 2;
		sort_by_med_b(ps, sorted_half, 0);
	}
	sort_4_not_alone_b(ps);
	while (x < 10)
	{
		sorted_half = 4 * count;
		y = count;
		z = sorted_half / 2;
		while (y > 2)
		{
			sort_by_med_b(ps, z, 1);
			y--;
			z /= 2;
		}
		sort_by_med_a(ps, sorted_half, 1);
		sort_4_not_alone_b(ps);
		count++;
		x++;
	}
	ft_printf("sorted_half: %d\n", sorted_half);
	// sorted_half *= 2;
	// sort_4_not_alone_b(ps);
	// sort_by_med_a(ps, sorted_half, 0);
	// sort_4_not_alone_b(ps);
	// sort_by_med_a(ps, sorted_half * 2, 1);
	// sort_by_med_b(ps, ps->len_b / 2, 1);
	// sort_by_med_b(ps, ps->len_b / 2, 1);
	// sort_4_not_alone_b(ps);
	// while (loops > 0)
	// {
	// 	ft_printf("sorted half before A sort: %d\n", sorted_half);
	// 	sort_by_med_a(ps, sorted_half, 1);
	// 	sorted_half /= 2;
	// 	sort_by_med_b(ps, sorted_half, 1);
	// 	sort_4_not_alone_b(ps);
	// 	sorted_half *= 2;
	// 	loops--;
	// }
	// if (ps->len_b < ps->size / 2)
	// 	while (ps->len_b < ps->size / 2)
	// 		push_b(ps);
}

void		sort_by_median(p_a *ps)
{
	int sorted_half;
	int loops;

	sorted_half = ps->size;
	loops = find_loops(ps->size);
	ft_printf("find loops result: %d\n", find_loops(ps->size));
	sort_by_med_a(ps, sorted_half, 0);
	sort_a_by_median(ps, sorted_half, loops - 1);
	// sort_b_by_median(ps, sorted_half, loops);
	// push_all_to_a(ps);
}
