/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarnpan <nkarnpan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:26:19 by nkarnpan          #+#    #+#             */
/*   Updated: 2026/04/03 21:30:46 by nkarnpan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	t_chunk	c;
	int		state_rb;

	c.min = 0;
	c.max = chunk_size - 1;
	state_rb = 0;
	while (a->size != 0)
	{
		if (compare(a, b, &c, &state_rb) == 0)
		{
			if (state_rb == 1)
			{
				rb(b);
				state_rb = 0;
			}
			c.min = c.min + chunk_size;
			c.max = c.max + chunk_size;
		}
		else
		{
			if ((c.max - (chunk_size / 2)) > b->top->index)
				state_rb = 1;
		}
	}
}

int	biggest_b(t_stack *b, int max)
{
	t_node	*t_b;
	int		pos;

	pos = 1;
	t_b = b->top;
	while (t_b != NULL)
	{
		if (t_b->index == max)
			break ;
		pos++;
		t_b = t_b->next;
	}
	return (pos);
}

void	move_up(t_stack *a, t_stack *b, int pos, int max)
{
	while (pos > 1)
	{
		if (b->top != NULL && b->top->index == (max - 1))
			pa(a, b);
		else
			rb(b);
		pos--;
	}
}

void	move_down(t_stack *a, t_stack *b, int pos, int max)
{
	while ((b->size - pos) >= 0)
	{
		if (b->top != NULL && b->top->index == (max - 1))
		{
			pa(a, b);
			pos--;
		}
		else
		{
			rrb(b);
			pos++;
		}
	}
}
