/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 18:07:53 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/05 13:21:40 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *input, ...)
{
	va_list		point;
	int			len;
	int			i;

	i = -1;
	len = 0;
	if (input == NULL)
		return (-1);
	va_start(point, input);
	len = ft_parser(point, input, i, len);
	va_end(point);
	return (len);
}
