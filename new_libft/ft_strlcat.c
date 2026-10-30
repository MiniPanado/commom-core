/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:19:25 by lucerque          #+#    #+#             */
/*   Updated: 2026/10/29 18:11:42 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_size;

	d_size = 0;
	while (d_size < size && dst[d_size])
	{
		d_size++;
	}
	if (d_size == size)
	{
		return (size + ft_strlen(src));
	}
	i = 0;
	while (src[i] && (i + d_size) < (size - 1))
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + ft_strlen(src));
}
