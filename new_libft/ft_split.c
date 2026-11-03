/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 21:29:08 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/03 22:34:58 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char const *s, char sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s1[i] && s[i] == sep)
		{
			i++;
		}
		if (s[i] == '\0')
		{
			break ;
		}
		words++;
		while (s1[i] && s[i] != sep)
		{
			i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	char	*start;
	char	*end;

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
	while (s[i])
	{
		while (s1[i] && s[i] == sep)
		{
			i++;
		}
		if (s[i] == '\0')
		{
			break ;
		}
		while (s1[i] && s[i] != sep)
		{
			i++;
		}
	}
}
