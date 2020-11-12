/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:21:30 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:21:30 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		get_pix_col(t_data *img, int x, int y, char tex)
{
	char	*dst;

	if (tex == 'N' || tex == 'E')
	{
		dst = img->adr + (y * img->len + x * (img->bpp / 8));
		return (*(int*)dst);
	}
	if (tex == 'S' || tex == 'W')
	{
		dst = img->adr + ((y + 1) * img->len - (x + 1) * (img->bpp / 8));
		return (*(int*)dst);
	}
	return (0);
}

int		get_next_line(char **line, int fd)
{
	char	buffer[2];

	buffer[1] = '\0';
	*line = malloc(1);
	*line[0] = '\0';
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n')
			return (1);
		*line = ft_strjoin(*line, buffer);
	}
	return (0);
}

int		check_xpm(t_param *prm)
{
	prm->win = mlx_new_window(prm->mlx, prm->r[0], prm->r[1], "cub3d");
	prm->img->img = mlx_new_image(prm->mlx, prm->r[0], prm->r[1]);
	prm->img2->img = mlx_new_image(prm->mlx, prm->r[0], prm->r[1]);
	prm->tex_s->img = mlx_xpm_file_to_image(prm->mlx,
			prm->s, &prm->tex_s->w, &prm->tex_s->h);
	prm->tex_e->img = mlx_xpm_file_to_image(prm->mlx,
			prm->ea, &prm->tex_e->w, &prm->tex_e->h);
	prm->tex_so->img = mlx_xpm_file_to_image(prm->mlx,
			prm->so, &prm->tex_so->w, &prm->tex_so->h);
	prm->tex_w->img = mlx_xpm_file_to_image(prm->mlx,
			prm->we, &prm->tex_w->w, &prm->tex_w->h);
	prm->tex_n->img = mlx_xpm_file_to_image(prm->mlx,
			prm->no, &prm->tex_n->w, &prm->tex_n->h);
	if (!prm->win || !prm->img->img || !prm->img2->img || !prm->tex_s->img ||
	!prm->tex_e->img || !prm->tex_so->img ||
	!prm->tex_w->img || !prm->tex_n->img)
		prm->er = "Error!\nbad texture link\n";
	if (((int)prm->tex_e->w % 64) || ((int)prm->tex_w->w % 64) ||
	((int)prm->tex_s->w % 64) || ((int)prm->tex_so->w % 64) ||
	((int)prm->tex_n->w % 64))
		prm->er = "Error!\nIncompatible texture resolution\n";
	return (0);
}

int		check_addr(t_param *prm)
{
	prm->img->adr = mlx_get_data_addr(prm->img->img,
		&prm->img->bpp, &prm->img->len, &prm->img->end);
	prm->img2->adr = mlx_get_data_addr(prm->img2->img,
		&prm->img2->bpp, &prm->img2->len, &prm->img2->end);
	prm->tex_s->adr = mlx_get_data_addr(prm->tex_s->img,
		&prm->tex_s->bpp, &prm->tex_s->len, &prm->tex_s->end);
	prm->tex_e->adr = mlx_get_data_addr(prm->tex_e->img,
		&prm->tex_e->bpp, &prm->tex_e->len, &prm->tex_e->end);
	prm->tex_so->adr = mlx_get_data_addr(prm->tex_so->img,
		&prm->tex_so->bpp, &prm->tex_so->len, &prm->tex_so->end);
	prm->tex_w->adr = mlx_get_data_addr(prm->tex_w->img,
		&prm->tex_w->bpp, &prm->tex_w->len, &prm->tex_w->end);
	prm->tex_n->adr = mlx_get_data_addr(prm->tex_n->img,
		&prm->tex_n->bpp, &prm->tex_n->len, &prm->tex_n->end);
	if (!prm->img->adr || !prm->img2->adr || !prm->tex_s->adr ||
	!prm->tex_e->adr || !prm->tex_so->adr ||
	!prm->tex_w->adr || !prm->tex_n->adr)
		prm->er = "Error!\nbad adres\n";
	return (0);
}
