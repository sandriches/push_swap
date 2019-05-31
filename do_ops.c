/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:26:42 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/31 18:50:23 by rcorke        ########   odam.nl         */
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

int		find_length(int *array, int len)
{
	int x;

	x = 0;
	while (x < len)
	{
		if (array[x] == 0)
			break ;
		x++;
	}
	return (x);
}

void	ft_rev_int_mem_move(int *dst, int *src, int len, int temp)
{
	int	x;

	len = find_length(src, len);
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
	if (pa->b[0] != 0)
	{
		pa->temp = pa->b[0];
		ft_int_mem_move(&pa->b[0], &pa->b[1], pa->size);
		pa->b[pa->size - 1] = 0;
		ft_int_mem_move(&pa->a[1], &pa->a[0], pa->size);
		pa->a[0] = pa->temp;
		ft_printf("\npa:");
	}
}

void	push_b(p_a *pa)
{
	if (pa->a[0] != 0)
	{
		pa->temp = pa->a[0];
		ft_int_mem_move(&pa->a[0], &pa->a[1], pa->size);
		pa->a[pa->size - 1] = 0;
		ft_int_mem_move(&pa->b[1], &pa->b[0], pa->size);
		pa->b[0] = pa->temp;
		ft_printf("\npb:");
	}
}

void	swap_a(p_a *pa)
{
	if (find_length(pa->a, pa->size) > 1)
	{
		pa->temp = pa->a[0];
		pa->a[0] = pa->a[1];
		pa->a[1] = pa->temp;
		ft_printf("\nsa:");
	}
}

void	swap_b(p_a *pa)
{
	if (find_length(pa->b, pa->size) > 1)
	{
		pa->temp = pa->b[0];
		pa->b[0] = pa->b[1];
		pa->b[1] = pa->temp;
		ft_printf("\nsb:");
	}
}

void	rotate_a(p_a *pa)
{
	if (pa->a[0] != 0)
	{
		pa->temp = pa->a[0];
		ft_rev_int_mem_move(&pa->a[0], &pa->a[1], pa->size, \
		pa->temp);
		ft_printf("\nra:");
	}
}

void	rotate_b(p_a *pa)
{
	if (pa->b[0] != 0)
	{
		pa->temp = pa->b[0];
		ft_rev_int_mem_move(&pa->b[0], &pa->b[1], pa->size, \
		pa->temp);
		ft_printf("\nrb:");
	}
}

void	reverse_a(p_a *pa)
{
	int len;

	if (pa->a[0] != 0)
	{
		len = find_length(pa->a, pa->size);
		pa->temp = pa->a[len - 1];
		ft_rev_int_mem_move(&pa->a[1], &pa->a[0], pa->size, \
		pa->temp);
		pa->a[0] = pa->temp;
		ft_printf("\nrra:");
	}
}

void	reverse_b(p_a *pa)
{
	int len;

	if (pa->b[0] != 0)
	{
		len = find_length(pa->b, pa->size);
		pa->temp = pa->b[len - 1];
		ft_rev_int_mem_move(&pa->b[1], &pa->b[0], pa->size, \
		pa->temp);
		pa->b[0] = pa->temp;
		ft_printf("\nrrb:");
	}
}