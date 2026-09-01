#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	if (!format)
	{
		return (-1);
	}
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ret = ft_handle_conversion(*format, &args);
			if (ret < 0)
			{
				va_end(args);
				return (-1);
			}
			count += ret;
		}
		else
		{
			count += ft_putchar_count(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
