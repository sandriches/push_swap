/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:23:10 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/25 15:07:13 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"
# include <time.h>

# define INDX_1 is->smallest_index
# define VALUE_1 is->smallest_value
# define INDX_2 is->second_index
# define VALUE_2 is->second_value
# define INDX_3 is->third_index
# define VALUE_3 is->third_value

# define IN_BIGGEST find_max_min_ps('M', INDX_1, INDX_2, INDX_3)
# define IN_SMALLEST find_max_min_ps('m', INDX_1, INDX_2, INDX_3)

typedef struct	index_struct
{
	int smallest_value;
	int smallest_index;
	int second_value;
	int second_index;
	int third_value;
	int third_index;
}				i_s;

typedef struct sort_4_struct
{
	int smallest;
	int smallest_index;
	int s_median;
	int s_median_index;
	int l_median;
	int l_median_index;
	int largest;
	int largest_index;
	int rotated;
	int size;
}				s_4;


typedef struct	push_swap
{
	int	*a;
	int	*b;
	int *sorted_stack;
	int size;
	int len_a;
	int len_b;
	int temp;
	int ret;
	int print;
}				p_a;

typedef struct	find_medium
{
	int data;
	int order;
	int original_order;
	struct find_medium *higher;
	struct find_medium *lower;
}				m_struct;


void		push_a(p_a *ps);
void		push_b(p_a *ps);
void		swap_a(p_a *ps);
void		swap_b(p_a *ps);
void		swap_both(p_a *ps);
void		rotate_a(p_a *ps);
void		rotate_b(p_a *ps);
void		rotate_both(p_a *ps);
void		reverse_a(p_a *ps);
void		reverse_b(p_a *ps);
void		reverse_both(p_a *ps);


int			find_length(int *array, int len);
void		print_arrays(p_a *ps);

void		ps_quicksort(p_a *ps, char which_stack);
void		ps_insertion_sort_a_3(p_a *ps);
void		ps_insertion_sort_4(p_a *ps);

void		sort_2_or_3_alone_a(p_a *ps);
void		sort_2_or_3_alone_b(p_a *ps);
int			find_unordered_descending(int *stack, int size);
int			find_unordered_ascending(int *stack, int size);

void		sort_4_not_alone_b(p_a *ps);
void		sort_3_not_alone_b(p_a *ps);

void		phill_struct(int *value, int *index, int *new_value, int *new_index);
int			find_median(int *stack, int size);

void		sort_6(p_a *ps);
int			find_smallest_from_3(int a, int b, int c);
int			find_biggest_from_3(int a, int b, int c);
int			return_smallest_int_4(int a, int b, int c, int d);
int			return_biggest_int_4(int a, int b, int c, int d);
int			return_3_int(int a, int b, int c, char sign);

void		check_rotate(p_a *ps, char which_stack);
void		check_r_rotate(p_a *ps, char which_stack);
void		check_swap(p_a *ps, char which_stack);

void        sort_by_median(p_a *ps);

int			lookahead_how_many_bigger(int x, int median, p_a *ps);
int			lookahead_how_many_smaller(int x, int median, p_a *ps);
int			find_unordered_descending(int *stack, int size);
int			find_unordered_ascending(int *stack, int size);
int			is_finished(p_a *ps);


# endif