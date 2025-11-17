/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:03:04 by marvin            #+#    #+#             */
/*   Updated: 2025/11/16 22:03:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_extend(int	*show_error, const char *str, int i, int neg)
{
	long	n;

	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			*show_error = 1;
			return (0);
		}
		n = (n * 10) + (str[i] - '0');
		if ((n > 2147483647 && neg > 0) || (n > 2147483648 && neg < 0))
		{
			*show_error = 1;
			return (0);
		}
		i++;
	}
	return (int n);
}

int	ft_atoi(const char *str, int *show_error)
{
	int		i;
	int		neg;
	int		n;

	neg = 1;
	i = 0;
	// if (str == NULL)
	// 	return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	if (str[i] == '\0')
	{
		*show_error = 1;
		return (0);
	}
	n = atoi_extend(show_error, str, i, neg);
	return (neg * n);
}

int	check_dup(t_stack	*a, int *new_value)
{
	t_node	*current_node;

	current_node = a->top;
	while (current_node != NULL)
	{
		if (current_node->value == new_value)
			return (1);
		current_node = current_node->next;
	}
	return (0);
}

t_node	*new_node(int add_value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->value = add_value;
	new->prev = NULL;
	new->next = NULL;
	new->index = -1;
	return (new);
}

void	add_node(t_stack *a, t_node *n)
{
	t_node	*current;

	if (a->size == 0)
	{
		a->top = n;
		a->bottom = n;
		n->prev = NULL;
		n->next = NULL;
	}
	else if (a->size > 0)
	{
		current = a->bottom;
		a->bottom = n;
		n->prev = current;
		n->next = NULL;
		current->next = n;
	}
	a->size++;
}
