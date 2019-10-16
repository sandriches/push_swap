/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/17 17:27:06 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 16:26:38 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	else if (b < a && b < c && b < d)
		return (b);
	else if (c < a && c < b && c < d)
		return (c);
	return (d);
}

static void	grab_smallest(t_ps *ps, int smallest)
{
	if (ps->a[1] == smallest)
		rotate_a(ps);
	else if (ps->a[2] == smallest)
	{
		reverse_a(ps);
		reverse_a(ps);
	}
	else if (ps->a[3] == smallest)
		reverse_a(ps);
	push_b(ps);
}

void		sort_4(t_ps *ps)
{
	grab_smallest(ps, find_smallest(ps->a[0], ps->a[1], ps->a[2], ps->a[3]));
	sort_3_a(ps);
	push_a(ps);
}
