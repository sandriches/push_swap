/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 15:21:56 by rcorke         #+#    #+#                */
/*   Updated: 2019/08/22 16:53:44 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_ps_listlen(t_clist *list)
{
	t_clist *iter;
	int		x;

	if (!list)
		return (0);
	iter = list;
	x = 0;
	while (iter)
	{
		iter = iter->next;
		x++;
	}
	return (x);
}

static void		remove_from_list(t_ps *ps, int x)
{
	t_clist *iter;
	t_clist	*end;
	int		i;

	iter = ps->clist;
	i = 0;
	while (iter->next && i < x - 1)
	{
		iter = iter->next;
		i++;
	}
	if (iter->next && iter->next->next && iter->next->next->next)
		end = iter->next->next->next;
	else
		end = NULL;
	free(iter->next->next->command);
	free(iter->next->next);
	free(iter->next->command);
	free(iter->next);
	iter->next = end;
}

void			check_for_dumb_commands(t_ps *ps, int x)
{
	t_clist *iter;

	if (ft_ps_listlen(ps->clist) < 6)
		return ;
	iter = ps->clist;
	while (iter->next)
	{
		if (iter->next->next != NULL && iter->next->next->next != NULL)
		{
			if ((!ft_strcmp(iter->command, "pb") && \
			!ft_strcmp(iter->next->command, "pa")) || \
			(!ft_strcmp(iter->command, "pa") && \
			!ft_strcmp(iter->next->command, \
			"pb")))
			{
				remove_from_list(ps, x);
				iter = ps->clist;
				x = 0;
			}
		}
		iter = iter->next;
		x++;
	}
	return ;
}

void			add_to_command_list(t_ps *ps, char *command)
{
	t_clist *iter;

	if (!ps->clist)
	{
		ps->clist = (t_clist *)malloc(sizeof(t_clist));
		ps->clist->command = ft_strdup(command);
		ps->clist->next = NULL;
		return ;
	}
	iter = ps->clist;
	while (iter->next != NULL)
		iter = iter->next;
	iter->next = (t_clist *)malloc(sizeof(t_clist));
	iter->next->command = ft_strdup(command);
	iter->next->next = NULL;
}

void			print_clist(t_ps *ps)
{
	t_clist *iter;
	t_clist	*list_free;

	if (!ps->clist)
		return ;
	iter = ps->clist;
	while (iter->next)
	{
		ft_printf("%s\n", iter->command);
		list_free = iter;
		iter = iter->next;
		free(list_free->command);
		free(list_free);
	}
	ft_printf("%s\n", iter->command);
	free(iter->command);
	free(iter);
}
