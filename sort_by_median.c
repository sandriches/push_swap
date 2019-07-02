/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_by_median.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 12:03:38 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/02 13:57:49 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_loops(int size)
{
	int x;
	float f_size;

	f_size = (float)size;
	x = 0;
	while (size > 4)
	{
		size /= 2;
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

void		sort_by_med_b(p_a *ps, int loops, int inoffensive)
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
		else if (ps->b[0] <= median)
		{
			check_rotate(ps, 'b');
			rotated++;
		}
		x++;
	}
	return (undo_rotates(ps, rotated, 'b', inoffensive));
}

void		sort_by_med_a(p_a *ps, int loops, int inoffensive)
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

void			sort_a_by_median_part_2(p_a *ps, int sorted_half, int loops, int *half_array)
{
	int old_len;
	int x;

	x = 0;
	old_len = ps->len_a;
	// sorted_half /= 2;
	sort_by_med_b(ps, half_array[0] - ps->len_a, 1);
	while (ps->len_a > old_len + 4)
	{
		sorted_half = ps->len_a - old_len;
		// ft_printf("sorted_half: %d\n", sorted_half);
		sort_by_med_a(ps, sorted_half, 1);
		x++;
	}
	sort_4_not_alone_a(ps);
	ft_printf("sorted half: %d\n", sorted_half);
	// sort_by_med_b(ps, sorted_half, 1);
	// sort_4_not_alone_a(ps);
	// ft_printf("x: %d\n", x);
	// sorted_half = half_array[loops];
	// sorted_half *= 2;
// 	while (loops > 0)
// 	{
// 		sort_by_med_b(ps, sorted_half, 1);
// 		sorted_half /= 2;
// 		sort_by_med_a(ps, sorted_half, 1);
// 		sort_4_not_alone_a(ps);
// 		sorted_half *= 2;
// 		loops--;
// 	}
// 	while (ps->len_a > ps->size / 2)
// 		push_b(ps);
// 	while (ps->len_a < ps->size / 2)
// 		push_a(ps);
}

void		sort_a_by_median(p_a *ps, int sorted_half, int loops, int *half_array)
{
	int x;
	int y;
	int old_len;

	y = 0;
	x = 0;
	while (ps->len_a > 4)
	{
		sort_by_med_a(ps, half_array[x], 0);
		x++;
	}
	sort_4_not_alone_a(ps);
	x--;
	sort_by_med_b(ps, half_array[x], 1);
	sort_4_not_alone_a(ps);
	x--;
	// x-= 2;
	ft_printf("x before going in to while loop: %d\n", x);
	while (loops > 0)
	{
		y = half_array[x - 1] - ps->len_a;
		// ft_printf("{GREEN}Y: %d\tLOOPS: %d{/}\n", y, loops);
		old_len = ps->len_a;
		sort_by_med_b(ps, y, 1);
		if (ps->len_a - old_len > 4)
			sort_by_med_a(ps, ps->len_a - old_len, 1);
		sort_4_not_alone_a(ps);
		loops--;
		// x--;
	}
	// while (ps->len_a > half_array[1])
		// push_b(ps);
	// while (ps->len_a < half_array[1])
		// push_a(ps);
}

void			sort_b_by_median_part_2(p_a *ps, int sorted_half, int loops)
{
	sorted_half /= 2;
	sort_by_med_a(ps, sorted_half, 1);
	while (ps->len_b > (ps->size / 4) + 4)
	{
		sorted_half /= 2;
		sort_by_med_b(ps, sorted_half, 1);
	}
	sort_4_not_alone_b(ps);
	sort_by_med_a(ps, sorted_half, 1);
	sort_4_not_alone_b(ps);
	sorted_half *= 2;
	while (loops > 0)
	{
		sort_by_med_a(ps, sorted_half, 1);
		sorted_half /= 2;
		sort_by_med_b(ps, sorted_half, 1);
		sort_4_not_alone_b(ps);
		sorted_half *= 2;
		loops--;
	}
	while (ps->len_b > ps->size / 2)
		push_a(ps);
	while (ps->len_b < ps->size / 2)
		push_b(ps);
}


void			sort_b_by_median(p_a *ps, int sorted_half, int loops)
{
	while (ps->len_b >= 4)
	{
		sorted_half /= 2;
		sort_by_med_b(ps, sorted_half, 0);
	}
	sort_4_not_alone_b(ps);
	sort_by_med_a(ps, sorted_half, 0);
	sort_4_not_alone_b(ps);
	sorted_half *= 2;
	while (loops > 0)
	{
		sort_by_med_a(ps, sorted_half, 1);
		sorted_half /= 2;
		sort_by_med_b(ps, sorted_half, 1);
		sort_4_not_alone_b(ps);
		sorted_half *= 2;
		loops--;
	}
	while (ps->len_b < ps->size / 4)
		push_b(ps);
	while (ps->len_b > ps->size / 4)
		push_a(ps);
}

void		sort_by_median(p_a *ps)
{
	int sorted_half;
	int loops;
	int	*half_array_a;
	int *half_array_b;

	sorted_half = ps->size;
	loops = find_loops(ps->size);
	half_array_a = make_halving_array(ps->size, 'a');
	half_array_b = make_halving_array(ps->size, 'b');
	sort_by_med_a(ps, sorted_half, 0);
	sort_a_by_median(ps, sorted_half, loops, half_array_a);
	sort_a_by_median_part_2(ps, sorted_half, loops, half_array_a);
	ft_printf("loops: %d\n", loops);
	ft_printf("array0: %d\tarray[1]: %d\tarray[2]: %d\tarray[3]: %d\n", half_array_a[0], half_array_a[1], half_array_a[2], half_array_a[3]);
	// sort_b_by_median(ps, sorted_half, loops);
	// sort_b_by_median_part_2(ps, sorted_half, loops);
	// push_all_to_a(ps);
	// ft_printf("unordered left on a: %d\n", find_unordered_ascending(ps->a, ps->len_a));
	// ft_printf("unordered left on b: %d\n", find_unordered_descending(ps->b, ps->len_b));
}
