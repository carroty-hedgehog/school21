
#include "cub3d.h"

char** make_map(t_list **head, int size)
{
    if (!(map = ft_calloc(size + 1, sizeof(char *))))
		return (0);
    int i = -1;
    t_list *tmp;
    
    tmp = *head;

    while (tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp -> next;
    }
    return(map);
}

char **read_map(char *name)
{
    int fd = open(name, O_RDONLY);
    char *line;
    line = 0;
    char **map;
    
    t_list *head = 0;
   

    while (get_next_line(fd, &line) == 1)
    {
        ft_lstadd_back(&head, ft_lstnew(line));
    }
    ft_lstadd_back(&head, ft_lstnew(line));
    if (get_next_line(fd, &line) == -1)
		return (0);
    map = make_map(&head, ft_lstsize(head));
    return(map);
}

void    draw_screen(char *name, char **map, void *mlx, void *win)
{

    int x;
    int y;
    int i;
    int j;
        
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
						mlx_pixel_put(mlx, win, 10 * x + j, 10 * y + i, WHITE);
				}
				else if (map[y][x] == '2')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(mlx, win, 10 * x + j, 10 * y + i, WHITE);
				}
				else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
				{
					j = -1;
					while (++j < 10)
						mlx_pixel_put(mlx, win, 10 * x + j, 10 * y + i, GREEN);
				}
		}
    }		
}

void gni_v_dele(t_file *all, int flag)
{

    t_all   all;

    while (get_next_line(file->fd, &file->line))
	{
		if (flag == 0)
		{
					//pars// 
			if (parser_my(file) == 1)
				flag = 1;
		}
		if (flag == 1)
			// look_for_map(file);
	}
	// look_for_map(file);
	// check_res(file);
	// onlymap(file);
	// flood_fill(file);
	// cub3d(file);
					mlx = mlx_init();
					win = mlx_new_window(mlx, 640, 480, "test");

					draw_screen(argv[1], map, mlx, win);

					mlx_loop(mlx);
}

static void	init(t_file *all)
{
	all->win.win_x = 0;
	all->win.win_y = 0;
	all->sides.south = NULL;
	all->sides.north = NULL;
	all->sides.east = NULL;
	all->sides.west = NULL;
	all->color.sky = 0;
	all->color.floor = 0;
}


int main(int argc, char **argv)
{
    t_all   all;
    // char **map;
    // void *mlx;
    // void *win;
    int flag;

    // map = 0;

    flag = 0;
    // if (argc <= 1)
    //     return(ERROR);
    // else if (argc >= 4)
	// 	return(ERROR);

	init(&all);

	// if (argc == 3)   
   

    gni_v_dele(&file, flag);
	return(0);
}