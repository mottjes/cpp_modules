NAME		= phonebook

SRC			= phonebook.cpp

OBJ			= $(SRC:.cpp=.o)

CC      	= c++
FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $@

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)


re:    	fclean all

.PHONY: all clean fclean format re
