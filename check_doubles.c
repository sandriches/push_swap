/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_doubles.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/24 14:41:22 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/26 15:02:13 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				find_smallest_from_3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	return (c);
}

int				find_biggest_from_3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	return (c);
}

void			check_rotate(p_a *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		if (ps->len_b == 2 && ps->b[0] < ps->b[1])
			return (rotate_both(ps));
		else if (ps->len_b == 3)
			if (find_smallest_from_3(ps->b[0], ps->b[1], ps->b[2]) == ps->b[0])
				return (rotate_both(ps));
		return (rotate_a(ps));
	}
	else
	{
		if (ps->len_a == 2 && ps->a[0] > ps->a[1])
			return (rotate_both(ps));
		else if (ps->len_b == 3)
			if (find_biggest_from_3(ps->a[0], ps->a[1], ps->a[2]) == ps->a[0])
				return (rotate_both(ps));
		return (rotate_b(ps));
	}	
}

void			check_r_rotate(p_a *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		if (ps->len_b == 2 && ps->b[0] < ps->b[1])
			return (rotate_both(ps));
		else if (ps->len_b == 3)
			if (find_smallest_from_3(ps->b[0], ps->b[1], ps->b[2]) == ps->b[1])
				return (rotate_both(ps));
		return (rotate_a(ps));
	}
	else
	{
		if (ps->len_a == 2 && ps->a[0] > ps->a[1])
			return (rotate_both(ps));
		else if (ps->len_b == 3)
			if (find_biggest_from_3(ps->a[0], ps->a[1], ps->a[2]) == ps->a[1])
				return (rotate_both(ps));
		return (rotate_b(ps));
	}	
}

void			check_swap(p_a *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		if ((ps->len_b > 1 && ps->b[0] < ps->b[1]) && ps->len_a > 1 && (ps->a[0] > ps->a[1]))
			swap_both(ps);
		else if (ps->len_a > 1 && ps->a[0] > ps->a[1])
			swap_a(ps);
	}
	else
	{
		if ((ps->len_a > 1 && ps->a[0] > ps->a[1]) && ps->len_b > 1 && (ps->b[0] < ps->b[1]))
			swap_both(ps);
		else if (ps->len_b > 1 && ps->b[0] < ps->b[1])
			swap_b(ps);
	}
}