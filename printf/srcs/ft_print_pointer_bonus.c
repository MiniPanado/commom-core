#include "ft_printf.h"

int	ft_print_pointer_bonus(va_list *args, t_flags *flags)
{
	const void		*ptr;
	char			buffer[(sizeof(uintptr_t) * CHAR_BIT + 3) / 4 + 3];

	ptr = va_arg(*args, void *);
	if (!ptr)
	{
		return (ft_apply_padding("(nil)", flags, ' '));
	}
	buffer[0] = '0';
	buffer[1] = 'x';
	ft_itoa_base_bonus((buffer + 2), (unsigned long)ptr, "0123456789abcdef");
	return (ft_apply_padding(buffer, flags, ' '));
}
