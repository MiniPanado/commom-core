#include "ft_printf_bonus.h"

static char	ft_sign(long long value, t_flags *flags)
{
	if (value < 0)
		return ('-');
	if (flags->plus)
		return ('+');
	if (flags->space)
		return (' ');
	return (0);
}

static unsigned long long	ft_magnitude(long long value)
{
	if (value < 0)
		return (-(unsigned long long)value);
	return ((unsigned long long)value);
}


int	ft_print_int_bonus(va_list *args, t_flags *flags)
{
	t_conv		conv;
	long long	value;

	value = (long long)va_arg(*args, int);
	conv.numeric = true;
	conv.prefix = NULL;
	conv.sign = ft_sign(value, flags);
	conv.body = ft_utoa_base(ft_magnitude(value), "0123456789");
	if (!conv.body)
		return (-1);
	return (ft_finalize_conv_bonus(&conv, flags, 'd'));
}
