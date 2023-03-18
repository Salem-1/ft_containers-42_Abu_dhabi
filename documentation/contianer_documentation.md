# Contianers
Bism Ellah Elrahman Al Raheem


# Specifications:

1-Turn files into:
	
	ft_vector.hpp
	ft_map.hpp
	ft_stack.hpp

2-Implement:

	std::iterator_triats
	std::reverse_iterators
	std::enable_if
	std::is_integral
	std::equal and/or std::lexicographical_compare
	std::pair
	std::make_pair

3-Implement public functions as the std, every thing else must be private or protected
4-Implement member, nonmember functions, overloads
5-Must follow original naming exactly
6-Implement iterators vectors and map
7-Must use std::allocator
8-For non member function the friend use is allowed
9-In map std::map::value_compare allowed
10-Produce two test binaries?
11-Compare outputs and timing, Can be up to 20 times slower than std::contianer?
	
# Questions:
-What is the difference bettween vector, map and stack?
Vector like an array it can grow and shrink, 
Stack: use LIFO, built on deque but we are going to build it on vectors inshalla
Maps: Store values in key value paris with ability for insertion, deletion and search.

-What is std:iterator_triats?
Determine value type, pointer type and category
-What are std::reverese_iterators?
-What is std::enable_if?
Used to enable or disable template function based on compile time boolean expression
-What is lexicographical_compare(comparing alphabitically)
Compare elements one by one till found inequality 
-What is std::is_integral?
determine weather given type is integer or not
-What is std::equal?
takes two iteratos of two containers and determine weather they are equal
-What is std::pari?
Function template represents pair of values that can be different types
-What is std::make_pair?
Constructor for std::pair, used for insertion in map and unordered map
-What is the use and functionality of all of the above, why do we need them, how will Earth look like without them?
-What is std::allocator, why and how to use it?
-What are the member and non member functions of vectors, maps, stack?
-What is friend, and who is my friend>
-What is std::map::value_compare
-How to make the test that compare the leaks and time?


# Refrences:
https://www.cplusplus.com/
https://cppreference.com/