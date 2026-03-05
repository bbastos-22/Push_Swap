/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:57:45 by bbastos-          #+#    #+#             */
/*   Updated: 2026/03/05 00:20:54 by bbastos-         ###   ########.fr       */
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