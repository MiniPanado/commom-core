/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 05:34:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/17 17:17:11 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (write(STDOUT_FILENO, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_print_string(va_list *args)
{
	const char	*str;
	size_t		len;

	str = va_arg(*args, const char *);
	if (!str)
		str = PF_NULL_STR;
	len = ft_strlen(str);
	if (write(STDOUT_FILENO, str, len) != (ssize_t)len)
		return (-1);
	return ((int)len);
}

int	ft_print_percent(va_list *args)
{
	(void)args;
	if (write(STDOUT_FILENO, "%", 1) != 1)
		return (-1);
	return (1);
}
