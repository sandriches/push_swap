/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:26:42 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/08 17:29:12 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arrays(p_a *ps)
{
	int x;

	x = 0;
	ft_printf("{BLUE}\n");
	ft_printf("\nSTACK A[%d]:\t", ps->len_a);
	while (x < ps->len_a)
	{
		ft_printf(" {/}{BLUE}%d{/}\t", ps->a[x]);
		x++;
	}
	x = 0;
	ft_printf("\n\n{RED}STACK B[%d]:\t", ps->len_b);
	while (x < ps->len_b)
	{
		ft_printf(" {RED}%d{/}\t", ps->b[x]);
		x++;
	}
	x = 0;
	ft_printf("{/}\n\n\n");
}

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

int		push_a(p_a *ps)
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
		if (ps->print_commands == 1)
			ft_printf("pa\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		push_b(p_a *ps)
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
		if (ps->print_commands == 1)
			ft_printf("pb\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		swap_a(p_a *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = ps->temp;
		ps->ret++;
		if (ps->print_commands == 1)
			ft_printf("sa\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		swap_b(p_a *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = ps->temp;
		ps->ret++;
		if (ps->print_commands == 1)
			ft_printf("sb\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		swap_both(p_a *ps)
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
		if (ps->print_commands == 1)
			ft_printf("ss\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		rotate_a(p_a *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[0];
		ft_rev_int_mem_move(&ps->a[0], &ps->a[1], ps->len_a, \
		ps->temp);
		ps->ret++;
		if (ps->print_commands == 1)
			ft_printf("ra\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		rotate_b(p_a *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[0];
		ft_rev_int_mem_move(&ps->b[0], &ps->b[1], ps->len_b, \
		ps->temp);
		ps->ret++;
		if (ps->print_commands == 1)
			ft_printf("rb\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		rotate_both(p_a *ps)
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
		if (ps->print_commands == 1)
			ft_printf("rr\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		reverse_a(p_a *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[ps->len_a - 1];
		ft_rev_int_mem_move(&ps->a[1], &ps->a[0], ps->len_a, \
		ps->temp);
		ps->a[0] = ps->temp;
		ps->ret++;
		if (ps->print_commands == 1)
			ft_printf("rra\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		reverse_b(p_a *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[ps->len_b - 1];
		ft_rev_int_mem_move(&ps->b[1], &ps->b[0], ps->len_b, \
		ps->temp);
		ps->b[0] = ps->temp;
		ps->ret++;
		if (ps->print_commands == 1)
			ft_printf("rrb\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}

int		reverse_both(p_a *ps)
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
		if (ps->print_commands == 1)
			ft_printf("rrr\n");
		if (ps->print_stacks == 1)
			print_arrays(ps);
		return (1);
	}
	return (0);
}
