# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 12:38:21 by lgottsch          #+#    #+#              #
#    Updated: 2025/05/20 13:55:48 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= megaphone.cpp


# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re