/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarnpan <nkarnpan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:28:42 by nkarnpan          #+#    #+#             */
/*   Updated: 2026/04/03 21:28:42 by nkarnpan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_n(t_stack	*a)
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

void	rra(t_stack	*a)
{
	rra_n(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack	*b)
{
	rra_n(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack	*a, t_stack	*b)
{
	rra_n(a);
	rra_n(b);
	write(1, "rrr\n", 4);
}
