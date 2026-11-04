/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:53:19 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/04 18:55:07 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digits(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	unsigned int	magnitude;
	size_t			len;
	char			*str;

	if (n < 0)
		magnitude = -(unsigned int)n;
	else
		magnitude = (unsigned int)n;
	len = count_digits(magnitude) + (n < 0);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = magnitude % 10 + '0';
		magnitude /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
