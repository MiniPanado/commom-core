#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del)
		return (NULL);
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
