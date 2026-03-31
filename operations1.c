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

void	sa_n(t_stack	*a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (a == NULL || a->size < 2)
		return ;
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

void	sa(t_stack	*a)
{
	sa_n(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack	*b)
{
	sa_n(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack	*a, t_stack	*b)
{
	sa_n(a);
	sa_n(b);
	write(1, "ss\n", 3);
}
