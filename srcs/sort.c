/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:51:06 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/31 21:41:17 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatcher(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->top == NULL)
		return ;
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->top->val > stack_a->top->next->val)
			sa(stack_a);
		return ;
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return ;
	}
	if (stack_a->size <= 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	sort_large(stack_a, stack_b);
}

void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;
	int	max;

	a = stack_a->top->val; 
	b = stack_a->top->next->val;
	c = stack_a->bottom->val;
	max = get_max(stack_a);
	if (a == max)
	{
		if (b < c)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
	else if (b == max)
	{
		if (a < c)
		{
			sa(stack_a);
			ra(stack_a);
		}
		else
			rra(stack_a);
	}
	else
	{
		if (a > b)
			sa(stack_a);
		else
			return;
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	pos;
	int	moves;

	while (stack_a->size > 3)
	{
		min = get_min(stack_a);
		pos = get_pos(stack_a, min);
		if (pos <= stack_a->size / 2)
		{
			moves = pos;
			while (moves > 0)
			{
				ra(stack_a);
				moves = moves - 1;
			}
		}
		else
		{
			moves = stack_a->size - pos;
			while (moves > 0)
			{
				rra(stack_a);
				moves = moves - 1;
			}
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
		int	chunk;
		int	pushed;
}