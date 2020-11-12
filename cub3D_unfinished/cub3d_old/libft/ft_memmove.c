/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:09:03 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 15:11:06 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	s = (unsigned char *)source;
	d = (unsigned char *)destination;
	if (!source && !destination)
		return (destination);
	if (source < destination)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
		{
			*d = *s;
			d++;
			s++;
		}
	return (destination);
}
