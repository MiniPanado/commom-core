#include "ft_printf_bonus.h"

int	ft_finalize_conv_bonus(t_conv *conv, t_flags *flags, char converter)
{
	char	*result;
	int		written;

	result = ft_assemble_bonus(conv, flags, converter);
	free(conv->body);
	if (!result)
		return (-1);
	written = ft_putstr_count(result);
	free(result);
	return (written);
}
