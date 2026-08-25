#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;

	little_len = 0;
	while (*(little + little_len) && little_len <= len)
		little_len++;
	if (little_len == 0)
		return ((char *)big);
	if (little_len > len)
		return ((char *)0);
	i = 0;
	len = len - little_len;
	while (i <= len && *big)
	{
		j = 0;
		while (*(little + j) && *(little + j) == *(big + j))
			j++;
		if (*(little + j) == '\0')
			return ((char *)big);
		i++;
		big++;
	}
	return ((char *)0);
}
