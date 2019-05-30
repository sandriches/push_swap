/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/01 17:23:10 by rcorke         #+#    #+#                */
/*   Updated: 2019/05/08 15:54:25 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf.h"
# include <time.h>

typedef struct	push_swap
{
	int	*a;
	int	*b;
	int size;
	int temp;
}				p_a;

typedef struct	find_medium
{
	int data;
	int order;
	int original_order;
	struct find_medium *higher;
	struct find_medium *lower;
}				m_struct;


void		push_a(p_a *push_struct);
void		push_b(p_a *push_struct);
void		swap_a(p_a *push_struct);
void		swap_b(p_a *push_struct);
void		rotate_a(p_a *push_struct);
void		rotate_b(p_a *push_struct);
void		reverse_a(p_a *push_struct);
void		reverse_b(p_a *push_struct);


# endif