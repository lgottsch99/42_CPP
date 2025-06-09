# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Watanudon <Watanudon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 14:01:38 by lgottsch          #+#    #+#              #
#    Updated: 2025/06/09 17:15:07 by Watanudon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavtrap

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= main.cpp ClapTrap.cpp ScavTrap.cpp

# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean: fclean

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean