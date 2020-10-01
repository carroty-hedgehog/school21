/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:06:43 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/27 21:35:58 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*newlst;

	newlst = *lst;
	if (*lst)
	{
		while (newlst->next != NULL)
			newlst = newlst->next;
		newlst->next = new;
	}
	else
		*lst = new;
}
