#include "push_swap.h"

void	sort_hun_helper(t_stack *a, t_stack *b, int max)
{
	if (b->size >= 2 && b->top->next->index == max)
		sb(b);
	else if (b->size >= 2 && b->top->next->index == (max - 1))
	{
		sb(b);
		pa(a, b);
	}
}

void	sort_hun(t_stack *a, t_stack *b, int size_b, int chunk_size)
{
	int		max;
	int		pos;

	push_to_b(a, b, chunk_size);
	max = size_b - 1;
	while (b->size > 0)
	{
		sort_hun_helper(a, b, max);
		pos = biggest_b(b, max);
		if (pos <= ((b->size + 1) / 2))
			move_up(a, b, pos, max);
		else
			move_down(a, b, pos, max);
		pa(a, b);
		if (a->size > 1 && (a->top->index > a->top->next->index))
		{
			sa(a);
			max--;
		}
		max--;
	}
}
