#include "ft_printf.h"

int	ft_print_hex(va_list *args, int is_upper)
{
	unsigned int	num;
	const char		*base;

	num = va_arg(*args, unsigned int);
	base = "0123456789abcdef";
	if (is_upper)
		base = "0123456789ABCDEF";
	return (ft_putnbr_base_count(num, base));
}
