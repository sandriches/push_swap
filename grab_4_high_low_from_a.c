/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grab_4_high_low_from_a.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 16:03:56 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 16:07:21 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		exists_in_array(int check, int *array)
{
	if (array[0] == check || array[1] == check || array[2] == check || \
	array[3] == check)
		return (1);
	return (0);
}

static int		return_s_above_zero(int *array)
{
	if (array[0] >= 0 && (array[0] < array[1] || array[1] < 0) && (array[0] < \
	array[2] || array[2] < 0) && (array[0] < array[3] || array[3] < 0))
		return (array[0]);
	if (array[1] >= 0 && (array[1] < array[0] || array[0] < 0) && (array[1] < \
	array[2] || array[2] < 0) && (array[1] < array[3] || array[3] < 0))
		return (array[1]);
	if (array[2] >= 0 && (array[2] < array[1] || array[1] < 0) && (array[2] < \
	array[0] || array[0] < 0) && (array[2] < array[3] || array[3] < 0))
		return (array[2]);
	else if (array[3] >= 0)
		return (array[3]);
	return (-1);
}

static int		return_b_above_zero(int *array)
{
	if (array[0] >= 0 && array[0] > array[1] && array[0] > array[2] && \
	array[0] > array[3])
		return (array[0]);
	else if (array[1] >= 0 && array[1] > array[0] && array[1] > array[2] \
	&& array[1] > array[3])
		return (array[1]);
	else if (array[2] >= 0 && array[2] > array[0] && array[2] > array[1] \
	&& array[2] > array[3])
		return (array[2]);
	else if (array[3] >= 0)
		return (array[3]);
	return (-1);
}

static void		init_to_grab(int *array)
{
	array[0] = -2147483648;
	array[1] = -2147483648;
	array[2] = 2147483647;
	array[3] = 2147483647;
}

static void		init_integers(int *x, int *y, int *remember_x)
{
	*x = 0;
	*y = 0;
	*remember_x = 0;
}

static void		fill_to_grab_2(int *stack, int *array, int size)
{
	int x;
	int y;
	int highest;
	int remember_x;

	init_integers(&x, &y, &remember_x);
	highest = 2147483647;
	y = 2;
	while (y < 4)
	{
		while (x < size)
		{
			if (stack[x] < highest && x != array[2])
			{
				highest = stack[x];
				remember_x = x;
			}
			x++;
		}
		array[y] = remember_x;
		highest = 2147483647;
		x = 0;
		y++;
	}
}

static void		fill_to_grab(int *stack, int *array, int size)
{
	int x;
	int y;
	int lowest;
	int remember_x;

	init_integers(&x, &y, &remember_x);
	lowest = -2147483648;
	while (y < 2)
	{
		while (x < size)
		{
			if (stack[x] > lowest && x != array[0])
			{
				lowest = stack[x];
				remember_x = x;
			}
			x++;
		}
		array[y] = remember_x;
		lowest = -2147483648;
		x = 0;
		y++;
	}
}

static char		get_closest_value(int *to_grab, int size)
{
	int		lowest;
	int		highest;
	char	rtn;

	lowest = return_s_above_zero(to_grab);
	highest = return_b_above_zero(to_grab);
	if (lowest < (size - highest))
	{
		return ('r');
	}
	return ('R');
}

static void		update_to_grab(int rotated, int *to_grab, int to_update)
{
	int x;

	x = 0;
	rotated--;
	while (x < 4)
	{
		if (to_grab[x] == to_update)
			to_grab[x] = -1;
		x++;
	}
	x = 0;
	while (x < 4)
	{
		if (to_grab[x] >= 0)
			to_grab[x] += rotated;
		x++;
	}
}

static void		rotate_grab_4(int *to_grab, p_a *ps, int size)
{
	int top_end;
	int x;
	int rotated;
	int to_update;

	x = 0;
	rotated = 0;
	top_end = return_s_above_zero(to_grab);
	to_update = top_end;
	while (x < top_end)
	{
		rotate_a(ps);
		rotated--;
		x++;
	}
	push_b(ps);
	update_to_grab(rotated, to_grab, to_update);
}

static void		reverse_grab_4(int *to_grab, p_a *ps, int size)
{
	int top_end;
	int x;
	int rotated;
	int to_update;

	x = 0;
	rotated = 0;
	top_end = size - return_b_above_zero(to_grab);
	to_update = return_b_above_zero(to_grab);
	while (x < top_end)
	{
		reverse_a(ps);
		rotated++;
		x++;
	}
	push_b(ps);
	update_to_grab(rotated, to_grab, to_update);
}

void			grab_4_high_low_from_a(p_a *ps, int size)
{
	int x;
	int *to_grab;
	int y;
	int top_end;
	int rotated;

	x = 0;
	to_grab = (int *)malloc(sizeof(int) * 4);
	ft_printf("START GRAB FROM B, SIZE %d\n", size);
	fill_to_grab(ps->a, to_grab, size);
	fill_to_grab_2(ps->a, to_grab, size);
	ft_printf("TO_GRAB[0]:%d\t[1]:%d\t[2]:%d\t[3]:%d\n", to_grab[0], to_grab[2], to_grab[2], to_grab[3]);
	while (x < 4)
	{
		if (get_closest_value(to_grab, size) == 'r')
			rotate_grab_4(to_grab, ps, size);
		else
			reverse_grab_4(to_grab, ps, size);
		size--;
		x++;
	}
	free(to_grab);
	ft_printf("END OF GRAB FROM B\n");
}
