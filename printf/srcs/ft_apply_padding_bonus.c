#include "ft_printf_bonus.h"

static int	ft_put_padding(int amount, char c)
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

int	ft_apply_padding(const char *content, t_flags *flags)
{
	int	len;
	int	padding;
	int	count;
	int	ret;

	len = 0;
	while (content[len])
		len++;
	if (len >= flags->width)
		return (ft_putstr_count(content));
	padding = flags->width - len;
	count = 0;
	if (flags->minus)
	{
		ret = ft_putstr_count(content);
		if (ret < 0)
			return (-1);
		count += ret;
		ret = ft_put_padding(padding, ' ');
		if (ret < 0)
			return (-1);
		count += ret;
	}
	else
	{
		ret = ft_put_padding(padding, flags->zero ? '0' : ' ');
		if (ret < 0)
			return (-1);
		count += ret;
		ret = ft_putstr_count(content);
		if (ret < 0)
			return (-1);
		count += ret;
	}
	return (count);
}
