#include <stdlib.h>

static size_t	get_real_len(const char *s, size_t len)
{
	size_t	real_len;

	real_len = 0;
	while (real_len < len && s[real_len])
	{
		real_len++;
	}
	return (real_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	src_idx;
	size_t	dst_idx;

	if (!s)
		return (NULL);
	src_idx = 0;
	while (s[src_idx] && src_idx < start)
		src_idx++;
	if (src_idx < start)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(get_real_len((s + start), len) + 1);
	if (!str)
		return (NULL);
	dst_idx = 0;
	while (dst_idx < len && s[src_idx])
		str[dst_idx++] = s[src_idx++];
	str[dst_idx] = '\0';
	return (str);
}
