# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpineda- <kpineda-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/30 12:04:48 by kpineda-          #+#    #+#              #
#    Updated: 2026/06/30 12:04:49 by kpineda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02

# Source files and objects
SRC = main.cpp
OBJ_DIR = obj
OBJ = $(SRC:.cpp=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

# Compiler and flags
C++ = c++
RM = rm -f
RMDIR = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

# ==================================== BANNER =================================== #

define banner
	@echo "\033[0;34m"
	@echo " _____        ___ ___ "
	@echo "|   __|_ _   |   |_  |"
	@echo "|   __|_'_|  | | |  _|"
	@echo "|_____|_,_|  |___|___|"
	@echo "\033[0m"
endef

# ================================ MAIN RULE ==================================== #

all: $(NAME)

$(NAME): $(OBJ)
	$(banner)
	@$(C++) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilation completed. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

# ============================ FILE COMPILATION ================================= #

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "\033[0;34m⚙️  Compiling $<...\033[0m"
	@$(C++) $(CPPFLAGS) -c $< -o $@

# =============================== CLEANING RULES ================================ #

clean:
	@echo "\033[0;35m🧹 Cleaning object files...\033[0m"
	@$(RMDIR) $(OBJ_DIR)

fclean: clean
	@echo "\033[0;35m🗑️  Removing executable...\033[0m"
	@$(RM) $(NAME)
	@$(RM) $(NAME)_asan

re: fclean all

# =============================== EXECUTION RULE =============================== #

run: all
	@echo "\033[0;36m🚀 Running program...\033[0m"
	@./$(NAME)

# ============================== ADDRESSSANITIZER RULES ======================== #

asan:
	@echo "\033[0;33m🧪 Compiling with AddressSanitizer...\033[0m"
	$(banner)
	@$(C++) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address $(SRC) -o $(NAME)_asan
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilation completed. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"

runasan:
	@echo "\033[0;33m🧪 Compiling with AddressSanitizer...\033[0m"
	$(banner)
	@$(C++) -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address $(SRC) -o $(NAME)_asan
	@echo "\033[0;32m▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄ Compilation completed. ▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄\033[0m"
	@echo "\033[0;36m🚀 Running with ASan...\033[0m"
	@./$(NAME)_asan

.PHONY: all clean fclean re run asan runasan