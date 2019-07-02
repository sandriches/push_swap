/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_find_median.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/08 17:02:12 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/01 19:20:25 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			adjust_limits(int *limits, int to_check, int higher)
{
	if (higher == 1)
		limits++;
	*limits = to_check;
	return (0);
}

static int			get_reference(int size)
{
	if (size % 2 == 1)
		return (size / 2);
	return ((size / 2) - 1);
}

static int			check_return(int reference, int size, int higher, int lower)
{
	if (lower == reference && ((reference == size / 2 && higher == reference) \
	|| (reference == size / 2 - 1 && higher == reference + 1)))
		return (1);
	return (0);
}

static int			check_current(int *stack, int size, int check, int *limits)
{
	int x;
	int reference;
	int higher;
	int lower;

	reference = get_reference(size);
	higher = 0;
	lower = 0;
	x = 0;
	while (x < size)
	{
		if (lower > reference)
			return (adjust_limits(limits, check, 0));
		else if ((reference == size / 2 && higher > reference) || \
		(reference == (size / 2 - 1) && higher > (reference + 1)))
			return (adjust_limits(limits, check, 1));
		if (stack[x] > check)
			higher++;
		else if (stack[x] < check)
			lower++;
		x++;
	}
	return (check_return(reference, size, higher, lower));
}

int					find_median(int *stack, int size)
{
	int x;
	int *limits;

	limits = (int *)malloc(sizeof(int) * 2);
	limits[0] = 2147483647;
	limits[1] = -2147483648;
	x = 0;
	ft_printf("IN FIND_MEDIAN, SIZE: %d\n", size);
	while (x < size)
	{
		if (stack[x] < limits[0] && stack[x] > limits[1])
		{
			if (check_current(stack, size, stack[x], limits) == 1)
			{
				free(limits);
				return (stack[x]);
			}
		}
		x++;
	}
	free(limits);
	return (-1);
}

// int main(void)
// {
// 	int stack[10] = {88, 87, 86, 89, 90, 93, 94, 91, 92};
// 	ft_printf("%d\n", find_median(stack, 15));
// }