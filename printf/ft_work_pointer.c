/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:30 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/03 20:11:02 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_work_pointer(unsigned long long num, t_flag flag)
{
	char	*point_str;
	int		len;

	len = 0;
	if (!(point_str = ft_itoa_hex(num)))
		return (-1);
	if (flag.minus == 1)
	{
		len += ft_write_string("0x", 2);
		len += ft_write_string(point_str, ft_strlen(point_str));
	}
	len += ft_work_width_space(flag.width - ft_strlen(point_str) - 2);
	if (flag.minus == 0)
	{
		len += ft_write_string("0x", 2);
		len += ft_write_string(point_str, ft_strlen(point_str));
	}
	free(point_str);
	return (len);
}
