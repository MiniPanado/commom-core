/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:09:01 by lucerque          #+#    #+#             */
/*   Updated: 2026/10/28 16:31:04 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*bytes;

	bytes = (unsigned char *)s;
	while (n > 0)
	{
		*bytes = 0;
		bytes++;
		n--;
	}
}
