#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtymchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/22 11:37:15 by vtymchen          #+#    #+#              #
#    Updated: 2016/12/22 11:55:18 by vtymchen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC =	fillit.c \
		ft_helper.c \
		ft_memdel.c \
		ft_memset.c \
		ft_new.c \
		ft_print.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_read.c \
		ft_solve.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strnew.c \
		ft_strsplit.c \
		ft_validity.c 

OBJ = $(SRC:.c=.o)	

GCC = gcc -Wall -Wextra -Werror

all: $(NAME)	

$(NAME): $(OBJ)	
	$(GCC) -o $(NAME) $(OBJ)	

%.o: %.c
	$(GCC) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all