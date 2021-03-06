/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:34 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/04 19:20:33 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len_unsigned(unsigned int num)
{
	int			len;

	len = 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char		*ft_itoa_unsigned(unsigned int num)
{
	char		*num_str;
	int			i;

	if (num == 0)
		return (ft_strdup("0"));
	i = ft_len_unsigned(num);
	if (!(num_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num_str[i] = '\0';
	i--;
	while (num > 0)
	{
		num_str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (num_str);
}

static int		ft_work_flag_unsigned(char *unsig_str, t_flag flag)
{
	int			len;

	len = 0;
	if (flag.minus == 1)
		len += ft_write_int(flag, unsig_str);
	if (flag.dot >= 0 && (size_t)flag.dot < ft_strlen(unsig_str))
		flag.dot = ft_strlen(unsig_str);
	if (flag.dot >= 0)
		len += ft_work_width_space(flag.width - flag.dot);
	else
	{
		if (flag.zero == 1)
			len += ft_work_width_zero(flag.width - ft_strlen(unsig_str));
		else
			len += ft_work_width_space(flag.width - ft_strlen(unsig_str));
	}
	if (flag.minus == 0)
		len += ft_write_int(flag, unsig_str);
	return (len);
}

int				ft_work_unsigned(t_flag flag, unsigned int num)
{
	int			len;
	char		*unsig_str;

	len = 0;
	if (flag.dot == 0 && num == 0)
		return (ft_work_width_space(flag.width));
	if (!(unsig_str = ft_itoa_unsigned(num)))
		return (-1);
	len = ft_work_flag_unsigned(unsig_str, flag);
	free(unsig_str);
	return (len);
}
