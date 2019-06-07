/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 10:04:02 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/07 17:28:30 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_swap_insertion_4(p_a *ps)
{
	if (ps->b[0] < ps->b[1] && ps->a[0] > ps->a[1])
		swap_both(ps);
	else
	{
		if (ps->b[0] < ps->b[1])
			swap_b(ps);
		else if (ps->a[0] > ps->a[1])
			swap_a(ps);
	}
}

static void	check_swap_b(p_a *ps)
{
	if (ps->b[0] < ps->b[1])
		swap_b(ps);
}

static void	check_swap_a(p_a *ps)
{
	if (ps->a[0] > ps->a[1])
			swap_a(ps);
}

static int	return_biggest_int(int a, int b, int c, int d)
{
	if (a > b && a > c && a > d)
		return (a);
	else if (b > a && b > c && b > d)
		return (b);
	else if (c > a && c > b && c > d)
		return (c);
	return (d);
}

static int	return_smallest_int(int a, int b, int c, int d)
{
	if (a < b && a < c && a < d)
		return (a);
	else if (b < a && b < c && b < d)
		return (b);
	else if (c < a && c < b && c < d)
		return (c);
	return (d);
}

static int	return_3_int(int a, int b, int c, char sign)
{
	if (sign == '>')
	{
		if (a > b && a > c)
			return (a);
		else if (b > a && b > c)
			return (b);
		return (c);
	}
	else
	{
		if (a < b && a < c)
			return (a);
		else if (b < a && b < c)
			return (b);
		return (c);
	}
}

static int	return_second_biggest_int(int a, int b, int c, int d)
{
	if (return_biggest_int(a, b, c, d) == a)
		return (return_3_int(b, c, d, '>'));
	else if (return_biggest_int(a, b, c, d) == b)
		return (return_3_int(a, c, d, '>'));
	else if (return_biggest_int(a, b, c, d) == c)
		return (return_3_int(a, b, d, '>'));
	else
		return (return_3_int(a, b, c, '>'));
}

static int	return_second_smallest_int(int a, int b, int c, int d)
{
	if (return_smallest_int(a, b, c, d) == a)
		return (return_3_int(b, c, d, '<'));
	else if (return_smallest_int(a, b, c, d) == b)
		return (return_3_int(a, c, d, '<'));
	else if (return_smallest_int(a, b, c, d) == c)
		return (return_3_int(a, b, d, '<'));
	else
		return (return_3_int(a, b, c, '<'));
}

static void	fill_index(int *stack, int len, s_4 *s4)
{
	int x;

	x = 0;
	while (x < len)
	{
		if (stack[x] == s4->smallest && s4->smallest_index < len)
			s4->smallest_index = x;
		else if (stack[x] == s4->s_median && s4->s_median_index < len)
			s4->s_median_index = x;
		else if (stack[x] == s4->l_median && s4->l_median_index < len)
			s4->l_median_index = x;
		else if (stack[x] == s4->largest && s4->largest_index < len)
			s4->largest_index = x;
		x++;
	}
}

static int	return_2_int(int a, int b, char which_sign)
{
	if (which_sign == '>')
	{
		if (a > b)
			return (a);
		return (b);
	}
	else
	{
		if (a < b)
			return (a);
		return (b);
	}
}
static int	closest_index_2_d(int len, s_4 *s4)
{
//	ft_printf("here\n");
	if (s4->largest_index >= len)
	{
		if (len - return_2_int(s4->l_median_index, s4->s_median_index, '>') < return_2_int(s4->l_median_index, s4->s_median_index, '<'))
			return (return_2_int(s4->l_median_index, s4->s_median_index, '>'));
		return (return_2_int(s4->l_median_index, s4->s_median_index, '<'));
	}
	else if (s4->l_median_index >= len)
	{
		if (len - return_2_int(s4->largest_index, s4->s_median_index, '>') < return_2_int(s4->largest_index, s4->s_median_index, '<'))
			return (return_2_int(s4->largest_index, s4->s_median_index, '>'));
		return (return_2_int(s4->largest_index, s4->s_median_index, '<'));
	}
	else
	{
		if (len - return_2_int(s4->largest_index, s4->l_median_index, '>') < return_2_int(s4->largest_index, s4->l_median_index, '<'))
			return (return_2_int(s4->largest_index, s4->l_median_index, '>'));
		return (return_2_int(s4->largest_index, s4->l_median_index, '<'));
	}
}

static int	closest_index_2_c(int len, s_4 *s4)
{
	if (s4->s_median_index >= len)
	{
		if (s4->largest_index >= len)
		{
			if (len - return_2_int(s4->l_median_index, s4->smallest_index, '>') < return_2_int(s4->l_median_index, s4->smallest_index, '<'))
				return (return_2_int(s4->l_median_index, s4->smallest_index, '>'));
			return (return_2_int(s4->l_median_index, s4->smallest_index, '<'));
		}
		else if (s4->l_median_index >= len)
		{
			if (len - return_2_int(s4->largest_index, s4->smallest_index, '>') < return_2_int(s4->largest_index, s4->smallest_index, '<'))
				return (return_2_int(s4->largest_index, s4->smallest_index, '>'));
			return (return_2_int(s4->largest_index, s4->smallest_index, '<'));
		}
		else
		{
			if (len - return_2_int(s4->largest_index, s4->l_median_index, '>') < return_2_int(s4->largest_index, s4->l_median_index, '<'))
				return (return_2_int(s4->largest_index, s4->l_median_index, '>'));
			return (return_2_int(s4->largest_index, s4->l_median_index, '<'));
		}
	}
	else
		return (closest_index_2_d(len, s4));
}

static int	closest_index_2_b(int len, s_4 *s4)
{
//	ft_printf("s4->l_med: %d\tlen: %d\n", s4->l_median_index, len);
	if (s4->l_median_index >= len)
	{
		if (s4->largest_index >= len)
		{
//			ft_printf("HERE\n");
			if (len - return_2_int(s4->s_median_index, s4->smallest_index, '>') < return_2_int(s4->s_median_index, s4->smallest_index, '<'))
				return (return_2_int(s4->s_median_index, s4->smallest_index, '>'));
			return (return_2_int(s4->s_median_index, s4->smallest_index, '<'));
		}
		else if (s4->s_median_index >= len)
		{
			if (len - return_2_int(s4->largest_index, s4->smallest_index, '>') < return_2_int(s4->largest_index, s4->smallest_index, '<'))
				return (return_2_int(s4->largest_index, s4->smallest_index, '>'));
			return (return_2_int(s4->largest_index, s4->smallest_index, '<'));
		}
		else
		{
//			ft_printf("rtn 2 int largest && smedian [>]: %d\trtn 2 int largest && smedian [<]: %d\n", return_2_int(s4->largest_index, s4->s_median_index, '>'), return_2_int(s4->largest_index, s4->s_median_index, '<'));
			if ((len - return_2_int(s4->largest_index, s4->s_median_index, '>')) < return_2_int(s4->largest_index, s4->s_median_index, '<'))
				return (return_2_int(s4->largest_index, s4->s_median_index, '>'));
			return (return_2_int(s4->largest_index, s4->s_median_index, '<'));
		}
	}
	else
		return (closest_index_2_c(len, s4));
}

static int	closest_index_2_a(int len, s_4 *s4)
{
	if (s4->largest_index >= len)
	{
//		ft_printf("here\n");
		if (s4->l_median_index >= len)
		{
			if (len - return_2_int(s4->s_median_index, s4->smallest_index, '>') < return_2_int(s4->s_median_index, s4->smallest_index, '<'))
				return (return_2_int(s4->s_median_index, s4->smallest_index, '>'));
			return (return_2_int(s4->s_median_index, s4->smallest_index, '<'));
		}
		else if (s4->s_median_index >= len)
		{
			if (len - return_2_int(s4->l_median_index, s4->smallest_index, '>') < return_2_int(s4->l_median_index, s4->smallest_index, '<'))
				return (return_2_int(s4->l_median_index, s4->smallest_index, '>'));
			return (return_2_int(s4->l_median_index, s4->smallest_index, '<'));
		}
		else
		{
			if (len - return_2_int(s4->l_median_index, s4->s_median_index, '>') < return_2_int(s4->l_median_index, s4->s_median_index, '<'))
				return (return_2_int(s4->l_median_index, s4->s_median_index, '>'));
			return (return_2_int(s4->l_median_index, s4->s_median_index, '<'));
		}
	}
	else
		return (closest_index_2_b(len, s4));
}

static int	find_closest_index(int len, s_4 *s4, int numbers_to_check)
{
	int highest;
	int lowest;
	ft_printf("len: %d\tnum_to_check: %d\ts4[1]: %d\ts4[2]: %d\ts4[3]: %d\ts4[4]: %d\n", numbers_to_check, len, s4->smallest_index, s4->s_median_index, s4->l_median_index, s4->largest_index);

	if (numbers_to_check == 4)
	{
		highest = return_biggest_int(s4->largest_index, s4->l_median_index, s4->s_median_index, s4->smallest_index);
		lowest = return_smallest_int(s4->largest_index, s4->l_median_index, s4->s_median_index, s4->smallest_index);
	}
	else if (numbers_to_check == 3)
	{
//		ft_printf("here\n");
		if (s4->largest_index >= len)
		{
			highest = return_3_int(s4->l_median_index, s4->s_median_index, s4->smallest_index, '>');
			lowest = return_3_int(s4->l_median_index, s4->s_median_index, s4->smallest_index, '<');
		}
		else if (s4->l_median_index >= len)
		{
			highest = return_3_int(s4->largest_index, s4->s_median_index, s4->smallest_index, '>');
			lowest = return_3_int(s4->largest_index, s4->s_median_index, s4->smallest_index, '<');
		}
		else if (s4->s_median_index >= len)
		{
			highest = return_3_int(s4->l_median_index, s4->largest_index, s4->smallest_index, '>');
			lowest = return_3_int(s4->l_median_index, s4->largest_index, s4->smallest_index, '<');
		}
		else
		{
			highest = return_3_int(s4->l_median_index, s4->s_median_index, s4->largest_index, '>');
			lowest = return_3_int(s4->l_median_index, s4->s_median_index, s4->largest_index, '<');
		}
	}
	else if (numbers_to_check == 2)
		return (closest_index_2_a(len, s4));
	else
		return (return_smallest_int(s4->largest_index, s4->l_median_index, s4->s_median_index, s4->smallest_index));
	if (len - highest < lowest)
		return (highest);
	return (lowest);
}

static void	start_struct(s_4 *s4)
{
	s4->smallest = 2147483647;
	s4->smallest_index = 0;
	s4->s_median = 2147483647;
	s4->s_median_index = 0;
	s4->l_median = 2147483647;
	s4->l_median_index = 0;
	s4->largest = 2147483647;
	s4->largest_index = 0;
	s4->rotated = 0;
}

static void	fill_s4_struct_1(int *stack, int len, s_4 *s4)
{
	int x;
	int smallest;

	x = 0;
	start_struct(s4);
	while (x < len)
	{
		if (stack[x] <= s4->smallest)
		{
			phill_struct(&(s4->smallest), &(s4->smallest_index), &stack[x], &x);
//			ft_printf("smallest: %d\n", s4->smallest);
		}
		x++;
	}
	x = 0;
	while (x < len)
	{
		if (stack[x] < s4->s_median && stack[x] > s4->smallest)
			phill_struct(&(s4->s_median), &(s4->s_median_index), &stack[x], &x);
		x++;
	}
}

static void	fill_s4_struct_2(int *stack, int len, s_4 *s4)
{
	int x;

	x = 0;
	while (x < len)
	{
		if (stack[x] < s4->l_median && stack[x] > s4->s_median)
			phill_struct(&(s4->l_median), &(s4->l_median_index), &stack[x], &x);
		x++;
	}
	x = 0;
	while (x < len)
	{
		if (stack[x] < s4->largest && stack[x] > s4->l_median)
			phill_struct(&(s4->largest), &(s4->largest_index), &stack[x], &x);
		x++;
	}
}

void		sort_4_not_alone_b(p_a *ps)
{
//	for (int i = 0; i < 4; i++)
//		push_b(ps);
	if (find_unordered_descending(ps->b, 4) == 0)
		return ;
	if (return_smallest_int(ps->b[0], ps->b[1], ps->b[2], ps->b[3]) == ps->b[3])
		return (sort_3_not_alone_b(ps));
	check_swap_b(ps);
	push_a(ps);
	check_swap_b(ps);
	push_a(ps);
	check_swap_insertion_4(ps);
	if (ps->b[0] > ps->a[0] || ps->b[0] > ps->a[1])
	{
		push_a(ps);
		check_swap_a(ps);
		push_b(ps);
		check_swap_insertion_4(ps);
	}
	push_b(ps);
	push_b(ps);
}

/*static void		check_negative_update(int stack_size, int *to_replace, int *rotated)
{
	if (*to_replace - *rotated < 0)
		*to_replace = stack_size - *rotated;
	else
		*to_replace -= *rotated
}*/

static void		update_rotated_indexes(s_4 *s4, int a, int b, int c)
{
//	ft_printf("in update rotated indexes: s[1]: %d\ts[2]: %d\ts[3]: %d\ts[4]: %d\n", s4->smallest_index, s4->s_median_index, s4->l_median_index, s4->largest_index);
	if (s4->largest_index < s4->size && (s4->largest_index == a || s4->largest_index == b || s4->largest_index == c))
		s4->largest_index -= s4->rotated;
	if (s4->l_median_index < s4->size && (s4->l_median_index == a || s4->l_median_index == b || s4->l_median_index == c))
		s4->l_median_index -= s4->rotated;
	if (s4->s_median_index < s4->size && (s4->s_median_index == a || s4->s_median_index == b || s4->s_median_index == c))
		s4->s_median_index -= s4->rotated;
	if (s4->smallest_index < s4->size && (s4->smallest_index == a || s4->smallest_index == b || s4->smallest_index == c))
		s4->smallest_index -= s4->rotated;
	s4->rotated = 0;
}

static void		update_index(int len, s_4 *s4, int to_update)
{
	ft_printf("in update index - to_update: %d\ts[1]: %d\ts[2]: %d\ts[3]: %d\ts[4]: %d\n", to_update, s4->smallest_index, s4->s_median_index, s4->l_median_index, s4->largest_index);
	if (s4->largest_index == to_update)
	{
		s4->largest_index = len;
		update_rotated_indexes(s4, s4->l_median_index, s4->s_median_index, s4->smallest_index);
	}
	else if (s4->l_median_index == to_update)
	{
		s4->l_median_index = len;
		update_rotated_indexes(s4, s4->largest_index, s4->s_median_index, s4->smallest_index);
	}
	else if (s4->s_median_index == to_update)
	{
		s4->s_median_index = len;
		update_rotated_indexes(s4, s4->l_median_index, s4->largest_index, s4->smallest_index);
	}
	else if (s4->smallest_index == to_update)
	{
		s4->smallest_index = len;
		update_rotated_indexes(s4, s4->l_median_index, s4->s_median_index, s4->largest_index);
	}
}

static void	push_all_to_a(p_a *ps)
{
	int x;
	int size;

	if (ps->len_a == 2 || ps->len_a == 3)
		return (sort_2_or_3_alone(ps, 'a'));
	size = ps->len_b;
	x = 0;
	while (x < size)
	{
		push_a(ps);
		x++;
	}
	return ;
}

static void		push_index(p_a *ps, s_4 *s4, int indexes)
{
	int x;
	int closest_index;
	int count;

	x = 0;
	closest_index = find_closest_index(ps->len_a, s4, indexes);
	ft_printf("closest index: %d\tindexes left: %d\n", closest_index, indexes);
	if (closest_index < ps->len_a / 2)
	{
		while (x < closest_index)
		{
			rotate_a(ps);
			s4->rotated++;
			x++;
		}
	}
	else
	{
		count = ps->len_a - closest_index;
		while (x < count)
		{
			reverse_a(ps);
			s4->rotated--;
			x++;
		}
	}	
	push_b(ps);
	s4->rotated++;
//	ft_printf("pre_updated indexes: 1: %d\t2: %d\t3: %d\t4: %d\n", s4->smallest_index, s4->s_median_index, s4->l_median_index, s4->largest_index);
	update_index(ps->size, s4, closest_index);
	ft_printf("updated indexes: 1: %d\t2: %d\t3: %d\t4: %d\n", s4->smallest_index, s4->s_median_index, s4->l_median_index, s4->largest_index);
}

void			ps_insertion_sort_4(p_a *ps)
{
	s_4 *s4;
	int indexes;
	static int i;

	if (!i)
		i = 0;
	ft_printf("unordered descending result: %d\tsize: %d\n", find_unordered_descending(ps->b, ps->size), ps->size);
	if (ps->len_a < 4)
		return ;
	if (ps->len_a < 4 && find_unordered_descending(ps->b, ps->size) == 0)
		return (push_all_to_a(ps));
	indexes = 4;
	s4 = (s_4 *)malloc(sizeof(s_4));
	fill_s4_struct_1(ps->a, ps->len_a, s4);
	fill_s4_struct_2(ps->a, ps->len_a, s4);
	s4->size = ps->size;
	fill_index(ps->a, ps->len_a, s4);
	ft_printf("s4 smallest index: %d\n", s4->smallest_index);
	while (indexes > 0)
	{
		push_index(ps, s4, indexes);
		indexes--;
	}
	sort_4_not_alone_b(ps);
//	i++;
//	if (i < 6)
	ps_insertion_sort_4(ps);
}