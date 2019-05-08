/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_ops.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:26:42 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/02 15:35:31 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_int_mem_move(int *dst, int *src, int len)
{
	int	x;

	x = 0;
	if ((size_t)src > (size_t)dst)
		while (x < len)
		{
			dst[x] = src[x];
			x++;
		}
	else
	{
		len--;
		while (len >= 0)
		{
			dst[len] = src[len];
			len--;
		}
	}
}

static int	find_length(int *array, int len)
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
		while (x < len)
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

void	push_a(p_a *push_struct)
{
	if (push_struct->b[0] != 0)
	{
		push_struct->temp = push_struct->b[0];
		ft_int_mem_move(&push_struct->b[0], &push_struct->b[1], push_struct->size);
		push_struct->b[push_struct->size - 1] = 0;
		ft_int_mem_move(&push_struct->a[1], &push_struct->a[0], push_struct->size);
		push_struct->a[0] = push_struct->temp;
	}
}

void	push_b(p_a *push_struct)
{
	if (push_struct->a[0] != 0)
	{
		push_struct->temp = push_struct->a[0];
		ft_int_mem_move(&push_struct->a[0], &push_struct->a[1], push_struct->size);
		push_struct->a[push_struct->size - 1] = 0;
		ft_int_mem_move(&push_struct->b[1], &push_struct->b[0], push_struct->size);
		push_struct->b[0] = push_struct->temp;
	}
}

void	swap_a(p_a *push_struct)
{
	if (find_length(push_struct->a, push_struct->size) > 1)
	{
		push_struct->temp = push_struct->a[0];
		push_struct->a[0] = push_struct->a[1];
		push_struct->a[1] = push_struct->temp;
	}
}

void	swap_b(p_a *push_struct)
{
	if (find_length(push_struct->b, push_struct->size) > 1)
	{
		push_struct->temp = push_struct->b[0];
		push_struct->b[0] = push_struct->b[1];
		push_struct->b[1] = push_struct->temp;
	}
}

void	rotate_a(p_a *push_struct)
{
	if (push_struct->a[0] != 0)
	{
		push_struct->temp = push_struct->a[0];
		ft_rev_int_mem_move(&push_struct->a[0], &push_struct->a[1], push_struct->size, \
		push_struct->temp);
	}
}

void	rotate_b(p_a *push_struct)
{
	if (push_struct->b[0] != 0)
	{
		push_struct->temp = push_struct->b[0];
		ft_rev_int_mem_move(&push_struct->b[0], &push_struct->b[1], push_struct->size, \
		push_struct->temp);
	}
}

void	reverse_a(p_a *push_struct)
{
	int len;

	if (push_struct->a[0] != 0)
	{
		len = find_length(push_struct->a, push_struct->size);
		push_struct->temp = push_struct->a[len - 1];
		ft_rev_int_mem_move(&push_struct->a[1], &push_struct->a[0], push_struct->size, \
		push_struct->temp);
		push_struct->a[0] = push_struct->temp;
	}
}

void	reverse_b(p_a *push_struct)
{
	int len;

	len = find_length(push_struct->b, push_struct->size);
	push_struct->temp = push_struct->b[len - 1];
	ft_rev_int_mem_move(&push_struct->b[1], &push_struct->b[0], push_struct->size, \
	push_struct->temp);
	push_struct->b[0] = push_struct->temp;
}