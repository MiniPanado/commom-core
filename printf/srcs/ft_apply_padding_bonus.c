#include "ft_printf_bonus.h"

int	ft_apply_padding(const char *content, t_flags *flags)
{
	/*
	** TODO:
	** - `content` is the string already built for the conversion
	**   (e.g. "2a" for %x of 42, "-13" for %d of -13, ...)
	** - work out how many padding chars are needed to reach
	**   `flags->width` (0 if `content` is already that long or longer)
	** - '-' set -> content first, then spaces on the right
	** - no '-' and '0' set (and no precision override on d/i/u/x/X)
	**   -> zeros on the left, but AFTER any sign, so "-007" not "00-7"
	** - otherwise -> spaces on the left
	** - write everything with ft_putchar_count / ft_putstr_count
	**   and return the total number of characters written
	*/
	(void)content;
	(void)flags;
	return (0);
}
