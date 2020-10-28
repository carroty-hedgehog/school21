/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:04:45 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:04:46 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int		check_col(t_param *prm, char *line, int *el, int i)
{
	while (*line != '\0' && (*line == ' ' || ft_isdigit(*line)))
	{
		while (*line == ' ')
			line++;
		if (*line && ft_isdigit(*line))
			el[i++] = check_atoi(prm, line, 0);
		while (ft_isdigit(*line))
			line++;
		while ((*line >= 9 && *line <= 13) || *line == 32)
			line++;
		if (*line != ',' && i < 3)
			prm->er = "Error\nbad Color!\n";
		if (*line == ',' && i < 3)
			line++;
	}
	if (*line)
		prm->er = "Error\nbad Color!\n";
	return (i);
}

void	el_col(char *line, t_param *prm, int *el, int num)
{
	int	i;

	i = 0;
	line++;
	i = check_col(prm, line, el, i);
	if (prm->flag[num] == 1)
		prm->er = "Error\nbad Color!\n";
	if (i != 3)
		prm->er = "Error\nbad Color!\n";
	i = 0;
	while (i < 3)
	{
		if (el[i] > 255 || el[i] < 0)
			prm->er = "Error\nbad Color!\n";
		i++;
	}
	prm->flag[num] = 1;
}

int		check_atoi(t_param *prm, char *line, int i)
{
	int	num;
	int	dig_count;

	dig_count = 0;
	num = 0;
	if (*line == '-' && i == 1)
		prm->er = "Error\nbad Resolution!\n";
	while (*line == '0')
		line++;
	num = ft_atoi(line);
	while (ft_isdigit(*line))
	{
		line++;
		dig_count++;
	}
	if (dig_count > 8)
		num = 2147483647;
	return (num);
}

void	check_resol(t_param *prm, int *el, int i)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	if (i != 2)
		prm->er = "Error\nbad Resolution!\n";
	mlx_get_screen_size(prm->mlx, &sizex, &sizey);
	if (el[0] > sizex)
		el[0] = sizex;
	if (el[1] > sizey)
		el[1] = sizey;
}

void	el_resolution(char *line, t_param *prm, int *el, int num)
{
	int	i;

	i = 0;
	line++;
	while (*line)
	{
		while (*line == ' ')
			line++;
		if (*line)
			el[i] = check_atoi(prm, line, 1);
		if (el[i++] <= 0)
			prm->er = "Error\nbad Resolution!\n";
		if (!ft_isdigit(*line))
			break ;
		while (ft_isdigit(*line))
			line++;
	}
	check_resol(prm, el, i);
	prm->flag[num] = 1;
}
