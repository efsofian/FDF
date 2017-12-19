# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seliasbe <seliasbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/23 17:45:30 by seliasbe          #+#    #+#              #
#    Updated: 2017/10/25 15:21:26 by seliasbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c sides.c parse.c mlxfunc.c keys.c

OBJ = $(SRC:.c=.o)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -Werror -Wextra -Wall -c $(SRC)
	gcc -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
