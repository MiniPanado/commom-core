/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:00:00 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/18 16:00:00 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

const char	*ft_sign_prefix(int nbr, t_flag *flags)
{
	if (nbr < 0)
		return ("-");
	if (flags->plus)
		return ("+");
	if (flags->space)
		return (" ");
	return ("");
}

const char	*ft_hex_prefix(unsigned int nbr, const char *prefix,
				t_flag *flags)
{
	if (flags->hash && nbr != 0)
		return (prefix);
	return ("");
}

const char	*ft_pointer_prefix(t_flag *flags)
{
	if (flags->plus)
		return ("+0x");
	if (flags->space)
		return (" 0x");
	return ("0x");
}
