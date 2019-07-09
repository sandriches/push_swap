/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3_or_4_not_alone.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/25 14:48:18 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 15:43:03 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_swap_sort_2_3_4(p_a *ps)
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

void		sort_3_not_alone_a(p_a *ps)
{
	if (find_unordered_ascending(ps->a, 3) == 0)
		return ;
	if (return_3_int(ps->a[0], ps->a[1], ps->a[2], '>') == ps->a[2] && \
	return_3_int(ps->a[0], ps->a[1], ps->a[2], 'M') == ps->a[0])
		return (check_swap(ps, 'a'));
	check_swap(ps, 'a');
	push_b(ps);
	check_swap(ps, 'a');
	push_a(ps);
	check_swap(ps, 'a');
}

void		sort_3_not_alone_b(p_a *ps)
{
	if (find_unordered_descending(ps->b, 3) == 0)
		return ;
	if (return_3_int(ps->b[0], ps->b[1], ps->b[2], '<') == ps->b[2] && \
	return_3_int(ps->b[0], ps->b[1], ps->b[2], 'M') == ps->b[0])
		return (check_swap(ps, 'b'));
	check_swap(ps, 'b');
	push_a(ps);
	check_swap(ps, 'b');
	push_b(ps);
	check_swap(ps, 'b');
}
static void		sort_3_high_low_b(p_a *ps)
{
	if (return_3_int(ps->b[0], ps->b[1], ps->b[2], '>') == ps->b[0])
	{
		rotate_b(ps);
		if (ps->b[1] > ps->b[0])
			swap_b(ps);
	}
	else if (return_3_int(ps->b[0], ps->b[1], ps->b[2], '>') == ps->b[1])
	{
		swap_b(ps);
		rotate_b(ps);
		if (ps->b[1] > ps->b[0])
			swap_b(ps);
	}
	else
	{
		push_a(ps);
		swap_b(ps);
		rotate_b(ps);
		push_b(ps);
		if (ps->b[1] > ps->b[0])
			swap_b(ps);
	}
}

static void	worst_case_4_high_low_b(p_a *ps)
{
	push_a(ps);
	push_a(ps);
	swap_b(ps);
	rotate_b(ps);
	if (return_3_int(ps->b[0], ps->a[0], ps->a[1], '>') == ps->b[0])
	{
		rotate_b(ps);
		push_b(ps);
		push_b(ps);
		if (ps->b[1] > ps->b[0])
			swap_b(ps);
	}
	else if (return_3_int(ps->b[0], ps->a[0], ps->a[1], '>') == ps->a[0])
	{
		push_b(ps);
		rotate_b(ps);
		push_b(ps);
		if (ps->b[1] > ps->b[0])
			swap_b(ps);
	}
	else
	{
		push_b(ps);
		push_b(ps);
		rotate_b(ps);
		if (ps->b[1] > ps->b[0])
			swap_b(ps);
	}
}

void		sort_4_high_low_b(p_a *ps)
{
	if (return_biggest_int_4(ps->b[0], ps->b[1], ps->b[2], ps->b[3]) == ps->b[0])
	{
		rotate_b(ps);
		return (sort_3_high_low_b(ps));
	}
	else if (return_biggest_int_4(ps->b[0], ps->b[1], ps->b[2], ps->b[3]) == ps->b[1])
	{
		swap_b(ps);
		rotate_b(ps);
		return(sort_3_high_low_b(ps));
	}
	else if (return_biggest_int_4(ps->b[0], ps->b[1], ps->b[2], ps->b[3]) == ps->b[2])
	{
		push_a(ps);
		swap_b(ps);
		rotate_b(ps);
		push_b(ps);
		return(sort_3_high_low_b(ps));
	}
	else
		return (worst_case_4_high_low_b(ps));
}

void		sort_4_not_alone_b(p_a *ps)
{
	if (find_unordered_descending(ps->b, 4) == 0)
		return ;
	else if (return_smallest_int_4(ps->b[0], ps->b[1], ps->b[2], ps->b[3]) == ps->b[3])
		return (sort_3_not_alone_b(ps));
	check_swap(ps, 'b');
	push_a(ps);
	check_swap(ps, 'b');
	push_a(ps);
	check_swap_sort_2_3_4(ps);
	if (ps->b[0] > ps->a[0] || ps->b[0] > ps->a[1])
	{
		push_a(ps);
		swap_a(ps);
		push_b(ps);
		check_swap_sort_2_3_4(ps);
	}
	push_b(ps);
	push_b(ps);
}

void		sort_4_not_alone_a(p_a *ps)
{
	if (find_unordered_ascending(ps->a, 4) == 0)
		return ;
	else if (return_biggest_int_4(ps->a[0], ps->a[1], ps->a[2], ps->a[3]) == ps->a[3])
		return (sort_3_not_alone_a(ps));
	check_swap(ps, 'a');
	push_b(ps);
	check_swap(ps, 'a');
	push_b(ps);
	check_swap_sort_2_3_4(ps);
	if (ps->a[0] < ps->b[0] || ps->a[0] < ps->b[1])
	{
		push_b(ps);
		swap_b(ps);
		push_a(ps);
		check_swap_sort_2_3_4(ps);
	}
	push_a(ps);
	check_swap(ps, 'a');
	push_a(ps);
	check_swap(ps, 'a');
}
