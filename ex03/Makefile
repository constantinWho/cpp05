NAME = coffee-making

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

FILES = main src/Bureaucrat src/AForm src/PresidentialPardonForm src/RobotomyRequestForm src/ShrubberyCreationForm src/Intern

OBJ = $(FILES:=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) *_shrubbery

re: fclean all

.PHONY: all clean fclean re
