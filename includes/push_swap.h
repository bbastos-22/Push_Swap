/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:32:58 by bbastos-          #+#    #+#             */
/*   Updated: 2026/04/15 22:43:05 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

//listas e stacks
void	print_error(void);
t_node	*new_node(int val);
t_stack	*init_stack(void);
void	stack_add(t_stack *head, int val);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		fill_stack_from_args(t_stack *stack_a, int ac, char **av);

//push
void	stack_push(t_stack *src, t_stack *dst);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

//swap
void	swap(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

//rotate
void	rotate(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

//reverse
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//parse
int		has_duplicates(t_stack *stack, int val);
int		is_in_range(char *str);
int		is_valid_number(char *str);

//auxiliares algoritmo
int		get_pos(t_stack *stack, int value);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_rank(t_stack *stack_a, t_stack *stack_b, int value);
void	sort_three_max_top(t_stack *stack_a, int b, int c);
void	sort_three_max_mid(t_stack *stack_a, int a, int c);
void	move_min_to_top(t_stack *stack_a);
int		get_chunk_size(int size);
void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b,
			int chunk, int total);
void	bring_max_to_top(t_stack *stack_b);
void	push_back_to_a(t_stack *stack_a, t_stack *stack_b);

//algoritmo
void	sort_dispatcher(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_large(t_stack *stack_a, t_stack *stack_b);

#endif