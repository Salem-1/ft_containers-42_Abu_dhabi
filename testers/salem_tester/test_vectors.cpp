#include "../../srcs/vector/vector.hpp"
#include <iostream>
#include <vector>
#include <stddef.h>

// void	test_at()
// {
// 	std::vector<int> original;
// 	ft::vector<int>	mine;

// 	for (int i = 0; i < 100; i++)
// 	{
// 		original.push_back(i);
// 		mine.push_back(i);
// 	}
// 	for (int i = 0; i < 100 ; i++)
// 	{
// 		std::cout << "at original " << original.at(i) << std::endl;			
// 		std::cout << "at mine " << mine.at(i) << std::endl;			
		
// 	}	
// 	std::cout << "back original " << original.back() << " front ";
// 	std::cout << original.front() << std::endl;	
// 	std::cout << "back mine " << mine.back() << " front ";
// 	std::cout << mine.front() << std::endl;
// }

// void	test_push_back()
// {
// 	ft::vector<int> a;
// 	a.back();
// 	std::cout <<  a.back() << std::endl;
// 	std::cout << "yes empty " << a.empty() << std::endl; 
// 	std::cout << "NO empty " << a.empty() << std::endl; 
// 	for (int i = 0; i < 100000; i++)
// 	{
// 		a.push_back(i);
// 		std::cout <<  a[i] << " capacity = " << a.capacity() <<std::endl;
// 	}
// };

// void	test_pop()
// {
// 	std::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 1000;i ++)
// 	{
// 		brand.push_back(i);
// 		copy.push_back(i);
// 	}
// 	for (int i = 0; i < 1000;i ++)
// 	{
// 		brand.pop_back();
// 		copy.pop_back();
// 		std::cout << brand.front() << " == " << copy.front() << std::endl;
// 		// if (brand.back() != copy.back())
// 		// 	throw (std::out_of_range("Failed pop_back()"));

// 	}
// }

// void	test_clear()
// {
// 	std::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 1000;i ++)
// 	{
// 		brand.push_back(i);
// 		copy.push_back(i);
// 	}
// 	std::cout << "Size before clear ";
// 	std::cout << brand.size() << " == " << copy.size() << std::endl;
// 	brand.clear();
// 	copy.clear();
// 	std::cout << "Size after clear ";
// 	std::cout << brand.size() << " == " << copy.size() << std::endl;
// 	std::cout << "Capacity after clear ";
// 	std::cout << brand.capacity() << " == " << copy.capacity() << std::endl;
// 	brand.get_allocator();
// 	copy.get_allocator();
// }

// void	test_equalibrium()
// {
// 	ft::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 10;i ++)
// 	{
// 		brand.push_back(i);
// 		copy.push_back(i);
// 	}
// 	// brand.push_back(1);
// 	// brand.push_back(-1);
// 	// brand.push_back(-1);
// 	if (copy == brand)
// 		std::cout << "They are equal" << std::endl;
// 	else
// 		std::cout << "Not equal" << std::endl;
// }

// void	test_begin_end()
// {
// 	ft::vector<int> a;
// 	ft::vector<int>::iterator it;
// 	for (int i = 10; i < 100; i++)
// 		a.push_back(i);
// 	for (it = a.begin(); it != a.end(); it++)
// 		std::cout<< "iterator " << *it << std::endl;
// }
// void	test_rbegin_rend()
// {
// 	ft::vector<int> a;
// 	ft::vector<int>::reverse_iterator it;
// 	for (int i = 10; i < 100; i++)
// 		a.push_back(i);
// 	for (it = a.rbegin(); it != a.rend(); it++)
// 		std::cout<< "iterator " << *it << std::endl;
// }
// void	test_crbegin_crend()
// {
// 	ft::vector<int> a;
// 	ft::vector<int>::const_reverse_iterator it;
// 	for (int i = 10; i < 100; i++)
// 		a.push_back(i);
// 	for (it = a.rbegin(); it != a.rend(); it++)
// 		std::cout<< "iterator " << *it << std::endl;
// }



// void	test_const_iter()
// {
// 	std::vector<int> a;
// 	std::vector<int>::const_iterator it;
// 	for (int i = 10; i < 100; i++)
// 		a.push_back(i);
// 	for (it = a.begin(); it != a.end(); it++)
// 		std::cout<< "iterator " << *it << std::endl;
// }

// void	test_smaller()
// {
// 	ft::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 10;i ++)
// 	{
// 		brand.push_back(0);
// 		copy.push_back(0);
// 	}
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	if (copy < brand)
// 		std::cout << "smaller" << std::endl;
// 	else
// 		std::cout << "Not smaller" << std::endl;
// }
// void	test_larger()
// {
// 	ft::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 10;i ++)
// 	{
// 		brand.push_back(0);
// 		copy.push_back(0);
// 	}
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	if (copy > brand)
// 		std::cout << "larger" << std::endl;
// 	else
// 		std::cout << "Not larger" << std::endl;
// }
// void	test_larger_or_equal()
// {
// 	ft::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 10;i ++)
// 	{
// 		brand.push_back(0);
// 		copy.push_back(0);
// 	}
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	if (copy >= brand)
// 		std::cout << "larger" << std::endl;
// 	else
// 		std::cout << "Not larger" << std::endl;
// }
// void	test_less_or_equal()
// {
// 	ft::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 10;i ++)
// 	{
// 		brand.push_back(0);
// 		copy.push_back(0);
// 	}
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	if (copy <= brand)
// 		std::cout << "larger" << std::endl;
// 	else
// 		std::cout << "Not larger" << std::endl;
// }
// void	test_not_equal()
// {
// 	ft::vector<int> brand;
// 	ft::vector<int> copy;
// 	for (int i = 0; i < 10;i ++)
// 	{
// 		brand.push_back(0);
// 		copy.push_back(0);
// 	}
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	copy.push_back(0);
// 	if (copy != brand)
// 		std::cout << "not equal" << std::endl;
// 	else
// 		std::cout << "equal" << std::endl;
// }

// void	test_insert()
// {
// 	std::vector<int> a(10, 12);
// 	std::vector<int> b(10, 12);
// 	a.insert(a.begin() + 10 , 25 );
// 	std::cout << "inserted " << a[10] << std::endl;
// }

// void	test_my_insert()
// {
// 	ft::vector<int> a;
// 	a.push_back(1);
// 	a.push_back(2);
// 	a.push_back(3);
// 	a.push_back(4);
// 	a.insert(a.begin() + 2, 5 , 5);
// 	std::cout << "inserted " << a[2] << std::endl;
// 	for ( int i =  0; i < 9; i++)
// 		std::cout << a[i] << std::endl;
// }

void	test_my_insert_iter()
{
	ft::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.insert(a.begin() + 2, 5 , 5);
	std::cout << "inserted " << a[2] << std::endl;
	for ( int i =  0; i < 9; i++)
		std::cout << a[i] << std::endl;
}

void	test_allocator_const()
{
    std::allocator<int> myAlloc; // Define an allocator object
    ft::vector<int, std::allocator<int> > myVector(myAlloc); // Create a vector object with specified allocator
    std::cout << "Vector size is: " << myVector.size() << std::endl; // Output the size of the vector
}
void	test_fill_vec_constr()
{
	ft::vector<int> a(10, 1);
	for ( int i =  0; i < 10; i++)
		std::cout << a[i] << std::endl;
}

void	test_fill_vec_iter_constr()
{
	int arr[]= {1, 2 , 3, 4};
	ft::vector<int> a(arr, arr + 4);
	arr[0] = 2;
	for ( int i =  0; i < 4; i++)
		std::cout << a[i] << std::endl;
}

void	test_assign()
{
	ft::vector<int> a;

	a.assign(10, 1);
	for ( int i =  0; i < 10; i++)
		std::cout << a[i] << std::endl;
}
void	test_assign2()
{
    ft::vector<int> myVector;

    int values[] = {1, 2, 3, 4, 5};
    myVector.assign(values, values + 5);

    std::cout << "Vector values: ";
    for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
void	test_equal_operator()
{
	ft::vector<int> a(10, 1);
	ft::vector<int>b;
	b = a;
};

void	test_copy_constructor()
{
	ft::vector<int> a(10,1);
	ft::vector<int> b(a);
	for ( int i =  0; i < 10; i++)
		std::cout << b[i] << std::endl;
}
void	test_erase()
{
   ft::vector<int> myVector(10, 1);
//    std::vector<int>::iterator its = myVector.begin();
   	myVector.erase(myVector.end() - 1);
    std::cout << "Vector values: ";
    for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
        std::cout << *it << " ";

}

void	test_erase_with_iter()
{
	//test erase(iterator first, iterator last) of std
	std::vector<int> a(10, 1);
	std::vector<int>::iterator its = a.begin();
	a.erase(its - 1, a.end());
	std::cout << "Vector values: ";
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";

}
int main()
{
	// test_erase();
	test_erase_with_iter();

}

//test iterator == const_iterator