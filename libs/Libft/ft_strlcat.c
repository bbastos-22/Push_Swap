/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:13:06 by bbastos-          #+#    #+#             */
/*   Updated: 2025/10/16 12:01:38 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_len;
	unsigned int	dest_len;

	dest_len = 0;
	while (dest[dest_len])
	{
		dest_len++;
	}
	src_len = 0;
	while (src[src_len])
	{
		src_len++;
	}
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (i < size - dest_len - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
