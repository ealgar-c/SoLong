NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
# MLX_FLAGS = -Imlx -Lmlx/ -lmlx -framework OpenGL -framework AppKit
MLX_LINUX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LINUX_OFLAGS = -I/usr/include -Imlx_linux -O3

SRC_DIR = src/
SRC = $(SRC_DIR)main.c
OBJ_DIR = objs/
OBJ = $(OBJ_DIR)main.o

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(MLX_LINUX_OFLAGS) -c $< -o $@

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_LINUX_FLAGS) libft/*.o

libft:
	@make -C libft/

clean:
	@$(RM) $(OBJ)
	@make -C libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re
