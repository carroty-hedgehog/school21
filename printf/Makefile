

NAME = libftprintf.a

SRCS =  ft_printf.c ft_flag.c ft_check_type.c ft_parser.c ft_write_char.c\
	ft_work_string.c ft_work_hex.c ft_work_int.c ft_work_percent.c \
	ft_work_pointer.c ft_work_unsigned.c ft_write.c ft_printf_utils.c

# FT_O = 	ft_printf.o ft_flag.o ft_check_type.o ft_parser.o \
# 	ft_work_string.o ft_work_hex.o ft_work_int.o ft_work_percent.o \
# 	ft_work_pointer.o ft_work_unsigned.o ft_write.o ft_printf_utils.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I.

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
