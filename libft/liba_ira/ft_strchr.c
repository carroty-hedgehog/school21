/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:10:08 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 15:14:49 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	m;

	m = (char)c;
	while (*s != '\0')
		if (*s++ == m)
			return ((char *)s - 1);
	if (!c && *s == '\0')
		return ((char *)s);
	return (NULL);
}
