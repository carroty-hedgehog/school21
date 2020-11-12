/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:10:16 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 15:16:45 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		n;
	char	*s;

	n = 0;
	while (src[n])
		n++;
	if (!(s = (char *)malloc(sizeof(*src) * (n + 1))))
		return (NULL);
	while (n >= 0)
	{
		s[n] = src[n];
		n--;
	}
	return (s);
}
