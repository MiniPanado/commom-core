/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 05:34:43 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/20 08:46:28 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list *args)
{
	return ((int)ft_put_int(va_arg(*args, int)));
}

int	ft_print_uint(va_list *args)
{
	return ((int)ft_put_ulong_base(va_arg(*args, unsigned int), BASE_DEC));
}

int	ft_print_hex_lower(va_list *args)
{
	return ((int)ft_put_ulong_base(va_arg(*args, unsigned int),
			BASE_HEX_LOWER));
}

int	ft_print_hex(va_list *args, int is_upper)
{
	const char	*base = BASE_HEX_LOWER;

	if (is_upper)
		base = BASE_HEX_UPPER;
	return ((int)ft_put_ulong_base(va_arg(*args, unsigned int), base));
}

int	ft_print_pointer(va_list *args)
{
	const void	*ptr = va_arg(*args, void *);
	ssize_t		ret;

	if (!ptr)
	{
		ret = write(STDOUT_FILENO, PF_NULL_PTR, 5);
		if (ret < 5)
			return (-1);
		return (ret);
	}
	ret = write(STDOUT_FILENO, "0x", 2);
	if (ret < 2)
		return (-1);
	ret = (int)ft_put_ulong_base((uintptr_t)ptr, BASE_HEX_LOWER);
	if (ret < 0)
		return (-1);
	return (ret + 2);
}
