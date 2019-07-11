/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easy_peasy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sandRICH <sandRICH@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 00:12:23 by sandRICH       #+#    #+#                */
/*   Updated: 2019/07/12 01:46:53 by sandRICH      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_or_rotate(p_a *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		if (ps->b[0] > ps->a[1])
		{
			push_b(ps);
			rotate_b(ps);
		}
		else if (ps->b[0] > ps->a[0])
		{
			push_b(ps);
			swap_b(ps);
		}
		else
			push_b(ps);	
	}
	else
	{
		if (ps->a[0] > ps->b[1])
		{
			push_a(ps);
			rotate_a(ps);
		}
		else if (ps->a[0] > ps->b[0])
		{
			push_a(ps);
			swap_a(ps);
		}
		else
			push_a(ps);
	}
}

void easy_peasy(p_a * ps)
{
	int x;
	int y;
	int stop;

	y = 0;
	x = 0;
	stop = ps->size;
	push_b(ps);
	push_b(ps);
	if (ps->b[0] > ps->b[1])
		swap_b(ps);
	while (y < stop + 10)
	{
		
		while (ps->len_a > 0)
			swap_or_rotate(ps, 'b');
		while (x < stop)
		{
			push_a(ps);
			x++;
		}
		// while (x < ps->size)
		// {
		// 	if (ps->a[0] > ps->a[1])
		// 		swap_a(ps);
		// 	else
		// 	{
		// 		rotate_a(ps);
		// 	}
		// 	x++;
		// }
		x = 0;
		y++;
	}
}