/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 23:12:55 by marvin            #+#    #+#             */
/*   Updated: 2025/11/14 23:12:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack	*a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (a == NULL || a->size < 2)
		return;

	first = a->top;
	second = first->next;
	third = second->next;

	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third != NULL)
		third->prev = first;
	a->top = second;
	if (a->size == 2)
		a->bottom = first;
}

void	sb(t_stack	*b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (b == NULL || b->size < 2)
		return ;

	first = b->top;
	second = first->next;
	third = second->next;

	second->prev = NULL;
	second->next = first;
	first->prev = second;
	
	first->next = third;
	if (third != NULL)
		third->prev = first;
	b->top = second;
	if (b->size == 2)
		b->bottom = first;
}

void	ra(t_stack	*a)
{
	t_node	*t;
	t_node	*b;
	t_node	*mid;

	if (a == NULL || a->size < 2)
		return ;
	t = a->top;
	b = a->bottom;
	mid = t->next;
	
	a->top = mid;
	a->bottom = t;
	mid->prev = NULL;
	t->next = NULL;
	b->next = t;
	t->prev = b;
}

void	rb(t_stack	*b)
{
	t_node	*t;
	t_node	*bt;
	t_node	*mid;

	if (b == NULL || b->size < 2)
		return ;
	t = b->top;
	bt = b->bottom;
	mid = t->next;
	
	b->top = mid;
	b->bottom = t;
	mid->prev = NULL;
	t->next = NULL;
	bt->next = t;
	t->prev = bt;
}