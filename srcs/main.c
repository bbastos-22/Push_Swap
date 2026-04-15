/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 15:16:56 by bbastos-          #+#    #+#             */
/*   Updated: 2026/04/15 19:59:21 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_stack_from_args(t_stack *stack_a, int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		if ((!is_valid_number(av[i])) || (!is_in_range(av[i]))
			|| (has_duplicates(stack_a, ft_atoi(av[i]))))
			return (1);
		stack_add(stack_a, ft_atoi(av[i]));
		i--;
	}
	return (0);
}

int	cleanup(t_stack *stack_a, t_stack *stack_b, int code)
{
	free_stack(stack_a);
	free_stack(stack_b);
	return (code);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if ((stack_a == NULL) || (stack_b == NULL))
		return (cleanup(stack_a, stack_b, 0));
	if (fill_stack_from_args(stack_a, argc, argv) == 1)
	{
		print_error();
		return (cleanup(stack_a, stack_b, 1));
	}
	if (is_sorted(stack_a))
		return (cleanup(stack_a, stack_b, 0));
	sort_dispatcher(stack_a, stack_b);
	cleanup(stack_a, stack_b, 0);
	return (0);
}
