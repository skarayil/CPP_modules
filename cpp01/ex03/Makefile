# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 13:26:21 by skarayil          #+#    #+#              #
#    Updated: 2026/08/01 23:18:56 by skarayil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= UnnecessaryViolence

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

OBJ_DIR		= obj
DEP_DIR		= dep

SRCS		= main.cpp \
			  Weapon.cpp \
			  HumanA.cpp \
			  HumanB.cpp

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS		= $(addprefix $(DEP_DIR)/, $(SRCS:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@$(CXX) $(CXXFLAGS) -MF $(DEP_DIR)/$*.d -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re