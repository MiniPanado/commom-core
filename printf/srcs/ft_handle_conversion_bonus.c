#include "ft_printf_bonus.h"

int	ft_handle_conversion_bonus(char conv, va_list *args, t_flags *flags)
{
	if (conv == 'c')
		return (ft_print_char_bonus(args, flags));
	if (conv == 's')
		return (ft_print_string_bonus(args, flags));
	if (conv == 'p')
		return (ft_print_pointer_bonus(args, flags));
	if (conv == 'd' || conv == 'i')
		return (ft_print_int_bonus(args, flags));
	if (conv == 'u')
		return (ft_print_uint_bonus(args, flags));
	if (conv == 'x' || conv == 'X')
		return (ft_print_hex_bonus(args, flags, (conv == 'X')));
	if (conv == '%')
		return (ft_print_percent_bonus(flags));
	return (-2);
}
