/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_x_from_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 14:50:17 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/11 19:12:19 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exists_in_array(int *array, int check, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		if (array[x] == check)
			return (1);
		x++;
	}
	return (0);
}

static void	fill_sorted_array_a(p_a *ps, int *array, int amount, int loop_over)
{
	int x;
	int j;
	int lowest;
	int to_add;

	x = 0;
	lowest = 2147483647;
	while (x < amount)
	{
		j = 0;
		while (j < loop_over)
		{
			if (ps->a[j] < lowest && exists_in_array(array, j, amount) == 0)
			{
				to_add = j;
				lowest = ps->a[j];
			}
			j++;
		}
		array[x] = to_add;
		lowest = 2147483647;
		x++;
	}
}

static int	get_index(int *array, int size, char sign)
{
	int x;
	int check;

	check = (sign == '<') ? 2147483647 : -2147483648;
	x = 0;
	while (x < size)
	{
		if (sign == '<')
		{
			if (array[x] < check && array[x] > -1)
				check = array[x];
		}
		else
		{
			if (array[x] > check && array[x] > -1)
				check = array[x];
		}
		x++;
	}
	return (check);
}

static char	rotate_or_reverse(p_a *ps, int *sorted_array, int array_size)
{
	int highest;
	int lowest;
	int negator;

	negator = ps->len_a;
	lowest = get_index(sorted_array, array_size, '<');
	highest = negator - get_index(sorted_array, array_size, '>');
	if (highest < lowest)
		return ('R');
	return ('r');
}

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

static int	push_closest(p_a *ps, int *array, int size)
{
	int		x;
	int		index;
	int		rotated;
	char	r_or_rv;

	r_or_rv = rotate_or_reverse(ps, array, size);
	index = (r_or_rv == 'R') ? (ps->len_a - get_index(array, size, \
	'>')) : get_index(array, size, '<');
	rotated = (r_or_rv == 'R') ? -1 : -1;
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

static void	undo_rotates(p_a *ps, int rotated)
{
	int x;

	x = 0;
	while (rotated != 0)
	{
		if (rotated < 0)
		{
			rotate_a(ps);
			rotated++;
		}
		else
		{
			reverse_a(ps);
			rotated--;
		}
	}
}

void		get_x_from_stack_a(p_a *ps, int amount, int loop_over, \
int inoffensive)
{
	int sorted_array[amount];
	int *p_array;
	int x;
	int rotated;

	x = 0;
	rotated = 0;
	p_array = sorted_array;
	fill_empty_array(p_array, amount);
	fill_sorted_array_a(ps, p_array, amount, loop_over);
	print_arrays(ps);
	while (x < amount)
	{
		rotated += push_closest(ps, sorted_array, amount);
		x++;
	}
	if (inoffensive == 1)
		undo_rotates(ps, rotated);
}
