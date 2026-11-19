#include "ft_printf_bonus.h"

int	ft_print_pointer_bonus(va_list *args, t_flags *flags)
{
	t_conv				conv;
	unsigned long long	value;

	value = (unsigned long long)(uintptr_t)va_arg(*args, void *);
	conv.sign = '\0';
	if (value == 0)
	{
		conv.numeric = false;
		conv.prefix = NULL;
		conv.body = ft_strndup("(nil)", 5);
	}
	else
	{
		conv.numeric = true;
		conv.prefix = "0x";
		conv.body = ft_utoa_base(value, "0123456789abcdef");
		if (flags->plus)
			conv.sign = '+';
		else if (flags->space)
			conv.sign = ' ';
	}
	if (!conv.body)
		return (-1);
	return (ft_finalize_conv_bonus(&conv, flags, 'p'));
}
