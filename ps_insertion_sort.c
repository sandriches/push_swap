/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_insertion_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:26:47 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/05 20:59:45 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_index(int *stack, int size)
{
	int x;
	int i;
	int index;

	i = 1;
	x = stack[0];
	index = 0;
	while (i < size)
	{
		ft_printf("stack[i]: %d\tx: %d\n", stack[i], x);
		if (stack[i] < x)
		{
			x = stack[i];
			index = i;
		}
		i++;
	}
	ft_printf("smallest index: %d\tvalue: %d\n", index, x);
	return (index);
}

static void	push_all_to_a(p_a *ps)
{
	int x;
	int size;

	size = ps->len_b;
	x = 0;
	while (x < size)
	{
		push_a(ps);
		x++;
	}
	return ;
}

void		ps_insertion_sort_a(p_a *ps)
{
	static int i;
	int smallest;
	int x;

	if (!i)
		i = 0;
	x = 0;
	ft_printf("len a: %d\tlen b: %d\n", ps->len_a, ps->len_b);
	if (ps->len_a == 0)
		return (push_all_to_a(ps));
	smallest = find_smallest_index(ps->a, ps->len_a);
//	if (ps->len_a % 2 == 1)
	if (smallest <= ps->len_a / 2)
	{
		while (x < smallest)
		{
			rotate_a(ps);
			x++;
		}
		push_b(ps);
	}
	else
	{
		smallest = ps->len_a - smallest;
		while (x < smallest)
		{
			reverse_a(ps);
			x++;
		}
		push_b(ps);
	}
	i++;
//	if (i < 2)
	ps_insertion_sort_a(ps);
}