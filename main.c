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

int	main(int ac, char **av)
{
	t_node	*node;
	int		i;
	int		show_error;
	int		num;
	t_stack	a;
	t_stack	b;

	show_error = 0;
	i = 1;
	if (ac < 2)
		return (0);
	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;	
	while (i < ac)
	{
		num = ft_atoi(av[i], &show_error);
		if (show_error == 1 || check_dup(&a, num) == 1)
			return (write_error(&a));
		node = new_node(num);
		if (node == NULL)
			return (write_error(&a));
		add_node(&a, node);
		i++;
	}
	free_stack(&a);
	return (0);
}