/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops3.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 12:44:41 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/22 10:26:14 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		swap_a(t_ps *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = ps->temp;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "sa");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		swap_b(t_ps *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = ps->temp;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "sb");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		swap_both(t_ps *ps)
{
	if (ps->len_b > 1 && ps->len_a > 1)
	{
		ps->temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = ps->temp;
		ps->temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = ps->temp;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "ss");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		rotate_a(t_ps *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[0];
		ft_rev_int_mem_move(&ps->a[0], &ps->a[1], ps->len_a, \
		ps->temp);
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "ra");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		rotate_b(t_ps *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[0];
		ft_rev_int_mem_move(&ps->b[0], &ps->b[1], ps->len_b, \
		ps->temp);
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "rb");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}
