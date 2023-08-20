# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjamsa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 15:41:21 by jjamsa            #+#    #+#              #
#    Updated: 2022/03/30 16:08:40 by jjamsa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_PATH = ./srcs/

SRCS = $(SRC_PATH)main.c $(SRC_PATH)actions.c $(SRC_PATH)free_allocated_memory.c \
		$(SRC_PATH)isometric.c $(SRC_PATH)line_drawing.c \
		$(SRC_PATH)more_actions.c $(SRC_PATH)oh_and_one_more_thing.c \
		$(SRC_PATH)read_file_into_array.c $(SRC_PATH)rev_isometric.c \
		$(SRC_PATH)sideview_horizontal.c $(SRC_PATH)sideview_vertical.c \
		$(SRC_PATH)topdown.c

INCLUDES = -I./includes/ -I./libft/ -I/usr/local/include

MLX = -L /usr/local/lib -L libft -l mlx -lft

FRAMEWORKS = -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

# -C moves to the directory specified after it and performs the preceding command there.
$(NAME):
	make -C libft
	gcc -o $(NAME) $(SRCS) \
	$(INCLUDES) $(MLX) $(FLAGS) $(FRAMEWORKS)
	@echo "Executable $(NAME) successfully created"

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re