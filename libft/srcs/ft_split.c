#include "libft.h"
#include <stdlib.h>

static size_t	ft_count_words(const char *s, char sep)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			word_count++;
		while (*s != sep && *s)
			s++;
	}
	return (word_count);
}

static void	ft_free_words(char **strs, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	ft_allocate_words(char **strs, const char *s, char sep)
{
	const char	*word_end;
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		word_end = s;
		while (*word_end != sep && *word_end)
			word_end++;
		if (word_end > s)
		{
			strs[i] = ft_substr(s, 0, word_end - s);
			if (!strs[i])
			{
				ft_free_words(strs, i);
				return (0);
			}
			s = word_end;
			i++;
		}
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	strs = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strs)
		return (NULL);
	if (!ft_allocate_words(strs, s, c))
		return (NULL);
	return (strs);
}
