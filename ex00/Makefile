# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 15:59:50 by lgottsch          #+#    #+#              #
#    Updated: 2025/05/27 16:04:09 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= main.cpp Zombie.cpp


# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re