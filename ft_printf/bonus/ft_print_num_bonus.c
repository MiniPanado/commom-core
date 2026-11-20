/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:34:42 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/20 17:14:24 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************* */

#include "ft_printf_bonus.h"

int	ft_print_int_bonus(va_list *args, t_flag *flags)
{
	int		num;
	char	pad;
	char	prefix;

	num = va_arg(*args, int);
	prefix = '\0';
	if (num < 0)
		prefix = '-';
	else if (flags->space)
		prefix = ' ';
	else if (flags->plus)
		prefix = '+';
	pad = ' ';
	if (flags->zero)
		pad = '0';
	if (
	return ();
}

int	ft_print_uint_bonus(va_list *args, t_flag *flags)
{
	return ((int)ft_put_ulong_base(va_arg(*args, unsigned int), BASE_DEC));
}

int	ft_print_hex_lower_bonus(va_list *args, t_flag *flags)
{
	return ((int)ft_put_ulong_base(va_arg(*args, unsigned int),
			BASE_HEX_LOWER));
}

int	ft_print_hex_bonus(va_list *args, t_flag *flags, int is_upper)
{
	const char	*base = BASE_HEX_LOWER;

	if (is_upper)
		base = BASE_HEX_UPPER;
	return ((int)ft_put_ulong_base(va_arg(*args, unsigned int), base));
}

int	ft_print_pointer_bonus(va_list *args, t_flag *flags)
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
