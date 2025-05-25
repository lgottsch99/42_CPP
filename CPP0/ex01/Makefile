# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgottsch <lgottsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 14:12:49 by lgottsch          #+#    #+#              #
#    Updated: 2025/05/24 16:01:22 by lgottsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC= main.cpp Contact.cpp PhoneBook.cpp


# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re