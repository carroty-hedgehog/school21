/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:21:01 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:21:01 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	elements(char *line, t_param *prm)
{
	if (*line)
	{
		while ((*line >= 9 && *line <= 13) || *line == 32)
			line++;
		if (!ft_strchr(TYPES, *line) && (prm->flag[0] == 0
			|| prm->flag[1] == 0 || prm->flag[2] == 0))
			prm->er = "Error!\nbad configs\n";
		if (*line == 'C')
			el_col(line, prm, prm->c, 0);
		if (*line == 'F')
			el_col(line, prm, prm->f, 1);
		if (*line == 'R')
			el_resolution(line, prm, prm->r, 2);
		if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
			el_line(line, prm);
	}
}

void	pars3(t_param *prm, int fd, char *line)
{
	if (line)
	{
		if (*line == '\0')
		{
			prm->white_lines++;
			free(line);
			line = NULL;
			while ((get_next_line(&line, fd)) && *line == '\0')
			{
				prm->white_lines++;
				free(line);
				line = NULL;
			}
			if (*line != '\0')
				prm->er = "Error!\nto many lines\n";
			free(line);
			line = NULL;
		}
		else
		{
			free(line);
			line = NULL;
		}
	}
}

int		pars2(t_param *prm, char *line, int i, int *flag_break)
{
	if (prm->flag[0] == 1 && prm->flag[1] == 1 && prm->flag[2] == 1 &&
		prm->flag[3] == 1 && prm->flag[4] == 1 && prm->flag[5] == 1
		&& prm->flag[6] == 1 && prm->flag[7] == 1)
	{
		if (*line == '\0')
			*flag_break = 1;
		prm->flag[8] = 1;
		if ((int)(ft_strlen(line)) > prm->map->max_line)
			prm->map->max_line = ft_strlen(line);
		if (!(prm->map1[i] = ft_strdup(line)))
			prm->er = "Error!\nbad malloc\n";
		while (*line)
		{
			if (*line == '2')
				prm->map->spt_count++;
			if (ft_strchr(MAP_SIM, *line++) == NULL)
				prm->er = "Error!\nbad configs\n";
		}
		if (*flag_break == 0)
			i++;
	}
	return (i);
}

int		pars1(t_param *prm, int fd, int j, char *tmp)
{
	int		i;
	int		flag_break;
	char	*line;

	i = 0;
	line = NULL;
	flag_break = 0;
	while (j++ < (prm->map->count_line) && prm->er == NULL)
	{
		while ((get_next_line(&line, fd)) && *line == '\0' && prm->flag[8] == 0)
		{
			prm->white_lines++;
			free(line);
			line = NULL;
		}
		tmp = line;
		i = pars2(prm, line, i, &flag_break);
		if (flag_break == 1)
			break ;
		elements(line, prm);
		free(tmp);
		line = NULL;
	}
	pars3(prm, fd, line);
	return (i);
}

void	pars(t_param *prm, char **rgv)
{
	int		fd;
	int		i;
	int		j;
	char	*tmp;

	tmp = NULL;
	j = 1;
	fd = open(rgv[1], O_RDONLY);
	i = pars1(prm, fd, j, tmp);
	close(fd);
	if (i == 0 && prm->er == NULL)
		prm->er = "Error!\nbad configs0\n";
	if (prm->er != NULL)
		err_exit(prm, prm->er);
	prm->map1[i] = NULL;
	prm->map->count_map = i;
	if ((prm->flag[0] == 0 || prm->flag[1] == 0 || prm->flag[2] == 0 ||
	prm->flag[3] == 0 || prm->flag[4] == 0 || prm->flag[5] == 0 || prm->flag[6]
	== 0 || prm->flag[7] == 0 || prm->flag[8] == 0) && prm->er == NULL)
		prm->er = "Error!\nbad configs1\n";
	check_map(prm);
	if (prm->er != NULL)
		err_exit(prm, prm->er);
}
