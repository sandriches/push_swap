/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:23:10 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/07 12:05:06 by rcorke        ########   odam.nl         */
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
	int smallest_used;
	int second_value;
	int second_index;
	int second_used;
	int third_value;
	int third_index;
	int third_used;
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

void		sort_2_or_3_alone(p_a *ps, char which_stack);
int				find_unordered_descending(int *stack, int size);
int				find_unordered_ascending(int *stack, int size);

void		sort_4_not_alone_b(p_a *ps);
void		sort_3_not_alone_b(p_a *ps);



# endif