#include "../../srcs/vector/vector.hpp"
#include <iostream>
#include <vector>
#include <stddef.h>

int main()
{
	std::cout << "Testing capcity" << std::endl;
	std::vector<int> a;
	a.back();
	// std::cout <<  a.back() << std::endl;
	std::cout << "yes empty " << a.empty() << std::endl; 
	std::cout << "NO empty " << a.empty() << std::endl; 
	// for (int i = 0; i < 100000; i++)
	// {
	// 	a.push_back(i);
	// 	std::cout <<  a[i] << " capacity = " << a.capacity() <<std::endl;
	// }
	return 0;

}

