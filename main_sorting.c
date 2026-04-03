#include "push_swap.h"

void	final_sorting(t_stack *a, t_stack *b)
{
	int	size_b;

	size_b = a->size;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
	else if (a->size <= 100)
		sort_hun(a, b, size_b, 20);
	else if (a->size <= 500 && a->size >= 100)
		sort_hun(a, b, size_b, 65);
}
