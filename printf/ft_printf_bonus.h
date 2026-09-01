/* ************************************************************************** */
/*                                                  ft_printf_bonus.h         */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

typedef struct s_flags
{
	int	minus;			/* '-' : left-justify within the field width      */
	int	zero;			/* '0' : pad with zeros instead of spaces         */
	int	hash;			/* '#' : alternate form (0x/0X prefix, etc.)      */
	int	plus;			/* '+' : force a sign on signed conversions       */
	int	space;			/* ' ' : space instead of '+' for positive nums   */
	int	width;			/* minimum field width (0 = none given)           */
	int	precision;		/* value found after '.'                          */
	int	has_precision;	/* whether a '.' was present at all               */
}	t_flags;

/* ---- Bonus: reads '-0.# +' and any width digits right after '%' ---- */
int		ft_parse_flags(const char **format, t_flags *flags);

/* ---- Bonus: pads/writes a conversion's already-built content ---- */
int		ft_apply_padding(const char *content, t_flags *flags);

#endif
