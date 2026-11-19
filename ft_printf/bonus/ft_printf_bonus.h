/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:11:15 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/19 14:49:19 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>

# define PF_NULL_STR	"(null)"
# define PF_NULL_PTR	"(nil)"

# define BASE_DEC		"0123456789"
# define BASE_HEX_LOWER	"0123456789abcdef"
# define BASE_HEX_UPPER	"0123456789ABCDEF"

# define INTEGER_CONVERSIONS	"diuxX"

typedef struct s_conversion
{
	char	type;
	int		(*func)(va_list *args);
}	t_conversion;

/* ---- API required by the subject ---- */
int		ft_printf(const char *format, ...);

/* ---- Mandatory conversions: c s p d i u x X % ---- */
int		ft_print_char(va_list *args);
int		ft_print_string(va_list *args);
int		ft_print_percent(va_list *args);

int		ft_print_int(va_list *args);
int		ft_print_uint(va_list *args);
int		ft_print_hex_lower(va_list *args);
int		ft_print_hex_upper(va_list *args);
int		ft_print_pointer(va_list *args);

/* --- Utils --- */
void	ft_init_flags(t_flag *flags);
void	ft_parse_flag_chars(const char **format, t_flag *flags);
int		ft_parse_number(const char **format, int *number);
void	ft_normalize_flags(t_flag *flags);

#endif
