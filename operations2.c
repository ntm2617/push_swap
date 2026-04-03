/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarnpan <nkarnpan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:28:29 by nkarnpan          #+#    #+#             */
/*   Updated: 2026/04/03 21:28:29 by nkarnpan         ###   ########.fr       */
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
