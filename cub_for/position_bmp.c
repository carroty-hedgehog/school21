/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_bmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:21:09 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:21:09 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int		my_position(t_param *prm, t_pos *pos)
{
	if (prm->map1[(int)pos->y][(int)pos->x] == 'N' ||
		prm->map1[(int)pos->y][(int)pos->x] == 'W' || prm->map1[(int)pos->y]
		[(int)pos->x] == 'E' || prm->map1[(int)pos->y][(int)pos->x] == 'S')
	{
		pos->flag++;
		prm->map->man_x = (pos->x2 + 1) - (double)prm->map->m / 2;
		prm->map->man_y = (pos->y2 + 1) - (double)prm->map->m / 2;
		if (prm->map1[(int)pos->y][(int)pos->x] == 'W')
			prm->map->pointer = M_PI;
		if (prm->map1[(int)pos->y][(int)pos->x] == 'S')
			prm->map->pointer = M_PI_2;
		if (prm->map1[(int)pos->y][(int)pos->x] == 'N')
			prm->map->pointer = 3 * (M_PI_2);
	}
	return (1);
}

void	position(t_param *prm)
{
	t_pos	pos;

	ft_bzero(&pos, sizeof(t_pos));
	while (pos.y < prm->map->count_map)
	{
		pos.j = 0;
		while (pos.j++ < prm->map->m)
		{
			pos.x = -1;
			pos.x2 = 0;
			while (prm->map1[(int)pos.y][(int)++pos.x])
			{
				pos.i = 0;
				while (pos.i++ < prm->map->m)
				{
					my_position(prm, &pos);
					pos.x2++;
				}
			}
			pos.y2++;
		}
		pos.y++;
	}
	if (pos.flag != (prm->map->m * prm->map->m))
		prm->er = "Error\n Bad player position!\n";
}

void	position_spt(t_param *prm)
{
	int	x;
	int	y;
	int	spt;

	y = 0;
	spt = 0;
	while (y < prm->map->count_map)
	{
		x = 0;
		while (x < prm->map->max_line)
		{
			if (prm->map1[y][x] && prm->map1[y][x] == '2'
			&& spt < prm->map->spt_count)
			{
				((t_spt *)prm->map->spt_arr[spt])->y = y * 64 + prm->map->m / 2;
				((t_spt *)prm->map->spt_arr[spt])->x = x * 64 + prm->map->m / 2;
				spt++;
			}
			x++;
		}
		y++;
	}
}

void	img_to_bmp2(t_param *prm, char **bmp)
{
	unsigned int	size;

	size = prm->r[0] * prm->r[1];
	ft_bzero(*bmp, sizeof(int) * size + 54);
	ft_memcpy(*bmp, "BM", 2);
	size = sizeof(int) * prm->r[0] * prm->r[1] + 54;
	ft_memcpy(*bmp + 2, &size, 4);
	size = 54;
	ft_memcpy(*bmp + 10, &size, 4);
	size = 40;
	ft_memcpy(*bmp + 14, &size, 4);
	ft_memcpy(*bmp + 18, &prm->r[0], 4);
	size = -prm->r[1];
	ft_memcpy(*bmp + 22, &size, 4);
	size = 1;
	ft_memcpy(*bmp + 26, &size, 2);
	ft_memcpy(*bmp + 28, (short*)&prm->img2->bpp, 2);
	size = prm->r[0] * prm->r[1];
	ft_memcpy(*bmp + 34, &size, 4);
}

void	img_to_bmp(t_param *prm)
{
	char	*bmp;
	char	*scrn;
	int		fd;
	int		y;

	y = 0;
	bmp = (char *)malloc(sizeof(int) * (prm->r[0] * prm->r[1] + 54));
	img_to_bmp2(prm, &bmp);
	scrn = bmp + 54;
	while (y < prm->r[1])
	{
		ft_memcpy(scrn, prm->img2->adr, prm->r[0] * sizeof(int));
		prm->img2->adr += prm->img2->len;
		scrn += (prm->r[0] * sizeof(int));
		y++;
	}
	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	write(fd, bmp, sizeof(int) * (prm->r[0] * prm->r[1]) + 54);
	close(fd);
	free(bmp);
	bmp = NULL;
	exit(0);
}
