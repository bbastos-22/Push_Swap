/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:57:45 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/05 16:24:28 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if(str[i] == '\0')
			return (0);
	}
	while (str[i] != '\0')
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_in_range(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = num * sign;
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	else
		return (1);
}

int	has_duplicates(t_stack *stack, int val)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp != NULL)
	{
		if (tmp->val == val)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}