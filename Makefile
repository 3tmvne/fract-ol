CC = cc
CFLAGS = -Wall -Werror -Wextra -I/usr/include/minilibx-linux -Iinc
MLX_FLAGS = -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm

SRC_DIR = src
OBJ_DIR = obj

SRC = main.c fractals.c key_events.c init_program.c \
	  error_handling.c utils.c color.c ft_atod.c mouse_events.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/fract_ol.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
