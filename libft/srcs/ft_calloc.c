#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*s;
	unsigned char	*ptr;
	size_t			total;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (nmemb > SIZE_MAX / size)
	{
		return ((void *)0);
	}
	total = nmemb * size;
	s = malloc(total * sizeof(char));
	if (!s)
	{
		return ((void *)0);
	}
	ptr = (unsigned char *)s;
	while (total--)
	{
		*ptr++ = (unsigned char)0;
	}
	return (s);
}
