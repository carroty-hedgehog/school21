/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:07:33 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/04 19:07:55 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int		ft_toupper(int ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	else
		return (ch);
}

static int	ft_len(long long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(long long n)
{
	char	*num;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_len(n);
	if (!(num = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i] = '\0';
	i--;
	if (n < 0)
	{
		n = (-1) * n;
		num[0] = '-';
	}
	while (n > 0)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

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
