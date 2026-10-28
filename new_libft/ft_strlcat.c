/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:19:25 by lucerque          #+#    #+#             */
/*   Updated: 2026/10/28 20:19:02 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings respec‐
     tively. strlcpy() and strlcat() take the full size of the buffer (not just the
     length) and guarantee to NUL-terminate the result (as long as size is larger
     than 0 or, in the case of strlcat(), as long as there is at least one byte
     free in dst).  Note that a byte for the NUL should be included in size.  Also
     note that strlcpy() and strlcat() only operate on true “C” strings.  This
     means that for strlcpy() src must be NUL-terminated and for strlcat() both
     src and dst must be NUL-terminated.

     The strlcat() function appends the NUL-terminated string src to the end of
     dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-terminating
     the result.

RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the string
     they tried to create. For strlcat() that means the initial length of dst plus the length of src.  While
     this may seem somewhat confusing, it was done to make truncation detection
     simple.

     Note, however, that if strlcat() traverses size characters without finding a
     NUL, the length of the string is considered to be size and the destination
     string will not be NUL-terminated (since there was no space for the NUL).
     This keeps strlcat() from running off the end of a string.  In practice this
     should not happen (as it means that either size is incorrect or that dst is
     not a proper “C” string).  The check exists to prevent potential security
     problems in incorrect code.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_size;

	d_size = 0;
	while (dst[d_size] && d_size < size)
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


size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_size;

	d_size = 0;
	while (d_size < size && dst[d_size])
		d_size++;
	if (d_size == size)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && (i + d_size) < (size - 1))
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + ft_strlen(src));
}

