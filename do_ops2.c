/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 12:41:51 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/22 10:25:58 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_int_mem_move(int *dst, int *src, int len)
{
	int	x;

	x = 0;
	if ((size_t)src > (size_t)dst)
	{
		while (x < len)
		{
			dst[x] = src[x];
			x++;
		}
	}
	else
	{
		len -= 2;
		while (len >= 0)
		{
			dst[len] = src[len];
			len--;
		}
	}
}

void	ft_rev_int_mem_move(int *dst, int *src, int len, int temp)
{
	int	x;

	x = 0;
	if ((size_t)src > (size_t)dst)
	{
		while (x < len - 1)
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = temp;
	}
	else
	{
		len -= 2;
		while (len >= 0)
		{
			dst[len] = src[len];
			len--;
		}
	}
}

int		push_a(t_ps *ps)
{
	if (ps->len_b > 0)
	{
		ps->temp = ps->b[0];
		ft_int_mem_move(&ps->b[0], &ps->b[1], ps->size);
		ps->b[ps->size - 1] = 0;
		ft_int_mem_move(&ps->a[1], &ps->a[0], ps->size);
		ps->a[0] = ps->temp;
		ps->len_b--;
		ps->len_a++;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "pa");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

int		push_b(t_ps *ps)
{
	if (ps->len_a > 0)
	{
		ps->temp = ps->a[0];
		ft_int_mem_move(&ps->a[0], &ps->a[1], ps->size);
		ps->a[ps->size - 1] = 0;
		ft_int_mem_move(&ps->b[1], &ps->b[0], ps->size);
		ps->b[0] = ps->temp;
		ps->len_b++;
		ps->len_a--;
		ps->ret++;
		if (ps->check == 0)
			add_to_command_list(ps, "pb");
		if (ps->print_stacks == 1)
			print_arrays(ps);
	}
	return (1);
}

void	check_swap(t_ps *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		if (ps->len_a > 1 && ps->a[0] > ps->a[1] && \
		ps->len_b > 1 && ps->b[0] < ps->b[1])
			swap_both(ps);
		else if (ps->len_a > 1 && ps->a[0] > ps->a[1])
			swap_a(ps);
	}
	else
	{
		if (ps->len_b > 1 && ps->b[0] < ps->b[1] && \
		ps->len_a > 1 && ps->a[0] > ps->a[1])
			swap_both(ps);
		else if (ps->len_b > 1 && ps->b[0] < ps->b[1])
			swap_b(ps);
	}
}
