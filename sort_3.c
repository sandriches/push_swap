/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 14:57:48 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 17:50:54 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pusha_swapb_pushb(t_ps *ps)
{
	push_a(ps);
	check_swap(ps, 'b');
	push_b(ps);
}

static void	pushb_swapa_pusha(t_ps *ps)
{
	push_b(ps);
	check_swap(ps, 'a');
	push_a(ps);
}

void		sort_3_b(t_ps *ps)
{
	if (ps->len_b < 2 || (ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2] \
	&& ps->b[1] > ps->b[2]))
		return ;
	else if (ps->len_b == 2)
	{
		if (ps->b[0] > ps->b[1])
			check_swap(ps, 'b');
		return ;
	}
	else if (ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2])
		pusha_swapb_pushb(ps);
	else if (ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2] && ps->b[0] > ps->b[2])
		check_swap(ps, 'b');
	else if (ps->b[1] > ps->b[0] && ps->b[1] > ps->b[2])
	{
		check_swap(ps, 'b');
		pusha_swapb_pushb(ps);
	}
	else if (ps->b[2] > ps->b[0] && ps->b[2] > ps->b[1])
	{
		if (ps->b[1] > ps->b[0])
			check_swap(ps, 'b');
		pusha_swapb_pushb(ps);
		check_swap(ps, 'b');
	}
}

void		sort_3_a(t_ps *ps)
{
	if (ps->len_a < 2 || (ps->len_a > 2 && ps->a[0] < ps->a[1] && \
	ps->a[0] < ps->a[2] && ps->a[1] < ps->a[2]))
		return ;
	else if (ps->len_a == 2)
	{
		if (ps->a[0] > ps->a[1])
			check_swap(ps, 'a');
		return ;
	}
	else if (ps->a[0] < ps->a[1] && ps->a[0] < ps->a[2])
		pushb_swapa_pusha(ps);
	else if (ps->a[1] < ps->a[0] && ps->a[1] < ps->a[2] && ps->a[0] < ps->a[2])
		check_swap(ps, 'a');
	else if (ps->a[1] < ps->a[0] && ps->a[1] < ps->a[2])
	{
		check_swap(ps, 'a');
		pushb_swapa_pusha(ps);
	}
	else if (ps->a[2] < ps->a[0] && ps->a[2] < ps->a[1])
	{
		if (ps->a[1] < ps->a[0])
			check_swap(ps, 'a');
		pushb_swapa_pusha(ps);
		check_swap(ps, 'a');
	}
}
