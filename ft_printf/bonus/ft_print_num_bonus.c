/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:00:00 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 16:00:00 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_int(va_list *args, t_flag *flags)
{
	int			nbr;
	uintmax_t	magnitude;

	nbr = va_arg(*args, int);
	if (nbr < 0)
		magnitude = -(long long)nbr;
	else
		magnitude = nbr;
	return (ft_put_number(magnitude, BASE_DEC,
			ft_sign_prefix(nbr, flags), flags));
}

int	ft_print_uint(va_list *args, t_flag *flags)
{
	return (ft_put_number(va_arg(*args, unsigned int), BASE_DEC, "", flags));
}

int	ft_print_hex_lower(va_list *args, t_flag *flags)
{
	unsigned int	nbr;

	nbr = va_arg(*args, unsigned int);
	return (ft_put_number(nbr, BASE_HEX_LOWER,
			ft_hex_prefix(nbr, "0x", flags), flags));
}

int	ft_print_hex_upper(va_list *args, t_flag *flags)
{
	unsigned int	nbr;

	nbr = va_arg(*args, unsigned int);
	return (ft_put_number(nbr, BASE_HEX_UPPER,
			ft_hex_prefix(nbr, "0X", flags), flags));
}

int	ft_print_pointer(va_list *args, t_flag *flags)
{
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
		return (ft_put_field(PF_NULL_PTR, (int)ft_strlen(PF_NULL_PTR), flags));
	return (ft_put_number((uintptr_t)ptr, BASE_HEX_LOWER,
			ft_pointer_prefix(flags), flags));
}
