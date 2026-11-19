/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:48:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/19 15:19:57 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	conversion(va_list *args, const char **format)
{
	t_flag	flags;

	(*format)++;
	if (parse_flags(format, &flags) < 0)
		return (-1);
	if (**format == 'c')
		return (ft_print_char_bonus(args, &flags));
	if (**format == 's')
		return (ft_print_string_bonus(args, &flags));
	if (**format == 'p')
		return (ft_print_pointer_bonus(args, &flags));
	if (**format == 'd' || **format == 'i')
		return (ft_print_int_bonus(args, &flags));
	if (**format == 'u')
		return (ft_print_uint_bonus(args, &flags));
	if (**format == 'x')
		return (ft_print_hex_lower_bonus(args, &flags));
	if (**format == 'X')
		return (ft_print_hex_upper_bonus(args, &flags));
	if (**format == '%')
		return (ft_print_percent_bonus(args, &flags));
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
