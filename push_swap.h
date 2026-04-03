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

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct c_chunk
{
	int	min;
	int	max;
}	t_chunk;

/*Operations*/
void	sa_n(t_stack	*a);
void	sa(t_stack	*a);
void	sb(t_stack	*b);
void	ss(t_stack	*a, t_stack	*b);
void	ra_n(t_stack	*a);
void	ra(t_stack	*a);
void	rb(t_stack	*b);
void	rr(t_stack	*a, t_stack	*b);
void	rra_n(t_stack	*a);
void	rra(t_stack	*a);
void	rrb(t_stack	*b);
void	rrr(t_stack	*a, t_stack	*b);
void	pa_n(t_stack	*a, t_stack	*b);
void	pa(t_stack	*a, t_stack	*b);
void	pb(t_stack	*a, t_stack	*b);

/*parsing*/
char	**ft_split(char const *s, char c);

/*helper for main*/
int		atoi_extend(int	*show_error, const char *str, int i, int neg);
int		ft_atoi(const char *str, int *show_error);
int		check_dup(t_stack	*a, int new_value);
t_node	*new_node(int add_value);
void	add_node(t_stack *a, t_node *n);

/*normalise the index*/
t_node	*find_smallest(t_stack *a);
void	set_index(t_stack *a);

/* small sorting (2,3,4,5)*/
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

/*free_error*/
void	free_stack(t_stack *a);
void	free_split(char **input);
int		write_error(t_stack *a);

/*sorting to use with main (in main_sorting)*/
void	final_sorting(t_stack *a, t_stack *b);

/*functions in main.c*/
int		already_sort(t_stack *a);
int		extend_main(char **av, t_stack *a, t_stack *b);

/*big sorting*/
int		moves_top(t_stack *a, int chunk_min, int chunk_max);
int		moves_bottom(t_stack *a, int chunk_min, int chunk_max);
int		compare(t_stack *a, t_stack *b, t_chunk *c, int *state_rb);
void	push_to_b(t_stack *a, t_stack *b, int chunk_size);
int		biggest_b(t_stack *b, int max);
void	move_up(t_stack *a, t_stack *b, int pos, int max);
void	move_down(t_stack *a, t_stack *b, int pos, int max);
void	sort_hun(t_stack *a, t_stack *b, int size_b, int chunk_size);
void	sort_hun_helper(t_stack *a, t_stack *b, int max);

#endif