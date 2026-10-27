#include "ft_printf_bonus.h"

static const char	*ft_hex_digits(bool upper)
{
	if (upper)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static const char	*ft_hex_prefix(bool upper)
{
	if (upper)
		return ("0X");
	return ("0x");
}

int	ft_print_hex_bonus(va_list *args, t_flags *flags, bool upper)
{
	t_conv			conv;
	unsigned int	value;

	value = va_arg(*args, unsigned int);
	conv.numeric = true;
	conv.sign = '\0';
	conv.prefix = NULL;
	conv.body = ft_utoa_base((unsigned long long)value, ft_hex_digits(upper));
	if (flags->hash && value != 0)
	{
		conv.prefix = ft_hex_prefix(upper);
	}
	if (upper)
		return (ft_finalize_conv_bonus(&conv, flags, 'X'));
	return (ft_finalize_conv_bonus(&conv, flags, 'x'));
}
