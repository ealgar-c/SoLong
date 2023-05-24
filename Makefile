NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
MLX_FLAGS = -Imlx -Lmlx/ -lmlx -framework OpenGL -framework AppKit

SRC_DIR = src/
SRC = $(SRC_DIR)main.c
OBJ_DIR = objs/
OBJ = $(OBJ_DIR)main.o

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@

all: libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) libft/*.o

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
