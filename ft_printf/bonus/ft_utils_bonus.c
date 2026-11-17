/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 13:27:58 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/17 17:12:58 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

ssize_t	ft_put_ulong_base(uintmax_t nbr, const char *base)
{
	size_t	base_len;
	ssize_t	head_count;
	ssize_t	tail_count;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (-1);
	head_count = 0;
	if (nbr >= base_len)
	{
		head_count = ft_put_ulong_base(nbr / base_len, base);
		if (head_count < 0)
			return (-1);
	}
	tail_count = write(STDOUT_FILENO, &base[nbr % base_len], 1);
	if (tail_count < 0)
		return (-1);
	return (head_count + tail_count);
}

ssize_t	ft_put_int(int nbr)
{
	ssize_t			sign_count;
	ssize_t			digits_count;
	unsigned long	magnitude;

	sign_count = 0;
	magnitude = nbr;
	if (nbr < 0)
	{
		sign_count = write(STDOUT_FILENO, "-", 1);
		if (sign_count < 0)
			return (-1);
		magnitude = -(long long)nbr;
	}
	digits_count = ft_put_ulong_base(magnitude, BASE_DEC);
	if (digits_count < 0)
		return (-1);
	return (sign_count + digits_count);
}
