# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebuber <bebuber@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 16:43:05 by bebuber           #+#    #+#              #
#    Updated: 2024/05/21 16:47:55 by bebuber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM	= rm -rf
NAME = push_swap
SRC = operations.c lists.c push_swap.c ft_split.c sort_stack.c ft_printf.c
OBJS = $(SRC:.c=.o)
#LIBFT = libft.a
#LIBRARY_DIR = libft
#PRINTF = libftprintf.a
#PRINTF_DIR = printf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
#make -C $(LIBRARY_DIR)
#make -C $(PRINTF_DIR)
#-L $(PRINTF_DIR) -lft
#-L $(LIBRARY_DIR) -lft 

clean:
	$(RM) $(OBJS) $(B_OBJS)
#make -C $(LIBRARY_DIR) clean
#make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
#make -C $(LIBRARY_DIR) fclean
#make -C $(PRINTF_DIR) fclean

re: fclean all

#t: $(NAME)
#	./$(NAME)

.PHONY: all clean fclean re t