/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 20:11:15 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/14 05:05:54 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# ifndef STDOUT_FILENO
#  define STDOUT_FILENO 
# endif

typedef struct s_conversion
{
	char	type;
	void	(*func)(va_list *ap);
}	t_conversion;

#endif
