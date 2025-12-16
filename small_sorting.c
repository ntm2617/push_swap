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

static int	helper_f(t_stack	*a)
{
	t_node	*t;
	int		i;

	i = 0;
	t = a->top;
	while (t != NULL)
	{
		if (t->index == 0)
			break ;
		i++;
		t = t->next;
	}
	return (i);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int		i;

	i  = helper_f(a);
	if (i < 2)
	{
		if (i == 1)
			sa(a);
		pb(a, b);
	}
	else if (i >= 2)
	{
		rra(a);
		if (i == 2)
			rra(a);
		pb(a, b);
	}
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*biggest;
	t_node	*current;
	int		i;

	current = a->top;
	while (current != NULL)
	{
		if (current->next > current)
			biggest = current->next;
		current = current->next;
	}
	i = helper_f(a);
	while (i < 2 && current != a->top)
		sa(a);
	while (i >= 2 && current != a->top)
		rra(a);
	if (current == a->top)
		pb(a, b);
	sort_four(a, b);
	/* add biggest to the last node of the stack */
	pa(a, b);
	ra(a);
}