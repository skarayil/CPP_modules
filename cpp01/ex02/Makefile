# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/08 12:00:00 by skarayil          #+#    #+#              #
#    Updated: 2026/05/10 15:26:06 by skarayil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = HiThisIsBrain
CXX         = c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMD -MP

OBJ_DIR     = obj
DEP_DIR     = dep

SRCS        = main.cpp

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS        = $(addprefix $(DEP_DIR)/, $(SRCS:.cpp=.d))

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