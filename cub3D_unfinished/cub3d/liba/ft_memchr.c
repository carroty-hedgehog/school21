/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:08:38 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/28 00:14:07 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	m;

	s = (unsigned char *)str;
	m = (unsigned char)c;
	while (n--)
	{
		if (*s == m)
			return ((char*)s);
		s++;
	}
	return (NULL);
}
