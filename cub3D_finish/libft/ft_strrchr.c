/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:11:29 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:02:07 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;

	i = 0;
	ch = NULL;
	while (s[i])
	{
		if (s[i] == c)
		{
			ch = ((char *)s + i);
			return (ch);
		}
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		ch = ((char *)s + i);
	return (ch);
}