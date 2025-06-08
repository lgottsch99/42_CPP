# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 14:01:38 by lgottsch          #+#    #+#              #
#    Updated: 2025/06/06 14:01:42 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= main.cpp Fixed.cpp 

# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean: fclean

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean