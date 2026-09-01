#include "libft.h"
#include <stdlib.h>

static size_t	ft_nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_uabs(int n, int *is_negative)
{
	*is_negative = (n < 0);
	if (*is_negative)
	{
		return (-(unsigned int)n);
	}
	return ((unsigned int)n);
}

static void	ft_fill_digits(char *end, unsigned int num, int is_negative)
{
	if (num == 0)
		*(--end) = '0';
	while (num != 0)
	{
		*(--end) = '0' + num % 10;
		num /= 10;
	}
	if (is_negative)
	{
		*(--end) = '-';
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;
	int				is_negative;

	num = ft_uabs(n, &is_negative);
	len = ft_nbrlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
	{
		return (NULL);
	}
	str[len] = '\0';
	ft_fill_digits((str + len), num, is_negative);
	return (str);
}
