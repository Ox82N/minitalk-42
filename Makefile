# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenjair <obenjair@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 18:25:41 by obenjair          #+#    #+#              #
#    Updated: 2022/07/08 18:25:48 by obenjair         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(cl) $(sr)

client = client.c

server = server.c

cl = client

utils = utils.c

SRC = $(client) $(server) $(utils)

sr = server

hd = minitalk.h

flags = -Wall -Wextra -Werror

all : $(NAME) 

$(NAME) : $(SRC) $(hd)
	gcc $(flags) $(client) $(utils) -o $(cl)
	gcc $(flags) $(server) $(utils) -o $(sr)


clean :
	rm -rf $(cl) $(sr)

fclean: clean

re : fclean	all