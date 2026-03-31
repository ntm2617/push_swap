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

void	ra_n(t_stack	*a)
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

void	ra(t_stack	*a)
{
	ra_n(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack	*b)
{
	ra_n(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack	*a, t_stack	*b)
{
	ra_n(a);
	ra_n(b);
	write(1, "rr\n", 3);
}
