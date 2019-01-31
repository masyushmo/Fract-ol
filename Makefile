#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 12:09:32 by mmasyush          #+#    #+#              #
#    Updated: 2019/01/17 12:09:33 by mmasyush         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = ./src/main.c \
		./src/thread.c \
		./src/mlx.c \
		./src/color.c \
		./src/julia.c \
		./src/mandelbrot.c \
		./src/keys.c \
		./src/changes.c



OUT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

MLX = -O2 -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OUT)
	make -C ./libft
	clang $(FLAGS) -g -o $(NAME) $(OUT) $(MLX) ./libft/libft.a
	@echo 'Compilated!'

clean:
	rm -f $(OUT)
	make -C ./libft clean

fclean: clean 
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all