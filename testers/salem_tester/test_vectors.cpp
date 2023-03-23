#include "../../srcs/vector/vector.hpp"
#include <iostream>
#include <vector>
#include <stddef.h>

void	test_at()
{
	std::vector<int> original;
	ft::vector<int>	mine;

	for (int i = 0; i < 100; i++)
	{
		original.push_back(i);
		mine.push_back(i);
	}
	for (int i = 0; i < 100 ; i++)
	{
		std::cout << "at original " << original.at(i) << std::endl;			
		std::cout << "at mine " << mine.at(i) << std::endl;			
		
	}	
	std::cout << "back original " << original.back() << " front ";
	std::cout << original.front() << std::endl;	
	std::cout << "back mine " << mine.back() << " front ";
	std::cout << mine.front() << std::endl;
}

int main()
{
	std::cout << "Testing capcity" << std::endl;
	ft::vector<int> a;
	a.back();
	std::cout <<  a.back() << std::endl;
	std::cout << "yes empty " << a.empty() << std::endl; 
	std::cout << "NO empty " << a.empty() << std::endl; 
	// for (int i = 0; i < 100000; i++)
	// {
	// 	a.push_back(i);
	// 	std::cout <<  a[i] << " capacity = " << a.capacity() <<std::endl;
	// }
	test_at();
	return 0;

}

