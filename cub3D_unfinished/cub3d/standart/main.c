#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "liba/libft.h"
#include "minilibx_mms/mlx.h"
#include "cub3d.h"

char	**make_map(t_list **head, int size)
{
	t_all	all;
	int 	i;
	t_list	*tmp;
	
	if (!(all.map.map = ft_calloc(size + 1, sizeof(char *))))
		return (0);
	tmp = *head;
	i = -1;
	while (tmp)
	{
		all.map.map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (all.map.map);
}

char	**read_map(char *name, t_all all)
{
	t_list	*head;
	
	all.fd = open(name, O_RDONLY);
	all.line = 0;
	head = 0;

	while (get_next_line(all.fd, &all.line) == 1)
	{
		ft_lstadd_back(&head, ft_lstnew(all.line));
	}
	ft_lstadd_back(&head, ft_lstnew(all.line));
	if (get_next_line(all.fd, &all.line) == -1)
		return (0);
	all.map.map = make_map(&head, ft_lstsize(head));
	return (all.map.map);
}

void	draw_map(char *name, t_all *all)
{

	int		x;
	int		y;
	int		i;
	int		j;

	all->map.map = read_map(name, *all);
	y = -1;
	while (all->map.map[++y])
	{
		i = -1;
		while (++i < 10)
		{
			x = -1;
			while (all->map.map[y][++x])
				if (all->map.map[y][x] == '1')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(all->img.mlx, all->win.win, 10 * x + j, 10 * y + i, WHITE);
				}
				else if (all->map.map[y][x] == '2')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(all->img.mlx, all->win.win, 10 * x + j, 10 * y + i, RED);
				}
				else if (all->map.map[y][x] == 'N' || all->map.map[y][x] == 'S' || all->map.map[y][x] == 'E' || all->map.map[y][x] == 'W')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(all->img.mlx, all->win.win, 10 * x + j, 10 * y + i, GREEN);
				}
		}		
	}
}

int 	main(int argc, char **argv)
{
	t_all	all;

	all.map.map = 0;
	all.img.mlx = mlx_init();
	all.win.win = mlx_new_window(all.img.mlx, 640, 480, "mycub2d");
	draw_map(argv[1], &all);

	mlx_loop(all.img.mlx);
	return (0);
}
