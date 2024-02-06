# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 07:11:37 by fzutter           #+#    #+#              #
#    Updated: 2024/02/06 11:10:37 by fzutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putnbr.c ft_putunnbr.c ft_putadd.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) ft_printf.h
	ar rcs $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re