/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 11:14:26 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/31 20:08:07 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pos(t_stack *stack, int value)
{
	int		i;
	t_node	*tmp;

	if (stack == NULL || stack->top == NULL)
		return (-1);
	tmp = stack->top;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->val == value)
			return (i);
		tmp = tmp->next;
		i = i + 1;
	}
	return (-1);
}

int	get_max(t_stack *stack)
{
	t_node	*tmp;
	int		max;

	if (stack == NULL || stack->top == NULL)
		return (0);
	max = stack->top->val;
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (tmp->val > max)
			max = tmp->val;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	t_node	*tmp;
	int		min;

	if (stack == NULL || stack->top == NULL)
		return (0);
	tmp = stack->top;
	min = tmp->val;
	while (tmp != NULL)
	{
		if (tmp->val < min)
			min = tmp->val;
		tmp = tmp->next;
	}
	return (min);
}

int	get_rank(t_stack *stack, int value)
{
	int		rank;
	t_node	*tmp;

	rank = 0;
	tmp = stack->top;
	while (tmp != NULL)
	{
		if (tmp->val < value)
			rank = rank + 1;
		tmp = tmp->next;
	}
	return (rank);
}