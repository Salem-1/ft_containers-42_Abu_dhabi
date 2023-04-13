NAME = salem_tester
# SRC =  test_vectors.cpp 
SRC =  test_map.cpp 
# MSRC = test_map.cpp
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -g3
# CXXFLAGS= 
CXX = c++ 
OBJ =  $(SRC:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJ)
	@$(CXX)  $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
test: re
	@echo "\n\n"
	@./salem_tester

mem: re
	valgrind --track-origins=yes ./salem_tester
re: fclean all 
