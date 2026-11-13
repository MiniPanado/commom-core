/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:48:27 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/04 18:57:05 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_unsigned_fd(unsigned int n, int fd)
{
	if (n >= 10)
		put_unsigned_fd(n / 10, fd);
	ft_putchar_fd("0123456789"[n % 10], fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		put_unsigned_fd(-(unsigned int)n, fd);
	}
	else
		put_unsigned_fd((unsigned int)n, fd);
}
