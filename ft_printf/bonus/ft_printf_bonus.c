/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:48:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 10:56:35 by lucerque         ###   ########.fr       */
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

static void	set_flag(char c, t_flag *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
}

static int	parse_number(const char **format, int *nbr)
{
	*nbr = 0;
	while (ft_isdigit(**format))
	{
		if (*nbr > (INT_MAX - (**format - '0')) / 10)
			return (-1);
		*nbr = *nbr * 10 + (**format - '0');
		(*format)++;
	}
	return (0);
}

static int	parse_flags(const char **format, t_flag *flags)
{
	ft_memset(flags, 0, sizeof(t_flag));
	flags->precision = -1;
	while (**format && ft_strchr(FLAG_CHARS, **format))
	{
		set_flag(**format, flags);
		(*format)++;
	}
	if (parse_number(format, &flags->width) < 0)
		return (-1);
	if (**format == '.')
	{
		(*format)++;
		if (parse_number(format, &flags->precision) < 0)
			return (-1);
	}
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	return (0);
}

static int	conversion(va_list *args, const char **format)
{
	t_flag	flags;
	size_t	i;

	(*format)++;
	if (parse_flags(format, &flags) < 0)
		return (-1);
	i = 0;
	while (g_conversions[i].type && g_conversions[i].type != **format)
		i++;
	if (!g_conversions[i].func)
		return (-1);
	return (g_conversions[i].func(args, &flags));
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
			ret = conversion(&args, &format);
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
