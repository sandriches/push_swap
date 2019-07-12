/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easy_peasy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sandRICH <sandRICH@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/12 00:12:23 by sandRICH       #+#    #+#                */
/*   Updated: 2019/07/12 18:41:33 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_temp_ordered_array(int *array)
{
	int x = 1;

	while (x < 21)
	{
		array[x] = x - 1;
		x++;
	}
}

static void	fill_temp_ordered_reverse_array(int *array)
{
	int x = 0;
	int y = 20;
	
	while (x < 20)
	{
		array[x] = y;
		x++;
		y--;
	}
}

static int	are_in_order(p_a *ps, int a, int b, int *ordered_array)
{
	int x;

	x = 0;
	while (x < ps->size - 1)
	{
		// ft_printf("in are_in_order_b - a:%d\tb:%d\n", a, b);
		if (ordered_array[x] == a)
		{
			if (ordered_array[x + 1] == b)
				return (1);
			else
				return (0);
		}
		x++;
	}
	return (0);
}

static int	get_ordered_descending(p_a *ps, int *ordered_array, char which_stack)
{
	int x;
	int ordered;
	int stop;

	x = 0;
	ordered = 0;
	stop = (which_stack == 'b') ? ps->len_b : ps->len_a;
	while (x < stop - 1)
	{
		if (which_stack == 'b')
		{
			if (are_in_order(ps, ps->b[x], ps->b[x + 1], ordered_array) == 1)
				ordered++;
			else
				return (ordered);
		}
		else
		{
			if (are_in_order(ps, ps->a[x], ps->a[x + 1], ordered_array) == 1)
				ordered++;
			else
				return (ordered);
		}
		x++;
	}
	return (ordered);
}

static int	get_ordered_ascending(p_a *ps, int *ordered_array, char which_stack)
{
	int x;
	int ordered;
	int stop;

	x = 0;
	ordered = 0;
	stop = (which_stack == 'b') ? ps->len_b : ps->len_a;
	while (x < stop - 1)
	{
		if (which_stack == 'a')
		{
			if (are_in_order(ps, ps->a[x], ps->a[x + 1], ordered_array) == 1)
				ordered++;
			else
				return (ordered);
		}
		else
		{
			if (are_in_order(ps, ps->b[x], ps->b[x + 1], ordered_array) == 1)
				ordered++;
			else
				return (ordered);
		}		
		x++;
	}
	return (ordered);
}

static void	swap_or_rotate(p_a *ps, char which_stack)
{
	if (which_stack == 'a')
	{
		push_b(ps);
		if (ps->len_b < 3)
		{
			if (ps->b[0] > ps->b[1])
				rotate_b(ps);
		}
		else
		{
			if (ps->b[0] > ps->b[2])
				rotate_b(ps);
			else if (ps->b[0] > ps->b[1])
				swap_b(ps);
		}
	}
	else
	{
		push_a(ps);
		if (ps->len_a < 3)
		{
			if (ps->a[0] < ps->a[1])
			{
				ft_printf("which stack - b, first if\n");
				rotate_a(ps);
			}
		}
		else
		{
			if (ps->a[0] < ps->a[2])
			{		
				ft_printf("which stack - b, second if\n");
				rotate_a(ps);
			}
			else if (ps->a[0] < ps->a[1])
			{
				ft_printf("which stack - b, second if\n");
				swap_a(ps);
			}
		}
	}
}

void easy_peasy(p_a *ps)
{
	int x;
	int y;
	int z;
	int i;
	int stop;
	int *ordered_array;
	int *rev_ordered_array;

	ordered_array = (int *)malloc(sizeof(int) * 20);
	rev_ordered_array = (int *)malloc(sizeof(int) * 20);
	fill_temp_ordered_array(ordered_array);
	fill_temp_ordered_reverse_array(rev_ordered_array);
	y = 0;
	x = 0;
	stop = ps->size;
	push_b(ps);
	push_b(ps);
	if (ps->b[0] < ps->b[1])
		swap_b(ps);
	z = 0;
	while (y < 3)
	{
		while (ps->len_a > z)
			swap_or_rotate(ps, 'a');
		ft_printf("[1]END OF SWAP OR ROTATE, BEGIN saving those ordered (LOW)\n");
		i = get_ordered_descending(ps, ordered_array, 'b');
		x = i;
		while (i >= 0)
		{
			rotate_b(ps);
			i--;
			z++;
		}
		while (ps->len_a > 0)
		{
			push_b(ps);
			rotate_b(ps);
		}
		// if (y == 1)
		// 	return ;
		ft_printf("[1]END OF SAVING BIGGEST AND SMALLEST, BACK 2 SWAP OR ROTATE\n");
		while (ps->len_b > z)
			swap_or_rotate(ps, 'b');
		ft_printf("[2]END OF SWAP OR ROTATE, BEGIN SAVING BIGGEST AND SMALLEST\n");
		// return ;
		i = get_ordered_ascending(ps, rev_ordered_array, 'a');
		while (i >= 0)
		{
			rotate_a(ps);
			i--;
			z++;
		}
		while (ps->len_b > 0)
		{
			push_a(ps);
			rotate_a(ps);
		}
		ft_printf("[2]END OF SAVING BIGGEST AND SMALLEST, BACK 2 SWAP OR ROTATE\n");
		y++;
	}
	x = 0;
	while (x < 5)
	{
		y = get_ordered_ascending(ps, ordered_array, 'a');
		z = get_ordered_descending(ps, rev_ordered_array, 'a');
		ft_printf("NEW GO: Z: %d\tY: %d\n", z, y);
		if (y > z)
		{
			while (y >= 0)
			{
				rotate_a(ps);
				y--;
			}
		}
		else
		{
			while (z >= 0)
			{
				push_b(ps);
				z--;
			}
		}
		x++;
	}
}