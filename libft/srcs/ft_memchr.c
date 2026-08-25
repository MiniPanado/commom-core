#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*current;
	unsigned char		target;

	current = (const unsigned char *)s;
	target = (unsigned char)c;
	while (n--)
	{
		if (*current == target)
		{
			return ((void *)current);
		}
		current++;
	}
	return ((void *)0);
}
