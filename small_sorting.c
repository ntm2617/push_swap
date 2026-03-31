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

int	smallest_pos(t_node	*current, t_node	*small)
{
	int		position;
	int		i;

	position = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->index == small->index)
			position = i;
		current = current->next;
		i++;
	}
	return (position);
}

void	smallest(t_stack *a, t_stack *b)
{
	t_node	*small;
	t_node	*current;
	int		i;

	current = a->top;
	small = a->top;
	while (current != NULL)
	{
		if (small->index > current->index)
			small = current;
		current = current->next;
	}
	current = a->top;
	i = smallest_pos(current, small);
	while (a->top != small)
	{
		if (i > (a->size / 2))
			rra(a);
		else if (i <= (a->size / 2))
			ra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	smallest(a, b);
	smallest(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
