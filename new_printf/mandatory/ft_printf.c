/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:48:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/17 08:13:04 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conversion	g_conversions[] = {
{'c', ft_print_char},
{'s', ft_print_string},
{'p', ft_print_pointer},
{'d', ft_print_int},
{'i', ft_print_int},
{'u', ft_print_unsigned},
{'x', ft_print_hex_lower},
{'X', ft_print_hex_upper},
{'%', ft_print_percent},
{0, NULL}
};

static int	conversion(va_list *ap, char c)
{
	size_t	i;

	i = 0;
	while (g_conversions[i].type && g_conversions[i].type != c)
		i++;
	if (!g_conversions[i].func)
		return (-1);
	return (g_conversions[i].func(ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		total;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	total = 0;
	while (*format)
	{
		if (*format == '%')
			ret = conversion(&ap, *(++format));
		else
			ret = write(STDOUT_FILENO, format, 1);
		if (ret < 0)
		{
			va_end(ap);
			return (-1);
		}
		total += ret;
		format++;
	}
	va_end(ap);
	return (total);
}
