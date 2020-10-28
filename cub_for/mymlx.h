/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:04:32 by tredtusk          #+#    #+#             */
/*   Updated: 2020/10/27 19:20:49 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMLX_H
# define MYMLX_H
# define TYPES "RNSWEFC"
# define MAP_SIM "SWEN 102"
# define SIM_IN_MAP "SWEN02"
# define WALL_IN_MAP " 1"

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef	struct	s_pos
{
	double		x;
	double		y;
	int			x2;
	int			y2;
	double		j;
	double		i;
	int			flag;
}				t_pos;

typedef struct	s_data
{
	void		*img;
	char		*adr;
	int			bpp;
	int			len;
	int			end;
	int			w;
	int			h;
}				t_data;

typedef	struct	s_spt
{
	int			x;
	int			y;
	double		dist;
}				t_spt;

typedef struct	s_map
{
	double		pointer;
	double		ray;
	int			m;
	double		man_x;
	double		man_y;
	int			count_line;
	int			count_map;
	int			max_line;
	int			spt_count;
	int			spt_count_1;
	double		spt_ang;
	void		**spt_arr;
}				t_map;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	char		**map1;
	char		*er;
	int			r[2];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f[3];
	int			c[3];
	int			flag[9];
	int			white_lines;
	t_map		*map;
	t_data		*img;
	t_data		*img2;
	t_data		*tex_w;
	t_data		*tex_s;
	t_data		*tex_e;
	t_data		*tex_so;
	t_data		*tex_n;
}				t_param;

int				get_next_line(char **line, int fd);
void			pars(t_param *param, char **rgv);
void			strc_init(t_data *strc);
void			strc_init_m(t_map *map, int count);
void			strc_init_p(t_param *param, int count);
int				close_red_x(t_param *param);
int				keyboard(int keycode, t_param *param);
void			reycasting(t_param *param);
void			my_mpp(t_data *img, int x, int y, int col);
int				create_trgb(int t, int r, int g, int b);
void			make_sprite(t_param *prm, double *arr_spt);
void			drow_spt(t_param *prm, int spt, double const *arr);
void			drow_spt1(t_param *prm, double const *arr,
				t_pos itr, double dist);
void			sort_spt(t_param *prm);
void			get_dist(t_param *prm);
void			make_wall(t_param *prm, t_pos *pos);
int				get_pix_col(t_data *img, int x, int y, char tex);
void			ft_step(t_param *prm, int step, double ang, int keycode);
int				check_addr(t_param *prm);
int				check_xpm(t_param *prm);
void			el_resolution(char *line, t_param *prm, int *el, int num);
void			check_resol(t_param *prm, int *el, int i);
int				check_atoi(t_param *prm, char *line, int i);
void			el_col(char *line, t_param *prm, int *el, int num);
int				check_col(t_param *prm, char *line, int *el, int i);
void			el_line(char *line, t_param *prm);
void			el_line2(char *line, t_param *prm);
void			texture(char *line, char **link, t_param *prm, int num);
void			check_map(t_param *prm);
void			check_first_last_lines(t_param *prm);
void			err_exit(t_param *prm, char *s);
void			play_win(t_param *prm);
int				my_position(t_param *prm, t_pos *pos);
void			position(t_param *prm);
void			position_spt(t_param *prm);
void			img_to_bmp(t_param *prm);

#endif
