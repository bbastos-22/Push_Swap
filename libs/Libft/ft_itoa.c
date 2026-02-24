/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:00:36 by bbastos-          #+#    #+#             */
/*   Updated: 2025/10/21 15:24:20 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	i;
	long	num;

	i = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		i++;
	}
	while (num != 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;
	size_t	i;

	len = count_digits(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	num = n;
	str[len] = '\0';
	i = len - 1;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		num = -num;
	while (num != 0)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
