/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ps_half_100.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 10:20:29 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 14:52:09 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_back_ints(p_a *ps, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		push_b(ps);
		x++;
	}
}

static void do_insert_4_sort(p_a *ps, int size)
{
	while (ps->len_b > 4)
	{
		grab_4_from_b(ps, ps->len_b);
		sort_4_not_alone_a(ps);
	}
	while (ps->len_b > 0)
		push_a(ps);
	sort_4_not_alone_a(ps);
}

static void	half_a(p_a *ps, int size)
{
	static int i;
	i++;
	sort_by_med_a(ps, size, 0);
	if (ps->len_a > 4)
	{
		half_a(ps, ps->len_a);
		sort_4_not_alone_a(ps);
		do_insert_4_sort(ps, size);
	}
}

void		ft_ps_half_100(p_a *ps, int size)
{
	half_a(ps, size);
}