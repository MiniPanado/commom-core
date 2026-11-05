/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 21:29:08 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/04 03:03:53 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char delimiter)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i] == '\0')
			break ;
		word_count++;
		while (str[i] && str[i] != delimiter)
			i++;
	}
	return (word_count);
}

static char	*dup_n_chars(const char *src, size_t len)
{
	size_t	i;
	char	*copy;

	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len && src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**free_words(char **words, size_t allocated_count)
{
	while (allocated_count > 0)
		free(words[--allocated_count]);
	free(words);
	return (NULL);
}

static char	**fill_words(const char *str, char delimiter, char **words)
{
	size_t	i;
	size_t	word_idx;
	size_t	word_len;

	i = 0;
	word_idx = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i] == '\0')
			break ;
		word_len = 0;
		while (str[i + word_len] && str[i + word_len] != delimiter)
			word_len++;
		words[word_idx] = dup_n_chars(&str[i], word_len);
		if (!words[word_idx])
			return (free_words(words, word_idx));
		i += word_len;
		word_idx++;
	}
	words[word_idx] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;

	if (!s)
		return (NULL);
	words = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	return (fill_words(s, c, words));
}
