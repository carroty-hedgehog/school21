# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/24 13:12:22 by tredtusk          #+#    #+#              #
#    Updated: 2020/05/25 20:07:59 by tredtusk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC =  ./ft_atoi.c ./ft_isalnum.c  ./ft_isascii.c ./ft_isalpha.c ./ft_isprint.c\
		./ft_isdigit.c ./ft_islower.c ./ft_isupper.c \
		./ft_bzero.c ./ft_calloc.c ./ft_itoa.c ./ft_tolower.c ./ft_toupper.c\
		./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c\
		./ft_lstiter.c ./ft_lstlast.c ./ft_lstmap.c ./ft_lstnew.c ./ft_lstsize.c\
		./ft_memcmp.c ./ft_memccpy.c ./ft_memcpy.c ./ft_memmove.c ./ft_memchr.c ./ft_memset.c\
		./ft_putchar_fd.c  ./ft_putstr_fd.c  ./ft_putendl_fd.c ./ft_putnbr_fd.c\
		./ft_split.c ./ft_strlcat.c ./ft_strncmp.c ./ft_substr.c \
		./ft_strchr.c ./ft_strrchr.c ./ft_strlen.c ./ft_strnstr.c ./ft_strtrim.c\
		./ft_strjoin.c ./ft_strmapi.c ./ft_strdup.c ./ft_strlcpy.c\

OBJ = ${SRC:.c=.o}

FLAG = -Wall -Werror -Wextra

COMPILE = gcc $(FLAG) -c

LIB = ar rc $(NAME)

RANLIB = ranlib $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME):
		@$(COMPILE) $(SRC)
		@echo "complit"
			@$(LIB) $(OBJ)
		@echo "o-file done"
				@$(RANLIB)
		@echo "libft done"
clean:
		@$(REMOVE) $(OBJ)
		@echo "clean done"

fclean: clean
		@$(REMOVE) $(NAME)
		@echo "clean o-file and libft"

re: fclean all

.PHONY: all clean fclean re
		


