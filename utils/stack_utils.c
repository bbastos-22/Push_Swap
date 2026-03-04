/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:59:09 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/02 14:59:10 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int val)
{
	t_node * head;

	head = malloc(sizeof(t_node));
	if (head == NULL)
		return (NULL);
	head->val = val;
	head->next = NULL;
	return (head);
}

t_stack	*init_stack(void)
{
	t_stack * head;

	head = malloc(sizeof(t_stack));
	if (head == NULL)
		return (NULL);
	head->top = NULL;
	head->size = 0;
	head->bottom = NULL;
	return (head);
}

void	push(t_stack * head, int val)
{
	t_node * stack_top;

	stack_top = new_node(val);
	if (stack_top == NULL)
		return;
	stack_top->next = head->top;
	if (head->top == NULL)
		head->bottom = stack_top;
	head->top = stack_top;
	head->size++;
}