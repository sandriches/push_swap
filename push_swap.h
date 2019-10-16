/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/12 12:30:58 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/22 16:56:16 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "ft_printf.h"

typedef struct	s_clist
{
	char			*command;
	struct s_clist	*next;
}				t_clist;

typedef struct	s_ps
{
	int		*a;
	int		*b;
	int		len_a;
	int		len_b;
	int		size;
	int		temp;
	int		ret;
	int		a_value;
	int		a_done;
	int		print_commands;
	int		print_stacks;
	int		check;
	t_clist	*clist;
}				t_ps;

typedef struct	s_blist
{
	int				value;
	struct s_blist	*next;
}				t_blist;

int				push_a(t_ps *ps);
int				push_b(t_ps *ps);
int				swap_a(t_ps *ps);
int				swap_b(t_ps *ps);
int				swap_both(t_ps *ps);
void			check_swap(t_ps *ps, char which_stack);
int				rotate_a(t_ps *ps);
int				rotate_b(t_ps *ps);
int				rotate_both(t_ps *ps);
int				check_r_rotate(t_ps *ps, char which_stack);
int				check_rotate(t_ps *ps, char which_stack);
int				reverse_a(t_ps *ps);
int				reverse_b(t_ps *ps);
int				reverse_both(t_ps *ps);
void			ft_int_mem_move(int *dst, int *src, int len);
void			ft_rev_int_mem_move(int *dst, int *src, int len, int temp);
void			print_arrays(t_ps *ps);
int				find_median(int	*stack, int	size);
int				find_median_sorted_array(int *stack, int len);
void			big_algorithm_three(t_ps *ps);
void			big_algo_two(t_ps *ps);
void			small_algo(t_ps *ps);
void			sort_3_a(t_ps *ps);
void			sort_3_b(t_ps *ps);
void			sort_4(t_ps *ps);
int				find_unordered_ascending(int *stack, int size);
int				find_unordered_descending(int *stack, int size);
int				check_amount_left_to_push_b(t_ps *ps, int len, int x, int med);
int				check_amount_left_to_push_a(t_ps *ps, int len, int x, int med);
int				check_rm_array(t_ps *ps, int index, int loop_counter);
void			reset_rm_array(t_ps *ps, int index);
void			change_end_list_value(t_blist *list, int new_value);
void			pop_list_end(t_blist *list);
void			add_to_list_end(t_blist *list, int to_add);
int				get_end_list_value(t_blist *list);
t_blist			*create_list(t_ps *ps);
void			smart_sort_finish_b(t_ps *ps, int len, int rtd, int pushed);
void			smart_sort_finish_a_inoff(t_ps *ps, int len, int rtd, int pd);
void			smart_sort_finish_a_off(t_ps *ps, int len, int pushed);
void			smart_sort_finish_b2(t_ps *ps, int len, int rotated, int pd);
void			smart_sort_finish_a_inoff2(t_ps *ps, int len, int rtd, int pd);
void			smart_sort_finish_a_off2(t_ps *ps, int len, int pushed);
int				get_index(int *array, int size, char sign);
char			x_rotate_or_reverse(t_ps *ps, int *s_array, int array_size);
void			fill_sorted_array_a(t_ps *ps, int *array, int amount, int l_o);
void			get_x_from_stack_a(t_ps *ps, int amt, int loop_over, int inoff);
int				check_errors(int argc, char **argv);
int				ps_get_next_line(const int fd, char **line);
void			sort_a_by_half(t_ps *ps, t_blist *list, int len);
void			sort_b_by_half(t_ps *ps, t_blist *list, int len, int inoff);
void			sort_a_by_half2(t_ps *ps, t_blist *list, int len);
void			sort_b_by_half2(t_ps *ps, t_blist *list, int len, int inoff);
void			add_to_command_list(t_ps *ps, char *command);
void			print_clist(t_ps *ps);
void			check_for_dumb_commands(t_ps *ps, int x);

#endif
