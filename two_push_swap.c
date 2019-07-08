/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   two_push_swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 10:20:29 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/08 18:26:28 by rcorke        ########   odam.nl         */
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

static void do_insert_4_sort(p_a *ps)
{
	while (ps->len_b > 4)
	{
		grab_4_from_b(ps, ps->len_b);
		// ft_printf("SORT 4 ALONE A: \n");
		sort_4_not_alone_a(ps);
		// ft_printf("FINISHED SORT 4\n");
	}
	while (ps->len_b > 0)
		push_a(ps);
	// ft_printf("SORT 4 ALONE A: \n");
	sort_4_not_alone_a(ps);
	// ft_printf("FINISHED SORT 4\n");
}

static void	half_a(p_a *ps, int size)
{
	sort_by_med_a(ps, size, 1);
	if (ps->len_a > 10)
	{
		half_a(ps, ps->len_a);
		do_insert_4_sort(ps);
		// bring_back_ints(ps, size);
	}
}

void		ft_ps_half(p_a *ps)
{
	half_a(ps, ps->len_a);
}