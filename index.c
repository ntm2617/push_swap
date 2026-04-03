/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarnpan <nkarnpan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:27:21 by nkarnpan          #+#    #+#             */
/*   Updated: 2026/04/03 21:27:21 by nkarnpan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find smallest number that not set the index yet //
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

// set the index to every node starting at index 0 and goes on //
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
