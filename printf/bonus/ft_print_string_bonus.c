#include "ft_printf_bonus.h"

int	ft_print_string_bonus(va_list *args, t_flags *flags)
{
	t_conv	conv;
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
	{
		s = "(null)";
	}
	conv.numeric = false;
	conv.sign = '\0';
	conv.prefix = NULL;
	conv.body = ft_strndup(s, ft_strlen(s));
	if (!conv.body)
		return (-1);
	return (ft_finalize_conv_bonus(&conv, flags, 's'));
}
