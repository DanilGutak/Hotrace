# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: secker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 10:42:49 by secker            #+#    #+#              #
#    Updated: 2023/10/14 17:36:10 by secker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	hotrace
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

SRC	=	hotrace.c	\
		ft_split.c	\
		hotrace_utils.c \
		add.c	\
		input_parser.c

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