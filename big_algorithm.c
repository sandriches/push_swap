/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   big_algorithm.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 14:00:31 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/22 16:54:05 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_next_amount_from_b(t_ps *ps, t_blist *list)
{
	int x;

	x = 0;
	while (x < get_end_list_value(list))
	{
		push_a(ps);
		x++;
	}
	if (x < 4)
	{
		sort_3_a(ps);
		ps->a_done = 1;
	}
	else
		ps->a_done = 0;
	pop_list_end(list);
}

static void	a_done_zero(t_ps *ps, t_blist *list)
{
	if (ps->a_value < 4)
	{
		sort_3_a(ps);
		ps->a_done = 1;
	}
	else if (ps->a_value > 3 && ps->a_value < 7)
	{
		sort_a_by_half(ps, list, ps->a_value);
		get_next_amount_from_b(ps, list);
	}
	else
	{
		while (ps->a_value > 3 && ps->a_done == 0)
			sort_a_by_half(ps, list, ps->a_value);
		ps->a_done = 1;
		sort_3_a(ps);
	}
}

void		big_algorithm_three(t_ps *ps)
{
	t_blist	*list;

	list = create_list(ps);
	get_x_from_stack_a(ps, ps->size / 2, ps->size, 0);
	ps->a_done = 0;
	add_to_list_end(list, ps->size / 2);
	while (ps->len_a > 3 && ps->a_done == 0)
		sort_a_by_half(ps, list, ps->len_a);
	while (ps->len_a < ps->size)
	{
		if (ps->a_done == 0)
			a_done_zero(ps, list);
		else if (get_end_list_value(list) < 4)
			get_next_amount_from_b(ps, list);
		else
		{
			sort_b_by_half(ps, list, get_end_list_value(list), 1);
			if (find_unordered_ascending(ps->a, ps->len_a) \
			== 0 && get_end_list_value(list) > 6)
				sort_b_by_half(ps, list, get_end_list_value(list), 1);
		}
	}
	free(list);
}
