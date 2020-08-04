/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 20:10:43 by tredtusk          #+#    #+#             */
/*   Updated: 2020/08/04 14:39:02 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flag		ft_flag_begin(void)
{
	t_flag			flag;

	flag.dot = -1;
	flag.minus = 0;
	flag.type = 0;
	flag.width = 0;
	flag.zero = 0;
	flag.err = 0;
	flag.neg = 1;
	return (flag);
}

static int			ft_check_type_list(const char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

static int			ft_check_flag_list(const char c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*'));
}

static int			ft_flag_parser(const char *save,
					int i, va_list point, t_flag *flag)
{
	while (save[i])
	{
		if ((!ft_isdigit(save[i])) &&
		(!ft_check_type_list(save[i])) && (!ft_check_flag_list(save[i])))
			break ;
		if (save[i] == '0' && flag->width == 0 && flag->minus == 0)
			flag->zero = 1;
		if (save[i] == '.')
			i = ft_flag_dot(save, point, flag, i);
		if (save[i] == '-')
			*flag = ft_flag_minus(*flag);
		if (save[i] == '*')
			*flag = ft_flag_width(point, *flag);
		if (ft_isdigit(save[i]))
			*flag = ft_flag_digit(save, *flag, &i);
		if (ft_check_type_list(save[i]))
		{
			flag->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int					ft_distribution(va_list point,
					const char *save, int i, int len)
{
	t_flag			flag;

	while (save[++i])
	{
		flag = ft_flag_begin();
		if (save[i] == '%' && save[i + 1] != '\0')
		{
			i = ft_flag_parser(save, ++i, point, &flag);
			if (flag.type != 0)
			{
				flag.err = ft_line_work(point, flag, flag.type);
				if (flag.err == -1)
					return (-1);
				len += flag.err;
			}
			else if (save[i])
				len += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			len += ft_putchar(save[i]);
	}
	return (len);
}
