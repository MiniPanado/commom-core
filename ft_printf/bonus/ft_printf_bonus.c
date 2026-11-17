/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:48:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/17 19:26:52 by lucerque         ###   ########.fr       */
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

void	parse_flags(const char *format, t_flag *flags)
{
}

static int	conversion(va_list *args, char **format, t_flag *flags)
{
	size_t	i;

	i = 0;
	while (g_conversions[i].type && g_conversions[i].type != c)
		i++;
	if (!g_conversions[i].func)
		return (-1);
	return (g_conversions[i].func(args));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flag	flags;
	int		total;
	int		ret;

	va_start(args, format);
	total = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_memset(&flags, 0, sizeof(t_flag));
			flags.precision = -1;
			ret = conversion(&args, &++format);
		}
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
