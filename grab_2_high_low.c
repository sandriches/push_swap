/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grab_2_high_low.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 14:39:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 14:50:17 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_integers(int *x, int *y, int *remember_x)
{
	*x = 0;
	*y = 0;
	*remember_x = -1;
}

static void	fill_to_grab_high(int *stack, int *to_grab, int size)
{
	int x;
	int lowest;
	int y;
	int remember_x;

	init_integers(&x, &y, &remember_x);
	lowest = -2147483648;
	to_grab[0] = lowest;
	while (x < size)
	{
		if (stack[x] > lowest && to_grab[0] != x)
		{
			lowest = stack[x];
			remember_x = x;
		}
		x++;
	}
	to_grab[0] = remember_x;
}

static void	fill_to_grab_low(int *stack, int *to_grab, int size)
{
	int x;
	int highest;
	int y;
	int remember_x;

	init_integers(&x, &y, &remember_x);
	highest = 2147483647;
	to_grab[0] = highest;
	while (x < size)
	{
		if (stack[x] < highest && to_grab[1] != x)
		{
			highest = stack[x];
			remember_x = x;
		}
		x++;
	}
	to_grab[1] = remember_x;
}

static void	update_to_grab(int rotated, int *to_grab, int to_update)
{
	int x;

	x = 0;
	rotated--;
	while (x < 2)
	{
		if (to_grab[x] == to_update)
			to_grab[x] = -1;
		x++;
	}
	x = 0;
	while (x < 2)
	{
		if (to_grab[x] >= 0)
			to_grab[x] += rotated;
		x++;
	}
}

static int	get_highest_and_lowest_index(int *to_grab, char big_or_small)
{
	int highest;
	int lowest;

	highest = (to_grab[0] > to_grab[1]) ? to_grab[0] : to_grab[1];
	lowest = (to_grab[0] < to_grab[1]) ? to_grab[0] : to_grab[1];
	if (to_grab[0] < 0)
		return (to_grab[1]);
	else if (to_grab[1] < 0)
		return (to_grab[0]);
	else
	{
		if (big_or_small == 'b')
			return (highest);
		return (lowest);
	}
}

static int	rotate_or_reverse(int *to_grab, int size)
{
	int highest;
	int lowest;

	highest = (to_grab[0] > to_grab[1] && to_grab[0] >= 0) ? to_grab[0] \
	: to_grab[1];
	lowest = (to_grab[0] < to_grab[1] && to_grab[0] >= 0) ? to_grab[0] : \
	to_grab[1];
	if (lowest < size - highest)
		return ('r');
	return ('R');
}

static void	do_loop_rotate(p_a *ps, int size, int *to_grab)
{
	int x;
	int to_update;
	int rotated;
	int top;

	x = 0;
	rotated = 0;
	top = get_highest_and_lowest_index(to_grab, 's');
	to_update = top;
	while (x < top)
	{
		rotate_a(ps);
		rotated--;
		x++;
	}
	push_b(ps);
	update_to_grab(rotated, to_grab, to_update);
}

static void	do_loop_reverse(p_a *ps, int size, int *to_grab)
{
	int x;
	int to_update;
	int rotated;
	int top;

	x = 0;
	rotated = 0;
	top = size - get_highest_and_lowest_index(to_grab, 'b');
	to_update = get_highest_and_lowest_index(to_grab, 'b');
	while (x < top)
	{
		reverse_a(ps);
		rotated++;
		x++;
	}
	push_b(ps);
	update_to_grab(rotated, to_grab, to_update);
}

void		grab_2_high_low(p_a *ps, int size)
{
	int x;
	int *to_grab;

	to_grab = (int*)malloc(sizeof(int) * 2);
	fill_to_grab_low(ps->a, to_grab, size);
	fill_to_grab_high(ps->a, to_grab, size);
	// ft_printf("to_grab: [0]%d\t[1]%d\n", to_grab[0], to_grab[1]);
	// return ;
	x = 0;
	while (x < 2)
	{
		if (rotate_or_reverse(to_grab, size) == 'r')
			do_loop_rotate(ps, size, to_grab);
		else
			do_loop_reverse(ps, size, to_grab);
		size--;
		x++;
	}
}
