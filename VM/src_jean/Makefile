NAME = corewar

CC = gcc
FLAGS = -g -Wall -Wextra -Werror

INC = $(addprefix -I , $(INC_PATH))
INC_PATH = ./include/

LIB_PATH = $(INC_PATH)libft/

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
SRC_PATH = ./src/
SRC_FILE = 	main.c \
			error_vm.c \
			check_arg.c \
			check_header.c \
			load_champ.c \
			start_ncurses.c \
			new_win.c \
			destroy_win.c \
			init_coor.c \
			draw_corewar.c \
			init_arena.c \
			draw_arena.c \
			refresh_arena.c \
			put_menu.c \
			checkocp.c \
			int_on_mem.c \
			f_st.c \
			run.c \
			atropos.c \
			deadline.c \
			op.c \
			timer.c \
			f_add.c\
			f_aff.c \
			f_and.c \
			f_fork.c \
			f_ld.c \
			f_ldi.c \
			f_lfork.c \
			f_live.c \
			f_lld.c \
			f_lldi.c \
			f_or.c \
			f_sti.c \
			f_sub.c \
			f_xor.c \
			f_zjmp.c \
			foreach_proc.c \
			chars_to_int.c \
			chars_to_short.c \
			chronos.c \
			execute_error.c \
			param_size.c \
			parse_params.c \
			reinit_life_status.c \
			convert.c \
			carry.c \
			dump_mem.c \
			strcpystatic.c \
			intr_msg.c \
			lives_reg.c \
			get_info.c \
			ini_info.c \
			check_int.c \
			check_opt.c \
			new_pid.c \
			info_player.c \

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))
OBJ_PATH = ./obj/
OBJ_FILE = $(SRC_FILE:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@$(CC) $(OBJ) -L $(LIB_PATH) -lft  -lcurses -L ./include/ -lfmod  -o $(NAME)
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
