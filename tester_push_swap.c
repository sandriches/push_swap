/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tester_push_swap.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:22:36 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/08 16:15:36 by rcorke        ########   odam.nl         */
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
	ft_printf("----------");
	while (x < ps->size)
	{
		ft_printf("----");
		x++;
	}
	x = 0;
	ft_printf("\nSTACK A: ");
	while (x < ps->size)
	{
		if (ps->a[x] == 0)
			ft_printf("|   ");
		else
			ft_printf("| {/}%c{BLUE} ", ps->a[x] + 48);
		x++;
	}
	x = 0;
	ft_printf("|{GREEN}\n");
	ft_printf("----------");
	while (x < ps->size)
	{
		ft_printf("----");
		x++;
	}
	x = 0;
	ft_printf("\n{RED}STACK B: ");
	while (x < ps->size)
	{
		if (ps->b[x] == 0)
			ft_printf("|   ");
		else
			ft_printf("| {/}%c{RED} ", ps->b[x] + 48);
		x++;
	}
	x = 0;
	ft_printf("|\n----------");
	while (x < ps->size)
	{
		ft_printf("----");
		x++;
	}
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

static int			find_size(int *stack)
{
	int x;

	x = 0;
	while (stack[x] != 0)
		x++;
	return (x);
}

static int			find_median(int *stack, int size)
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
/*	x = 0;
	while (ordered_stack[x] != 0)
	{
		ft_printf("ordered_stack[%d]: %d\n", x, ordered_stack[x]);
		x++;
	}
	*/
	tmp = (size % 2 != 0) ? ordered_stack[size / 2] : ordered_stack[(size / 2) - 1];
	free(ordered_stack);
	return (tmp);
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

void	convert_from_originals(m_struct *node, p_a *ps)
{
	int x;
	m_struct *tmp;

	x = 0;
	while (x < ps->size - 1)
	{
		tmp = find_node(node, ps->a[x]);
//		ft_printf("tmp->data[%d]: %d\n", x, tmp->data);
//		ft_printf("find_new_data result: %d\n", find_new_data(node, ps->original_order[x]));
		x++;
	}
}

void	sort_by_median(p_a *ps, char which_stack)
{
	int x;
	int median;
	int size;

	size = (which_stack == 'a') ? find_size(ps->a) : find_size(ps->b);
	median = (which_stack == 'a') ? find_median(ps->a, size) : find_median(ps->b, size);
//	ft_printf("median: %d\n", median);
	x = 0;
	while (x < ps->size)
	{
		if (which_stack == 'a')
		{
			if (ps->a[0] > median)
			{
				push_b(ps);
				print_arrays(ps);
			}
			else
			{
				rotate_a(ps);
				print_arrays(ps);
			}
		}
		else
		{
			if (ps->b[0] < median)
			{
				push_a(ps);
				print_arrays(ps);
			}
			else
			{
				rotate_b(ps);
				print_arrays(ps);
			}
		}
		x++;
	}
}

static int		is_ordered_descending(int *stack)
{
	int x;

	x = 1;
	while (stack[x] != 0)
	{
		if (stack[x - 1] < stack[x])
			return (0);
		x++;
	}
	return (1);
}

static int		is_ordered_ascending(int *stack)
{
	int x;

	x = 1;
	while (stack[x] != 0)
	{
		if (stack[x - 1] > stack[x])
			return (0);
		x++;
	}
	return (1);
}

static int		is_finished(p_a *ps)
{
	if (is_ordered_ascending(ps->a) == 1 && find_size(ps->b) == 0)
		return (1);
	return (0);
}

void	sort_finished(p_a *ps, char which_stack)
{
	int temp;
	int size;

	temp = 0;
	size = (which_stack == 'a') ? find_size(ps->a) : find_size(ps->b);
	if (which_stack == 'b')
	{
		if (size == 2 && ps->b[0] > ps->b[1])
		{
			swap_b(ps);
			print_arrays(ps);
		}
		else if (size == 3)
		{
			if (ps->b[0] > ps->b[1] && ps->b[0] > ps->b[2])
			{
				rotate_b(ps);
				print_arrays(ps);
			}
			else if (ps->b[1] > ps->b[0] && ps->b[2])
			{
				reverse_b(ps);
				print_arrays(ps);
			}
			if (ps->b[0] > ps->b[1])
			{
				swap_b(ps);
				print_arrays(ps);
			}
		}
	}
	else
	{
		if (size == 2 && ps->a[0] < ps->a[1])
		{
			swap_a(ps);
			print_arrays(ps);
		}
		else if (size == 3)
		{
			if (ps->a[0] < ps->a[1] && ps->a[0] < ps->a[2])
			{
				rotate_a(ps);
				print_arrays(ps);
			}
			else if (ps->a[1] < ps->a[0] && ps->a[2])
			{
				reverse_b(ps);
				print_arrays(ps);
			}
			if (ps->a[0] < ps->a[1])
			{
				swap_a(ps);
				print_arrays(ps);
			}
		}
	}
}

void	start_sort(p_a *ps)
{
	while (is_finished(ps) == 0)
	{
		if (find_size(ps->b) <= ps->size / 2)
		{
			sort_finished(ps, 'b');
		}
		else if (find_size(ps->a) <= ps->size / 2)
		{
			sort_finished(ps, 'a');
		}
		sort_by_median(ps, 'a');
	}
}

void	start_struct(int argc, char **args)
{
	p_a *ps;
	m_struct *head;
	int x;

	x = 0;
	head = NULL;
	ps = (p_a *)malloc(sizeof(p_a));
	ps->size = argc - 1;
	ps->temp = 0;
	ps->a = (int *)malloc(sizeof(int) * ps->size);
	ps->b = (int *)malloc(sizeof(int) * ps->size);
//	ps->original_order = (int *)malloc(sizeof(int) * ps->size);
	fill_arrays(ps, args);
	head = make_tree(ps, head);
	add_order(head);
//	convert_from_originals(head, ps);
	print_arrays(ps);
	sort_by_median(ps, 'a');
	print_arrays(ps);
	start_sort(ps);
	print_arrays(ps);
//	start_program(ps);
}

int	main(int argc, char **argv)
{
	start_struct(argc, argv);
	return (0);
}