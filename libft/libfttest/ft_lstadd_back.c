#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*newlst;

	newlst = *lst;
	if (!lst)
		return;
	
	if (lst && *lst)
	{
		newlst = ft_lstlast(*lst);
			newlst->next = new;	
	}
	else
		*lst = new;
}