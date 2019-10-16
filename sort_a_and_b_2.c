/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_a_and_b_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 13:03:42 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 13:06:33 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_int_variables(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

static void	finish_sort_b_function(t_ps *ps, int pushed, int rotated, int inoff)
{
	int median;

	ps->a_value = pushed;
	ps->a_done = 0;
	median = rotated;
	while (median > 0 && inoff == 1)
	{
		reverse_b(ps);
		median--;
	}
	if (pushed < 3)
		check_swap(ps, 'a');
}

void		sort_b_by_half2(t_ps *ps, t_blist *list, int len, int inoffensive)
{
	int median;
	int x;
	int pushed;
	int rotated;

	median = find_median(ps->b, len);
	init_int_variables(&x, &pushed, &rotated);
	while (x < len)
	{
		if (check_amount_left_to_push_b(ps, len, x, median) == 0)
		{
			change_end_list_value(list, rotated + (len - x));
			return (smart_sort_finish_b2(ps, len, rotated, pushed));
		}
		if (ps->b[0] > median)
			pushed += push_a(ps);
		else
			rotated += rotate_b(ps);
		x++;
	}
	change_end_list_value(list, rotated);
	finish_sort_b_function(ps, pushed, rotated, inoffensive);
	if (len < 5)
		check_swap(ps, 'b');
}

static void	finish_sort_a_function(t_ps *ps, int pushed, int rotated)
{
	int median;

	median = rotated;
	while (median > 0)
	{
		reverse_a(ps);
		median--;
	}
	ps->a_value = rotated;
	ps->a_done = 0;
	if (pushed < 3)
		check_swap(ps, 'b');
}

void		sort_a_by_half2(t_ps *ps, t_blist *list, int len)
{
	int median;
	int x;
	int pushed;
	int rotated;

	median = find_median(ps->a, len);
	init_int_variables(&x, &pushed, &rotated);
	while (x < len)
	{
		if (check_amount_left_to_push_a(ps, len, x, median) == 0)
		{
			add_to_list_end(list, pushed);
			ps->a_value = rotated + (len - x);
			return (smart_sort_finish_a_inoff2(ps, len, rotated, pushed));
		}
		if (ps->a[0] <= median)
			pushed += push_b(ps);
		else
			rotated += rotate_a(ps);
		x++;
	}
	add_to_list_end(list, pushed);
	finish_sort_a_function(ps, pushed, rotated);
	if (len <= 4)
		check_swap(ps, 'a');
}
