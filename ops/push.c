/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:34:59 by bbastos-          #+#    #+#             */
/*   Updated: 2026/04/15 18:32:49 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if ((src->size > 0) && (src->top != NULL))
	{
		tmp = src->top;
		src->top = src->top->next;
		src->size -= 1;
		if (src->top == NULL)
			src->bottom = NULL;
		tmp->next = dst->top;
		dst->top = tmp;
		dst->size += 1;
		if (dst->size == 1)
			dst->bottom = tmp;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 0)
	{
		stack_push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 0)
	{
		stack_push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
}
