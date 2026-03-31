/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 00:50:16 by marvin            #+#    #+#             */
/*   Updated: 2025/11/17 00:50:16 by marvin           ###   ########.fr       */
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

int	write_error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	return (1);
}

int	already_sort(t_stack *a)
{
	t_node	*current;

	if (a == NULL || a->top == NULL)
		return (1);
	current = a->top;
	while (current->next != NULL)
	{
		if (current->index > current->next->index)
			return (1);
		current = current->next;
	}
	return (0);
}

int	extend_main(int ac, char **av, t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;
	int		show_error;
	int		num;

	show_error = 0;
	i = 1;
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0; 
	while (i < ac)
	{
		num = ft_atoi(av[i], &show_error);
		if (show_error == 1 || check_dup(a, num) == 1)
			return (write_error(a));
		node = new_node(num);
		if (node == NULL)
			return (write_error(a));
		add_node(a, node);
		i++;
	}
	return (0);
}

/*return 1 if error occurs*/
int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	if (extend_main(ac, av, &a, &b) == 1)
		return (1);
	set_index(&a);
	if (already_sort(&a) == 0)
	{
		free_stack(&a);
		return (0);
	}
	if (a.size == 2)
		sort_two(&a);
	else if (a.size == 3)
		sort_three(&a);
	else if (a.size == 5)
		sort_five(&a, &b);
	free_stack(&a);
	return (0);
}
