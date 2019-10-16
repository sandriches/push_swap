/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_rotates.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 16:58:56 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 12:24:53 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_smallest_from_3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	else
		return (c);
}

static int		find_biggest_from_3(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	else
		return (c);
}

int				check_rotate(t_ps *ps, char which_stack)
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

int				check_r_rotate(t_ps *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		if (ps->len_b == 2 && ps->b[0] < ps->b[1])
			return (rotate_both(ps));
		else if (ps->len_b == 3)
			if (find_smallest_from_3(ps->b[0], ps->b[1], ps->b[2]) == ps->b[1])
				return (rotate_both(ps));
		return (reverse_a(ps));
	}
	else
	{
		if (ps->len_a == 2 && ps->a[0] > ps->a[1])
			return (rotate_both(ps));
		else if (ps->len_b == 3)
			if (find_biggest_from_3(ps->a[0], ps->a[1], ps->a[2]) == ps->a[1])
				return (rotate_both(ps));
		return (reverse_b(ps));
	}
}
