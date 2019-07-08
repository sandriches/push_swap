/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_by_median.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 12:03:38 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/08 18:23:21 by rcorke        ########   odam.nl         */
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
	int highest;

	highest = get_highest_from_stack(ps->b, loops);
	// ft_printf("SORT BY MED_B, LOOPS: %d\tHIGHEST: %d\tLOWEST: %d\n", loops, get_highest_from_stack(ps->b, loops), get_lowest_from_stack(ps->b, loops));
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

void		sort_by_med_b_higher(p_a *ps, int loops, int inoffensive)
{
	int x;
	int median;
	int rotated;

	// ft_printf("SORT BY MED_B_lower, LOOPS: %d\n", loops);
	x = 0;
	median = find_median(ps->b, loops);
	rotated = 0;
	while (x < loops)
	{
		// ft_printf("median: %d\n", median);
		if (lookahead_how_many_bigger(0, median, ps, loops) == 0)
			return (undo_rotates(ps, rotated, 'b', inoffensive));
		if (ps->b[0] <= median)
			push_a(ps);
		else if (ps->b[0] > median)
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

	// ft_printf("SORT BY MED_A, LOOPS: %d\n", loops);
	x = 0;
	median = find_median(ps->a, loops);
	rotated = 0;
	while (x < loops)
	{
		// ft_printf("median: %d\n", median);
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

void		sort_by_med_a_lower(p_a *ps, int loops, int inoffensive)
{
	int x;
	int median;
	int rotated;

	// ft_printf("SORT BY MED_A_lower, LOOPS: %d\n", loops);
	x = 0;
	median = find_median(ps->a, loops);
	rotated = 0;
	while (x < loops)
	{
		// ft_printf("median: %d\n", median);
		if (lookahead_how_many_smaller(0, median, ps, loops) == 0)
			return (undo_rotates(ps, rotated, 'a', inoffensive));
		if (ps->a[0] > median)
			push_b(ps);
		else if (ps->a[0] <= median)
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
	int to_loop_over1;
	int to_loop_over2;
	int x;

	x = 0;
	old_len = ps->len_a;
	sort_by_med_b(ps, half_array[0] - ps->len_a, 1);
	sort_by_med_a(ps, half_array[1] , 1);
	to_loop_over1 = ps->len_a - old_len;
	// sort_by_med_a(ps, ps->len_a - old_len, 1);
	// x++;
	// to_loop_over2 = ps->len_a - old_len;
	// sort_by_med_a(ps, ps->len_a - old_len, 1);
	// x++;
	// sort_4_not_alone_a(ps);
	// ft_printf("loop over1: %d\tloop over 2: %d\n", to_loop_over1, to_loop_over2);
	// while (ps->len_a > old_len + 4)
	// {
	// 	sorted_half = ps->len_a - old_len;
	// 	// ft_printf("sorted_half: %d\n", sorted_half);
	// 	sort_by_med_a(ps, sorted_half, 1);
	// 	x++;
	// }
	// sort_4_not_alone_a(ps);
	// ft_printf("sorted half: %d\n", sorted_half);
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
	// ft_printf("x before going in to while loop: %d\n", x);
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

static void		do_insert_4_sort(p_a *ps, int four_or_two)
{
	if (four_or_two == 4)
	{
		while (ps->len_b > 4)
		{
			grab_4_from_b(ps, ps->len_b);
			// ft_printf("SORT 4 ALONE A: \n");
			sort_4_not_alone_a(ps);
			// ft_printf("FINISHED SORT 4\n");
		}
		while (ps->len_b > 0)
			push_a(ps);
		// ft_printf("SORT 4 ALONE A: \n");
		sort_4_not_alone_a(ps);
		// ft_printf("FINISHED SORT 4\n");
	}
	else
	{
		while (ps->len_b > 2)
		{
			grab_2_from_b(ps, ps->len_b);
			check_swap(ps, 'a');
		}
		while (ps->len_b > 0)
			push_a(ps);
		check_swap(ps, 'a');
	}
}

static void		push_amount_to_b(p_a *ps, int stop_index)
{
	int x;
	
	x = 0;
	while (x < stop_index)
	{
		push_b(ps);
		x++;
	}
}

static void		push_to_b(p_a *ps, int *half_array)
{
	int x;
	
	x = 0;
	while (x < half_array[0] - half_array[1])
	{
		// ft_printf("push rest up to %d\n", half_array[0]);
		push_b(ps);
		x++;
	}
}

static void		second_push_to_b(p_a *ps, int *half_array)
{
	int x;
	
	x = 0;
	while (x < half_array[1])
	{
		// ft_printf("push rest up to %d\n", half_array[0]);
		push_b(ps);
		x++;
	}
}

static void		push_into_place(p_a *ps, int stop_at)
{
	while (ps->a[0] != stop_at)
		rotate_a(ps);
	rotate_a(ps);
}

static void	do_7_lines(p_a *ps, int *half_array_a, int *half_array_b)
{
	int			stop_at;
	static int	check_different;

	if (!check_different)
		check_different = 0;
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);
	// if (check_ab_7_lines(case, check_different) == 'a')
	// 	push_amount_to_b(ps, half_array_a[3]);
	// else
		push_amount_to_b(ps, half_array_b[3]);
	check_different++;
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);
}

static void	big_loop_1(p_a *ps, int *half_array_a, int *half_array_b, int x)
{
	if (x == 1)
	{
		sort_by_med_a(ps, half_array_b[1], 1);
		sort_by_med_b(ps, half_array_b[2], 0);
	}
	else if (x == 2)
	{
		sort_by_med_a(ps, half_array_b[1], 1);
		sort_by_med_b(ps, half_array_b[2], 0);
	}
	else if (x == 3)
		sort_by_med_a(ps, half_array_b[2], 1);
	else if (x == 7)
		sort_by_med_a(ps, half_array_a[2], 1);
}

static void	big_loop_2(p_a *ps, int *half_array_a, int *half_array_b, int x)
{

	if (x == 0)
	{
		sort_by_med_b(ps, half_array_b[0], 0);
		sort_by_med_b(ps, half_array_b[1], 0);
		sort_by_med_b(ps, half_array_b[2], 0);
	}
	else if (x == 5)
	{
		sort_by_med_a(ps, half_array_a[1], 1);
		sort_by_med_b(ps, half_array_a[2], 1);
	}
	else if (x == 6)
	{
		sort_by_med_a(ps, half_array_b[1], 1);
		sort_by_med_b(ps, half_array_b[2], 1);
	}
}

void		sort_by_median_over_200(p_a *ps)
{
	int	*half_array_a;
	int *half_array_b;
	int x;
	int y;
	int z;
	int stop_at;

	half_array_a = make_halving_array(ps->size, 'a');
	half_array_b = make_halving_array(ps->size, 'b');
	sort_by_med_a(ps, ps->size, 0);
	x = 0;
	y = 0;

	// while (x < 8)
	// {
	// 	if (x == 0 || x == 5 || x == 6)
	// 		big_loop_2(ps, half_array_a, half_array_b, x);
	// 	else if (x == 1 || x == 2 || x == 3 || x == 7)
	// 		big_loop_1(ps, half_array_a, half_array_b, x);
	// 	else if (x == 4)
	// 	{
	// 		sort_by_med_a(ps, half_array_a[0], 1);
	// 		sort_by_med_b(ps, half_array_b[1], 1);
	// 		sort_by_med_b(ps, half_array_b[2], 1);
	// 	}
	// 	do_7_lines(ps, half_array_a, half_array_b);
	// 	x++;
	// }

/* 0 */
	sort_by_med_b(ps, half_array_b[0], 0);
	sort_by_med_b(ps, half_array_b[1], 0);
	sort_by_med_b(ps, half_array_b[2], 0);
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);
	push_amount_to_b(ps, half_array_b[3]);
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);

/* 1 */
	sort_by_med_a(ps, half_array_b[1], 1);
	// sort_by_med_b(ps, half_array_a[2], 0);
	// stop_at = get_highest_from_stack(ps->b, ps->len_b);
	// do_insert_4_sort(ps, 4);
	// push_into_place(ps, stop_at);
	// push_amount_to_b(ps, half_array_a[3]);
	// stop_at = get_highest_from_stack(ps->b, ps->len_b);
	// do_insert_4_sort(ps, 4);
	// push_into_place(ps, stop_at);

// /* 2 */
// 	sort_by_med_a(ps, half_array_a[1], 1);
// 	sort_by_med_b(ps, half_array_b[2], 0);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);
// 	push_amount_to_b(ps, half_array_b[3]);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);

// /* 3 */
// 	sort_by_med_a(ps, half_array_b[2], 1);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);
// 	push_amount_to_b(ps, half_array_b[3]);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);

// /* 4 */
// 	sort_by_med_a(ps, half_array_a[0], 1);
// 	sort_by_med_b(ps, half_array_b[1], 1);
// 	sort_by_med_b(ps, half_array_b[2], 1);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);
// 	push_amount_to_b(ps, half_array_b[3]);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);

// /* 5 */
// 	sort_by_med_a(ps, half_array_b[1], 1);
// 	sort_by_med_b(ps, half_array_b[2], 1);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);
// 	push_amount_to_b(ps, half_array_b[3]);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);

// /* 6 */
// 	sort_by_med_a(ps, half_array_a[1], 1);
// 	sort_by_med_b(ps, half_array_b[2], 1);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);
// 	push_amount_to_b(ps, half_array_b[3]);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);

// /* 7 */
// 	sort_by_med_a(ps, half_array_a[2], 1);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);
// 	push_amount_to_b(ps, half_array_a[3]);
// 	stop_at = get_highest_from_stack(ps->b, ps->len_b);
// 	do_insert_4_sort(ps, 4);
// 	push_into_place(ps, stop_at);

	ft_printf("half_arrayA[0]: %d\tA[1]: %d\tA[2]: %d\tA[3]: %d\n", half_array_a[0], half_array_a[1], half_array_a[2], half_array_a[3]);
	ft_printf("half_arrayB[0]: %d\tB[1]: %d\tB[2]: %d\tB[3]: %d\n", half_array_b[0], half_array_b[1], half_array_b[2], half_array_b[3]);
}

void		sort_by_median(p_a *ps)
{
	int sorted_half;
	int loops;
	int	*half_array_a;
	int *half_array_b;
	int x;
	int stop_at;

	sorted_half = ps->size;
	loops = find_loops(ps->size);
	half_array_a = make_halving_array(ps->size, 'a');
	half_array_b = make_halving_array(ps->size, 'b');
	// return ;
	sort_by_med_a(ps, ps->size, 0);
	sort_by_med_b(ps, half_array_b[0], 0);
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);
	if ((half_array_a[0] == half_array_b[0]) && (half_array_a[1] != half_array_b[1]))
		push_to_b(ps, half_array_b);
	else
		second_push_to_b(ps, half_array_b);
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);
	sort_by_med_a(ps, half_array_a[0], 1);
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);
	second_push_to_b(ps, half_array_a);
	stop_at = get_highest_from_stack(ps->b, ps->len_b);
	do_insert_4_sort(ps, 4);
	push_into_place(ps, stop_at);
	ft_printf("half_arrayA[0]: %d\tA[1]: %d\tA[2]: %d\tA[3]: %d\n", half_array_a[0], half_array_a[1], half_array_a[2], half_array_a[3]);
	ft_printf("half_arrayB[0]: %d\tB[1]: %d\tB[2]: %d\tB[3]: %d\n", half_array_b[0], half_array_b[1], half_array_b[2], half_array_b[3]);

	// sort_a_by_median(ps, sorted_half, loops, half_array_a);
	// sort_a_by_median_part_2(ps, sorted_half, loops, half_array_a);
	// ft_printf("loops: %d\n", loops);
	// ft_printf("array0: %d\tarray[1]: %d\tarray[2]: %d\tarray[3]: %d\n", half_array_a[0], half_array_a[1], half_array_a[2], half_array_a[3]);
	// sort_b_by_median(ps, sorted_half, loops);
	// sort_b_by_median_part_2(ps, sorted_half, loops);
	// push_all_to_a(ps);
	// ft_printf("unordered left on a: %d\n", find_unordered_ascending(ps->a, ps->len_a));
	// ft_printf("unordered left on b: %d\n", find_unordered_descending(ps->b, ps->len_b));
}
