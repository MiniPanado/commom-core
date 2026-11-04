/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:33:12 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/04 19:36:54 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*following;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		following = current->next;
		ft_lstdelone(current, del);
		current = following;
	}
	*lst = NULL;
}
