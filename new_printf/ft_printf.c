/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:48:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/14 05:36:03 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conversion	g_table[] = {
{'c', print_char},
{'s', print_string},
{'p', print_pointer},
{'d', print_int},
{'i', print_int},
{'u', print_unsigned},
{'x', print_hexdecimal},
{'X', print_big_hexdecimal},
{'%', print_percent},
{0, NULL}
};

static int	conversion(va_list *ap, char c)
{
	size_t	i;

	if (!g_table)
	{
		return (-1);
	}
	i = 0;
	while (g_table[i].type != c && g_table[i].type)
	{
		i++;
	}
	if (g_table[i].type == '\0')
	{
		return (-1);
	}
	return (g_table[i].func(ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (conversion(&ap))
			{
				return (-1);
			}
			format++;
		}
		else
			ft_putchar_fd(*format, STDOUT_FILENO);
		format++;
	}
	va_end(ap);
	return (0);
}
