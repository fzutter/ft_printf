# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzutter <fzutter@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 07:11:37 by fzutter           #+#    #+#              #
#    Updated: 2023/12/05 15:13:13 by fzutter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c 

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	ar -r $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re