# NAME = salem_tester
NAME = map_tester
# SRC =  test_vectors.cpp 
SRC =  map_ft.cpp map_std.cpp vector_ft.cpp vector_std.cpp 
# MSRC = test_map.cpp
CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -g3
# CXXFLAGS= 
CXX = c++ 
OBJ =  $(SRC:.cpp=.o)


all: $(NAME)


# $(NAME): $(OBJ)
# 	@$(CXX)  $(CXXFLAGS) $(OBJ) -o $(NAME)

ft:
	@$(CXX)  $(CXXFLAGS) map_ft.cpp -o ft_map
	@$(CXX)  $(CXXFLAGS) vector_ft.cpp -o ft_vector
std:
	@$(CXX)  $(CXXFLAGS) map_std.cpp -o std_map
	@$(CXX)  $(CXXFLAGS) vector_std.cpp -o std_vector

map: ft std
	./test_result.sh
vector: ft std 
	./test_vector
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
test: re
	@./salem_tester

mem: re
	valgrind --track-origins=yes --leak-check=full ./salem_tester
re: fclean all 
