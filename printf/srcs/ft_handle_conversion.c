#include "ft_printf.h"

int	ft_handle_conversion(char conv, va_list *args)
{
	if (conv == 'c')
		return (ft_print_char(args));
	if (conv == 's')
		return (ft_print_string(args));
	if (conv == 'p')
		return (ft_print_pointer(args));
	if (conv == 'd' || conv == 'i')
		return (ft_print_int(args));
	if (conv == 'u')
		return (ft_print_uint(args));
	if (conv == 'x' || conv == 'X')
		return (ft_print_hex(args, (conv == 'X')));
	if (conv == '%')
		return (ft_print_percent());
	return (-2);
}
