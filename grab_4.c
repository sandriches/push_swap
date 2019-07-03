/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grab_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/03 15:09:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/03 17:12:02 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		exists_in_array(int check, int *array)
{
	if (array[0] == check || array[1] == check || array[2] == check || array[3] == check)
		return (1);
	return (0);
}

static int		return_b_or_s_above_zero(int *array, char big_or_small)
{
	if (big_or_small == 'b')
	{
		if (array[0] >= 0 && array[0] > array[1] && array[0] > array[2] && array[0] > array[3])
			return(array[0]);
		else if (array[1] >= 0 && array[1] > array[0] && array[1] > array[2] && array[1] > array[3])
			return(array[1]);
		else if (array[2] >= 0 && array[2] > array[0] && array[2] > array[1] && array[2] > array[3])
			return(array[2]);
		else if (array[3] >= 0)
			return(array[3]);
	}
	else
	{
		if (array[0] >= 0 && (array[0] < array[1] || array[1] < 0) && (array[0] < array[2] || array[2] < 0) && (array[0] < array[3] || array[3] < 0))
			return(array[0]);
		if (array[1] >= 0 && (array[1] < array[0] || array[0] < 0) && (array[1] < array[2] || array[2] < 0) && (array[1] < array[3] || array[3] < 0))
			return(array[1]);
		if (array[2] >= 0 && (array[2] < array[1] || array[1] < 0) && (array[2] < array[0] || array[0] < 0) && (array[2] < array[3] || array[3] < 0))
			return(array[2]);
		else if (array[3] >= 0)
			return(array[3]);
	}
	return (-1);
}

static void		fill_to_grab(int *stack, int *array, int size)
{
	int x;
	int y;
	int lowest;
	int remember_x;

	x = 0;
	y = 0;
	remember_x = 0;
	lowest = -2147483648;
	array[0] = -2147483648;
	array[1] = -2147483648;
	array[2] = -2147483648;
	array[3] = -2147483648;
	while (y < 4)
	{
		while (x < size)
		{
			if (stack[x] > lowest && exists_in_array(x, array) == 0)
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

static char	get_closest_value(int *to_grab, int size)
{
	int lowest;
	int highest;
	char rtn;

	lowest = return_b_or_s_above_zero(to_grab, 's');
	highest = return_b_or_s_above_zero(to_grab, 'b');
	ft_printf("in get closest - highest index: %d\tlowest index: %d\tsize: %d\n", highest, lowest, size);
	if (lowest < (size - highest))
	{
		return ('r');
	}
	return ('R');
}

static void	update_to_grab(int rotated, int *to_grab, int to_update)
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

static void	rotate_or_reverse(char closest_value, int *to_grab, p_a *ps, int size)
{
	int top_end;
	int x;
	int rotated;
	int to_update;

	x = 0;
	rotated = 0;
	if (closest_value == 'r')
	{
		top_end = return_b_or_s_above_zero(to_grab, 's');
		to_update = top_end;
		while (x < top_end)
		{
			rotate_b(ps);
			rotated--;
			x++;
		}
	}
	else
	{
		top_end = size - return_b_or_s_above_zero(to_grab, 'b');
		to_update = return_b_or_s_above_zero(to_grab, 'b');
		while (x < top_end)
		{
			reverse_b(ps);
			rotated++;
			x++;
		}
	}
	push_a(ps);
	ft_printf("in ROTATE OR REVERSE: to update index: %d\trotated: %d\ttop end: %d\n", to_update, rotated, top_end);
	update_to_grab(rotated, to_grab, to_update);
}

void	grab_4_from_b(p_a *ps, int size)
{
	int x;
	int *to_grab;
	int y;
	int top_end;
	int rotated;

	x = 0;
	to_grab = (int *)malloc(sizeof(int) * 4);
	fill_to_grab(ps->b, to_grab, size);
	while (x < 4)
	{
		ft_printf("closest_value: %c\n", get_closest_value(to_grab, size));
		ft_printf("0: %d\n1: %d\n2: %d\n3: %d\n\n\n", to_grab[0], to_grab[1], to_grab[2], to_grab[3]);
		rotate_or_reverse(get_closest_value(to_grab, size), to_grab, ps, size);
		size--;
		// ft_printf("AFTER\n0: %d\n1: %d\n2: %d\n3: %d\n\n\n", to_grab[0], to_grab[1], to_grab[2], to_grab[3]);
		x++;
	}
	free(to_grab);
	ft_printf("END OF GRAB FROM B\n");
}

// int	main(void)
// {
// 	int array[4] = {5, 2, -1, -1};
// 	int *array_p = array;

// 	ft_printf("%d\n", return_b_or_s_above_zero(array_p, 's'));
// 	return (0);
// }