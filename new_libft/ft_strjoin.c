/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:40:52 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/02 18:52:40 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*join;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc((size) * sizeof(char));
	if (!join)
	{
		return (NULL);
	}
	join[0] = '\0';
	ft_strlcat(join, s1, size);
	ft_strlcat(join, s2, size);
	return (join);
}
