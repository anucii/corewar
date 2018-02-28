# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 16:19:20 by jgonthie          #+#    #+#              #
#    Updated: 2018/02/28 10:38:43 by jgonthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm
NAME_2 = corewar
NAME_3 = crack

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIB_PATH = $(INC_PATH)libft/
INC_PATH = ./include/
INC = $(addprefix -I , $(INC_PATH))

SRC_ASM = $(addprefix $(SRC_PATH_ASM), $(SRC_FILE_ASM))
SRC_COREWAR = $(addprefix $(SRC_PATH_COREWAR), $(SRC_FILE_COREWAR))
SRC_CRACK = $(addprefix $(SRC_PATH_CRACK), $(SRC_FILE_CRACK))

SRC_PATH_ASM = ./src_asm/
SRC_PATH_COREWAR = ./src_corewar/
SRC_PATH_CRACK = ./src_crack/

SRC_FILE_ASM =		asm.c \
					init_hdr.c \
					launch_parsing.c \
					skip_line.c \
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
					conversion.c \
					labelcall.c \
					str_t.c \
					deref_label.c \
					calc_prog_size.c \
					free.c \
					write_order_size.c \
					write_order_pos.c \
					has_ocp.c \
					new_name.c \
					realloc_order.c \

SRC_FILE_COREWAR =	main.c \
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
					color_pc.c \
					print_board.c \
					count_proc.c \
					print_child.c \
					proc_hdr.c \
					proc_add.c \
					proc_pop.c \
					proc_dup.c \
					proc_unqueue.c \
					free_music.c \
					store_names.c \
					id_is_new.c \
					store_nb.c \
					draw_info_player.c \

SRC_FILE_CRACK =	main.c \
					parse_file.c \
					littleendian.c \
					parse_header.c \
					write_header.c \
					write_instr.c \
					op.c \
					join.c \
					op_matches.c \
					f_all.c \
					ft_to_deci.c \
					to_hexa.c \
					check_opc.c \
					write_reg.c \
					write_dir.c \
					write_ind.c \
					close_file.c \

OBJ_ASM = $(addprefix $(OBJ_PATH_ASM), $(OBJ_FILE_ASM))
OBJ_COREWAR = $(addprefix $(OBJ_PATH_COREWAR), $(OBJ_FILE_COREWAR))
OBJ_CRACK = $(addprefix $(OBJ_PATH_CRACK), $(OBJ_FILE_CRACK))

OBJ_PATH_ASM = ./obj_asm/
OBJ_PATH_COREWAR = ./obj_corewar/
OBJ_PATH_CRACK = ./obj_crack/

OBJ_FILE_ASM = $(SRC_FILE_ASM:.c=.o)
OBJ_FILE_COREWAR = $(SRC_FILE_COREWAR:.c=.o)
OBJ_FILE_CRACK = $(SRC_FILE_CRACK:.c=.o)

.PHONY: all clean fclean re

all: $(NAME) $(NAME_2) $(NAME_3)

$(NAME) : $(OBJ_ASM)
	@make -C $(LIB_PATH)
	@$(CC) $(FLAGS) $(OBJ_ASM) -L $(LIB_PATH) -lft -o $(NAME)
	@echo "\033[32masm success.\033[0m"

$(OBJ_PATH_ASM)%.o: $(SRC_PATH_ASM)%.c
	@mkdir -p $(OBJ_PATH_ASM)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(NAME_2) : $(OBJ_COREWAR)
	@$(CC) $(FLAGS) $(OBJ_COREWAR) -L $(LIB_PATH) -lft -lcurses -L $(INC_PATH) -lfmod -o $(NAME_2)
	@echo "\033[32mcorewar success.\033[0m"

$(OBJ_PATH_COREWAR)%.o: $(SRC_PATH_COREWAR)%.c
	@mkdir -p $(OBJ_PATH_COREWAR)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(NAME_3) : $(OBJ_CRACK)
	@$(CC) $(FLAGS) $(OBJ_CRACK) -L $(LIB_PATH) -lft -o $(NAME_3)
	@echo "\033[32mcrack success.\033[0m"

$(OBJ_PATH_CRACK)%.o: $(SRC_PATH_CRACK)%.c
	@mkdir -p $(OBJ_PATH_CRACK)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean :
	@make clean -C $(LIB_PATH)
	@rm -rf $(OBJ_PATH_ASM)
	@rm -rf $(OBJ_PATH_COREWAR)
	@rm -rf $(OBJ_PATH_CRACK)
	@echo "\033[31mclean success.\033[0m"

fclean : clean
	@make fclean -C $(LIB_PATH)
	@rm -rf $(NAME)
	@rm -rf $(NAME_2)
	@rm -rf $(NAME_3)
	@echo "\033[31mfclean success.\033[0m"

re: fclean all
