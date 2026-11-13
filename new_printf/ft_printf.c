/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:48:34 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/13 20:25:37 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_conversion	g_table[] = {
{'c', print_c},
{'s', print_s},
{'p', print_p},
{'d', print_d},
{'i', print_i},
{'u', print_u},
{'x', print_x},
{'X', print_big_x},
{'%', print_percent},
{0, NULL}
};

int	ft_printf(const char *, ...)
{
	va_list	ap;

	va_end(ap);
	return (0);
}
