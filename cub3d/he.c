#include <fcntl.h>
#include "gnl/get_next_line.h"
#include "liba/libft.h"
#include "minilibx_mms/mlx.h"

char	**make_map(t_list **head, int size)
{
	char	**map;
	int 	i;
	t_list	*tmp;

	if (!(map = ft_calloc(size + 1, sizeof(char *))))
		return (0);
	tmp = *head;
	i = -1;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

char	**read_map(char *name)
{
	int		fd;
	char 	*line;
	t_list	*head;
	char	**map;

	fd = open(name, O_RDONLY);
	line = 0;
	head = 0;

	while (get_next_line(fd, &line) == 1)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	if (get_next_line(fd, &line) == -1)
		return (0);
	map = make_map(&head, ft_lstsize(head));
	return (map);
}

void	draw_map(char *name, char **map, void *mlx, void *win)
{
	int		x;
	int		y;
	int		i;
	int		j;

	map = read_map(name);
	y = -1;
	while (map[++y])
	{
		i = -1;
		while (++i < 10)
		{
			x = -1;
			while (map[y][++x])
				if (map[y][x] == '1')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(mlx, win, 10 * x + j, 10 * y + i, 0xFFFFFF);
				}
				else if (map[y][x] == '2')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(mlx, win, 10 * x + j, 10 * y + i, 0xFFFF00);
				}
				else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(mlx, win, 10 * x + j, 10 * y + i, 0xFF0000);
				}
		}		
	}
}

int 	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	char	**map;

	map = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "test");
	draw_map(argv[1], map, mlx, win);

	mlx_loop(mlx);
	return (0);
}
