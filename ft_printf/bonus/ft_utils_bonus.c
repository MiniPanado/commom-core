/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:00:00 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 16:00:00 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_unsigned_base(uintmax_t nbr, const char *base)
{
	size_t	base_len;
	int		head_count;
	int		tail_count;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (-1);
	head_count = 0;
	if (nbr >= base_len)
	{
		head_count = ft_put_unsigned_base(nbr / base_len, base);
		if (head_count < 0)
			return (-1);
	}
	tail_count = write(STDOUT_FILENO, &base[nbr % base_len], 1);
	if (tail_count < 0)
		return (-1);
	return (head_count + tail_count);
}

int	ft_count_digits(uintmax_t nbr, size_t base_len)
{
	int	count;

	count = 1;
	while (nbr >= base_len)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}

int	ft_put_padding(int count, char fill)
{
	int	printed;

	printed = 0;
	while (printed < count)
	{
		if (write(STDOUT_FILENO, &fill, 1) != 1)
			return (-1);
		printed++;
	}
	return (printed);
}

int	ft_parse_number(const char **format, int *value)
{
	int	digit;

	*value = 0;
	while (ft_isdigit(**format))
	{
		digit = **format - '0';
		if (*value > (INT_MAX - digit) / 10)
			return (-1);
		*value = *value * 10 + digit;
		(*format)++;
	}
	return (0);
}
