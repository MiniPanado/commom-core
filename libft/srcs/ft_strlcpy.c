#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (*(src + src_len))
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	*(dst + --size) = '\0';
	while (size--)
	{
		*(dst + size) = *(src + size);
	}
	return (src_len);
}
