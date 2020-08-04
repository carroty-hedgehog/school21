/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:21 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/04 14:42:50 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_hex(unsigned long long num)
{
	char				*hex_str;
	int					len;
	char				*tab;
	unsigned long long	save_num;

	tab = "0123456789abcdef";
	len = 0;
	save_num = num;
	while (save_num /= 16)
		len++;
	len++;
	if (!(hex_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	hex_str[len] = '\0';
	while (len > 0)
	{
		hex_str[len - 1] = tab[num % 16];
		len--;
		num /= 16;
	}
	return (hex_str);
}

static char		*ft_toupper_str(char *str)
{
	int			i;

	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}

static int		ft_write_hex(t_flag flag, char *hex_str)
{
	int			len;

	len = 0;
	if (flag.dot >= 0)
		len += ft_work_width_zero(flag.dot - ft_strlen(hex_str));
	len += ft_write_string(hex_str, ft_strlen(hex_str));
	return (len);
}

static int		ft_work_flag_hex(char *hex_str, t_flag flag)
{
	int			len;

	len = 0;
	if (flag.minus == 1)
		len += ft_write_hex(flag, hex_str);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(hex_str))
		flag.dot = ft_strlen(hex_str);
	if (flag.dot >= 0)
		len += ft_work_width_space(flag.width - flag.dot);
	else
	{
		if (flag.zero == 1)
			len += ft_work_width_zero(flag.width - ft_strlen(hex_str));
		else
			len += ft_work_width_space(flag.width - ft_strlen(hex_str));
	}
	if (flag.minus == 0)
		len += ft_write_hex(flag, hex_str);
	return (len);
}

int				ft_work_hex(unsigned int num, t_flag flag, int bigorsmall)
{
	int			len;
	char		*hex_str;

	len = 0;
	//num = (unsigned int)(4294967296 + num);
	if (flag.dot == 0 && num == 0)
		return (ft_work_width_space(flag.width));
	if (!(hex_str = ft_itoa_hex(num)))
		return (-1);
	if (bigorsmall == 1)
		hex_str = ft_toupper_str(hex_str);
	len += ft_work_flag_hex(hex_str, flag);
	free(hex_str);
	return (len);
}
