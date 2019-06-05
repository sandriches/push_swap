/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_quicksort.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 14:28:56 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/05 17:26:40 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_quicksort_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

static int		ps_quicksort_is_sorted(int *stack, int start, int end)
{
	int x;

	x = start + 1;
	while (x < end)
	{
		if (stack[x - 1] > stack[x])
			return (0);
		x++;
	}
	ft_printf("sorted with start: %d\tend: %d\n", start, end);
	return (1);
}

static int		ps_quicksort_partition(p_a *ps, int *stack, int start, int end)
{
	static int i;
	int pivot;
	int x;
	int pushed;
	int rotated;
	int return_value;

	if (!i)
		i = 0;
	ft_printf("Beginning of sort: start: %d\tend: %d\tpivot: %d\n", start, end, stack[end]);
	print_arrays(ps);
	if (end - start == 1)
	{
		if (stack[start] > stack[end])
			swap_a(ps);
		return (0);
	}
//	if (ps_quicksort_is_sorted(stack, 0, ps->len_a) == 1)
//		return ;
//	print_arrays(ps);
	return_value = 0;
	pushed = 0;
	rotated = 0;
	pivot = stack[end];
	x = start;
//	reverse_a(ps);
	while (x < end)
	{
		ft_printf("stack[0]: %d\n", stack[0]);
		if (stack[0] >= pivot)
		{
			rotate_a(ps);
			rotated++;
		}
		else if (stack[0] < pivot)
		{
			push_b(ps);
			pushed++;
		}
		x++;
	}
	return_value = pushed + 1;
	while (pushed > 0)
	{
		push_a(ps);
		pushed--;
	}
	i++;
	ft_printf("return_value: %d\n", return_value);
	return (return_value);
//	if (i < 3)
//		ps_quicksort_partition(ps, ps->a, start, return_value--);
//	ps_quicksort_pivot_end(ps, ps->a, return_value++, end);
}

void			ps_quicksort_pivot_end(p_a *ps, int *stack, int start, int end)
{
	static int i;
	int partition_result;

	if (!i)
		i = 0;
	if (start < end && i < 25)
	{
		i++;
		partition_result = ps_quicksort_partition(ps, stack, start, end);
		ps_quicksort_pivot_end(ps, ps->a, start, partition_result - 1);
		ps_quicksort_pivot_end(ps, ps->a, partition_result + 1, end);
	}
}

void			ps_quicksort(p_a *ps, char which_stack)
{
	if (which_stack == 'a')
		ps_quicksort_pivot_end(ps, ps->a, 0, ps->len_a - 1);
//	else
//		ps_quicksort_stack_pivot_end(ps, ps->b, ps->len_b, 0);
}
