/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easy_peasy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sandRICH <sandRICH@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 00:12:23 by sandRICH       #+#    #+#                */
/*   Updated: 2019/07/12 02:31:42 by sandRICH      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_or_rotate(p_a *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		push_b(ps);
		if (ps->len_b <= 1)
		{
			if (ps->b[0] < ps->b[1])
				rotate_b(ps);
		}
		else
		{
			if (ps->b[0] < ps->b[2])
				rotate_b(ps);
			else if (ps->b[0] < ps->b[1])
				swap_b(ps);
		}
	}
	else
	{
		push_a(ps);
		if (ps->len_a <= 1)
		{
			if (ps->a[0] > ps->a[1])
				rotate_a(ps);
		}
		else
		{
			if (ps->a[0] > ps->a[2])
				rotate_a(ps);
			else if (ps->a[0] > ps->a[1])
				swap_a(ps);
		}
	}
}

void easy_peasy(p_a *ps)
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
	while (y < 1)
	{
		while (ps->len_a > 0)
			swap_or_rotate(ps, 'a');
		while (ps->len_b > 0)
			swap_or_rotate(ps, 'b');
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
	if (ps->a[0] > ps->a[1])
		swap_a(ps);
}