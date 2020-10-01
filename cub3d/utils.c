static int
	config_key(char const *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (C_R);
	else if (line[0] == 'N' && line[1] == 'O')
		return (C_NO);
	else if (line[0] == 'S' && line[1] == 'O')
		return (C_SO);
	else if (line[0] == 'W' && line[1] == 'E')
		return (C_WE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (C_EA);
	else if (line[0] == 'S' && line[1] == 'T')
		return (C_ST);
	else if (line[0] == 'F' && line[1] == 'T')
		return (C_FT);
	else if (line[0] == 'S' && line[1] == ' ')
		return (C_S);
	else if (line[0] == 'S' && line[1] == 'U')
		return (C_SU);
	else if (line[0] == 'S' && line[1] == 'C')
		return (C_SC);
	else if (line[0] == 'F' && line[1] == ' ')
		return (C_F);
	else if (line[0] == 'C' && line[1] == ' ')
		return (C_C);
	return (C_MAP);
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
	// all->sprite = NULL;
	// all->stop_map = 0;
	// all->stop_gamer = 0;
	// all->check_for_data = 0;
	// all->first = NULL;
	// all->map = NULL;
	// all->y_max = 0;
	// all->x_max = 0;
}
