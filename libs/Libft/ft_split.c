/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:42:31 by bbastos-          #+#    #+#             */
/*   Updated: 2025/10/21 11:58:03 by bbastos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	if (!s)
		return (0);
	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	free_array(char **array, size_t count)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*copy_word(char const *s, size_t len)
{
	char	*word;
	size_t	j;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		result[i] = copy_word(s, len);
		if (!result[i])
			return (free_array(result, i), NULL);
		s += len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
