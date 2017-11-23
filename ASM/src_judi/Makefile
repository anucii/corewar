.PHONY: all re clean fclean

NAME = t_parse

DIR_S = ./
DIR_O = ./
DIR_H = ../../include/

RDX = maintest parse_instr parse_params

SRC = $(addprefix $(DIR_S), $(addsuffix .c, $(RDX)))
OBJ = $(addprefix $(DIR_O), $(addsuffix .o, $(RDX)))
HDR = $(addprefix $(DIR_H), judi.h)

LIB_DIR = $(addprefix $(DIR_H), libft/)
LIB = -I $(LIB_DIR)includes

PRINT_DIR = $(addprefix $(DIR_H), ft_printf/)
PRINT = -I $(PRINT_DIR)includes

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)
	make -C $(PRINT_DIR)
	$(CC) $(CFLAGS) $^ -I $(DIR_H) $(LIB) $(PRINT) -L $(LIB_DIR) \
		-L $(PRINT_DIR) -lft -lftprintf -o $@

$(DIR_O)%.o : $(DIR_S)%.c $(HDR)
	$(CC) $(CFLAGS) -c $< -I $(DIR_H) $(LIB) $(PRINT)

clean : 
	rm $(OBJ)

fclean : clean
	rm $(NAME)

re : fclean all
