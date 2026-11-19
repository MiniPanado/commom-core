/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:19:24 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/19 14:50:22 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_flags(t_flag *flags)
{
	ft_memset(flags, 0, sizeof(t_flag));
	flags->precision = -1;
}

void	ft_parse_flag_chars(const char **format, t_flag *flags)
{
	char	c;

	while (1)
	{
		c = **format;
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
		else
			break ;
		(*format)++;
	}
}

int	ft_parse_number(const char **format, int *number)
{
	int				digit;
	unsigned char	c;

	c = (unsigned char)**format;
	while (ft_isdigit(c))
	{
		digit = c - '0';
		if (*number > (INT_MAX - digit) / 10)
			return (-1);
		*number = *number * 10 + digit;
		(*format)++;
		c = (unsigned char)**format;
	}
	return (0);
}

void	ft_normalize_flags(t_flag *flags, char conversion)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->precision >= 0 && ft_strchr(INTEGER_CONVERSIONS, conversion))
		flags->zero = 0;
}
