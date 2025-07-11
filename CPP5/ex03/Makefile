
NAME = bureau

CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRC= main.cpp  Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp Intern.cpp

# rules
$(NAME):
	 $(CC) $(CFLAGS) $(SRC) -o $(NAME)


all: $(NAME)

clean: fclean

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean