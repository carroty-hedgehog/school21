/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:09:13 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 15:11:43 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *str;
	unsigned char m;

	str = (unsigned char *)s;
	m = (unsigned char)c;
	while (n--)
		*str++ = m;
	return (s);
}
