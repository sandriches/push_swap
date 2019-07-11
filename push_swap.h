/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:23:10 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/12 00:28:36 by sandRICH      ########   odam.nl         */
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
	int *h_a;
	int *h_b;
	int size;
	int len_a;
	int len_b;
	int temp;
	int ret;
	int print_stacks;
	int print_commands;
	int w_case;
}				p_a;

typedef struct	find_medium
{
	int data;
	int order;
	int original_order;
	struct find_medium *higher;
	struct find_medium *lower;
}				m_struct;

int			push_a(p_a *ps);
int			push_b(p_a *ps);
int			swap_a(p_a *ps);
int			swap_b(p_a *ps);
int			swap_both(p_a *ps);
int			rotate_a(p_a *ps);
int			rotate_b(p_a *ps);
int			rotate_both(p_a *ps);
int			reverse_a(p_a *ps);
int			reverse_b(p_a *ps);
int			reverse_both(p_a *ps);


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
void		sort_4_not_alone_a(p_a *ps);
void		sort_3_not_alone_b(p_a *ps);
void		sort_4_high_low_b(p_a *ps);

void	get_x_from_stack_a(p_a *ps, int amount, int loop_over, int inoffensive);
void	get_x_from_stack_b(p_a *ps, int amount, int loop_over, int inoffensive);

void		phill_struct(int *value, int *index, int *new_value, int *new_index);
int			find_median(int *stack, int size);

void		sort_6(p_a *ps);
int			find_smallest_from_3(int a, int b, int c);
int			find_biggest_from_3(int a, int b, int c);
int			return_smallest_int_4(int a, int b, int c, int d);
int			return_biggest_int_4(int a, int b, int c, int d);
int			return_3_int(int a, int b, int c, char sign);

int		check_rotate(p_a *ps, char which_stack);
int		check_r_rotate(p_a *ps, char which_stack);
void		check_swap(p_a *ps, char which_stack);

void        sort_by_median(p_a *ps);
void		sort_by_med_b(p_a *ps, int loops, int inoffensive);
void		sort_by_med_a(p_a *ps, int loops, int inoffensive);



int		lookahead_how_many_bigger(int x, int median, p_a *ps, int amount_to_search);
int		lookahead_how_many_smaller(int x, int median, p_a *ps, int amount_to_search);
int			find_unordered_descending(int *stack, int size);
int			find_unordered_ascending(int *stack, int size);
int				find_first_unordered_ascending(int *stack, int size);

int			is_finished(p_a *ps);


int				*make_halving_array(int size, char which_array);
void		sort_by_med_b(p_a *ps, int loops, int inoffensive);
void		sort_by_med_a(p_a *ps, int loops, int inoffensive);
void		do_recursion_a(p_a *ps, int start_loop, int *half_array, int old_len);

void	grab_4_from_b(p_a *ps, int size);
void			grab_4_from_a(p_a *ps, int size);

void		grab_2_from_b(p_a *ps, int size);
int		get_highest_from_stack(int *stack, int size);
int		get_lowest_from_stack(int *stack, int size);

void			grab_4_high_low_from_b(p_a *ps, int size);
void			grab_4_high_low_from_a(p_a *ps, int size);

void		grab_2_high_low(p_a *ps, int size);



void		sort_by_median_over_200(p_a *ps);
int				find_unordered_ascending_from_one(int *stack, int size);
void		ft_ps_half_100(p_a *ps, int size);
void		ft_ps_half_500(p_a *ps, int size);


int		get_num(p_a *ps, int step);

void easy_peasy(p_a * ps);


int		check_errors(int argc, char **argv);


# endif