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

void	test_push_back()
{
	ft::vector<int> a;
	a.back();
	std::cout <<  a.back() << std::endl;
	std::cout << "yes empty " << a.empty() << std::endl; 
	std::cout << "NO empty " << a.empty() << std::endl; 
	for (int i = 0; i < 100000; i++)
	{
		a.push_back(i);
		std::cout <<  a[i] << " capacity = " << a.capacity() <<std::endl;
	}
};

void	test_pop()
{
	std::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 1000;i ++)
	{
		brand.push_back(i);
		copy.push_back(i);
	}
	for (int i = 0; i < 1000;i ++)
	{
		brand.pop_back();
		copy.pop_back();
		std::cout << brand.front() << " == " << copy.front() << std::endl;
		// if (brand.back() != copy.back())
		// 	throw (std::out_of_range("Failed pop_back()"));

	}
}

void	test_clear()
{
	std::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 1000;i ++)
	{
		brand.push_back(i);
		copy.push_back(i);
	}
	std::cout << "Size before clear ";
	std::cout << brand.size() << " == " << copy.size() << std::endl;
	brand.clear();
	copy.clear();
	std::cout << "Size after clear ";
	std::cout << brand.size() << " == " << copy.size() << std::endl;
	std::cout << "Capacity after clear ";
	std::cout << brand.capacity() << " == " << copy.capacity() << std::endl;
	brand.get_allocator();
	copy.get_allocator();
}

void	test_equalibrium()
{
	std::vector<int> brand;
	std::vector<int> copy;
	for (int i = 0; i < 10;i ++)
	{
		brand.push_back(i);
		copy.push_back(i);
	}
	brand.push_back(1);
	// brand.push_back(-1);
	// brand.push_back(-1);
	if (copy == brand)
		std::cout << "They are equal" << std::endl;
	else
		std::cout << "Not equal" << std::endl;
}
void	test_begin_end()
{
	ft::vector<int> a;
	ft::vector<int>::iterator it;
	for (int i = 10; i < 100; i++)
		a.push_back(i);
	for (it = a.begin(); it != a.end(); it++)
		std::cout<< "iterator " << *it << std::endl;
}
void	test_rbegin_rend()
{
	ft::vector<int> a;
	ft::vector<int>::reverse_iterator it;
	for (int i = 10; i < 100; i++)
		a.push_back(i);
	for (it = a.rbegin(); it != a.rend(); it++)
		std::cout<< "iterator " << *it << std::endl;
}



void	test_const_iter()
{
	std::vector<int> a;
	std::vector<int>::const_iterator it;
	for (int i = 10; i < 100; i++)
		a.push_back(i);
	for (it = a.begin(); it != a.end(); it++)
		std::cout<< "iterator " << *it << std::endl;
}
int main()
{
	test_const_iter();
}

