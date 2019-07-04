/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:26:42 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/04 13:48:56 by rcorke        ########   odam.nl         */
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

void	push_a(p_a *ps)
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
		ft_printf("\npa");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	push_b(p_a *ps)
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
		ft_printf("\npb");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	swap_a(p_a *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[0];
		ps->a[0] = ps->a[1];
		ps->a[1] = ps->temp;
		ps->ret++;
		ft_printf("\nsa");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	swap_b(p_a *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[0];
		ps->b[0] = ps->b[1];
		ps->b[1] = ps->temp;
		ps->ret++;
		ft_printf("\nsb");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	swap_both(p_a *ps)
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
		ft_printf("\nss");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	rotate_a(p_a *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[0];
		ft_rev_int_mem_move(&ps->a[0], &ps->a[1], ps->len_a, \
		ps->temp);
		ps->ret++;
		ft_printf("\nra");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	rotate_b(p_a *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[0];
		ft_rev_int_mem_move(&ps->b[0], &ps->b[1], ps->len_b, \
		ps->temp);
		ps->ret++;
		ft_printf("\nrb");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	rotate_both(p_a *ps)
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
		ft_printf("\nrr");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	reverse_a(p_a *ps)
{
	if (ps->len_a > 1)
	{
		ps->temp = ps->a[ps->len_a - 1];
		ft_rev_int_mem_move(&ps->a[1], &ps->a[0], ps->len_a, \
		ps->temp);
		ps->a[0] = ps->temp;
		ps->ret++;
		ft_printf("\nrra");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	reverse_b(p_a *ps)
{
	if (ps->len_b > 1)
	{
		ps->temp = ps->b[ps->len_b - 1];
		ft_rev_int_mem_move(&ps->b[1], &ps->b[0], ps->len_b, \
		ps->temp);
		ps->b[0] = ps->temp;
		ps->ret++;
		ft_printf("\nrrb");
		if (ps->print == 1)
			print_arrays(ps);
	}
}

void	reverse_both(p_a *ps)
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
		ft_printf("\nrrr");
		if (ps->print == 1)
			print_arrays(ps);
	}
}
