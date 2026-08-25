#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dest;

	len = 0;
	while (*(s + len))
	{
		len++;
	}
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
	{
		return ((char *)0);
	}
	*(dest + len) = '\0';
	while (len--)
	{
		*(dest + len) = *(s + len);
	}
	return (dest);
}
