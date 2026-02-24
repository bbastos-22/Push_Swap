/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:38:30 by bbastos-          #+#    #+#             */
/*   Updated: 2025/10/21 14:51:04 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	if (!f)
		return (NULL);
	len = ft_strlen(s);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[len] = '\0';
	return (s2);
}
