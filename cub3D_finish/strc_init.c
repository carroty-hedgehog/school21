/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strc_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:21:24 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:21:24 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	strc_init(t_data *strc)
{
	strc->img = NULL;
	strc->adr = NULL;
	strc->bpp = 0;
	strc->len = 0;
	strc->end = 0;
	strc->w = 0;
	strc->h = 0;
}

void	strc_init_m(t_map *map, int count)
{
	map->pointer = 0;
	map->ray = 0;
	map->m = 64;
	map->man_x = 0;
	map->man_y = 0;
	map->count_line = count;
	map->count_map = 0;
	map->max_line = 0;
	map->spt_count = 0;
	map->spt_count_1 = 0;
}

void	arr_init(int *arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		arr[i++] = 0;
}

void	strc_init_p2(t_param *param, int count)
{
	param->er = NULL;
	param->mlx = NULL;
	param->win = NULL;
	param->no = NULL;
	param->so = NULL;
	param->we = NULL;
	param->ea = NULL;
	param->s = NULL;
	arr_init(param->r, 2);
	arr_init(param->f, 3);
	arr_init(param->c, 3);
	arr_init(param->flag, 10);
	strc_init(param->img);
	strc_init(param->img2);
	strc_init(param->tex_w);
	strc_init(param->tex_s);
	strc_init(param->tex_e);
	strc_init(param->tex_so);
	strc_init(param->tex_n);
	strc_init_m(param->map, count);
}

void	strc_init_p(t_param *param, int count)
{
	if (!(param->map = malloc(sizeof(t_map))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->img = malloc(sizeof(t_data))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->img2 = malloc(sizeof(t_data))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->tex_w = malloc(sizeof(t_data))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->tex_s = malloc(sizeof(t_data))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->tex_e = malloc(sizeof(t_data))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->tex_so = malloc(sizeof(t_data))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->tex_n = malloc(sizeof(t_data))))
		param->er = "Error!\nbad malloc\n";
	if (!(param->map1 = (char **)malloc((count + 1) * sizeof(char *))))
		param->er = "Error!\nbad malloc\n";
	strc_init_p2(param, count);
}
