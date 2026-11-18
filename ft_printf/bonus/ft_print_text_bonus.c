/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:00:00 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 16:00:00 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_put_field(const char *str, int len, t_flag *flags)
{
	int	pad;
	int	left;
	int	body;
	int	right;

	pad = flags->width - len;
	if (pad < 0)
		pad = 0;
	left = 0;
	right = 0;
	if (!flags->minus)
		left = ft_put_padding(pad, ' ');
	if (left < 0)
		return (-1);
	body = write(STDOUT_FILENO, str, len);
	if (body != len)
		return (-1);
	if (flags->minus)
		right = ft_put_padding(pad, ' ');
	if (right < 0)
		return (-1);
	return (left + body + right);
}

static const char	*ft_resolve_string(const char *str, t_flag *flags)
{
	int	null_len;

	if (str)
		return (str);
	null_len = (int)ft_strlen(PF_NULL_STR);
	if (flags->precision >= 0 && flags->precision < null_len)
		return ("");
	return (PF_NULL_STR);
}

int	ft_print_char(va_list *args, t_flag *flags)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (ft_put_field(&c, 1, flags));
}

int	ft_print_string(va_list *args, t_flag *flags)
{
	const char	*str;
	int			len;

	str = ft_resolve_string(va_arg(*args, const char *), flags);
	len = (int)ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	return (ft_put_field(str, len, flags));
}

int	ft_print_percent(va_list *args, t_flag *flags)
{
	(void)args;
	(void)flags;
	if (write(STDOUT_FILENO, "%", 1) != 1)
		return (-1);
	return (1);
}
