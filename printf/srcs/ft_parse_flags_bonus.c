#include "ft_printf_bonus.h"

static void	ft_parse_flag_chars(const char **format, t_flags *flags)
{
	while (**format == '-' || **format == '0' || **format == '#'
			|| **format == '+' || **format == ' ')
	{
		if (**format == '-')
			flags->minus = 1;
		else if (**format == '0')
			flags->zero = 1;
		else if (**format == '#')
			flags->hash = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (**format == ' ')
			flags->space = 1;
		(*format)++;
	}
}

static void	ft_parse_width(const char **format, t_flags *flags)
{
	while (**format >= '0' && **format <= '9')
	{
		flags->width = flags->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void	ft_parse_precision(const char **format, t_flags *flags)
{
	if (**format == '.')
	{
		flags->has_precision = 1;
		(*format)++;
	}
	while (**format >= '0' && **format <= '9')
	{
		flags->precision = flags->precision * 10 + (**format - '0');
		(*format)++;
	}
}

int	ft_parse_flags(const char **format, t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->has_precision = 0;
	ft_parse_flag_chars(format, flags);
	ft_parse_width(format, flags);
	ft_parse_precision(format, flags);
	return (1);
}
