/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:04:59 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:05:00 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	check_last_lines(t_param *prm)
{
	int	i;
	int	j;

	i = prm->map->count_map - 1;
	j = 0;
	while (prm->map1[i][j] &&
			(prm->map1[i][j] == '1' || prm->map1[i][j] == ' '))
		j++;
	if (prm->map1[i][j])
		prm->er = "Error\n bad map!\n";
	while (prm->map1[i - 1][j])
	{
		if ((prm->map1[i - 1][j] != '1' && prm->map1[i - 1][j] != ' '))
			prm->er = "Error\n bad map!\n";
		j++;
	}
}

void	check_first_last_lines(t_param *prm)
{
	int	j;

	j = 0;
	if (prm->map->count_map < 3)
		prm->er = "Error\n bad map!\n";
	while (prm->map1[0][j] &&
			(prm->map1[0][j] == '1' || prm->map1[0][j] == ' '))
		j++;
	if (prm->map1[0][j])
		prm->er = "Error\n bad map!\n";
	while (prm->map1[1][j])
	{
		if ((prm->map1[1][j] != '1' && prm->map1[1][j] != ' '))
			prm->er = "Error\n bad map!\n";
		j++;
	}
	check_last_lines(prm);
}

void	check_map(t_param *prm)
{
	int	i;
	int	j;

	i = 0;
	check_first_last_lines(prm);
	while (++i < prm->map->count_map - 1)
	{
		j = 0;
		if (prm->map1[i][j] == '1' || prm->map1[i][j] == ' ')
		{
			while (prm->map1[i][j])
			{
				if (ft_strchr(SIM_IN_MAP, prm->map1[i][j]))
				{
					if (!prm->map1[i - 1][j] || !prm->map1[i + 1][j])
						prm->er = "Error\n bad map!\n";
				}
				j++;
			}
			if (prm->map1[i][--j] != '1' && prm->map1[i][j] != ' ')
				prm->er = "Error\n bad map!\n";
		}
		else
			prm->er = "Error\n bad map!\n";
	}
}
