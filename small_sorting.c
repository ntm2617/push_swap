/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 02:27:21 by marvin            #+#    #+#             */
/*   Updated: 2025/11/18 02:27:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a)
{
	t_node	*t;

	t = a->top;
	if (t->index > t->next->index)
		sa(a);
	else
		return ;
}

void	sort_three(t_stack *a)
{
	t_node	*t;
	t_node	*bt;

	t = a->top;
	bt = a->bottom;
	if (t->index > t->next->index && t->index > bt->index)
		ra(a);
	else if (t->next->index > t->index && t->next->index > bt->index)
		rra(a);
	sort_two(a);
}

void	sort_four(t_stack *a, t_stack *b)
{
	t_node	*t;
	int		i;

	i = 0;
	t = a->top;
	while (t->index >= 0)
	{
		if (t->index == 0)
			break ;
		i++;
		t = t->next;
	}
	if (t->index == 0 && i < 2)
	{
		if (i == 1)
			sa(a);
		pb(a);
	}
	else if (t->index == 0 && i >= 2)
	{
		rra(a);
		if (i == 2)
			rra(a);
		pb(a);
	}
	sort_three(a);
	pa(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	
}