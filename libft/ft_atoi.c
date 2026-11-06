/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 23:04:38 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/06 13:18:25 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned long	result;
	unsigned long	limit;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = -1;
	limit = (unsigned long)LONG_MAX + (sign == -1);
	while (ft_isdigit(nptr[i]))
	{
		if (result > (limit - (nptr[i] - '0')) / 10)
			result = limit;
		else
			result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(long)(sign * result));
}
