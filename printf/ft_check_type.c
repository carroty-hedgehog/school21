/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:40 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/05 13:51:21 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_type(va_list point, t_flag flag, int c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_write_char(va_arg(point, int), flag);
	else if (c == 's')
		len = ft_work_string(va_arg(point, char *), flag);
	else if (c == 'p')
		len = ft_work_pointer(va_arg(point, unsigned long int), flag);
	else if ((c == 'd') || (c == 'i'))
		len = ft_work_int(flag, va_arg(point, int));
	else if (c == 'u')
		len = ft_work_unsigned(flag, va_arg(point, unsigned int));
	else if (c == 'x')
		len = ft_work_hex(va_arg(point, unsigned int), flag, 0);
	else if (c == 'X')
		len = ft_work_hex(va_arg(point, unsigned int), flag, 1);
	else if (c == '%')
		len = ft_work_percent(flag);
	return (len);
}
