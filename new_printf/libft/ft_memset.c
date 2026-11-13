/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 19:01:42 by lucerque          #+#    #+#             */
/*   Updated: 2026/10/28 16:31:21 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*bytes;
	unsigned char	byte;

	bytes = (unsigned char *)s;
	byte = (unsigned char)c;
	while (n > 0)
	{
		*bytes = byte;
		bytes++;
		n--;
	}
	return (s);
}
