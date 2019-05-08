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
	ft_printf("{BLUE}\n\n\n\n");
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
		ft_printf("Moves made: %d\n\n", ret);
		ft_printf("[q to quit] ENTER COMMAND: ");
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

int			find_original_order(m_struct *node, int data)
{
	if (!node)
		return (-1);
	if (node->data == data)
		return (node->original_order);
	else if (node->data < data && node->higher != NULL)
		return (find_original_order(node->higher, data));
	else if (node->data > data && node->lower != NULL)
		return (find_original_order(node->lower, data));
	return (-1);
}

int			find_new_data(m_struct *node, int order)
{
	if (!node)
		return (-1);
	if (node->original_order == order)
		return (node->data);
	else if (node->original_order < order && node->higher != NULL)
		return (find_original_order(node->higher, order));
	else if (node->original_order > order && node->lower != NULL)
		return (find_original_order(node->lower, order));
	return (-1);
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
//		ft_printf("DATA: %d|ORDER: %d|Orignal order: %d\n", head->data, head->order, head->original_order);
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
		new->original_order = x;
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
		ps->original_a[x - 1] = ft_atoi(args[x]);
		ps->original_b[x - 1] = 0;
		x++;
	}
}

void	fill_ordered_arrays(m_struct *node, p_a *ps)
{
	int ordered_number;
	int x;

	x = 0;
	while (x < ps->size)
	{
		ft_printf("result from search: %d\n", find_new_data(node, ps->original_a[x]));
		ps->a[x] = find_new_data(node, ps->original_a[x]);
		x++;
	}
}

void	start_struct(int argc, char **args)
{
	p_a *ps;
	m_struct *head;
	int x;
	int place_in_position;

	x = 0;
	place_in_position = 0;
	head = NULL;
	ps = (p_a *)malloc(sizeof(p_a));
	ps->size = argc - 1;
	ps->temp = 0;
	ps->a = (int *)malloc(sizeof(int) * ps->size);
	ps->b = (int *)malloc(sizeof(int) * ps->size);
	ps->original_a = (int *)malloc(sizeof(int) * ps->size);
	ps->original_b = (int *)malloc(sizeof(int) * ps->size);
	fill_arrays(ps, args);
	head = make_tree(ps, head);
	fill_ordered_arrays(head, ps);
	add_order(head);
//	print_arrays(ps);
//	start_program(ps);
}

int	main(int argc, char **argv)
{
	start_struct(argc, argv);
	return (0);
}