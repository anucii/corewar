.PHONY: all re clean fclean

NAME = calculator

DIR = ./
SRC = calc.c disp_mem.c execute.c main.c mem.c ops.c
OBJ = $(patsubst %.c,%.o,$(SRC))
HDR = calc.h

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(CFLAGS) $^ -o $@

$(DIR)%.o : $(DIR)%.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	for file in $(OBJ); do [ -f $file && rm $file ]; done

fclean : clean
	[ -f $(NAME) ] && rm $(NAME)

re : fclean all
