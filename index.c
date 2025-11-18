/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:51:29 by marvin            #+#    #+#             */
/*   Updated: 2025/11/17 16:51:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_smallest(t_stack *a)
{
	t_node	*current;
	t_node	*smallest;

	if (a->size == 0)
		return (NULL);
	current = a->top;
	smallest = NULL;
	while (current != NULL)
	{
		if (current->index == -1)
		{
			if (smallest == NULL)
				smallest = current;
			else if (current->value < smallest->value)
				smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

void	set_index(t_stack *a)
{
	t_node	*smallest;
	int		i;

	i = 0;
	if (a->size == 0)
		return ;

	smallest = find_smallest(a);
	while (smallest != NULL)
	{
		smallest->index = i;
		smallest = find_smallest(a);
		i++;
	}
}