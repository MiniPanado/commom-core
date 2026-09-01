#include "ft_printf.h"

int	ft_putchar_count(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_count(char *s)
{
	/*
	** TODO: escrever `s` no fd 1 e devolver o numero de bytes escritos
	*/
	(void)s;
	return (0);
}

int	ft_putnbr_base_count(unsigned long n, const char *base)
{
	/*
	** TODO: conversao (recursiva ou iterativa) de `n` para a base dada.
	** o comprimento de `base` e a propria base numerica
	** (ex: "0123456789abcdef" tem 16 caracteres -> base 16)
	*/
	(void)n;
	(void)base;
	return (0);
}
