/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:08:20 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/27 19:33:00 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	unsigned long	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
