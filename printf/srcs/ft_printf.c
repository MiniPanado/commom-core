#ifdef BONUS

# include "ft_printf_bonus.h"

static int	ft_process_conversion(const char **format, va_list *args)
{
	t_flags	flags;

	(*format)++;
	ft_parse_flags(format, &flags);
	return (ft_handle_conversion_bonus(**format, args, &flags));
}

#else

# include "ft_printf.h"

static int	ft_process_conversion(const char **format, va_list *args)
{
	(*format)++;
	return (ft_handle_conversion(**format, args));
}

#endif

static int	ft_process_char(const char **format, va_list *args)
{
	if (**format == '%')
		return (ft_process_conversion(format, args));
	return (ft_putchar_count(**format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		ret = ft_process_char(&format, &args);
		if (ret < 0)
		{
			va_end(args);
			return (-1);
		}
		count += ret;
		format++;
	}
	va_end(args);
	return (count);
}
