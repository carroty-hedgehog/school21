/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:38 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/03 20:10:54 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_flag_minus(t_flag flag)
{
	flag.minus = 1;
	flag.zero = 0;
	return (flag);
}

int			ft_flag_dot(const char *save, va_list point, t_flag *flag, int len)
{
	int		i;

	i = len + 1;
	if (save[i] == '*')
	{
		flag->dot = va_arg(point, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(save[i]))
			flag->dot = (10 * flag->dot) + (save[i++] - '0');
	}
	return (i);
}

t_flag		ft_flag_width(va_list point, t_flag flag)
{
	flag.width = va_arg(point, int);
	if (flag.width < 0)
	{
		flag.minus = 1;
		flag.width *= -1;
		flag.zero = 0;
	}
	return (flag);
}

t_flag		ft_flag_digit(const char *save, t_flag flag, int *i)
{
	while (ft_isdigit(save[*i]))
		flag.width = (10 * flag.width) + (save[(*i)++] - '0');
	(*i)--;
	return (flag);
}
