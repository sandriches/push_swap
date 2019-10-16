/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/15 16:41:16 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/19 12:48:41 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_end_list_value(t_blist *list)
{
	t_blist	*iter;

	iter = list;
	while (iter->next)
		iter = iter->next;
	return (iter->value);
}

void		add_to_list_end(t_blist *list, int to_add)
{
	t_blist	*new;
	t_blist	*iter;

	new = (t_blist *)malloc(sizeof(t_blist));
	new->value = to_add;
	new->next = NULL;
	iter = list;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = new;
}

void		pop_list_end(t_blist *list)
{
	t_blist	*iter;

	iter = list;
	while (iter->next->next != NULL)
		iter = iter->next;
	free(iter->next);
	iter->next = NULL;
}

void		change_end_list_value(t_blist *list, int new_value)
{
	t_blist	*iter;

	iter = list;
	while (iter->next != NULL)
		iter = iter->next;
	iter->value = new_value;
}

t_blist		*create_list(t_ps *ps)
{
	t_blist	*list;

	list = (t_blist *)malloc(sizeof(t_blist));
	list->value = ps->size;
	list->next = NULL;
	return (list);
}
