#include "ft_printf_bonus.h"

bool	ft_zero_padding_applies_bonus(t_conv *conv, t_flags *flags)
{
	if (flags->minus || !flags->zero)
		return (false);
	if (!conv->numeric)
		return (false);
	if (flags->has_precision)
		return (false);
	return (true);
}
