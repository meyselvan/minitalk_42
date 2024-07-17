# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relvan <relvan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 20:09:49 by relvan            #+#    #+#              #
#    Updated: 2023/12/23 20:09:51 by relvan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minitalk
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f
CLIENT_SRC	=	client.c
SERVER_SRC	=	server.c

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

$(NAME):	client server

all:		$(NAME)

$(SERVER):	$(SERVER).c minitalk.h
			gcc $(CFLAGS) $(SERVER_OBJ) -o server 

$(CLIENT):	$(CLIENT).c minitalk.h
			gcc $(CFLAGS) $(CLIENT_OBJ).c -o client

clean:
			rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)


fclean:		clean
			rm -rf client server

re:			fclean all

.PHONY: 	all clean fclean re