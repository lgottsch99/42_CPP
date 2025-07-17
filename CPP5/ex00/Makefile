
# TODO refactor to generate .o files -> scales better for large projects!!

NAME = bureau

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC= main.cpp  Bureaucrat.cpp

# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean: fclean

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean