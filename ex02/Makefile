# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 16:17:31 by lgottsch          #+#    #+#              #
#    Updated: 2025/05/25 14:29:21 by Watanudon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= mytest.cpp Account.cpp


# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re