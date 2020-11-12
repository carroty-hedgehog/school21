/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:20:19 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/28 18:09:44 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	ft_step2(t_param *prm, int step, double ang)
{
	double	x;
	double	y;

	prm->map->man_y = prm->map->man_y + (step * sin(ang));
	x = prm->map->man_x / prm->map->m;
	y = prm->map->man_y / prm->map->m;
	if (prm->map1[(int)y][(int)x] == '1' ||
	prm->map1[(int)y][(int)x] == '\0' || prm->map1[(int)y][(int)x] == ' ')
		prm->map->man_y = prm->map->man_y - (step * sin(ang));
	prm->map->man_x = prm->map->man_x + (step * cos(ang));
	x = prm->map->man_x / prm->map->m;
	y = prm->map->man_y / prm->map->m;
	if (prm->map1[(int)y][(int)x] == '1' ||
	prm->map1[(int)y][(int)x] == '\0' || prm->map1[(int)y][(int)x] == ' ')
		prm->map->man_x = prm->map->man_x - (step * cos(ang));
}

void	ft_step(t_param *prm, int step, double ang, int keycode)
{
	double	x;
	double	y;

	if (keycode == 0 || keycode == 1)
	{
		prm->map->man_y = prm->map->man_y - (step * sin(ang));
		x = prm->map->man_x / prm->map->m;
		y = prm->map->man_y / prm->map->m;
		if (prm->map1[(int)y][(int)x] == '1' ||
		prm->map1[(int)y][(int)x] == '\0' || prm->map1[(int)y][(int)x] == ' ')
			prm->map->man_y = prm->map->man_y + (step * sin(ang));
		prm->map->man_x = prm->map->man_x - (step * cos(ang));
		x = prm->map->man_x / prm->map->m;
		y = prm->map->man_y / prm->map->m;
		if (prm->map1[(int)y][(int)x] == '1' ||
		prm->map1[(int)y][(int)x] == '\0' || prm->map1[(int)y][(int)x] == ' ')
			prm->map->man_x = prm->map->man_x + (step * cos(ang));
	}
	if (keycode == 2 || keycode == 13)
		ft_step2(prm, step, ang);
}

int		keyboard(int keycode, t_param *prm)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		prm->map->pointer = prm->map->pointer - 0.1;
	if (keycode == 124)
		prm->map->pointer = prm->map->pointer + 0.1;
	if (keycode == 0)
		ft_step(prm, 25, (prm->map->pointer + M_PI_2), 0);
	if (keycode == 1)
		ft_step(prm, 25, prm->map->pointer, 1);
	if (keycode == 2)
		ft_step(prm, 25, (prm->map->pointer + M_PI_2), 2);
	if (keycode == 13)
		ft_step(prm, 25, prm->map->pointer, 13);
	reycasting(prm);
	mlx_put_image_to_window(prm->mlx, prm->win, prm->img2->img, 0, 0);
	play_win(prm);
	mlx_do_sync(prm->mlx);
	return (0);
}

int		close_red_x(t_param *prm)
{
	(void)*prm;
	exit(0);
}

void	play_win(t_param *prm)
{
	char	*spt;
	char	*tmp;

	mlx_string_put(prm->mlx, prm->win, (int)(0.05 * prm->r[0]),
				(int)(0.05 * prm->r[1]), 0x00, "***************************");
	mlx_string_put(prm->mlx, prm->win, (int)(0.05 * prm->r[0]),
				(int)(0.1 * prm->r[1]), 0x00, "    WELCOME TO PLAY  ");
	if (prm->map->spt_count_1 == 0)
		spt = ft_strdup("WHERE ARE ALL BARRELS?:(");
	else if (prm->map->spt_count_1 != 0 && prm->map->spt_count == 0)
		spt = ft_strdup("      GOOD JOB!  ");
	else
	{
		spt = ft_strdup("   FIND ALL BARRELS - ");
		tmp = ft_itoa((prm->map->spt_count_1 - prm->map->spt_count));
		spt = ft_strjoin(spt, tmp);
		free(tmp);
		tmp = NULL;
	}
	mlx_string_put(prm->mlx, prm->win, (int)(0.05 * prm->r[0]),
				(int)(0.15 * prm->r[1]), 0x00, spt);
	mlx_string_put(prm->mlx, prm->win, (int)(0.05 * prm->r[0]),
				(int)(0.2 * prm->r[1]), 0x00, "***************************");
	free(spt);
	spt = NULL;
}
