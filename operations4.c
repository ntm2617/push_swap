#include "push_swap.h"

static t_node	*p_help(t_stack	*b)
{
	t_node	*t_b;

	t_b = b->top;
	if (b->size == 1)
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	else 
	{
		b->top = t_b->next;
		t_b->next->prev = NULL;
	}
	b->size--;
	return (t_b);
}

void	pa_n(t_stack	*a, t_stack	*b)
{
	t_node	*t_b;
	t_node	*t_a;

	if (b == NULL || b->size == 0)
		return ;
	t_b = p_help(b);
	if (a->size == 0)
	{
		a->top = t_b;
		a->bottom = t_b;
		t_b->next = NULL;
		t_b->prev = NULL;
	}
	else
	{
		t_a = a->top;
		a->top = t_b;
		t_a->prev = t_b;
		t_b->next = t_a;
		t_b->prev = NULL;
	}
	a->size++;
}

void	pa(t_stack	*a, t_stack	*b)
{
	pa_n(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack	*a, t_stack	*b)
{
	pa_n(b, a);
	write(1, "pb\n", 3);
}
