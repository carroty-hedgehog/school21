/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:32 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/03 20:11:00 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_work_width_space(int width)
{
	int	len;

	len = -1;
	while (++len < width)
		ft_putchar(' ');
	return (len);
}

static int		ft_work_flag_string(char *str, t_flag flag)
{
	int			len;

	len = 0;
	if (flag.dot >= 0)
		len += ft_write_string(str, flag.dot);
	else
		len += ft_write_string(str, ft_strlen(str));
	return (len);
}

int				ft_work_string(char *str, t_flag flag)
{
	int			len;

	len = 0;
	if (!str)
		str = "(null)";
	if (flag.dot >= 0 && (size_t)flag.dot > ft_strlen(str))
		flag.dot = ft_strlen(str);
	if (flag.minus == 1)
		len += ft_work_flag_string(str, flag);
	if (flag.dot >= 0)
		len += ft_work_width_space(flag.width - flag.dot);
	else
		len += ft_work_width_space(flag.width - ft_strlen(str));
	if (flag.minus == 0)
		len += ft_work_flag_string(str, flag);
	return (len);
}
