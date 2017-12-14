.PHONY: all re clean fclean

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

TEST = tester

LIB_DIR = ./libft/
LIB_HDR_DIR = $(addprefix $(LIB_DIR), includes/)

PRINT_DIR = ./ft_printf/
PRINT_HDR_DIR = $(addprefix $(PRINT_DIR), includes/)


SRC_DIR = ./src/
HDR_DIR = ./include/
OBJ_DIR = ./builts/
FILES = atropos.c checkheader.c chronos.c error_vm.c f_add.c f_aff.c\
		f_and.c f_fork.c f_ld.c f_ldi.c f_lfork.c f_live.c f_lld.c\
		f_lldi.c f_or.c f_st.c f_sti.c f_sub.c f_xor.c f_zjmp.c\
		foreach_proc.c load_champ.c new_pid.c op.c run.c start.c\
		timer.c error_vm.c new_player.c chars_to_int.c
HDR_FILES = judi.h op.h

HDR = $(addprefix $(HDR_DIR), $(HDR_FILES))
SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c,%.o,$(FILES)))

INC = -I $(HDR_DIR) -I $(LIB_HDR_DIR) -I $(PRINT_HDR_DIR)
LIB = -L$(LIB_DIR) -lft -L$(PRINT_DIR) -lftprintf
LIBFT = $(addprefix $(LIB_DIR), libft.a)
PRINTF = $(addprefix $(PRINT_DIR), libftprintf.a)

all : $(TEST)

$(TEST) : $(OBJ)
	$(CC) $(CFLAGS) $^ $(INC) $(LIB) -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HDR)
	[ -d $(OBJ_DIR) ] || mkdir $(OBJ_DIR)
	@echo $(HDR)
	@make -C $(LIB_DIR)
	@make -C $(PRINT_DIR)
	$(CC) $(CFLAGS) -c $< $(INC) -o $@

clean :
	for file in $(OBJ); do [ -f $$file ] && rm $$file; done
	[ -d $(OBJ_DIR) ] && rm $(OBJ_DIR)
	@make clean -C $(LIB_DIR)
	@make clean -C $(PRINT_DIR)

fclean : clean
	[ -f $(TEST) ] && rm $(TEST)
	[ -f $(LIBFT) ] && rm $(LIBFT)
	[ -f $(PRINTF) ] && rm $(PRINTF)

re : fclean all
