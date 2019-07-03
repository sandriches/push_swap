/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grab_2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 18:33:48 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/03 19:25:09 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_to_grab(int *stack, int *to_grab, int size)
{
	int x;
	int lowest;
	int y;
	int remember_x;

	x = 0;
	y = 0;
	lowest = -2147483648;
	remember_x = -1;
	to_grab[0] = lowest;
	to_grab[1] = lowest;
	while (y < 2)
	{
		while (x < size)
		{
			if (stack[x] > lowest && to_grab[0] != x && to_grab[1] != x)
			{
				lowest = stack[x];
				remember_x = x;
			}
			x++;
		}
		to_grab[y] = remember_x;
		lowest = -2147483648;
		x = 0;
		y++;
	}
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

	highest = (to_grab[0] > to_grab[1] && to_grab[0] >= 0) ? to_grab[0] : to_grab[1];
	lowest = (to_grab[0] < to_grab[1] && to_grab[0] >= 0) ? to_grab[0] : to_grab[1];
	if (lowest < size - highest)
		return ('r');
	return ('R');
}

static void	do_loop(p_a *ps, int size, char ro_or_rv, int *to_grab)
{
	int x;
	int to_update;
	int rotated;
	int top;

	x = 0;
	rotated = 0;
	if (ro_or_rv == 'r')
	{
		top = get_highest_and_lowest_index(to_grab, 's');
		to_update = top;
		while (x < top)
		{
			rotate_b(ps);
			rotated--;
			x++;
		}
	}
	else
	{
		top = size - get_highest_and_lowest_index(to_grab, 'b');
		to_update = get_highest_and_lowest_index(to_grab, 'b');
		while (x < top)
		{
			reverse_b(ps);
			rotated++;
			x++;
		}
	}
	ft_printf("top in DO_LOOP: %d\n", top);
	push_a(ps);
	ft_printf("to_update: %d\n", to_update);
	ft_printf("BEFORE\n0: %d\n1: %d\n\n", to_grab[0], to_grab[1]);
	update_to_grab(rotated, to_grab, to_update);
	ft_printf("AFTER\n0: %d\n1: %d\n\n", to_grab[0], to_grab[1]);
}

void		grab_2_from_b(p_a *ps, int size)
{
	int x;
	int *to_grab;

	to_grab = (int*)malloc(sizeof(int) * 2);
	fill_to_grab(ps->b, to_grab, size);
	x = 0;
	while (x < 2)
	{
		// ft_printf("0: %d\n1: %d\n", to_grab[0], to_grab[1]);
		do_loop(ps, size, rotate_or_reverse(to_grab, size), to_grab);
		size--;
		x++;
	}
}

// int main(void)
// {
// 	int array[9] = {50, 2, -4, 25, -11, 30, 23, 10};
// 	int *array_p = array;
// 	ft_printf("r_r return: %d\tvalue: %c\n", rotate_or_reverse(array_p, 5, 1), rotate_or_reverse(array_p, 5, 0));
// 	return (0);
// }