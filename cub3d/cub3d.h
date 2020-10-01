#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>
#include "liba/libft.h"
#include "gnl/get_next_line.h"
#include "minilibx_mms/mlx.h"

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x9ACD32
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define ERROR   



typedef struct	s_win
{
	int win_x;
    int win_y;
}				t_win;

typedef struct	s_map
{
    char **map;
	int map_x;
    int map_y;
}				t_map;

typedef struct	s_color
{
	unsigned int sky;
    unsigned int floor;
}				t_color;

typedef struct		s_sides
{
	char			*north;
	char			*west;
	char			*east;
	char			*south;
}					t_sides;

typedef struct	s_img
{
    void    *mlx;
    void    *win;

    void    NO_img;
    void    SO_img;
    void    WE_img;
    void    EA_img;
    void    S_img;
    void    *img;

}				t_img;

typedef struct	s_mlx
{
	void    *ptr;
    
}				t_mlx;

typedef struct	s_all
{
	t_win   win;
    t_map   *map;
    t_color color;
    t_img  *img;
    t_mlx   *mlx;
    t_sides sides;

    int				fd;
    char			*line;


}				t_all;







#endif