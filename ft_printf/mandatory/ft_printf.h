/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:11:15 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/20 08:49:09 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define PF_NULL_STR	"(null)"
# define PF_NULL_PTR	"(nil)"

# define BASE_DEC		"0123456789"
# define BASE_HEX_LOWER	"0123456789abcdef"
# define BASE_HEX_UPPER	"0123456789ABCDEF"

/* ---- API required by the subject ---- */
int		ft_printf(const char *format, ...);

/* ---- Mandatory conversions: c s p d i u x X % ---- */
int		ft_print_char(va_list *args);
int		ft_print_string(va_list *args);
int		ft_print_percent(va_list *args);

int		ft_print_int(va_list *args);
int		ft_print_uint(va_list *args);
int		ft_print_hex(va_list *args, int is_upper);
int		ft_print_pointer(va_list *args);

/* --- Utils --- */
ssize_t	ft_put_int(int nbr);
ssize_t	ft_put_ulong_base(uintmax_t nbr, const char *base);

#endif
