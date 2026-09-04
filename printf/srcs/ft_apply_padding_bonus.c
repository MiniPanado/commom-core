#include "ft_printf_bonus.h"

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

static int	ft_pad_zero_prefixed(const char *content, int padding)
{
	int	prefix_len;
	int	count;
	int	ret;

	prefix_len = ft_get_prefix_len(content);
	ret = ft_putstr_count_n(content, prefix_len);
	if (ret < 0)
		return (-1);
	count = ret;
	ret = ft_put_padding(padding, '0');
	if (ret < 0)
		return (-1);
	count += ret;
	ret = ft_putstr_count(content + prefix_len);
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

int	ft_apply_padding(const char *content, t_flags *flags)
{
	int	len;
	int	padding;

	len = 0;
	while (content[len])
		len++;
	if (len >= flags->width)
		return (ft_putstr_count(content));
	padding = flags->width - len;
	if (flags->minus)
		return (ft_pad_left_justify(content, padding));
	if (flags->zero && ft_get_prefix_len(content) > 0)
		return (ft_pad_zero_prefixed(content, padding));
	if (flags->zero)
		return (ft_pad_simple(content, padding, '0'));
	return (ft_pad_simple(content, padding, ' '));
}
