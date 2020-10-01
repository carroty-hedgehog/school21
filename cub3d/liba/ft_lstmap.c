/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:08:03 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/26 23:36:54 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;

	new_lst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	if (lst)
	{
		temp = lst;
		new_lst = ft_lstnew(lst->content);
		if (!(new_lst))
		{
			ft_lstclear((&new_lst), del);
			return (NULL);
		}
		new_lst->content = f(new_lst->content);
		if (temp->next)
			new_lst->next = ft_lstmap(temp->next, f, del);
	}
	return (new_lst);
}
