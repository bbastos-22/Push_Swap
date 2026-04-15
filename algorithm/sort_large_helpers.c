/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 18:25:01 by bbastos-          #+#    #+#             */
/*   Updated: 2026/04/15 22:46:05 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	int	chunk;

	chunk = size / 11;
	if (chunk <= 10)
		chunk = 10;
	if (chunk <= 100)
		chunk = 20;
	if (chunk > 100)
		chunk = 45;
	return (chunk);
}

void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b,
			int chunk, int total)
{
	int	pushed;
	int	rank_top;
	int	max_push_rank;

	pushed = 0;
	max_push_rank = total - 4;
	while (stack_a->size > 3)
	{
		rank_top = get_rank(stack_a, stack_b, stack_a->top->val);
		if ((rank_top <= max_push_rank) && (rank_top <= pushed + chunk))
		{
			pb(stack_a, stack_b);
			if ((stack_b->size > 1) && (rank_top < pushed + chunk / 2))
				rb(stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
}

void	bring_max_to_top(t_stack *stack_b)
{
	int	max_b;
	int	pos_max;
	int	moves;

	max_b = get_max(stack_b);
	pos_max = get_pos(stack_b, max_b);
	if (pos_max <= stack_b->size / 2)
	{
		moves = pos_max;
		while (moves > 0)
		{
			rb(stack_b);
			moves--;
		}
	}
	else
	{
		moves = stack_b->size - pos_max;
		while (moves > 0)
		{
			rrb(stack_b);
			moves--;
		}
	}
}

void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		bring_max_to_top(stack_b);
		pa(stack_a, stack_b);
	}
}
