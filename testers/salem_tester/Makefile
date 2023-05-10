# NAME = salem_tester
NAME = map_tester
# SRC =  test_vectors.cpp 
SRC =  map_ft.cpp map_std.cpp vector_ft.cpp vector_std.cpp test_stack.cpp stack_ft.cpp stack_std.cpp
# MSRC = test_map.cpp
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -g3
# CXXFLAGS= 
CXX = c++ 
OBJ =  $(SRC:.cpp=.o)


all: $(NAME)


# $(NAME): $(OBJ)
# 	@$(CXX)  $(CXXFLAGS) $(OBJ) -o $(NAME)
stack_old:
	@$(CXX)  $(CXXFLAGS) test_stack.cpp -o stack_test
	./stack_test
ft:
	@$(CXX)  $(CXXFLAGS) map_ft.cpp -o ft_map
	@$(CXX)  $(CXXFLAGS) vector_ft.cpp -o ft_vector
	@$(CXX)  $(CXXFLAGS) stack_ft.cpp -o ft_stack
std:
	@$(CXX)  $(CXXFLAGS) map_std.cpp -o std_map
	@$(CXX)  $(CXXFLAGS) vector_std.cpp -o std_vector
	@$(CXX)  $(CXXFLAGS) stack_std.cpp -o std_stack

map: ft std
	./test_result.sh
vector: ft std 
	./test_vector_result.sh
stack: ft std 
	./test_stack.sh

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ft_map ft_vector std_stack std_map std_vector ft_stack a.out


	
test: re
	@./salem_tester

mem: re
	valgrind --track-origins=yes --leak-check=full ./salem_tester
re: fclean all 
