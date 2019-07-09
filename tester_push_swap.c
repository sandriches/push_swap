/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester_push_swap.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:22:36 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/09 17:03:47 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		command_to_op(char *str, p_a *ps)
{
	if (ft_strcmp(str, "sa") == 0)
		swap_a(ps);
	else if (ft_strcmp(str, "sb") == 0)
		swap_b(ps);
	else if (ft_strcmp(str, "pa") == 0)
		push_a(ps);
	else if (ft_strcmp(str, "pb") == 0)
		push_b(ps);
	else if (ft_strcmp(str, "ra") == 0)
		rotate_a(ps);
	else if (ft_strcmp(str, "rb") == 0)
		rotate_b(ps);
	else if (ft_strcmp(str, "rr") == 0)
		rotate_both(ps);
	else if (ft_strcmp(str, "rra") == 0)
		reverse_a(ps);
	else if (ft_strcmp(str, "rrb") == 0)
		reverse_b(ps);
	else if (ft_strcmp(str, "rrr") == 0)
		reverse_both(ps);
	else
		return (0);
	return (1);
}

void	start_program(p_a *ps)
{
	int		ret;
	int		command;
	char	str[25];

	ret = 0;
	print_arrays(ps);
	while (ft_strcmp(str, "q") != 0)
	{
		ft_strclr(str);
//		ft_printf("size of a: %d\n", find_size(ps->a));
		// ft_printf("median: %d\n", find_median(ps->a, find_size(ps->a)));
		ft_printf("Moves: %d\n\n", ret);
		ft_printf("[q to quit, - to moves--] ENTER COMMAND: ");
		scanf("%s", str);
		command = command_to_op(str, ps);
		if (command == 1)
			ret++;
		if (ft_strcmp(str, "-") == 0)
			ret--;
	}
}



static m_struct		*make_struct(int data)
{
	m_struct *rtn_struct;

	rtn_struct = (m_struct *)malloc(sizeof(m_struct));
	rtn_struct->data = data;
	rtn_struct->higher = NULL;
	rtn_struct->lower = NULL;
	return (rtn_struct);
}


void		traverse_tree(m_struct *iterate, m_struct *new)
{
	if (new->data >= iterate->data && iterate->higher == NULL)
		iterate->higher = new;
	else if (new->data < iterate->data && iterate->lower == NULL)
		iterate->lower = new;
	else if (new->data >= iterate->data && iterate->higher != NULL)
		traverse_tree(iterate->higher, new);
	else if (new->data < iterate->data && iterate->lower != NULL)
		traverse_tree(iterate->lower, new);
}

m_struct	*find_node(m_struct *head, int data)
{
	if (!head)
		return (0);
	if (head->data == data)
		return (head);
	else if (data > head->data)
		return (find_node(head->higher, data));
	else if (data < head->data)
		return (find_node(head->lower, data));
//	else
//		return (0);
}

void		add_order(m_struct *head)
{
	static int		i;

	if (!i)
		i = 0;
	if (head != NULL)
	{
		add_order(head->lower);
		head->order = i;
		i++;
//		ft_printf("DATA: %d|ORDER: %d\n", head->data, head->order);
		add_order(head->higher);
	}
}

m_struct	*make_tree(p_a *ps, m_struct *head)
{
	int x;
	m_struct *new;
	m_struct *iterate;

	head = make_struct(ps->a[0]);
	iterate = head;
	x = 1;
	while (x < ps->size)
	{
		new = make_struct(ps->a[x]);
		traverse_tree(iterate, new);
		iterate = head;
		x++;
	}
	return (head);
}

void	fill_arrays(p_a *ps, char **args)
{
	int x;

	x = 1;
	while (x < ps->size + 1)
	{
		ps->a[x - 1] = ft_atoi(args[x]);
		ps->b[x - 1] = 0;
		x++;
	}
}

static int			find_numbers_to_push(int *stack, int median, char sign, int stack_size)
{
	int x;
	int to_push;

	x = 0;
	to_push = 0;
	while (x < stack_size)
	{
		if (sign == '>')
		{
			if (stack[x] > median)
				to_push++;
		}
		else
		{
			if (stack[x] < median)
				to_push++;
		}
		x++;
	}
	return (to_push);
}

static int			*fill_ordered_stack(int *stack, int *ordered_stack, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		ordered_stack[x] = stack[x];
		x++;
	}
	return (ordered_stack);
}

static int		find_position_to_place(p_a *ps, char which_stack, int to_place)
{
	int x;

	x = 0;
	if (which_stack == 'a')
	{
		while (x < ps->len_a)
		{
			if (to_place < ps->a[x])
				return (x);
			x++;
		}
	}
	else
	{
		while (x < ps->len_b)
		{
			if (to_place > ps->b[x])
				return (x);
			x++;
		}
	}
	return (x);
}

static void		place_one_a(p_a *ps)
{
	int x;
	int pos_to_place;

	x = 0;
	pos_to_place = find_position_to_place(ps, 'a', ps->b[0]);
	if (pos_to_place == 0)
	{
		push_a(ps);
		return ;
	}
	else if (pos_to_place == 1)
	{
		push_a(ps);
		check_swap(ps, 'a');
	}
//	ft_printf("position to place: %d\tstack size: %d\n", pos_to_place, ps->len_a);
	if (pos_to_place > ps->len_a / 2)
	{
		while (x < pos_to_place)
		{
			reverse_a(ps);
			x++;
		}
		push_a(ps);
		while (x >= 0)
		{
			rotate_a(ps);
			x--;
		}
	}
	else
	{
		while (x < pos_to_place)
		{
			rotate_a(ps);
			x++;
		}
		push_a(ps);
		while (x > 0)
		{
			reverse_a(ps);
			x--;
		}
	}
}

static void		place_one_b(p_a *ps)
{
	int x;
	int pos_to_place;

	x = 0;
	pos_to_place = find_position_to_place(ps, 'b', ps->a[0]);
	if (pos_to_place == 0)
	{
		push_b(ps);
		return ;
	}
	else if (pos_to_place == 1)
	{
		push_b(ps);
		check_swap(ps, 'b');
	}
//	ft_printf("position to place: %d\tstack size: %d\n", pos_to_place, ps->len_b);
	if (pos_to_place > ps->len_b / 2)
	{
		while (x < pos_to_place)
		{
			rotate_b(ps);
			x++;
		}
		push_b(ps);
		while (x >= 0)
		{
			reverse_b(ps);
			x--;
		}
	}
	else
	{
		while (x < pos_to_place)
		{
			reverse_b(ps);
			x++;
		}
		push_b(ps);
		while (x > 0)
		{
			rotate_b(ps);
			x--;
		}
	}
}

void	sort_by_median_a(p_a *ps)
{
	int x;
	int median;
	int loops;
	int pushed;

	pushed = 0;
	loops = ps->len_a;
	median = find_median(ps->a, ps->len_a);
//	ft_printf("median[A]: %d\tloops: %d\n", median, loops);
	x = 0;
	while (x < loops)
	{
		// if (lookahead_how_many_smaller(x, median, ps) == 0)
		// 	break ;
		// else if (lookahead_how_many_smaller(x, median, ps) == 1 && ps->len_a == 3)
		// 	break ;
		if (ps->a[0] < median)
		{
			if (ps->len_b > 1 && find_unordered_descending(ps->b, ps->len_b) == 0)
			{
				place_one_b(ps);
			}
			else
				push_b(ps);
		}
		else 
			rotate_a(ps);
		x++;
	}
}

void	sort_by_median_b(p_a *ps)
{
	int x;
	int median;
	int loops;

	loops = ps->len_b;
	x = 0;
	median = find_median(ps->b, ps->len_b);
//	ft_printf("median[A]: %d\tloops: %d\n", median, loops);
	while (x < loops)
	{
		// if (lookahead_how_many_bigger(x, median, ps) == 0)
		// 	break ;
		// else if (lookahead_how_many_bigger(x, median, ps) == 1 && ps->len_b == 3)
		// 	break ;
		if (ps->b[0] > median)
		{
			if (ps->len_a > 1 && find_unordered_ascending(ps->a, ps->len_a) == 0)
			{
				place_one_a(ps);
			}
			else
				push_a(ps);
		}
		else
			rotate_b(ps);
		x++;
	}
}

void	sort_2_or_3_alone_b(p_a *ps)
{
	if (ps->len_b == 2 && ps->b[0] < ps->b[1])
		check_swap(ps, 'b');
	else if (ps->len_b == 3)
	{
		if (ps->b[0] < ps->b[1] && ps->b[0] < ps->b[2])
			rotate_b(ps);
		else if (ps->b[1] < ps->b[0] && ps->b[1] < ps->b[2])
			reverse_b(ps);
		if (ps->b[0] < ps->b[1])
			check_swap(ps, 'b');
	}
}

void	sort_2_or_3_alone_a(p_a *ps)
{
	if (ps->len_a == 2 && ps->a[0] > ps->a[1])
		check_swap(ps, 'a');
	else if (ps->len_a == 3)
	{
		if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
			rotate_a(ps);
		else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
			reverse_a(ps);
		if (ps->a[0] > ps->a[1])
			check_swap(ps, 'a');
	}
}

static void		push_rest_to_a(p_a *ps)
{
	int x;

	x = 0;
	while (x < ps->len_b)
		push_a(ps);
}

static void		start_sort(p_a *ps)
{
	int unordered_a;
	int unordered_b;

	unordered_a = find_unordered_ascending(ps->a, ps->len_a);
	unordered_b = find_unordered_descending(ps->b, ps->len_b);
	if (is_finished(ps) == 1)
	{
		// ft_printf("DONE\n");
		return ;
	}
	if (unordered_a == 0 && unordered_b == 0)
	{
		ft_printf("PUSH ALL TO A\n");
		push_rest_to_a(ps);
	}
	else if (ps->len_a > 3 && unordered_a > 0)
	{
		ft_printf("SORT BY MEDIAN - STACK A\n");
		sort_by_median_a(ps);
	}
	else if (ps->len_b <= 3 && unordered_b > 0)
	{
		ft_printf("SORT BY 2/3 - STACK B\n");
		sort_2_or_3_alone_b(ps);
	}
	else if (unordered_a == 0)
	{
		ft_printf("SORT BY MEDIAN - STACK B\n");
		sort_by_median_b(ps);
	}
	else if (ps->len_a <= 3 && unordered_a > 0)
	{
		ft_printf("SORT BY 2/3 - STACK A\n");
		sort_2_or_3_alone_a(ps);
	}
//	i++;
//	if (i < 500)
	start_sort(ps);
}

void	start_struct(int argc, char **args)
{
	p_a *ps;
	m_struct *head;
	int x;

	x = 0;
	head = NULL;
	ps = (p_a *)malloc(sizeof(p_a));
	ps->len_a = argc - 1;
	ps->len_b = 0;
	ps->size = argc - 1;
	ps->temp = 0;
	ps->ret = 0;
	ps->print_commands = 1;
	ps->a = (int *)malloc(sizeof(int) * ps->len_a);
	ps->b = (int *)malloc(sizeof(int) * ps->len_a);
//	ps->ordered_stack = fill_ordered_stack()
	ps->print_stacks = 0;
	fill_arrays(ps, args);
	head = make_tree(ps, head);
	add_order(head);
	print_arrays(ps);
//	ps_quicksort(ps, 'a');
	// ps_insertion_sort_a_3(ps);
	// ps_insertion_sort_4(ps);
	// sort_4_not_alone_b(ps);
//	print_arrays(ps);
	// start_sort(ps);
	// sort_6(ps);
	// sort_by_median(ps);
	sort_by_median_over_200(ps);
	// ft_ps_half_500(ps, ps->size);
	print_arrays(ps);
	ft_printf("\n\nARGUMENTS: {BLUE}%d{/}\nTOTAL COUNT: {YELLOW}%d{/}\n", ps->size, ps->ret);
	if (find_unordered_ascending(ps->a, ps->len_a) == 0 && ps->len_b == 0)
		ft_printf("{GREEN}CORRECTLY SORTED!{/}\n\n");
	else
	{
		ft_printf("\nUNORDERED LEFT ON A: {RED}%d[%d]{/}\n\n", find_unordered_ascending(ps->a, ps->len_a), find_first_unordered_ascending(ps->a, ps->len_a));
		ft_printf("UNORDERED FROM 1: %d\n", find_unordered_ascending_from_one(ps->a, ps->len_a));
	}
//	start_program(ps);
}

int		main(int argc, char **argv)
{
	start_struct(argc, argv);
	return (0);
}
