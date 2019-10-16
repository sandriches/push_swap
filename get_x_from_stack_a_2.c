/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_x_from_stack_a_2.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/18 13:02:35 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/17 17:36:20 by rcorke        ########   odam.nl         */
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

void		fill_sorted_array_a(t_ps *ps, \
int *array, int amount, int loop_over)
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

int			get_index(int *array, int size, char sign)
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

char		x_rotate_or_reverse(t_ps *ps, int *sorted_array, int array_size)
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
