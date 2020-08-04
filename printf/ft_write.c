/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:36 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/03 20:10:56 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

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

int		ft_write_string(char *str, int end)
{
	int i;

	i = 0;
	while (str[i] && i < end)
		ft_putchar(str[i++]);
	return (i);
}

int		ft_write_int(t_flag flag, char *num_str)
{
	int len;

	len = 0;
	if ((size_t)flag.dot >= ft_strlen(num_str))
		len += ft_work_width_zero((size_t)flag.dot - ft_strlen(num_str));
	len += ft_write_string(num_str, ft_strlen(num_str));
	return (len);
}
