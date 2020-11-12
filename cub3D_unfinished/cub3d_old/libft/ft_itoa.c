/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:06:33 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 14:15:58 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_itoa_len(int n)
{
	size_t			r;

	r = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		r++;
	while (n)
	{
		n /= 10;
		r++;
	}
	return (r);
}

static int			ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

char				*ft_itoa(int n)
{
	size_t			l;
	size_t			e;
	char			*r;

	l = ft_itoa_len(n);
	if (!(r = (char *)malloc(l + 1)))
		return (NULL);
	r[l] = '\0';
	if (n < 0)
	{
		r[0] = '-';
		e = 1;
	}
	else
		e = 0;
	while (l-- > e)
	{
		r[l] = '0' + ft_abs(n % 10);
		n /= 10;
	}
	return (r);
}
