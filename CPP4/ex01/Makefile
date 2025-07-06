

NAME = brain

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

SRC= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean: fclean

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean