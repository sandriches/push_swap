/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 10:04:02 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/07 12:26:34 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_swap_insertion_4(p_a *ps)
{
	if (ps->b[0] < ps->b[1] && ps->a[0] > ps->a[1])
		swap_both(ps);
	else
	{
		if (ps->b[0] < ps->b[1])
			swap_b(ps);
		else if (ps->a[0] > ps->a[1])
			swap_a(ps);
	}
}

static void	check_swap_b(p_a *ps)
{
	if (ps->b[0] < ps->b[1])
		swap_b(ps);
}

static void	check_swap_a(p_a *ps)
{
	if (ps->a[0] > ps->a[1])
			swap_a(ps);
}

static int	return_biggest_int(int a, int b, int c, int d)
{
	if (a > b && a > c && a > d)
		return (a);
	else if (b > a && b > c && b > d)
		return (b);
	else if (c > a && c > b && c > d)
		return (c);
	return (d);
}

static int	return_smallest_int(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	else if (b < a && b < c && b < d)
		return (b);
	else if (c < a && c < b && c < d)
		return (c);
	return (d);
}

static int	return_3_int(int a, int b, int c, char sign)
{
	if (sign == '>')
	{
		if (a > b && a > c)
			return (a);
		else if (b > a && b > c)
			return (b);
		return (c);
	}
	else
	{
		if (a < b && a < c)
			return (a);
		else if (b < a && b < c)
			return (b);
		return (c);
	}
}

static int	return_second_biggest_int(int a, int b, int c, int d)
{
	if (return_biggest_int(a, b, c, d) == a)
		return (return_3_int(b, c, d, '>'));
	else if (return_biggest_int(a, b, c, d) == b)
		return (return_3_int(a, c, d, '>'));
	else if (return_biggest_int(a, b, c, d) == c)
		return (return_3_int(a, b, d, '>'));
	else
		return (return_3_int(a, b, c, '>'));
}

static int	return_second_smallest_int(int a, int b, int c, int d)
{
	if (return_smallest_int(a, b, c, d) == a)
		return (return_3_int(b, c, d, '<'));
	else if (return_smallest_int(a, b, c, d) == b)
		return (return_3_int(a, c, d, '<'));
	else if (return_smallest_int(a, b, c, d) == c)
		return (return_3_int(a, b, d, '<'));
	else
		return (return_3_int(a, b, c, '<'));
}

static void	fill_index(int *stack, int len, s_4 *s4)
{
	int x;

	x = 0;
	while (x < len)
	{
		if (stack[x] == s4->smallest && s4->smallest_index < len)
			s4->smallest_index = x;
		else if (stack[x] == s4->s_median && s4->s_median_index < len)
			s4->s_median_index = x;
		else if (stack[x] == s4->l_median && s4->l_median_index < len)
			s4->l_median_index = x;
		else if (stack[x] == s4->largest && s4->largest_index < len)
			s4->largest_index = x;
		x++;
	}
}

static int	find_closest_index(int len, s_4 *s4)
{
	int highest;
	int lowest;

	highest = return_biggest_int(s4->largest_index, s4->l_median_index, s4->s_median_index, s4->smallest_index);
	lowest = return_smallest_int(s4->largest_index, s4->l_median_index, s4->s_median_index, s4->smallest_index);
	if (len - highest < lowest)
		return (highest);
	return (lowest);
}

static void	fill_s4_struct(s_4 *s4, p_a *ps)
{
	s4->smallest = return_smallest_int(ps->b[0], ps->b[1], ps->b[2], ps->b[3]);
	s4->s_median = return_second_smallest_int(ps->b[0], ps->b[1], ps->b[2], ps->b[3]);
	s4->l_median = return_second_biggest_int(ps->b[0], ps->b[1], ps->b[2], ps->b[3]);
	s4->largest = return_biggest_int(ps->b[0], ps->b[1], ps->b[2], ps->b[3]);
}

void		sort_4_not_alone_b(p_a *ps)
{
	for (int i = 0; i < 4; i++)
		push_b(ps);
	if (find_unordered_descending(ps->b, 4) == 0)
		return ;
	if (return_smallest_int(ps->b[0], ps->b[1], ps->b[2], ps->b[3]) == ps->b[3])
		return (sort_3_not_alone_b(ps));
	check_swap_b(ps);
	push_a(ps);
	check_swap_b(ps);
	push_a(ps);
	check_swap_insertion_4(ps);
	if (ps->b[0] > ps->a[0] || ps->b[0] > ps->a[1])
	{
		push_a(ps);
		check_swap_a(ps);
		push_b(ps);
		check_swap_insertion_4(ps);
	}
	push_b(ps);
	push_b(ps);
}

static void		update_index(int len, s_4 *s4, int to_update, int rotated)
{
	if (s4->largest_index == to_update)
		s4->largest_index = len + 1;
	
}

static void		push_index(p_a *ps, s_4 *s4)
{
	int x;
	int closest_index;
	int rotated;

	x = 0;
	rotated = 0;
	closest_index = find_closest_index(ps->len_a, s4);
	if (closest_index < ps->len_a / 2)
	{
		while (x < closest_index)
		{
			rotate_a(ps);
			rotated++;
		}
		push_b(ps);
		update_index(ps->len_a, s4, closest_index, rotated);
	}
}

static void		ps_insertion_sort_4(p_a *ps)
{
	s_4 *s4;
	int counter;

	counter = 0;
	s4 = (s_4 *)malloc(sizeof(s_4));
	fill_s4_struct(s4, ps);
	fill_index(ps->a, ps->len_a, s4);
	while (counter < 4)
	{
		push_index(ps, s4);
	}
}