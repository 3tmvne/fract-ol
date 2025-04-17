CC = cc  -g
CFLAGS = -Wall -Werror -Wextra -I/usr/include/minilibx-linux
MLX_FLAGS = -L/usr/include/minilibx-linux -lmlx -lXext -lX11 -lm
SRC = main.c fractals.c key_events.c init_program.c error_handling.c utils.c color.c ft_atod.c mouse_events.c
OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
NAME = fractol

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c fract_ol.h
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean 
	@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
