NAME = salem_tester
SRC =  test_vectors.cpp 
CXXFLAGS= -Wall -Wextra -Werror -std=c++98
CXX = c++ 
OBJ =  $(SRC:.cpp=.o)


all: $(NAME)


$(NAME): $(OBJ)
	$(CXX)  $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
test: all
	./salem_tester

mem: re
	valgrind ./salem_tester
re: fclean all 
