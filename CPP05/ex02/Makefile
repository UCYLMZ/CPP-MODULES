NAME =	Bureaucrat
SRCS =	Bureaucrat.cpp AForm.cpp PresidentalPardonForm.cpp \
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp main.cpp 

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all