/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:05:15 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/28 18:08:24 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	texture(char *line, char **link, t_param *prm, int num)
{
	int fd;

	line++;
	while ((*line >= 9 && *line <= 13) || *line == 32)
		line++;
	if (!(*link = ft_strdup(line)))
		prm->er = "Error\nbad malloc!\n";
	if ((fd = open(*link, O_RDONLY)) <= 0)
		prm->er = "Error\nbad texture!\n";
	close(fd);
	prm->flag[num] = 1;
}

void	el_line2(char *line, t_param *prm)
{
	if (*line == 'S')
	{
		line++;
		if (*line == 'O' && prm->so == NULL)
			texture(line, &prm->so, prm, 5);
		else if (*line == ' ' && prm->s == NULL)
			texture(line, &prm->s, prm, 6);
		else
			prm->er = "Error\nbad texture!\n";
	}
	else if (*line == 'E')
	{
		line++;
		if (*line == 'A' && prm->ea == NULL)
			texture(line, &prm->ea, prm, 7);
		else
			prm->er = "Error\nbad texture!\n";
	}
}

void	el_line(char *line, t_param *prm)
{
	if (*line == 'N')
	{
		line++;
		if (*line == 'O' && prm->no == NULL)
			texture(line, &prm->no, prm, 3);
		else
			prm->er = "Error\nbad texture!\n";
	}
	else if (*line == 'W')
	{
		line++;
		if (*line == 'E' && prm->we == NULL)
			texture(line, &prm->we, prm, 4);
		else
			prm->er = "Error\nbad texture!\n";
	}
	else if (*line == 'S' || *line == 'E')
		el_line2(line, prm);
}
