#include "ft_printf_bonus.h"

int	ft_print_char_bonus(va_list *args, t_flags *flags)
{
	const int	c = va_arg(*args, int);
	char		buffer[2];

	buffer[0] = (char)c;
	buffer[1] = '\0';
	return (ft_apply_padding(buffer, flags));
}
