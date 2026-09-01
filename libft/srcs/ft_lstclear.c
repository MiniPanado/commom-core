#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
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
