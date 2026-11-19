/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 14:51:01 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/19 20:18:33 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <limits.h>

static int	ft_write_all(const char *buffer, size_t length)
{
	size_t	offset;
	ssize_t	bytes_written;

	offset = 0;
	while (offset < length)
	{
		bytes_written = write(STDOUT_FILENO, buffer + offset, length - offset);
		if (bytes_written <= 0)
			return (-1);
		offset += (size_t)bytes_written;
	}
	return (0);
}

static int	ft_apply_padding(char padding_char, int padding_size)
{
	int	chars_written;

	chars_written = 0;
	while (chars_written < padding_size)
	{
		if (ft_write_all(&padding_char, 1) < 0)
			return (-1);
		chars_written++;
	}
	return (chars_written);
}

static int	ft_print_padded(const char *content, size_t content_length,
		t_flag *flags)
{
	int	padding_size;
	int	total_chars;

	if (content_length > INT_MAX)
		return (-1);
	padding_size = 0;
	if (flags->width > (int)content_length)
		padding_size = flags->width - (int)content_length;
	total_chars = (int)content_length + padding_size;
	if (flags->minus)
	{
		if (ft_write_all(content, content_length) < 0)
			return (-1);
		if (ft_apply_padding(' ', padding_size) < 0)
			return (-1);
	}
	else
	{
		if (ft_apply_padding(' ', padding_size) < 0)
			return (-1);
		if (ft_write_all(content, content_length) < 0)
			return (-1);
	}
	return (total_chars);
}

int	ft_print_char_bonus(va_list *args, t_flag *flags)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (ft_print_padded(&c, 1, flags));
}

int	ft_print_string_bonus(va_list *args, t_flag *flags)
{
	const char	*str;
	size_t		len;

	str = va_arg(*args, const char *);
	if (!str)
		str = PF_NULL_STR;
	len = ft_strlen(str);
	if (flags->precision >= 0 && (size_t)flags->precision < len)
		len = (size_t)flags->precision;
	return (ft_print_padded(str, len, flags));
}
