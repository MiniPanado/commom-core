/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 18:40:52 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/02 18:58:58 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	total_len;
	char	*join;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	s1_len = ft_strlen(s1);
	total_len = s1_len + ft_strlen(s2) + 1;
	join = malloc(total_len);
	if (!join)
	{
		return (NULL);
	}
	ft_strlcpy(join, s1, (s1_len + 1));
	ft_strlcpy(join + s1_len, s2, (total_len - s1_len));
	return (join);
}
