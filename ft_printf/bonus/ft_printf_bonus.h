/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:00:00 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 16:00:00 by lucerque         ###   ########.fr       */
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

typedef struct s_flag
{
	int	minus;
	int	plus;
	int	zero;
	int	hash;
	int	space;
	int	width;
	int	precision;
}	t_flag;

typedef struct s_conversion
{
	char	type;
	int		(*func)(va_list *args, t_flag *flags);
}	t_conversion;

/* ---- API required by the subject ---- */
int			ft_printf(const char *format, ...);

/* ---- Conversions: c s p d i u x X % ---- */
int			ft_print_char(va_list *args, t_flag *flags);
int			ft_print_string(va_list *args, t_flag *flags);
int			ft_print_percent(va_list *args, t_flag *flags);

int			ft_print_int(va_list *args, t_flag *flags);
int			ft_print_uint(va_list *args, t_flag *flags);
int			ft_print_hex_lower(va_list *args, t_flag *flags);
int			ft_print_hex_upper(va_list *args, t_flag *flags);
int			ft_print_pointer(va_list *args, t_flag *flags);

/* --- Output --- */
int			ft_put_padding(int count, char fill);
int			ft_put_field(const char *str, int len, t_flag *flags);
int			ft_put_unsigned_base(uintmax_t nbr, const char *base);
int			ft_put_number(uintmax_t value, const char *base,
				const char *prefix, t_flag *flags);

/* --- Number helpers --- */
int			ft_count_digits(uintmax_t nbr, size_t base_len);
const char	*ft_sign_prefix(int nbr, t_flag *flags);
const char	*ft_hex_prefix(unsigned int nbr, const char *prefix,
				t_flag *flags);
const char	*ft_pointer_prefix(t_flag *flags);

/* --- Parse --- */
int			ft_parse_flags(const char **format, t_flag *flags);
int			ft_parse_number(const char **format, int *value);

#endif
