/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:26:42 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/03 16:42:54 by rcorke        ########   odam.nl         */
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
		len-= 2;
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
		len-= 2;
		while (len >= 0)
		{
			dst[len] = src[len];
			len--;
		}
	}
}

void	push_a(p_a *pa)
{
	if (pa->len_b > 0)
	{
		pa->temp = pa->b[0];
		ft_int_mem_move(&pa->b[0], &pa->b[1], pa->size);
		pa->b[pa->size - 1] = 0;
		ft_int_mem_move(&pa->a[1], &pa->a[0], pa->size);
		pa->a[0] = pa->temp;
		pa->len_b--;
		pa->len_a++;
		pa->ret++;
		ft_printf("\npa:");
		print_arrays(pa);
	}
}

void	push_b(p_a *pa)
{
	if (pa->len_a > 0)
	{
		pa->temp = pa->a[0];
		ft_int_mem_move(&pa->a[0], &pa->a[1], pa->size);
		pa->a[pa->size - 1] = 0;
		ft_int_mem_move(&pa->b[1], &pa->b[0], pa->size);
		pa->b[0] = pa->temp;
		pa->len_b++;
		pa->len_a--;
		pa->ret++;
		ft_printf("\npb:");
		print_arrays(pa);
	}
}

void	swap_a(p_a *pa)
{
	if (pa->len_a > 1)
	{
		pa->temp = pa->a[0];
		pa->a[0] = pa->a[1];
		pa->a[1] = pa->temp;
		pa->ret++;
		ft_printf("\nsa:");
		print_arrays(pa);
	}
}

void	swap_b(p_a *pa)
{
	if (pa->len_b > 1)
	{
		pa->temp = pa->b[0];
		pa->b[0] = pa->b[1];
		pa->b[1] = pa->temp;
		pa->ret++;
		ft_printf("\nsb:");
		print_arrays(pa);
	}
}

void	rotate_a(p_a *pa)
{
	if (pa->a[0] != 0)
	{
		pa->temp = pa->a[0];
		ft_rev_int_mem_move(&pa->a[0], &pa->a[1], pa->len_a, \
		pa->temp);
		pa->ret++;
		ft_printf("\nra:");
		print_arrays(pa);
	}
}

void	rotate_b(p_a *pa)
{
	if (pa->b[0] != 0)
	{
		pa->temp = pa->b[0];
		ft_rev_int_mem_move(&pa->b[0], &pa->b[1], pa->len_b, \
		pa->temp);
		pa->ret++;
		ft_printf("\nrb:");
		print_arrays(pa);
	}
}

void	reverse_a(p_a *pa)
{
	if (pa->a[0] != 0)
	{
		pa->temp = pa->a[pa->len_a - 1];
		ft_rev_int_mem_move(&pa->a[1], &pa->a[0], pa->len_a, \
		pa->temp);
		pa->a[0] = pa->temp;
		pa->ret++;
		ft_printf("\nrra:");
		print_arrays(pa);
	}
}

void	reverse_b(p_a *pa)
{
	if (pa->b[0] != 0)
	{
		pa->temp = pa->b[pa->len_b - 1];
		ft_rev_int_mem_move(&pa->b[1], &pa->b[0], pa->len_b, \
		pa->temp);
		pa->b[0] = pa->temp;
		pa->ret++;
		ft_printf("\nrrb:");
		print_arrays(pa);
	}
}