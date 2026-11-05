/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 19:02:21 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/02 22:11:01 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set || *set == '\0')
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim = (char *)malloc(((end - start + 1)) * sizeof(char));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, s1 + start, (end - start + 1));
	return (trim);
}
