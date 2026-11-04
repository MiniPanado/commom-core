/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucerque <lucerque@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:40:33 by lucerque          #+#    #+#             */
/*   Updated: 2026/11/04 20:06:27 by lucerque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del)
	{
		return (NULL);
	}
	begin_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&begin_list, del);
			return (NULL);
		}
		ft_lstadd_back(&begin_list, new_node);
		lst = lst->next;
	}
	return (begin_list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	**tail;
	t_list	*node;
	void	*content;

	if (!f || !del)
		return (NULL);
	head = NULL;
	tail = &head;
	while (lst)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		*tail = node;
		tail = &node->next;
		lst = lst->next;
	}
	return (head);
}
