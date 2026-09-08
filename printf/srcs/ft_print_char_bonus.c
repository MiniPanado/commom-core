#include "ft_printf_bonus.h"

int	ft_print_char_bonus(va_list *args, t_flags *flags)
{
	t_conv	conv;

	conv.numeric = false;
	conv.sign = '\0';
	conv.prefix = NULL;
	conv.body = (char *)malloc(2 * sizeof(char));
	if (!conv.body)
		return (-1);
	conv.body[0] = (char)va_arg(*args, int);
	conv.body[1] = '\0';
	return (ft_finalize_conv_bonus(&conv, flags, 'c');
}
