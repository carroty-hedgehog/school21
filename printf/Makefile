# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 09:39:21 by tredtusk          #+#    #+#              #
#    Updated: 2020/08/06 13:30:50 by tredtusk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c ft_flag.c ft_check_type.c ft_parser.c ft_write_char.c\
	ft_work_string.c ft_work_hex.c ft_work_int.c ft_work_percent.c \
	ft_work_pointer.c ft_work_unsigned.c ft_write.c ft_printf_utils.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I.

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
