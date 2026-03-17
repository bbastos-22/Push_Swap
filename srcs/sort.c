/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:51:06 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/12 20:18:40 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	t_node	*tmp
	int	max;

	max = stack->top->val;
	tmp = stack->top;
	while (tmp != NULL)
	{
		
	}
}

void	sort_three(t_stack *stack_a)