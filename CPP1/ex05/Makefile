# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 12:53:17 by lgottsch          #+#    #+#              #
#    Updated: 2025/05/31 13:48:13 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= main.cpp Harl.cpp

# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean: fclean

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean