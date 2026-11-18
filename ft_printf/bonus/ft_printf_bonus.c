/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:00:00 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 16:00:00 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static const t_conversion	g_conversions[] = {
{'c', ft_print_char},
{'s', ft_print_string},
{'p', ft_print_pointer},
{'d', ft_print_int},
{'i', ft_print_int},
{'u', ft_print_uint},
{'x', ft_print_hex_lower},
{'X', ft_print_hex_upper},
{'%', ft_print_percent},
{0, NULL}
};

static const t_conversion	*ft_find_conversion(char type)
{
	size_t	i;

	i = 0;
	while (g_conversions[i].type)
	{
		if (g_conversions[i].type == type)
			return (&g_conversions[i]);
		i++;
	}
	return (NULL);
}

static int	ft_handle_conversion(va_list *args, const char **format)
{
	t_flag				flags;
	const t_conversion	*conversion;
	int					printed;

	(*format)++;
	if (ft_parse_flags(format, &flags) < 0)
		return (-1);
	conversion = ft_find_conversion(**format);
	if (!conversion)
		return (-1);
	printed = conversion->func(args, &flags);
	(*format)++;
	return (printed);
}

static int	ft_put_literal(const char **format)
{
	size_t	len;

	len = 0;
	while ((*format)[len] && (*format)[len] != '%')
		len++;
	if (write(STDOUT_FILENO, *format, len) != (ssize_t)len)
		return (-1);
	*format += len;
	return ((int)len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		printed;

	if (!format)
		return (-1);
	va_start(args, format);
	total = 0;
	while (*format)
	{
		if (*format == '%')
			printed = ft_handle_conversion(&args, &format);
		else
			printed = ft_put_literal(&format);
		if (printed < 0)
		{
			va_end(args);
			return (-1);
		}
		total += printed;
	}
	va_end(args);
	return (total);
}
