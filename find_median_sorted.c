/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_median_sorted.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 12:30:02 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/21 12:37:07 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_sorted(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	fill_sorted_array(int *stack, int len, int *sorted)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < len)
	{
		sorted[x] = stack[x];
		x++;
	}
	x = 0;
	while (y < len)
	{
		while (x < len - 1)
		{
			if (sorted[x] > sorted[x + 1])
				swap_sorted(&(sorted[x]), &(sorted[x + 1]));
			x++;
		}
		x = 0;
		y++;
	}
}

int			find_median_sorted_array(int *stack, int len)
{
	int *sorted;
	int rtn;

	sorted = (int *)malloc(sizeof(int) * len);
	fill_sorted_array(stack, len, sorted);
	if (len % 2 == 1)
		rtn = sorted[len / 2];
	else
		rtn = sorted[(len / 2) - 1];
	free(sorted);
	return (rtn);
}
