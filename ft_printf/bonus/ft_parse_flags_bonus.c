/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 22:55:15 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 22:55:20 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_init_flags(t_flag *flags)
{
	ft_memset(flags, 0, sizeof(t_flag));
	flags->precision = -1;
}

static void	ft_parse_flag_chars(const char **format, t_flag *flags)
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

static int	ft_parse_precision(const char **format, t_flag *flags)
{
	if (**format != '.')
		return (0);
	(*format)++;
	return (ft_parse_number(format, &flags->precision));
}

int	ft_parse_flags(const char **format, t_flag *flags)
{
	ft_init_flags(flags);
	ft_parse_flag_chars(format, flags);
	if (ft_parse_number(format, &flags->width) < 0)
		return (-1);
	if (ft_parse_precision(format, flags) < 0)
		return (-1);
	if (flags->minus)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	return (0);
}
