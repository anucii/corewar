# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgonthie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 13:26:24 by jgonthie          #+#    #+#              #
#    Updated: 2017/07/20 13:28:51 by jgonthie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

#INCLUDE = libft.h
INC_PATH = ./include/
INC = $(addprefix -I , $(INC_PATH))

SRC_LIB = $(addprefix $(SRC_PATH), $(SRC_FILE_LIB))
SRC_GNL = $(addprefix $(SRC_PATH), $(SRC_FILE_GNL))
SRC_PRINTF = $(addprefix $(SRC_PATH), $(SRC_FILE_PRINTF))
SRC_PATH_LIB = ./src_lib/
SRC_PATH_GNL = ./src_gnl/
SRC_PATH_PRINTF = ./src_printf/
SRC_FILE_LIB =	ft_memset.c \
				ft_bzero.c \
	   			ft_memcpy.c \
	   			ft_memccpy.c \
	   			ft_memmove.c \
	   			ft_memchr.c \
	   			ft_memcmp.c \
	  			ft_strlen.c \
	   			ft_strdup.c \
	   			ft_strcpy.c \
	   			ft_strncpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
	   			ft_strcat.c \
	   			ft_strncat.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_foreach.c \
				ft_lstprint.c \
				ft_lstsize.c \
				ft_range.c \
				ft_sqrt.c \
				ft_realloc.c\
				ft_strbase.c\
				ft_reverse.c\

SRC_FILE_GNL =	get_next_line.c \

SRC_FILE_PRINTF =	ft_printf.c\
					ft_struct.c\
					ft_checkspec.c\
					ft_spec.c\
					ft_spec_number.c\
					ft_spec_char.c\
					ft_spec_string.c\
					ft_spec_pointer.c\
					ft_spec_binary.c\
					ft_buffer.c\
					ft_size.c\
					ft_size_string.c\
					ft_flag_hash.c\
					ft_flag_plus.c\
					ft_flag_minus.c\
					ft_flag_space.c\
					ft_flag_zero.c\
					ft_unicode.c\
					ft_master_itoa.c\

OBJ_LIB = $(addprefix $(OBJ_PATH_LIB), $(OBJ_FILE_LIB))
OBJ_GNL = $(addprefix $(OBJ_PATH_GNL), $(OBJ_FILE_GNL))
OBJ_PRINTF = $(addprefix $(OBJ_PATH_PRINTF), $(OBJ_FILE_PRINTF))
OBJ_PATH_LIB = ./obj_lib/
OBJ_PATH_GNL = ./obj_gnl/
OBJ_PATH_PRINTF = ./obj_printf/
OBJ_FILE_LIB = $(SRC_FILE_LIB:.c=.o)
OBJ_FILE_GNL = $(SRC_FILE_GNL:.c=.o)
OBJ_FILE_PRINTF = $(SRC_FILE_PRINTF:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ_LIB) $(OBJ_GNL) $(OBJ_PRINTF)
	@ar rc $(NAME) $(OBJ_LIB) $(OBJ_GNL) $(OBJ_PRINTF)
	@ranlib $(NAME)

$(OBJ_PATH_LIB)%.o: $(SRC_PATH_LIB)%.c
	@mkdir -p $(OBJ_PATH_LIB)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH_GNL)%.o: $(SRC_PATH_GNL)%.c
	@mkdir -p $(OBJ_PATH_GNL)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OBJ_PATH_PRINTF)%.o: $(SRC_PATH_PRINTF)%.c
	@mkdir -p $(OBJ_PATH_PRINTF)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean :
	@rm -Rf $(OBJ_PATH_LIB)
	@rm -Rf $(OBJ_PATH_GNL)
	@rm -Rf $(OBJ_PATH_PRINTF)

fclean : clean
	@rm -Rf $(NAME)

re: fclean all
