/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_halving_array.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/28 12:31:18 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/05 16:32:04 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		get_total(int *array, int size)
{
	int x;
	int ret;

	x = size - 1;
	ret = array[size - 1];
	while (x > 0)
	{
		ret += array[x];
		x--;
	}
	return (ret);
}

static void		fill_int_array(int *array1, int *array2, int start, int array_size)
{
	int excess;
	int x;
	int temp;

	array1[0] = start / 2;
	array2[0] = start / 2;
	if (start % 2 == 1)
		array2[0]++;
	x = 1;
	while (x < array_size)
	{
		array1[x] = array1[x - 1] / 2;
		array2[x] = array1[x - 1] / 2;
		if (array1[x] + array2[x] < array1[x - 1] || array1[x] + array2[x] < array2[x - 1])
			array2[x]++;
		x++;
	}
}

static int		get_half_int_array_size(int size)
{
	int array_size;

	array_size = 0;
	while (size > 4)
	{
		size /= 2;
		array_size++;
	}
	return (array_size);
}

int				*make_halving_array(int size, char which_array)
{
	int *array1;
	int *array2;
	int array_size;
	int total;

	total = 0;
	array_size = get_half_int_array_size(size);
	array1 = (int *)malloc(sizeof(int) * array_size);
	array2 = (int *)malloc(sizeof(int) * array_size);
	fill_int_array(array1, array2, size, array_size);
	// ft_printf("\nsize: %d\t[0]: %d|%d\t[1]: %d|%d\t[2]: %d|%d\t[3]: %d|%d\n", size, array1[0], array2[0], array1[1], array2[1], array1[2], array2[2], array1[3], array2[3]);
	// ft_printf("TOTAL: %d\tSIZE: %d\n\n", array1[3] + array1[2] + array1[1] + array2[3] + array2[2] + array2[1], size);
	if (which_array == 'a')
	{
		free(array2);
		return (array1);
	}
	else
	{
		free(array1);
		return (array2);
	}
}

// int main(void)
// {
// 	int x;
// 	x = 497;

// 	while (x <= 512)
// 	{
// 		make_halving_array(x, 'a');
// 		x++;
// 	}
// 	return (0);
// }