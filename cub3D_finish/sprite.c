/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:21:17 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:21:17 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	get_dist(t_param *prm)
{
	int	i;

	i = -1;
	while (prm->map->spt_arr[++i])
	{
		((t_spt *)prm->map->spt_arr[i])->dist = sqrt(pow(prm->map->man_x -
			((t_spt *)prm->map->spt_arr[i])->x, 2) + pow(prm->map->man_y -
			((t_spt *)prm->map->spt_arr[i])->y, 2));
	}
}

void	sort_spt(t_param *prm)
{
	t_spt	*tmp;
	int		i;
	int		j;

	j = 1;
	tmp = NULL;
	while (j < prm->map->spt_count - 1)
	{
		i = 0;
		while (i < prm->map->spt_count - 1)
		{
			if (((t_spt *)prm->map->spt_arr[i])->dist <
					((t_spt *)prm->map->spt_arr[i + 1])->dist)
			{
				tmp = prm->map->spt_arr[i];
				prm->map->spt_arr[i] = prm->map->spt_arr[i + 1];
				prm->map->spt_arr[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

void	drow_spt1(t_param *prm, double const *arr, t_pos i, double dist)
{
	int	scale;
	int	col;

	i.i = -1;
	scale = (int)((double)prm->r[1] / dist * 64);
	i.x2 = (int)(prm->map->spt_ang * (((double)prm->r[0]) / (M_PI / 3))
			+ (double)prm->r[0] / 2 - (double)scale / 2);
	i.y2 = prm->r[1] / 2 - (int)scale / 2;
	while (++i.i < scale && dist > 10)
	{
		if (i.x2 + (int)(i.i) < 0 || i.x2 + i.i >= prm->r[0])
			continue ;
		i.j = -1;
		while (++i.j < scale)
		{
			if (i.y2 + (int)(i.j) < 0 || i.y2 + i.j >= prm->r[1])
				continue ;
			i.x = (int)(i.i * ((double)prm->tex_s->w / (double)scale));
			i.y = (int)(i.j * ((double)prm->tex_s->h / (double)scale));
			col = *(int *)(prm->tex_s->adr + ((int)i.y *
					prm->tex_s->len + (int)i.x * (prm->tex_s->bpp / 8)));
			if (col >= 0 && arr[(int)(i.x2 + i.i)] >= dist)
				my_mpp(prm->img2, (int)(i.x2 + i.i), (int)(i.y2 + i.j), col);
		}
	}
}

void	drow_spt(t_param *prm, int spt, double const *arr)
{
	double	dist;
	t_pos	itr;

	ft_bzero(&itr, sizeof(t_pos));
	dist = ((t_spt *)prm->map->spt_arr[spt])->dist;
	prm->map->spt_ang = atan2(((t_spt *)prm->map->spt_arr[spt])->y -
	prm->map->man_y, ((t_spt *)prm->map->spt_arr[spt])->x
	- prm->map->man_x) - prm->map->pointer;
	while (prm->map->spt_ang > 2 * M_PI)
		prm->map->spt_ang -= 2 * M_PI;
	while (prm->map->spt_ang < 0)
		prm->map->spt_ang += 2 * M_PI;
	while (prm->map->spt_ang < (-1) * M_PI)
		prm->map->spt_ang += 2 * M_PI;
	while (prm->map->spt_ang > M_PI)
		prm->map->spt_ang -= 2 * M_PI;
	drow_spt1(prm, arr, itr, dist);
}

void	make_sprite(t_param *prm, double *arr_spt)
{
	int	i;

	i = 0;
	get_dist(prm);
	sort_spt(prm);
	while (prm->map->spt_arr[i])
	{
		if (((t_spt *)prm->map->spt_arr[i])->dist < 25)
		{
			free(prm->map->spt_arr[i]);
			ft_bzero(&prm->map->spt_arr[i], sizeof(t_spt *));
			prm->map->spt_count -= 1;
			continue ;
		}
		drow_spt(prm, i, arr_spt);
		i++;
	}
}
