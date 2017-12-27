NAME = crack

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

INC = $(addprefix -I , $(INC_PATH))
INC_PATH = ./include/

LIB_PATH = $(INC_PATH)libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
SRC_PATH = ./src/
SRC_FILE = 	main.c \
			parse_file.c \
			error.c \
			print_output.c \
			littleendian.c \
			parse_header.c \
			write_header.c \
			write_instr.c \
			op.c \
			op_matches.c \
			f_live.c \
			f_ld.c \
			f_st.c \
			f_add.c \
			f_or.c \
			f_xor.c \
			f_zjmp.c \
			f_ldi.c \
			f_lldi.c \
			f_sti.c \
			f_fork.c \
			f_lld.c \
			f_lfork.c \
			f_aff.c \
			f_and.c \
			f_sub.c \
			ft_to_deci.c \
			to_hexa.c \
			check_opc.c \

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))
OBJ_PATH = ./obj/
OBJ_FILE = $(SRC_FILE:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(OBJ) -L $(LIB_PATH) -lft -lcurses -o $(NAME)
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
