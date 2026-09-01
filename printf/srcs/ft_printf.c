#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	/*
	** TODO:
	** - percorrer `format` caractere a caractere
	** - caractere normal -> escreve-lo e somar 1 a `count`
	** - ao encontrar '%' -> avancar para o proximo caractere e chamar
	**   ft_handle_conversion(conv, &args); somar o retorno a `count`
	**   (e tratar o caso de retorno -1 == erro)
	*/
	va_end(args);
	return (count);
}
