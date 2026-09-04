#include "ft_printf_bonus.h"

int	ft_put_padding(int amount, char c)
{
	int	count;
	int	ret;

	count = 0;
	while (amount-- > 0)
	{
		ret = ft_putchar_count(c);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	return (count);
}

int	ft_putstr_count_n(const char *str, int n)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (str[i] && i < n)
	{
		ret = ft_putchar_count(str[i]);
		if (ret < 0)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	ft_get_prefix_len(const char *content)
{
	if (content[0] == '-' || content[0] == '+' || content[0] == ' ')
	{
		return (1);
	}
	if (content[0] == '0' && (content[1] == 'x' || content[1] == 'X'))
	{
		return (2);
	}
	return (0);
}
