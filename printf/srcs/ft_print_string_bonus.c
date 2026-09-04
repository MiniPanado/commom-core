#include "ft_printf_bonus.h"

static const char	*ft_null_replacement(t_flags *flags)
{
	if (flags->has_precision && flags->precision < 6)
	{
		return ("");
	}
	return ("(null)");
}

static int	ft_build_truncated(const char *str, int len, t_flags *flags)
{
	char	*buffer;
	int		i;
	int		ret;

	if (!flags->has_precision || flags->precision >= len)
	{
		return (ft_apply_padding(str, flags));
	}
	len = flags->precision;
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
	{
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	ret = ft_apply_padding(buffer, flags);
	free(buffer);
	return (ret);
}

int	ft_print_string_bonus(va_list *args, t_flags *flags)
{
	const char	*str;
	int			len;

	flags->zero = 0;
	str = va_arg(*args, char *);
	if (!str)
	{
		str = ft_null_replacement(flags);
	}
	len = 0;
	while (str[len])
		len++;
	return (ft_build_truncated(str, len, flags));
}
