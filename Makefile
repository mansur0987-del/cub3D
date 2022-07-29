# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 14:02:31 by armaxima          #+#    #+#              #
#    Updated: 2022/06/17 19:28:32 by armaxima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft.a

LIBFT_PATH = -Llibft -lft

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -lz
NAME = cub3D

SRC = src/main.c \
	src/ft_check.c \
	src/ft_utils.c \
	src/ft_check_file.c \
	src/ft_check_map.c \
	src/ft_game.c \
	src/ft_init.c \
	src/ft_draw.c \
	src/ft_wall_paint.c \
	src/keys.c \
	src/ft_open_door.c \
	src/anime.c

OBJ = $(patsubst %.c, %.o, $(SRC))

HEADERS = -I includes -I libft -I mlx
CC		=	gcc
CFLAGS	= -Wall -Wextra -Werror
RM 		=	rm -f

%.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEAD) Makefile
	make -sC mlx
	make -C libft
	@$(CC) $(HEADERS) $(OBJ) $(LIBFT_PATH) $(MLX) -o $@
	@echo "object files $(NAME) created"
	@echo "$(NAME) created"

clean:
	@make -C libft clean
	@echo "libft clean"
	@make -sC mlx clean
	@$(RM) $(OBJ)
	@echo "object files clean"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) clean"

re: fclean all

.PHONY: all clean fclean re bonus
