#include "ft_printf_bonus.h"

int	ft_print_percent_bonus(t_flags *flags)
{
	t_conv	conv;

	conv.numeric = false;
	conv.sign = '\0';
	conv.prefix = NULL;
	conv.body = ft_strndup("%", 1);
	if (!conv.body)
		return (-1);
	return (ft_finalize_conv_bonus(&conv, flags, '%'));
}
