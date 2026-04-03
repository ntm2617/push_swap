/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:50:01 by ming              #+#    #+#             */
/*   Updated: 2026/04/02 21:50:01 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_top(t_stack *a, int chunk_min, int chunk_max)
{
	int		i;
	t_node	*t;

	if (a == NULL || a->top == NULL)
		return (-1);
	i = 0;
	t = a->top;
	while (t != NULL)
	{
		if (t->index >= chunk_min && t->index <= chunk_max)
			return (i);
		t = t->next;
		i++;
	}
	return (-1);
}

int	moves_bottom(t_stack *a, int chunk_min, int chunk_max)
{
	int		i;
	t_node	*t;

	if (a == NULL || a->bottom == NULL)
		return (-1);
	i = 1;
	t = a->bottom;
	while (t != NULL)
	{
		if (t->index >= chunk_min && t->index <= chunk_max)
			return (i);
		t = t->prev;
		i++;
	}
	return (-1);
}

void	compare_helper1(int m_bot, t_stack *a)
{
	while (m_bot > 0)
	{
		rra(a);
		m_bot--;
	}
}

void	compare_helper2(int m_top, int *state_rb, t_stack *a, t_stack *b)
{
	while (m_top > 0)
	{
		if (*state_rb == 1)
		{
			rr(a, b);
			*state_rb = 0;
		}
		else
			ra(a);
		m_top--;
	}
}

int	compare(t_stack *a, t_stack *b, t_chunk *c, int *state_rb)
{
	int	m_top;
	int	m_bot;
	int	true_bot;

	m_top = moves_top(a, c->min, c->max);
	m_bot = moves_bottom(a, c->min, c->max);
	if (m_top == -1)
		return (0);
	true_bot = m_bot;
	if (*state_rb == 1)
		true_bot++;
	if (m_top > true_bot)
		compare_helper1(m_bot, a);
	else
		compare_helper2(m_top, state_rb, a, b);
	if (*state_rb == 1)
	{
		rb(b);
		*state_rb = 0;
	}
	pb(a, b);
	return (1);
}




