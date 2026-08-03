# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/04 16:00:00 by skarayil          #+#    #+#              #
#    Updated: 2026/08/01 18:26:23 by skarayil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= BraiiiiiiinnnzzzZ

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP -I..

OBJ_DIR		= obj
DEP_DIR		= dep

SRCS		= main.cpp \
			  Zombie.cpp \
			  newZombie.cpp \
			  randomChump.cpp

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
