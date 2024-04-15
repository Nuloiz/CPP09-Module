NAME := PmergeMe

CC := c++

CPPFLAGS := -Wall -Wextra -Werror -g3 -std=c++98
#CPPFLAGS := -Wall -Wextra -Werror -g3 -std=c++98 -fsanitize=address

SRC := main.cpp PmergeMe.cpp

INCLUDES := -I

OBJ := $(SRC:%.cpp=$(OBJ)%.o)

all: $(NAME)

$(NAME): $(OBJ)
			@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)


clean:
			rm -r $(OBJ)

fclean: clean
			@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re%