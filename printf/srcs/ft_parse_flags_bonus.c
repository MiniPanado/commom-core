#include "ft_printf_bonus.h"

int	ft_parse_flags(const char **format, t_flags *flags)
{
	/*
	** TODO:
	** - reset every field of `flags` to 0 first
	** - while `**format` is one of '-0#+ ' -> set the matching field
	**   in `flags` and advance `*format`
	** - while `**format` is a digit -> build up `flags->width`
	** - if `**format` == '.' -> advance, set has_precision = 1,
	**   then read digits into `flags->precision` (stays 0 if none follow)
	** - leave `*format` pointing AT the conversion character
	**   ('c', 's', 'd', ...), not past it
	*/
	(void)format;
	(void)flags;
	return (0);
}
