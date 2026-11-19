/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:01:55 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/19 14:45:30 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_parse_width(const char **format, t_flag *flags)
{
	return (ft_parse_number(format, &flags->width));
}

static int	ft_parse_precision(const char **format, t_flag *flags)
{
	if (**format != '.')
		return (0);
	(*format)++;
	flags->precision = 0;
	return (ft_parse_number(format, &flags->precision));
}

int	parse_flags(const char **format, t_flag *flags)
{
	ft_init_flags(flags);
	ft_parse_flag_chars(format, flags);
	if (ft_parse_width(format, flags) < 0)
		return (-1);
	if (ft_parse_precision(format, flags) < 0)
		return (-1);
	ft_normalize_flags(flags, **format);
	return (0);
}
