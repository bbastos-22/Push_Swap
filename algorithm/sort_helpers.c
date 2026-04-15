/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:58:46 by bbastos-          #+#    #+#             */
/*   Updated: 2026/04/15 18:32:21 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_max_top(t_stack *stack_a, int b, int c)
{
	if (b < c)
		ra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_three_max_mid(t_stack *stack_a, int a, int c)
{
	if (a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else
		rra(stack_a);
}

void	move_min_to_top(t_stack *stack_a)
{
	int	min;
	int	pos;
	int	moves;

	min = get_min(stack_a);
	pos = get_pos(stack_a, min);
	if (pos <= stack_a->size / 2)
	{
		moves = pos;
		while (moves > 0)
		{
			ra(stack_a);
			moves--;
		}
	}
	else
	{
		moves = stack_a->size - pos;
		while (moves > 0)
		{
			rra(stack_a);
			moves--;
		}
	}
}
