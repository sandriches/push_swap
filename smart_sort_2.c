/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smart_sort_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 12:39:07 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 12:42:15 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		smart_sort_finish_b2(t_ps *ps, int len, int rotated, int pushed)
{
	ps->a_value = pushed;
	ps->a_done = 0;
	while (rotated > 0)
	{
		reverse_b(ps);
		rotated--;
	}
	if (pushed < 3)
		check_swap(ps, 'a');
	if (len < 5)
		check_swap(ps, 'b');
}

void		smart_sort_finish_a_inoff2(t_ps *ps, int len, int rotated, \
int pushed)
{
	while (rotated > 0)
	{
		reverse_a(ps);
		rotated--;
	}
	ps->a_done = 0;
	if (pushed < 3)
		check_swap(ps, 'b');
	if (len <= 5)
		check_swap(ps, 'a');
}

void		smart_sort_finish_a_off2(t_ps *ps, int len, int pushed)
{
	ps->a_done = 0;
	if (pushed < 3)
		check_swap(ps, 'b');
	if (len <= 5)
		check_swap(ps, 'a');
}
