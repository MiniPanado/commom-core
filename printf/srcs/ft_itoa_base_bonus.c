#include "ft_printf_bonus.h"

static int	ft_count_digits(unsigned long n, int base_len)
{
	int	count;

	if (n == 0)
	{
		return (1);
	}
	count = 0;
	while (n != 0)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(char *buffer, unsigned long n, const char *base)
{
	int	i;
	int	base_len;

	base_len = ft_strlen(base);
	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	i = ft_count_digits(n, base_len);
	buffer[i] = '\0';
	while (n != 0)
	{
		buffer[--i] = base[n % base_len];
		n /= base_len;
	}
	return (buffer);
}
