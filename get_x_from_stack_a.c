/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_x_from_stack_a.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 14:50:17 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 12:09:24 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_sorted_array(int to_update, int rotated, int *array, \
int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (array[x] == to_update)
			array[x] = -1;
		x++;
	}
	x = 0;
	while (x < size)
	{
		if (array[x] > -1)
			array[x] += rotated;
		x++;
	}
}

static int	push_closest(t_ps *ps, int *array, int size)
{
	int		x;
	int		index;
	int		rotated;
	char	r_or_rv;

	r_or_rv = x_rotate_or_reverse(ps, array, size);
	index = (r_or_rv == 'R') ? (ps->len_a - get_index(array, size, \
	'>')) : get_index(array, size, '<');
	rotated = -1;
	x = 0;
	while (x < index)
	{
		if (r_or_rv == 'R')
			reverse_a(ps);
		else
			rotate_a(ps);
		rotated += (r_or_rv == 'R') ? 1 : -1;
		x++;
	}
	push_b(ps);
	(r_or_rv == 'r') ? update_sorted_array(index, rotated, array, size) \
	: update_sorted_array(get_index(array, size, '>'), rotated, array, size);
	return (rotated);
}

static void	fill_empty_array(int *array, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		array[x] = -1;
		x++;
	}
}

static void	undo_rotates(t_ps *ps, int end_position, int rotated)
{
	int x;

	x = 0;
	while (ps->a[ps->len_a - 1] != end_position)
		reverse_a(ps);
	while (rotated != 0)
	{
		if (rotated < 0)
		{
			reverse_a(ps);
			rotated++;
		}
		else
		{
			rotate_a(ps);
			rotated--;
		}
	}
}

void		get_x_from_stack_a(t_ps *ps, int amount, int loop_over, \
int inoffensive)
{
	int sorted_array[amount];
	int *ptr_array;
	int x;
	int rotated;
	int end_position;

	end_position = ps->a[ps->len_a - 1];
	x = 0;
	rotated = 0;
	ptr_array = sorted_array;
	fill_empty_array(ptr_array, amount);
	fill_sorted_array_a(ps, ptr_array, amount, loop_over);
	while (x < amount)
	{
		rotated += push_closest(ps, sorted_array, amount);
		x++;
	}
	ps->a_value = loop_over - amount;
	ps->a_done = 0;
	if (inoffensive == 1)
		undo_rotates(ps, end_position, rotated);
}
