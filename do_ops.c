/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 12:38:29 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/22 16:56:11 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arrays(t_ps *ps)
{
	int x;

	x = 0;
	ft_printf("\n\033[1;34mSTACK A[%d]:\t", ps->len_a);
	while (x < ps->len_a)
	{
		ft_printf(" \033[0m\033[1;34m%d\033[0m\t", ps->a[x]);
		x++;
	}
	x = 0;
	ft_printf("\n\n\033[01;33mSTACK B[%d]:\t", ps->len_b);
	while (x < ps->len_b)
	{
		ft_printf(" \033[01;33m%d\033[0m\t", ps->b[x]);
		x++;
	}
	x = 0;
	ft_printf("\033[0m\n");
	ft_printf("A_VALUE: %d (DONE %d)\n", ps->a_value, ps->a_done);
}

int		rotate_both(t_ps *ps)
{
	if (ps->len_a > 1 && ps->len_b > 1)
	{
		ps->temp = ps->a[0];
		ft_rev_int_mem_move(&ps->a[0], &ps->a[1], ps->len_a, \
		ps->temp);
		ps->temp = ps->b[0];
		ft_rev_int_mem_move(&ps->b[0], &ps->b[1], ps->len_b, \
		ps->temp);
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "rr");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		reverse_a(t_ps *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[ps->len_a - 1];
		ft_rev_int_mem_move(&ps->a[1], &ps->a[0], ps->len_a, \
		ps->temp);
		ps->a[0] = ps->temp;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "rra");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		reverse_b(t_ps *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[ps->len_b - 1];
		ft_rev_int_mem_move(&ps->b[1], &ps->b[0], ps->len_b, \
		ps->temp);
		ps->b[0] = ps->temp;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "rrb");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		reverse_both(t_ps *ps)
{
	if (ps->len_a > 1 && ps->len_b > 1)
	{
		ps->temp = ps->a[ps->len_a - 1];
		ft_rev_int_mem_move(&ps->a[1], &ps->a[0], ps->len_a, \
		ps->temp);
		ps->a[0] = ps->temp;
		ps->temp = ps->b[ps->len_b - 1];
		ft_rev_int_mem_move(&ps->b[1], &ps->b[0], ps->len_b, \
		ps->temp);
		ps->b[0] = ps->temp;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "rrr");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}
