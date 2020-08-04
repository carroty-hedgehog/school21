/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:28 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/03 20:11:04 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_work_percent(t_flag flag)
{
	int	len;

	len = 0;
	if (flag.minus == 1)
		len += ft_putchar('%');
	if (flag.zero == 0)
		len += ft_work_width_space(flag.width - 1);
	else
		len += ft_work_width_zero(flag.width - 1);
	if (flag.minus == 0)
		len += ft_putchar('%');
	return (len);
}
