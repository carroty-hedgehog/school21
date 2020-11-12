/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:08:54 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 13:52:02 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	s = (unsigned char *)source;
	d = (unsigned char *)destination;
	if (!source && !destination)
		return (destination);
	while (n--)
		*d++ = *s++;
	return (destination);
}
