# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 19:34:15 by tredtusk          #+#    #+#              #
#    Updated: 2020/10/27 19:45:06 by tredtusk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEAD = mymlx.h
LIB = libmlx.dylib ./libft/libft.a

SRCS = cub3d.c pars_map.c sprite.c map3d.c hook_func.c \
	utils.c check_col_res.c check_tex.c strc_init.c \
	position_bmp.c check_map_line.c

SRCO = cub3d.o pars_map.o sprite.o map3d.o hook_func.o \
		utils.o check_col_res.o check_tex.o strc_init.o \
		position_bmp.o check_map_line.o

all: $(NAME)

$(SRCO): %.o:%.c $(HEAD)
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(SRCO) $(HEAD)
	cd ./libft && make && cd ..
	cd ./mlx && make && cp libmlx.dylib ../ && cd ..
	gcc $(SRCO) -o $(NAME) -L. $(LIB) -framework OpenGL -framework AppKit
	@echo "\t\033[0;36mgo_play"
	
clean:
	cd ./libft && make clean && cd ..
	cd ./mlx && make clean && cd ..
	/bin/rm -rf $(SRCO)
	@echo "\t\033[0;32mclean done"

fclean: clean
	cd ./libft && make fclean && cd ..
	/bin/rm -rf libmlx.dylib
	/bin/rm -rf $(NAME)
	@echo "\t\033[0;32mclean o-file and lib"

re: fclean all

bonus: all

.PHONY: clean fclean re