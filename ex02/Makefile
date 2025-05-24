# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 16:17:31 by lgottsch          #+#    #+#              #
#    Updated: 2025/05/24 16:59:41 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= tests.cpp Account.cpp


# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re