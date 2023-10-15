# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 10:42:49 by secker            #+#    #+#              #
#    Updated: 2023/10/15 17:04:28 by dgutak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	hotrace
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -Ofast -march=native

SRC	=	hotrace.c	\
		hotrace_utils.c \
		add.c	\
		get_next_line.c get_next_line_utils.c search.c

OBJ =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:	
		rm -f *.o

fclean:	clean 
		rm -f hotrace

re: fclean all

.PHONY: all clean fclean re