/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 01:28:50 by marvin            #+#    #+#             */
/*   Updated: 2025/11/16 01:28:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack	*a)
{
	t_node	*t;
	t_node	*bt;
	t_node	*mid;

	if (a == NULL || a->size < 2)
		return ;
	t = a->top;
	bt = a->bottom;
	mid = bt->prev;

	a->top = bt;
	a->bottom = mid;
	bt->prev = NULL;
	bt->next = t;
	t->prev = bt;
	mid->next = NULL;
}

void	rrb(t_stack	*b)
{
	t_node	*t;
	t_node	*bt;
	t_node	*mid;

	if (b == NULL || b->size < 2)
		return ;
	t = b->top;
	bt = b->bottom;
	mid = bt->prev;

	b->top = bt;
	b->bottom = mid;
	bt->prev = NULL;
	bt->next = t;
	t->prev = bt;
	mid->next = NULL;
}

static t_node	*p_help(t_stack	*b, t_node	*t_b)
{
	t_b = b->top;
	if (b->size == 1)
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	else 
	{
		b->top = t_b->next;
		t_b->next->prev = NULL;
	}
	b->size--;
	return (t_b);
}

void	pa(t_stack	*a, t_stack	*b)
{
	t_node	*t_b;
	t_node	*t_a;

	if (b == NULL || b->size == 0)
		return ;
	t_b = p_help(b, t_b);
	if (a->size == 0)
	{
		a->top = t_b;
		a->bottom = t_b;
		t_b->next = NULL;
		t_b->prev = NULL;
	}
	else
	{
		t_a = a->top;
		a->top = t_b;
		t_a->prev = t_b;
		t_b->next = t_a;
		t_b->prev = NULL;
	}
	a->size++;
}

void	pb(t_stack	*a, t_stack	*b)
{
	t_node	*t_b;
	t_node	*t_a;

	if (a == NULL || a->size == 0)
		return ;
	t_a = p_help(a, t_a);
	if (b->size == 0)
	{
		b->top = t_a;
		b->bottom = t_a;
		t_a->next = NULL;
		t_a->prev = NULL;
	}
	else
	{
		t_b = b->top;
		b->top = t_a;
		t_b->prev = t_a;
		t_a->next = t_b;
		t_a->prev = NULL;
	}
	b->size++;
}