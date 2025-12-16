/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:42:06 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 14:42:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
	int			value;
	int			index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node 	*top;
	t_node 	*bottom;
	int		size;
}	t_stack;

/*Operations*/
void	sa(t_stack	*a);
void	sb(t_stack	*b);
void	ra(t_stack	*a);
void	rb(t_stack	*b);
void	rra(t_stack	*a);
void	rrb(t_stack	*b);
void	pa(t_stack	*a, t_stack	*b);
void	pb(t_stack	*a, t_stack	*b);

/*helper for main*/
int		atoi_extend(int	*show_error, const char *str, int i, int neg)
int		ft_atoi(const char *str, int *show_error);
int		check_dup(t_stack	*a, int *new_value);
t_node	*new_node(int add_value);
void	add_node(t_stack *a, t_node *n);

/*normalise the index*/
t_node	*find_smallest(t_stack *a);
void	set_index(t_stack *a);

/* small sorting (2,3,4,5)*/
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);

#endif