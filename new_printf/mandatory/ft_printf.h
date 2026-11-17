/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:11:15 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/17 08:46:32 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# ifndef STDOUT_FILENO
#  define STDOUT_FILENO 
# endif

#define PF_NULL_STR "(null)"

typedef struct s_conversion
{
	char	type;
	int		(*func)(va_list *ap);
}	t_conversion;

/* ---- API required by the subject ---- */
int	ft_printf(const char *format, ...);

/* ---- Mandatory conversions: c s p d i u x X % ---- */
int	ft_print_char(va_list *ap);
int	ft_print_string(va_list *ap);
int	ft_print_pointer(va_list *ap);
int	ft_print_int(va_list *ap);
int	ft_print_uint(va_list *ap);
int	ft_print_hex(va_list *ap);
int	ft_print_percent(va_list *ap);

#endif
