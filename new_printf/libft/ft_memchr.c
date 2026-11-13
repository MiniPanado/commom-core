/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 18:51:12 by lucerque          #+#    #+#             */
/*   Updated: 2026/10/30 22:41:32 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*bytes;
	unsigned char		byte;

	bytes = (const unsigned char *)s;
	byte = (unsigned char)c;
	while (n > 0)
	{
		if (*bytes == byte)
		{
			return ((void *)bytes);
		}
		bytes++;
		n--;
	}
	return (NULL);
}
