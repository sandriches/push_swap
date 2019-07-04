/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_highest_from_stack.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/04 11:06:07 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/04 11:08:23 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lowest_from_stack(int *stack, int size)
{
	int x;
	int lowest;

	x = 0;
	lowest = 2147483647;
	while (x < size)
	{
		if (stack[x] < lowest)
			lowest = stack[x];
		x++;
	}
	return (lowest);
}

int		get_highest_from_stack(int *stack, int size)
{
	int x;
	int highest;

	x = 0;
	highest = -2147483648;
	while (x < size)
	{
		if (stack[x] > highest)
			highest = stack[x];
		x++;
	}
	return (highest);
}
