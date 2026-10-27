#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_flags
{
	bool			minus;
	bool			zero;
	bool			hash;
	bool			plus;
	bool			space;
	size_t			width;
	size_t			precision;
	bool			has_precision;
}	t_flags;

typedef struct s_conv
{
	char			*body;
	char			sign;
	const char		*prefix;
	bool			numeric;
}	t_conv;

/* ---- API required by the subject ---- */
int					ft_printf(const char *format, ...);

/* ---- Bonus: reads '-0.# +' and any width digits right after '%' ---- */
int					ft_parse_flags(const char **format,
						t_flags *flags);

/* ---- Bonus: pads/writes a conversion's already-built content ---- */
int					ft_apply_padding(const char *content,
						t_flags *flags, char fill);

/* ---- Bonus: dispatch, aware of flags ---- */
int					ft_handle_conversion_bonus(char conv,
						va_list *args, t_flags *flags);

/* ---- Bonus: conversions cspdiuxX%, aware of flags/width/precision ---- */
int					ft_print_char_bonus(va_list *args, t_flags *flags);
int					ft_print_string_bonus(va_list *args, t_flags *flags);
int					ft_print_pointer_bonus(va_list *args, t_flags *flags);
int					ft_print_int_bonus(va_list *args, t_flags *flags);
int					ft_print_uint_bonus(va_list *args, t_flags *flags);
int					ft_print_hex_bonus(va_list *args,
						t_flags *flags, bool upper);
int					ft_print_percent_bonus(t_flags *flags);

/* */
int					ft_finalize_conv_bonus(t_conv *conv, t_flags *flags,
						char converter);
void				ft_apply_precision_bonus(t_conv *conv, t_flags *flags,
						char converter);
char				*ft_assemble_bonus(t_conv *conv, t_flags *flags,
						char converter);
bool				ft_zero_padding_applies_bonus(t_conv *conv,
						t_flags *flags);

/* */
size_t				ft_strlen(const char *s);
char				*ft_strndup(const char *src, size_t n);
char				*ft_utoa_base(unsigned long long value, const char *base);

/* ---- Helpers ---- */
int		ft_putchar_count(const char c);
int		ft_putstr_count(const char *s);
int		ft_putnbr_base_count(unsigned long n, const char *base);


#endif
