#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*b1;
	const unsigned char	*b2;
	size_t				i;

	b1 = (const unsigned char *)s1;
	b2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && *b1 == *b2)
	{
		b1++;
		b2++;
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)*b1 - (unsigned char)*b2);
}
