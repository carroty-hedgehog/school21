/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:05:22 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:05:29 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymlx.h"

void	err_exit(t_param *prm, char *s)
{
	(void)*prm;
	ft_putendl_fd(s, 1);
	exit(1);
}

void	my_mpp(t_data *img, int x, int y, int col)
{
	char	*dst;

	dst = img->adr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = col;
}

void	cub3d(t_param *prm, char **argv)
{
	int		i;
	t_spt	*spt;

	i = 0;
	pars(prm, argv);
	prm->map->spt_count_1 = prm->map->spt_count;
	!(prm->mlx = mlx_init()) ? exit(1) : 0;
	check_xpm(prm);
	if (prm->er != NULL)
		err_exit(prm, prm->er);
	check_addr(prm);
	if (!(prm->map->spt_arr = malloc(sizeof(void *)
			* (prm->map->spt_count + 1))))
		prm->er = "Error!\nbad malloc\n";
	while (i < prm->map->spt_count && prm->er == NULL)
	{
		if (!(spt = ft_calloc(sizeof(t_spt)
				* prm->map->spt_count, sizeof(t_spt))))
			prm->er = "Error!\nbad malloc\n";
		prm->map->spt_arr[i++] = spt;
	}
	prm->map->spt_arr[i] = NULL;
	position(prm);
	position_spt(prm);
	reycasting(prm);
}

void	check_cub3d(t_param *prm, int argc, char **argv)
{
	char	*line;
	int		fd;
	int		count;

	line = NULL;
	count = 0;
	if (argc < 2 || argc > 3)
		err_exit(prm, "Error!\nbad arguments\n");
	if (ft_strlen(argv[1]) < 4 ||
		(ft_strncmp(&argv[1][(ft_strlen(argv[1]) - 4)], ".cub", 4)) ||
		(argc == 3 && (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))))
		err_exit(prm, "Error!\nbad arguments\n");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit(1);
	while ((get_next_line(&line, fd)) && ++count >= 0)
		free(line);
	free(line);
	close(fd);
	if (count++)
		strc_init_p(prm, count);
	else
		err_exit((t_param *)NULL, "Error!\nbad configs\n");
}

int		main(int argc, char **argv)
{
	t_param	prm;

	check_cub3d(&prm, argc, argv);
	cub3d(&prm, argv);
	if (prm.er != NULL)
		err_exit(&prm, prm.er);
	mlx_put_image_to_window(prm.mlx, prm.win, prm.img2->img, 0, 0);
	if (argc == 3)
		img_to_bmp(&prm);
	mlx_do_sync(prm.mlx);
	prm.img->img = mlx_new_image(prm.mlx, prm.r[0], prm.r[1]);
	prm.img->adr = mlx_get_data_addr(prm.img->img,
						&prm.img->bpp, &prm.img->len, &prm.img->end);
	if (!prm.img->img || !prm.img2->img)
		err_exit(&prm, "Error!\nmlx function not good\n");
	mlx_hook(prm.win, 2, 0L, keyboard, &prm);
	mlx_hook(prm.win, 17, 0L, close_red_x, &prm);
	mlx_loop(prm.mlx);
}
