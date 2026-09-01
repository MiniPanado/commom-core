#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/* ---- API required by the subject ---- */
int		ft_printf(const char *format, ...);

/* ---- Parsing of the conversion character ---- */
int		ft_handle_conversion(char conv, va_list *args);

/* ---- Mandatory conversions: c s p d i u x X % ---- */
int		ft_print_char(va_list *args);
int		ft_print_string(va_list *args);
int		ft_print_pointer(va_list *args);
int		ft_print_int(va_list *args);
int		ft_print_uint(va_list *args);
int		ft_print_hex(va_list *args, int is_upper);
int		ft_print_percent(void);

/* ---- Helpers ---- */
int		ft_putchar_count(char c);
int		ft_putstr_count(char *s);
int		ft_putnbr_base_count(unsigned long n, const char *base);

#endif
