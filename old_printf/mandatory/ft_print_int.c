#include "ft_printf.h"

int	ft_print_int(va_list *args)
{
	long	num;
	int		total;

	num = va_arg(*args, int);
	total = 0;
	if (num < 0)
	{
		num = -num;
		total += ft_putchar_count('-');
	}
	total += ft_putnbr_base_count(num, "0123456789");
	return (total);
}
