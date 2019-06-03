/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester_push_swap.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:22:36 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/03 17:44:22 by rcorke        ########   odam.nl         */
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
	else if (ft_strcmp(str, "rra") == 0)
		reverse_a(ps);
	else if (ft_strcmp(str, "rrb") == 0)
		reverse_b(ps);
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate_a(ps);
		rotate_b(ps);
	}
	else if (ft_strcmp(str, "rrr") == 0)
	{
		reverse_a(ps);
		reverse_b(ps);
	}
	else
		return (0);
	return (1);
}

void	print_arrays(p_a *ps)
{
	int x;

	x = 0;
	ft_printf("{BLUE}\n\n");
	ft_printf("\nSTACK A[%d]: ", ps->len_a);
	while (x < ps->len_a)
	{
		if (ps->a[x] == 0)
			ft_printf("|   ");
		else
			ft_printf("|\t{/}%d{BLUE}\t", ps->a[x]);
		x++;
	}
	x = 0;
	ft_printf("|{GREEN}\n");
	ft_printf("----------");
/*	while (x < ps->size)
	{
		ft_printf("---------------");
		x++;
	}*/
	x = 0;
	ft_printf("\n{RED}STACK B[%d]: ", ps->len_b);
	while (x < ps->len_b)
	{
		if (ps->b[x] == 0)
			ft_printf("|   ");
		else
			ft_printf("|\t{/}%d{RED}\t", ps->b[x]);
		x++;
	}
	x = 0;
	ft_printf("|\n");
	ft_printf("{/}\n\n\n");
}

void	start_program(p_a *ps)
{
	int		ret;
	int		command;
	char	str[25];

	ret = 0;
	while (ft_strcmp(str, "q") != 0)
	{
		ft_strclr(str);
		print_arrays(ps);
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

static int		lookahead_median_split(int x, char sign, int median, p_a *ps)
{
	int y;

	y = 0;
	if (sign == '>')
	{
		while (x < ps->len_b)
		{
			if (ps->b[y] > median)
				return (0);
			x++;
			y++;
		}
	}
	else
	{
		while (x < ps->len_a)
		{
			if (ps->a[y] < median)
				return (0);
			x++;
			y++;
		}
	}
	return (1);
}

static int			find_size(int *stack)
{
	int x;

	x = 0;
	while (stack[x] != 0)
		x++;
	return (x);
}

static int			find_numbers_to_push(int *stack, int median, char sign, int stack_size)
{
	int x;
	int to_push;

	x = 0;
	to_push = 0;
	while (stack[x] != 0)
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

static int			find_median(int *stack, int size, char sign)
{
	int x;
	int y;
	int *ordered_stack;
	int ordered_size;
	int tmp;

	ordered_stack = (int *)malloc(sizeof(int) * size);
	ordered_size = size - 1;
	x = 0;
	y = 0;
	while (x < size)
	{
		ordered_stack[x] = stack[x];
		x++;
	}
	x = 0;
	while (x < size)
	{
		while (y < ordered_size)
		{
			if (ordered_stack[y] > ordered_stack[y + 1])
			{
				tmp = ordered_stack[y];
				ordered_stack[y] = ordered_stack[y + 1];
				ordered_stack[y + 1] = tmp;
			}
			y++;
		}
		ordered_size--;
		y = 0;
		x++;
	}
	tmp = (size % 2 != 0) ? ordered_stack[size / 2] : ordered_stack[(size / 2) - 1];
	if (size % 2 == 0)
	{
		if (find_numbers_to_push(stack, tmp, sign, size) * 2 != size)
			tmp = ordered_stack[(size / 2)];
	}
	free(ordered_stack);
	return (tmp);
}

void	sort_by_median_a(p_a *ps)
{
	int x;
	int median;
	int loops;
	int pushed;

	pushed = 0;
	loops = ps->len_a;
	median = find_median(ps->a, ps->len_a, '<');
	ft_printf("median[A]: %d\n", median);
	x = 0;
	while (x < loops)
	{
		//if (lookahead_median_split(x, '<', median, ps) == 1)
		//	break ;
		if (ps->a[0] < median)
		{
			push_b(ps);
			pushed++;
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
	median = find_median(ps->b, ps->len_b, '>');
	ft_printf("median[B]: %d\n", median);
	while (x < loops)
	{
		//if (lookahead_median_split(x, '>', median, ps) == 1)
		//	break ;
		if (ps->b[0] > median)
			push_a(ps);
		else
			rotate_b(ps);
		x++;
	}
}

static int		is_ordered_descending(int *stack, int size)
{
	int x;

	x = 1;
	while (x < size)
	{
		if (stack[x - 1] < stack[x])
			return (0);
		x++;
	}
	return (1);
}

static int		is_ordered_ascending(int *stack, int size)
{
	int x;

	x = 1;
	while (x < size)
	{
		if (stack[x - 1] > stack[x])
			return (0);
		x++;
	}
	return (1);
}

static int		is_finished(p_a *ps)
{
	if (is_ordered_ascending(ps->a, ps->len_a) == 1 && ps->len_b == 0)
		return (1);
	return (0);
}

void	sort_2_or_3_alone(p_a *ps, char which_stack)
{
	if (which_stack == 'b')
	{
		if (ps->len_b == 2 && ps->b[0] < ps->b[1])
			swap_b(ps);
		else if (ps->len_b == 3)
		{
			if (ps->b[0] < ps->b[1] && ps->b[0] < ps->b[2])
				rotate_b(ps);
			else if (ps->b[1] < ps->b[0] && ps->b[1] < ps->b[2])
				reverse_b(ps);
			if (ps->b[0] < ps->b[1])
				swap_b(ps);
		}
	}
	else
	{
		if (ps->len_a == 2 && ps->a[0] > ps->a[1])
			swap_a(ps);
		else if (ps->len_a == 3)
		{
			if (ps->a[0] > ps->a[1] && ps->a[0] > ps->a[2])
				rotate_a(ps);
			else if (ps->a[1] > ps->a[0] && ps->a[1] > ps->a[2])
				reverse_a(ps);
			if (ps->a[0] > ps->a[1])
				swap_a(ps);
		}
	}
}

static void		push_rest_to_a(p_a *ps)
{
	int x;

	x = 0;
	while (x < ps->len_b)
		push_a(ps);
}

static int		start_sort(p_a *ps)
{
	static int i;
	int ordered_a;
	int ordered_b;

	ordered_a = is_ordered_ascending(ps->a, ps->len_a);
	ordered_b = is_ordered_descending(ps->b, ps->len_b);
	if (!i)
		i = 0;
	if (is_finished(ps) == 1)
	{
		ft_printf("DONE\n");
		return (1);
	}
	if (ps->len_a > 3 && ordered_a == 0)
	{
		ft_printf("SORT BY MEDIAN - STACK A\n");
		sort_by_median_a(ps);
	}
	else if (ps->len_b <= 3 && ordered_b == 0)
	{
		ft_printf("SORT BY 2/3 - STACK B\n");
		sort_2_or_3_alone(ps, 'b');
	}
	else if (ordered_a == 1 && ordered_b == 1)
	{
		ft_printf("PUSH ALL TO A\n");
		push_rest_to_a(ps);
	}
	else if (ps->len_a <= 3 && ordered_a == 1)
	{
		ft_printf("SORT BY MEDIAN - STACK B\n");
		sort_by_median_b(ps);
	}
	else if (ps->len_a <= 3 && ordered_a == 0)
	{
		ft_printf("SORT BY 2/3 - STACK A\n");
		sort_2_or_3_alone(ps, 'a');
	}
	i++;
//	if (i < 50)
		start_sort(ps);
/*	else if (ordered_b == 0 && length_b < 4)
	{
		ft_printf("IF 1\n");
		sort_2_or_3_alone(ps, 'b');
	}
	else if (ordered_a == 0 && length_a < 4)
	{
		ft_printf("IF 2\n");
		sort_2_or_3_alone(ps, 'a');
	}
	else
	{
		ft_printf("IF 3\n");
		sort_by_median(ps, 'b');
	}
	i++;
	if (i < 5)
		start_sort(ps);*/
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
	ps->a = (int *)malloc(sizeof(int) * ps->len_a);
	ps->b = (int *)malloc(sizeof(int) * ps->len_a);
	fill_arrays(ps, args);
	head = make_tree(ps, head);
	add_order(head);
	start_sort(ps);
	ft_printf("TOTAL COUNT: %d\n", ps->ret);
//	start_program(ps);
}

int	main(int argc, char **argv)
{
	start_struct(argc, argv);
	return (0);
}