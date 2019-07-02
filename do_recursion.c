/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_recursion.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/02 11:47:53 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/02 12:39:11 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		do_recursion_a(p_a *ps, int start_loop, int *half_array, int old_len)
{
	int x;
	int y;

	x = start_loop;
	if (ps->len_a <= old_len + 4)
	{
		sort_4_not_alone_a(ps);
		return ;
	}
	else
	{
		sort_by_med_b(ps, half_array[start_loop], 1);
		sort_by_med_a(ps, half_array[start_loop - 1], 1);
		do_recursion_a(ps, start_loop--, half_array, old_len);
	}
}
