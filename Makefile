# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almatsch <almatsch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/20 20:50:51 by almatsch          #+#    #+#              #
#    Updated: 2025/03/30 22:33:22 by almatsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./minilibx-linux/include
LDFLAGS = -ldl -pthread -lm

SRCS = main.c utils.c key_hooks.c fractal.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX42 = ./minilibx-linux/mlx.a

MLX_FLAGS = -L./MLX42/build -lmlx42 -lglfw -lm -ldl -lX11 -lXrandr -lXi -lXxf86vm -lXcursor -lpthread
all: $(NAME)

$(NAME): $(MLX42) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX42):
	chmod +x ./minilibx-linux/configure
	make -C ./minilibx-linux

%.o: %.c
	$(CC) $(CFLAGS) -I./MLX42/include -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	make -C libft clean
	make -C ./minilibx-linux clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	make -C ./minilibx-linux clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
