/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:08:11 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 13:49:29 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s;

	if (!(s = (t_list*)malloc(sizeof(*s))))
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}
