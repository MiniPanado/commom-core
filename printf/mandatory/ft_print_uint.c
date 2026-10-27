#include "ft_printf.h"

int	ft_print_uint(va_list *args)
{
	const unsigned int	num = va_arg(*args, unsigned int);

	return (ft_putnbr_base_count(num, "0123456789"));
}
