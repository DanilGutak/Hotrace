# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgutak <dgutak@student.42vienna.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 10:42:49 by secker            #+#    #+#              #
#    Updated: 2023/10/14 13:29:41 by dgutak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	hotrace
CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g

SRC	=	hotrace.c	\
		ft_split.c	\
		hotrace_utils.c \
		add.c

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