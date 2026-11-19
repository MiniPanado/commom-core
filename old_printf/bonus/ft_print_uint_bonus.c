#include "ft_printf_bonus.h"

int	ft_print_uint_bonus(va_list *args, t_flags *flags)
{
	t_conv			conv;
	unsigned int	value;

	value = va_arg(*args, unsigned int);
	conv.numeric = true;
	conv.prefix = NULL;
	conv.sign = '\0';
	conv.body = ft_utoa_base((unsigned long long)value, "0123456789");
	if (!conv.body)
		return (-1);
	return (ft_finalize_conv_bonus(&conv, flags, 'u'));
}
