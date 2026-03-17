/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:59:01 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/17 04:19:09 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return;
	while (stack->top != NULL)
	{
		tmp = stack->top->next;
		free (stack->top);
		stack->top = tmp;
	}
	free (stack);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
}