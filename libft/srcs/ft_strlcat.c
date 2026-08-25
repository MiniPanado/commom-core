#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = 0;
	dst_len = 0;
	i = 0;
	while (*(src + src_len))
	{
		src_len++;
	}
	while (dst_len < size && *(dst + dst_len))
	{
		dst_len++;
	}
	if (dst_len == size)
	{
		return (src_len + size);
	}
	while (dst_len + i < (size - 1))
	{
		*(dst + dst_len + i) = *(src + i);
		i++;
	}
	*(dst + dst_len + i) = '\0';
	return (src_len + dst_len);
}
