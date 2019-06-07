/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_insertion_sort.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 18:26:47 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/07 11:58:22 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_min_ps(char min_or_max, int a, int b, int c)
{
	if (min_or_max == 'm')
	{
		if (a < b && a < c)
			return (a);
		else if (b < a && b < c)
			return (b);
		else
			return (c);	
	}
	else
	{
		if (a > b && a > c)
			return (a);
		else if (b > a && b > c)
			return (b);
		else
			return (c);
	}
}

static void	change_index_value(i_s *is, int index, int len)
{
	if (INDX_1 == index)
		INDX_1 = len + 1;
	else if (INDX_2 == index)
		INDX_2 = len + 1;
	else
		INDX_3 = len + 1;
}

static int	smallest_to_push(int biggest, int smallest, int len, i_s *is)
{
	ft_printf("in smallest to push: smallest %d\tbiggest: %d\tlen: %d\n", smallest, biggest, len);
	if (len - biggest < smallest)
	{
		return (biggest);
	}
//	change_index_value(is, smallest, len);
	return (smallest);
}

static int	find_to_return(int a, int b, int c, int len)
{
	if (a < len)
		return (a);
	else if (b < len)
		return (b);
	else
		return (c);
}

static int	find_to_push(int *stack, int len, i_s *is)
{
	int biggest;
	int smallest;
	int return_value;

	ft_printf("in find to push - len: %d\ti1: %d\ti2: %d\ti3: %d\n", len, INDX_1, INDX_2, INDX_3);
	if ((INDX_1 > len && INDX_2 > len) || (INDX_2 > len && INDX_3 > len) || \
	(INDX_3 > len && INDX_1 > len))
	{
		ft_printf("first if\n");
		return (find_to_return(INDX_1, INDX_2, INDX_3, len));
	}
	else if (INDX_1 < len && INDX_2 < len && INDX_3 < len)
	{
		ft_printf("second if\n");
		return (smallest_to_push(IN_BIGGEST, IN_SMALLEST, len, is));
	}
	else if (INDX_1 < len && INDX_2 < len)
	{
		ft_printf("third if\n");
		biggest = (INDX_1 < INDX_2) ? INDX_2 : INDX_1;
		smallest = (INDX_1 < INDX_2) ? INDX_1 : INDX_2;
	}
	else if (INDX_2 < len && INDX_3 < len)
	{
		ft_printf("fourth if\n");
		biggest = (INDX_2 < INDX_3) ? INDX_3 : INDX_2;
		smallest = (INDX_2 < INDX_3) ? INDX_2 : INDX_3;
	}
	else if (INDX_1 < len && INDX_3 < len)
	{
		ft_printf("fifth if\n");
		biggest = (INDX_3 < INDX_1) ? INDX_1 : INDX_3;
		smallest = (INDX_3 < INDX_1) ? INDX_3 : INDX_1;
	}
	return (smallest_to_push(biggest, smallest, len, is));
}

static void	initialize_struct(i_s *is, int *stack)
{
	is->smallest_value = 2147483647;
	is->smallest_index = 0;
	is->smallest_used = 1;
	is->second_value = 2147483647;
	is->second_index = 0;
	is->second_used = 1;
	is->third_value = 2147483647;
	is->third_index = 0;
	is->third_used = 1;
}

static void	phill_struct(int *value, int *index, int *new_value, int *new_index)
{
	*value = *new_value;
	*index = *new_index;
}

static i_s	*find_smallest_index(i_s *is, int *stack, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		if (stack[i] <= VALUE_1)
			phill_struct(&VALUE_1, &INDX_1, &stack[i], &i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (stack[i] < VALUE_2 && stack[i] > VALUE_1)
			phill_struct(&VALUE_2, &INDX_2, &stack[i], &i);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (stack[i] < VALUE_3 & stack[i] > VALUE_2)
			phill_struct(&VALUE_3, &INDX_3, &stack[i], &i);
		i++;
	}
	return (is);
}

static void	push_all_to_a(p_a *ps)
{
	int x;
	int size;

	if (ps->len_a == 2)
	{
		if (ps->a[0] > ps->a[1])
			swap_a(ps);
	}
	size = ps->len_b;
	x = 0;
	while (x < size)
	{
		push_a(ps);
		x++;
	}
	return ;
}

static void	update_indexes(i_s *is, int rotated, int len)
{
	ft_printf("len in update_indexes: %d\ti1: %d\ti2: %d\ti3: %d\trotated: %d\n", len, INDX_1, INDX_2, INDX_3, rotated);
	if (is->smallest_index < len)
		is->smallest_index += rotated;
	if (is->second_index < len)
		is->second_index += rotated;
	if (is->third_index < len)
		is->third_index += rotated;
}

static void	print_is(i_s *is)
{
	ft_printf("smallest value: %d\tsmallest index: %d\n", VALUE_1, INDX_1);
	ft_printf("second value: %d\tsecond index: %d\n", VALUE_2, INDX_2);
	ft_printf("third value: %d\tthird index: %d\n", VALUE_3, INDX_3);
}

void		sort_3_not_alone_b(p_a *ps)
{
	ft_printf("in sort 3 not alone, b[0]: %d\tb[1]: %d\tb[2]: %d\n", ps->b[0], ps->b[1], ps->b[2]);
	if (find_unordered_ascending(ps->b, 3) == 0)
		return ;
	if (ps->b[0] > ps->b[1])
	{
		push_a(ps);
		swap_b(ps);
		push_b(ps);
		if (ps->b[0] < ps->b[1])
			swap_b(ps);
	}
	else
	{
		swap_b(ps);
		if (find_unordered_ascending(ps->b, 4) != 0)
		{
			push_a(ps);
			swap_b(ps);
			push_b(ps);
			if (ps->b[0] < ps->b[1])
				swap_b(ps);
		}
	}
}

void		ps_insertion_sort_a_3(p_a *ps)
{
	static int i;
	int smallest;
	int biggest;
	int x;
	i_s *is;
	int to_push;
	int counter;
	int a_size;
	int rotated;

	counter = 0;
	if (!i)
		i = 0;
	x = 0;
	ft_printf("len a: %d\tlen b: %d\n", ps->len_a, ps->len_b);
	if (ps->len_a < 3)
		return (push_all_to_a(ps));
	is = (i_s *)malloc(sizeof(i_s));
	a_size = ps->len_a;
	initialize_struct(is, ps->a);
	find_smallest_index(is, ps->a, ps->len_a);
	biggest = find_max_min_ps('M', INDX_1, INDX_2, INDX_3);
	smallest = find_max_min_ps('m', INDX_1, INDX_2, INDX_3);
	to_push = find_to_push(ps->a, ps->len_a, is);
	print_is(is);
	while (counter < 3)
	{
		x = 0;
		rotated = 0;
		ft_printf("to_push: %d\n", to_push);
		if (to_push <= ps->len_a / 2)
		{
			while (x < to_push)
			{
				rotate_a(ps);
				rotated--;
				x++;
			}
			push_b(ps);
		}
		else
		{
			biggest = ps->len_a - to_push;
			while (x < biggest)
			{
				reverse_a(ps);
				rotated++;
				x++;
			}
			push_b(ps);
		}
//		print_is(is);
		change_index_value(is, to_push, a_size);
		update_indexes(is, rotated - 1, ps->len_a);
//		print_is(is);
		ft_printf("to_push before: %d\n", to_push);
		print_is(is);
		to_push = find_to_push(ps->a, ps->len_a + 1, is);
		ft_printf("to_push after: %d\n", to_push);
		print_is(is);
		counter++;
	}
	if (ps->len_b == 3)
		sort_2_or_3_alone(ps, 'b');
	else
		sort_3_not_alone_b(ps);	
//	i++;
	ps_insertion_sort_a_3(ps);
}
