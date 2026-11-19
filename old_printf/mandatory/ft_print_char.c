#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	const int	c = va_arg(*args, int);

	return (ft_putchar_count(c));
}
