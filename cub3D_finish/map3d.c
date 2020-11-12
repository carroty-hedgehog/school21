/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:20:41 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:20:42 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void		make_wall2(t_param *prm, t_pos *pos, double h, double hgt_wall)
{
	double	start;

	start = (double)(prm->r[1]) / 2 - (prm->r[1] / pos->i * 64) / 2;
	if (pos->x > prm->map->man_x)
		my_mpp(prm->img2, pos->x2, (int)h, (int)(get_pix_col(prm->tex_e,
		(int)pos->y * (prm->tex_e->w / 64) % prm->tex_e->h,
		(int)((h - start) * ((double)prm->tex_e->h / hgt_wall)), 'E')));
	else
		my_mpp(prm->img2, pos->x2, (int)h, (int)(get_pix_col(prm->tex_w,
		(int)pos->y * (prm->tex_w->w / 64) % prm->tex_w->h,
		(int)((h - start) * ((double)prm->tex_w->h / hgt_wall)), 'W')));
}

void		make_wall1(t_param *prm, t_pos *pos, double h, double hgt_wall)
{
	double	start;

	start = (double)(prm->r[1]) / 2 - (prm->r[1] / pos->i * 64) / 2;
	if (ft_strchr(WALL_IN_MAP, prm->map1[(int)pos->y / 64][(int)(pos->x
	- 0.25 * cos(prm->map->ray)) / 64]) || prm->map1[(int)pos->y /
	64][(int)(pos->x - 0.25 * cos(prm->map->ray)) / 64] == '\0')
	{
		if (pos->y > prm->map->man_y)
			my_mpp(prm->img2, pos->x2, (int)h, (int)(get_pix_col(prm->tex_so,
			(int)pos->x * (prm->tex_so->w / 64) % prm->tex_so->w,
			(int)((h - start) * ((double)prm->tex_so->h / hgt_wall)), 'S')));
		else
			my_mpp(prm->img2, pos->x2, (int)h, (int)(get_pix_col(prm->tex_n,
			(int)pos->x * (prm->tex_n->w / 64) % prm->tex_n->w,
			(int)((h - start) * ((double)prm->tex_n->h / hgt_wall)), 'N')));
	}
	else
		make_wall2(prm, pos, h, hgt_wall);
}

void		make_wall(t_param *prm, t_pos *pos)
{
	double	q;
	double	h;
	double	hgt_wall;
	double	start;
	int		y2;

	pos->i *= cos(prm->map->pointer - prm->map->ray);
	q = (double)(prm->r[1]) / 2 + (prm->r[1] / pos->i * 64) / 2;
	h = (double)(prm->r[1]) / 2 - (prm->r[1] / pos->i * 64) / 2;
	hgt_wall = q - h;
	start = h;
	y2 = 0;
	while (h >= 0 && h < (prm->r[1] - 1) && y2 >= 0)
		my_mpp(prm->img2, pos->x2, (int)h--,
		create_trgb(0, prm->c[0], prm->c[1], prm->c[2]));
	h = start;
	while (h < q && h < prm->r[1])
	{
		if (h >= 0)
			make_wall1(prm, pos, h, hgt_wall);
		h++;
	}
	while (h < prm->r[1])
		my_mpp(prm->img2, pos->x2, (int)h++,
		create_trgb(0, prm->f[0], prm->f[1], prm->f[2]));
}

int			if_wall(t_param *prm, t_pos pos)
{
	if (ft_strchr(WALL_IN_MAP, prm->map1[(int)pos.y / 64][(int)pos.x / 64])
	|| (ft_strchr(WALL_IN_MAP, prm->map1[((int)(pos.y - 1) / 64)][(int)
	(pos.x + 1) / 64]) && ft_strchr(WALL_IN_MAP, prm->map1[((int)(pos.y + 1)
	/ 64)][(int)(pos.x - 1) / 64])) || (ft_strchr(WALL_IN_MAP,
	prm->map1[((int)(pos.y - 1) / 64)][(int)(pos.x - 1) / 64]) &&
	ft_strchr(WALL_IN_MAP, prm->map1[((int)(pos.y + 1)
	/ 64)][(int)(pos.x + 1) / 64])))
		return (1);
	return (0);
}

void		reycasting(t_param *prm)
{
	t_pos	pos;
	double	arr_wall[(prm->r[0])];

	ft_bzero(&pos, sizeof(t_pos));
	prm->map->ray = prm->map->pointer - (M_PI / 6);
	while (pos.x2 < prm->r[0])
	{
		pos.i = 1;
		while (pos.i)
		{
			pos.x = prm->map->man_x + pos.i * cos(prm->map->ray);
			pos.y = prm->map->man_y + pos.i * sin(prm->map->ray);
			if (if_wall(prm, pos))
			{
				make_wall(prm, &pos);
				arr_wall[pos.x2] = pos.i /
						cos(prm->map->pointer - prm->map->ray);
				break ;
			}
			pos.i += 0.2;
		}
		prm->map->ray += ((M_PI / 3) / prm->r[0]);
		pos.x2++;
	}
	make_sprite(prm, arr_wall);
}
