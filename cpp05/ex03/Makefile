# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/02 15:49:24 by skarayil          #+#    #+#              #
#    Updated: 2026/10/03 00:18:44 by skarayil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = coffeemaking
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS     = main.cpp \
           Bureaucrat.cpp \
           AForm.cpp \
           ShrubberyCreationForm.cpp \
           RobotomyRequestForm.cpp \
           PresidentialPardonForm.cpp \
           Intern.cpp
OBJ_DIR  = obj
OBJS     = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
HEADERS  = Bureaucrat.hpp AForm.hpp \
           ShrubberyCreationForm.hpp \
           RobotomyRequestForm.hpp \
           PresidentialPardonForm.hpp \
           Intern.hpp

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) *_shrubbery

re: fclean all

.PHONY: all clean fclean re