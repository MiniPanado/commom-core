/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 21:29:08 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/03 23:50:18 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
		{
			i++;
		}
		if (s[i] == '\0')
		{
			break ;
		}
		words++;
		while (s[i] && s[i] != sep)
		{
			i++;
		}
	}
	return (words);
}

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
	{
		return (NULL);
	}
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	size_t		i;
	size_t		word;
	const char	*start;
	const char	*end;

	if (!s)
	{
		return (NULL);
	}
	split = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
	{
		return (NULL);
	}
	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i] == '\0')
		{
			break ;
		}
		start = &s[i];
		while (s[i] && s[i] != c)
		{
			i++;
		}
		end = &s[i];
		split[word] = ft_strndup(start, (end - start));
		if (!split[word])
		{
			return (NULL);
		}
		word++;
	}
	split[word] = NULL;
	return (split);
}
