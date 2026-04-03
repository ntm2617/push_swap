/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarnpan <nkarnpan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:27:01 by nkarnpan          #+#    #+#             */
/*   Updated: 2026/04/03 21:27:04 by nkarnpan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_node	*node_bottom;
	t_node	*before;

	if (a == NULL)
		return ;
	node_bottom = a->bottom;
	while (node_bottom != NULL)
	{
		before = node_bottom->prev;
		free(node_bottom);
		node_bottom = before;
	}
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
}

void	free_split(char **input)
{
	int	i;

	if (input == NULL)
		return ;
	i = 0;
	while (input[i] != NULL)
	{
		free(input[i]);
		i++;
	}
	free(input);
}

int	write_error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	return (1);
}
