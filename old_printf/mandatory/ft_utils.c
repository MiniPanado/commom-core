#include "ft_printf.h"

int	ft_putchar_count(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_count(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	ft_putnbr_base_count(unsigned long n, const char *base)
{
	int				total;
	unsigned long	base_len;

	total = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
	{
		total = ft_putnbr_base_count((n / base_len), base);
	}
	return (total + ft_putchar_count(base[n % base_len]));
}
