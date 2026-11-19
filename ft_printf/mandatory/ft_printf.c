/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:48:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/19 21:29:04 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(va_list *args, char c)
{
	if (c == 'c')
		return (ft_print_char(args));
	if (c == 's')
		return (ft_print_string(args));
	if (c == 'p')
		return (ft_print_pointer(args));
	if (c == 'd' || c == 'i')
		return (ft_print_int(args));
	if (c == 'u')
		return (ft_print_uint(args));
	if (c == 'x')
		return (ft_print_hex_lower(args));
	if (c == 'X')
		return (ft_print_hex_upper(args));
	if (c == '%')
		return (ft_print_percent(args));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	total = 0;
	while (*format)
	{
		if (*format == '%')
			ret = conversion(&args, *(++format));
		else
			ret = write(STDOUT_FILENO, format, 1);
		if (ret < 0)
		{
			va_end(args);
			return (-1);
		}
		total += ret;
		format++;
	}
	va_end(args);
	return (total);
}
