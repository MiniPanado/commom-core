#include "ft_printf_bonus.h"

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
	while (**format == '-' || **format == '0' || **format == '#' || **format == '+' || **format == ' ')
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
	while (**format >= '0' && **format <= '9')
	{
		flags->width = flags->width * 10 + (**format - '0');
		(*format)++;
	}
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
	/*
	** TODO:
	** - reset every field of `flags` to 0 first
	** - while `**format` is one of '-0#+ ' -> set the matching field
	**   in `flags` and advance `*format`
	** - while `**format` is a digit -> build up `flags->width`
	** - if `**format` == '.' -> advance, set has_precision = 1,
	**   then read digits into `flags->precision` (stays 0 if none follow)
	** - leave `*format` pointing AT the conversion character
	**   ('c', 's', 'd', ...), not past it
	*/
	return (1);
}
