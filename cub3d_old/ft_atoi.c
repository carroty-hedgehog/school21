/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 00:18:48 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 14:05:53 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char			*ft_lets_go(const char *str)
{
	while (*str != '\0' && (*str == '\t' || *str == '\n' || *str == '\v' ||
		*str == '\f' || *str == '\r' || *str == ' '))
		str++;
	return (str);
}

int					ft_atoi(const char *str)
{
	short int		m;
	unsigned long	r;
	unsigned long	save;

	str = ft_lets_go(str);
	r = 0;
	m = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			m = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		save = r;
		r = (r * 10) + (*str - '0');
		str++;
		if (save > r && m == 1)
			return (-1);
		if (save > r && m == -1)
			return (0);
	}
	return (r * m);
}
