/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarnpan <nkarnpan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:28:08 by nkarnpan          #+#    #+#             */
/*   Updated: 2026/04/03 21:28:08 by nkarnpan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	extend_main2(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
}

int	extend_main(char **av, t_stack *a, t_stack *b)
{
	t_node	*node;
	int		i;
	int		show_error;
	int		num;

	if (av == NULL || av[0] == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	show_error = 0;
	i = 0;
	extend_main2(a, b);
	while (av[i] != NULL)
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
	char	**input;

	if (ac < 2)
		return (0);
	if (ac == 2)
		input = ft_split(av[1], ' ');
	else
		input = av + 1;
	if (extend_main(input, &a, &b) == 1)
	{
		if (ac == 2)
			free_split(input);
		return (1);
	}
	set_index(&a);
	if (already_sort(&a) == 1)
		final_sorting(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (ac == 2)
		free_split(input);
	return (0);
}
