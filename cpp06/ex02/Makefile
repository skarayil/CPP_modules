# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/08 20:22:53 by skarayil          #+#    #+#              #
#    Updated: 2026/10/09 08:34:02 by skarayil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     = identify
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS     = main.cpp Base.cpp
OBJ_DIR  = objs
OBJS     = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re