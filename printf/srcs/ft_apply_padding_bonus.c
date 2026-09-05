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

static int	ft_pad_left_justify(const char *content, int padding)
{
	int	count;
	int	ret;

	ret = ft_putstr_count(content);
	if (ret < 0)
		return (-1);
	count = ret;
	ret = ft_put_padding(padding, ' ');
	if (ret < 0)
		return (-1);
	return (count + ret);
}

static int	ft_pad_simple(const char *content, int padding, char fill)
{
	int	count;
	int	ret;

	ret = ft_put_padding(padding, fill);
	if (ret < 0)
		return (-1);
	count = ret;
	ret = ft_putstr_count(content);
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_apply_padding(const char *content, t_flags *flags, char fill)
{
	int	len;
	int	width;

	len = ft_strlen(content);
	if (len >= flags->width)
	{
		return (ft_putstr_count(content));
	}
	width = flags->width - len;
	if (flags->minus)
	{
		return (ft_pad_left_justify(content, width));
	}
	return (ft_pad_simple(content, width, fill));
}
