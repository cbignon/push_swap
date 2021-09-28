# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 16:10:36 by cbignon           #+#    #+#              #
#    Updated: 2021/09/28 09:40:21 by cbignon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES =	ft_chunk.c \
			ft_parse.c \
			ft_find.c \
			push_swap.c \
			ft_stack.c \
			is_sorted.c \
			utils.c \
			operations_ab.c \
			operations_p.c \
			operations_s.c \
			operations_r.c \
			main.c \

CFLAGS = -Wall -Werror -Wextra

CC = clang

INC = ft_push_swap.h

ARG500 =`ruby -e "puts (-43..456).to_a.shuffle.join(' ')"`

ARG100 =`ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`

ARG1000 =`ruby -e "puts (1..1000).to_a.shuffle.join(' ')"`

OBJETS = $(SOURCES:.c=.o)

$(NAME) : $(OBJETS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJETS)

all : $(NAME)

clean :
	rm -f $(OBJETS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test500 : all 
	./push_swap $(ARG500) | wc -l

test100 : all
	./push_swap $(ARG100) | wc -l

test1000 : all
	./push_swap $(ARG1000) | wc -l
