/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:16:56 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/31 18:49:12 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if ((stack_a == NULL) || (stack_b == NULL))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	while (i < argc)
	{
		if ((!is_valid_number(argv[i])) || (!is_in_range(argv[i]))
			|| (has_duplicates(stack_a, ft_atoi(argv[i]))))
		{
			print_error();
			free_stack(stack_a);
			free_stack(stack_b);
			return (1);
		}
		stack_add(stack_a, ft_atoi(argv[i]));
		i++;
	}
	if (is_sorted(stack_a))
	{
			free_stack(stack_a);
			free_stack(stack_b);
			return (0);
	}
	sort_dispatcher(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
