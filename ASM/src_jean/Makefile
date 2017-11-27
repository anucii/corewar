NAME = a.out

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

LIB_PATH = ../../include/libft

INC = $(addprefix -I , $(INC_PATH))
INC_PATH = ../../include/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
SRC_PATH = ./
SRC_FILE =	main.c \
			ft_error.c \
			ft_realloc_order.c \
			ft_pars_info.c \
			ft_pars_order.c \
			ft_is_label_char.c \
			ft_multi_split.c \
			parse_params.c \
			op.c \
			reg_param.c \
			dir_param.c \
			ind_param.c \
			param_utility.c \

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))
OBJ_PATH = ./obj/
OBJ_FILE = $(SRC_FILE:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIB_PATH)
		@$(CC) $(OBJ) -L $(LIB_PATH) -lft -o $(NAME)
		@echo "\033[32mMake success.\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(FLAGS) $(INC) -o $@ -c $<
		@echo "\033[33mCreat. file $@ ..\033[0m"

clean:
		@make clean -C $(LIB_PATH)
		@rm -rf $(OBJ)
		@rm -rf $(OBJ_PATH)
		@echo "\033[31mclean success.\033[0m"

fclean: clean
		@make fclean -C $(LIB_PATH)
		@rm -Rf $(NAME)
		@echo "\033[31mfclean success.\033[0m"

re: fclean all
