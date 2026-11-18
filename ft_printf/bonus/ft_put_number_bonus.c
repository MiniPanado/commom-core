/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_number_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:00:00 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 16:00:00 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_num_digits(uintmax_t value, const char *base, t_flag *flags)
{
	if (value == 0 && flags->precision == 0)
		return (0);
	return (ft_count_digits(value, ft_strlen(base)));
}

static int	ft_num_zeros(int digits, const char *prefix, t_flag *flags)
{
	int	zeros;

	zeros = 0;
	if (flags->precision >= 0)
		zeros = flags->precision - digits;
	else if (flags->zero)
		zeros = flags->width - (int)ft_strlen(prefix) - digits;
	if (zeros < 0)
		zeros = 0;
	return (zeros);
}

static int	ft_put_prefix(const char *prefix, int zeros)
{
	size_t	len;
	int		padded;

	len = ft_strlen(prefix);
	if (write(STDOUT_FILENO, prefix, len) != (ssize_t)len)
		return (-1);
	padded = ft_put_padding(zeros, '0');
	if (padded < 0)
		return (-1);
	return ((int)len + padded);
}

static int	ft_put_digits(uintmax_t value, const char *base, int digits)
{
	if (digits == 0)
		return (0);
	return (ft_put_unsigned_base(value, base));
}

int	ft_put_number(uintmax_t value, const char *base, const char *prefix,
			t_flag *flags)
{
	int	digits;
	int	zeros;
	int	pad;
	int	body;
	int	tail;

	digits = ft_num_digits(value, base, flags);
	zeros = ft_num_zeros(digits, prefix, flags);
	pad = flags->width - (int)ft_strlen(prefix) - zeros - digits;
	if (pad < 0)
		pad = 0;
	if (!flags->minus && ft_put_padding(pad, ' ') < 0)
		return (-1);
	body = ft_put_prefix(prefix, zeros);
	if (body < 0)
		return (-1);
	tail = ft_put_digits(value, base, digits);
	if (tail < 0)
		return (-1);
	if (flags->minus && ft_put_padding(pad, ' ') < 0)
		return (-1);
	return (pad + body + tail);
}
