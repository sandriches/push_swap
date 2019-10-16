/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smart_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/16 15:35:59 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 12:42:07 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		smart_sort_finish_b(t_ps *ps, int len, int rotated, int pushed)
{
	ps->a_value = pushed;
	ps->a_done = 0;
	while (rotated > 0)
	{
		reverse_b(ps);
		rotated--;
	}
	if (pushed < 4)
		sort_3_a(ps);
	if (len < 7)
		sort_3_b(ps);
}

void		smart_sort_finish_a_inoff(t_ps *ps, int len, int rotated, \
int pushed)
{
	while (rotated > 0)
	{
		reverse_a(ps);
		rotated--;
	}
	ps->a_done = 0;
	if (pushed < 4)
		sort_3_b(ps);
	if (len <= 7)
		sort_3_a(ps);
}

void		smart_sort_finish_a_off(t_ps *ps, int len, int pushed)
{
	ps->a_done = 0;
	if (pushed < 4)
		sort_3_b(ps);
	if (len <= 7)
		sort_3_a(ps);
}
