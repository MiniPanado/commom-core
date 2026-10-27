#include "ft_printf_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	i;

	dst = malloc((n + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

unsigned long long	ft_magnitude(long long value)
{
	if (value < 0)
		return (-(unsigned long long)value);
	return ((unsigned long long)value);
}

char	*ft_utoa_base(unsigned long long value, const char *base)
{
	char	buf[sizeof(unsigned long long) * CHAR_BIT + 1];
	size_t	base_len;
	int		i;

	base_len = ft_strlen(base);
	i = (int)(sizeof(unsigned long long) * CHAR_BIT);
	buf[i--] = '\0';
	if (value == 0)
	{
		buf[i--] = '0';
	}
	while (value != 0)
	{
		buf[i--] = base[value % base_len];
		value /= base_len;
	}
	return (ft_strndup(&buf[i + 1], ft_strlen(&buf[i + 1])));
}
