/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:09:24 by bbastos-          #+#    #+#             */
/*   Updated: 2025/10/18 20:08:01 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int value, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		v;

	s = (const unsigned char *)src;
	v = (unsigned char)value;
	i = 0;
	while (i < n)
	{
		if (s[i] == v)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
