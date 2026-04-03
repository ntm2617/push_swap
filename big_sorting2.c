/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 01:11:14 by ming              #+#    #+#             */
/*   Updated: 2026/04/03 18:57:04 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_hun(t_stack *a, t_stack *b, int size_b, int chunk_size)
{
	int		max;
	int		pos;

	push_to_b(a, b, chunk_size);
	max = size_b - 1;
	pos = biggest_b(b, max);
	while (size_b > 0)
	{
		if (pos <= ((b->size + 1) / 2))
			move_up(a, b, pos, max);
		else
			move_down(a, b, pos, max);
		pa(a, b);
		if (a->size > 1 && (a->top->index > a->top->next->index))
		{
			sa(a);
			size_b--;
			max--;
		}
		size_b--;
		max--;
		pos = biggest_b(b, max);
	}
}

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

