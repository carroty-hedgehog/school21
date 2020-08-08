/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:23:01 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/05 13:28:08 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_char(char c, t_flag flag)
{
	int	len;

	len = 0;
	if (flag.minus == 1)
		len += ft_putchar(c);
	len += ft_work_width_space(flag.width - 1);
	if (flag.minus == 0)
		len += ft_putchar(c);
	return (len);
}
