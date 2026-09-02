#include "ft_printf.h"

int	ft_print_string(va_list *args)
{
	const char	*str = va_arg(*args, char *);

	if (!str)
		return (ft_putstr_count("(null)"));
	return (ft_putstr_count(str));
}
