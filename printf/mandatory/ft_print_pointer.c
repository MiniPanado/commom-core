#include "ft_printf.h"

int	ft_print_pointer(va_list *args)
{
	const void		*ptr;
	unsigned long	num;
	int				total;

	ptr = va_arg(*args, void *);
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	num = (unsigned long)ptr;
	total = 0;
	total += ft_putstr_count("0x");
	total += ft_putnbr_base_count(num, "0123456789abcdef");
	return (total);
}
