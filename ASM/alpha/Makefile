NAME = asm

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

INC = $(addprefix -I , $(INC_PATH))
INC_PATH = ./include/

LIB_PATH = $(INC_PATH)libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
SRC_PATH = ./src/
SRC_FILE =	asm.c \
			launch_parsing.c \
			pars_info.c \
			pars_order.c \
			parse_instr.c \
			parse_params.c \
			reg_param.c \
			ind_param.c \
			dir_param.c \
			param_utility.c \
			is_label_char.c \
			add_label.c \
			op_matches.c \
			multi_split.c \
			error.c \
			op.c \
			conversion.c\
			labelcall.c\
			deref_label.c\

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
