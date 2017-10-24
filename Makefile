# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apouchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/06 19:39:48 by apouchet          #+#    #+#              #
#    Updated: 2017/06/06 19:39:50 by apouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

NAME = push_swap

CHECKER = checker

SRC = ./src/swap_pab.c ./src/swap_rab.c ./src/swap_sab.c ./src/swap_rr.c ./src/ft_here_nb.c \
	src/mouve.c ./src/ft_tri_nb.c ./src/ft_atoi.c ./src/ft_verif.c ./src/ft_fin.c ./src/ft_strsplit.c

CHEK = ./src/ft_check.c ./src/get_next_line.c ./src/ft_bzero.c ./src/ft_memalloc.c ./src/ft_strstr.c ./src/ft_strlen.c

PUSH = ./src/push_swap.c ./src/main.c

OBJ = $(SRC:.c=.o)

OP = $(PUSH:.c=.o)

OC = $(CHEK:.c=.o)

all: $(NAME) 

$(NAME) : $(OBJ) $(OP) $(OC)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) $(OP)
	gcc -Wall -Werror -Wextra -o $(CHECKER) $(SRC) $(OC)

clean :
	rm -f ./src/*.o

re : fclean all

fclean : clean
	rm -f $(NAME)
	rm -f $(CHECKER)