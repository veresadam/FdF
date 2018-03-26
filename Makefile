# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adveres <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 12:10:45 by adveres           #+#    #+#              #
#    Updated: 2018/01/26 16:46:36 by adveres          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = *.c */*.c
OBJ = *.o
INC = includes/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -L ./includes/ -lmlx -framework OpenGL -framework AppKit
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
