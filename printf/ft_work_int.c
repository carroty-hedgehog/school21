/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:26 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/03 20:11:05 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_work_width_zero(int width)
{
	int len;

	len = -1;
	while (++len < width)
		ft_putchar('0');
	return (len);
}

static int		ft_work_width_int(t_flag *flag, char *num_str)
{
	int			len;

	len = 0;
	if (flag->dot >= 0 && (size_t)flag->dot < ft_strlen(num_str))
		flag->dot = ft_strlen(num_str);
	if (flag->dot >= 0)
		len += ft_work_width_space(flag->width - flag->dot);
	else
	{
		if (flag->zero == 0)
			len += ft_work_width_space(flag->width - ft_strlen(num_str));
		else
			len += ft_work_width_zero(flag->width - ft_strlen(num_str));
	}
	return (len);
}

static int		ft_work_flag_int(t_flag flag, long long num_save, long long num)
{
	int			len;
	char		*num_str;

	if (!(num_str = ft_itoa(num)))
		return (-1);
	if (flag.zero == 1 && flag.dot < 0 && num > 0 && flag.neg == -1)
		ft_putchar('-');
	len = 0;
	if (flag.minus == 1)
	{
		if (num_save < 0 && flag.dot >= 0)
			ft_putchar('-');
		len += ft_write_int(flag, num_str);
	}
	len += ft_work_width_int(&flag, num_str);
	if (flag.minus == 0)
	{
		if (num_save < 0 && flag.dot >= 0)
			ft_putchar('-');
		len += ft_write_int(flag, num_str);
	}
	free(num_str);
	return (len);
}

static int		ft_work_neg(long long *num, t_flag *flag)
{
	int			len;

	len = 0;
	if (*num < 0 && (flag->dot >= 0 || flag->zero == 1))
	{
		*num = *num * -1;
		flag->zero = 1;
		flag->neg = -1;
		len++;
		flag->width = flag->width - 1;
	}
	return (len);
}

int				ft_work_int(t_flag flag, long long num)
{
	int			len;
	long long	save_num;

	save_num = num;
	len = 0;
	if (flag.dot == 0 && num == 0)
		return (ft_work_width_space(flag.width));
	len += ft_work_neg(&num, &flag);
	flag.err = ft_work_flag_int(flag, save_num, num);
	if (flag.err == -1)
		return (-1);
	len += flag.err;
	return (len);
}
