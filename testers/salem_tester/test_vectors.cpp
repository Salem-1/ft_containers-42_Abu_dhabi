#include "../../srcs/vector/vector.hpp"
#include <iostream>
#include <vector>
#include <stddef.h>
#include <list>

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	test_insert_mli()
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct2;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct3;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	printSize(vct);

	vct2.insert(vct2.end() , 42);
	printSize(vct2);
	vct2.insert(vct2.begin(), 2, 21);
	printSize(vct2);

	vct2.insert(vct2.end() - 2, 42);
	printSize(vct2);

	vct2.insert(vct2.end(), 2, 84);
	printSize(vct2);

	vct2.resize(4);
	printSize(vct2);

	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	printSize(vct2);

	printSize(vct);

	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	printSize(vct3);
}
// void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
// 					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
// {
// 	static int i = 0;
// 	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
// 	printSize(vct);
// }

// void test_erase_mli(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 		vct[i] = std::string((vct.size() - i), i + 65);
// 	// printSize(vct);

// 	checkErase(vct, vct.erase(vct.begin() + 2));

// 	checkErase(vct, vct.erase(vct.begin()));
// 	checkErase(vct, vct.erase(vct.end() - 1));

// 	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
// 	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

// 	vct.push_back("Hello");
// 	vct.push_back("Hi there");
// 	printSize(vct);
// 	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

// 	vct.push_back("ONE");
// 	vct.push_back("TWO");
// 	vct.push_back("THREE");
// 	vct.push_back("FOUR");
// 	printSize(vct);
// 	checkErase(vct, vct.erase(vct.begin(), vct.end()));

// }

// void test_copy_constructor_mli()
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

// 	std::cout << "len: " << (ite - it) << std::endl;
// 	for (; it != ite; ++it)
// 		*it = (ite - it);

// 	it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 5;

// 	it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 7;
// 	vct_copy.push_back(42);
// 	vct_copy.push_back(21);

// 	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);

// 	vct = vct_copy;
// 	vct_copy = vct_range;
// 	vct_range.clear();

// 	std::cout << "\t-- PART TWO --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);
// }

int		test_biderection_at(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}

// int		test_at_mli(void)
// {
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

// 	for (unsigned long int i = 0; i < vct.size(); ++i)
// 	{
// 		vct.at(i) = (vct.size() - i) * 3;
// 		std::cout << "vct.at(): " << vct.at(i) << " | ";
// 		std::cout << "vct[]: " << vct[i] << std::endl;
// 	}
// 	// printSize(vct);

// 	TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

// 	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
// 	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

// 	try {
// 		vct.at(10) = 42;
// 	}
// 	catch (std::out_of_range &e) {
// 		std::cout << "Catch out_of_range exception!" << std::endl;
// 	}
// 	catch (std::exception &e) {
// 		std::cout << "Catch exception: " << e.what() << std::endl;
// 	}
// 	return (0);
// }
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

// void	test_my_insert_iter()
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

// void	test_allocator_const()
// {
//     std::allocator<int> myAlloc; // Define an allocator object
//     ft::vector<int, std::allocator<int> > myVector(myAlloc); // Create a vector object with specified allocator
//     std::cout << "Vector size is: " << myVector.size() << std::endl; // Output the size of the vector
// }
// void	test_fill_vec_constr()
// {
// 	ft::vector<int> a(10, 1);
// 	for ( int i =  0; i < 10; i++)
// 		std::cout << a[i] << std::endl;
// }

// void	test_fill_vec_iter_constr()
// {
// 	int arr[]= {1, 2 , 3, 4};
// 	ft::vector<int> a(arr, arr + 4);
// 	arr[0] = 2;
// 	for ( int i =  0; i < 4; i++)
// 		std::cout << a[i] << std::endl;
// }

// void	test_assign()
// {
// 	ft::vector<int> a;

// 	a.assign(10, 1);
// 	for ( int i =  0; i < 10; i++)
// 		std::cout << a[i] << std::endl;
// }
// void	test_assign2()
// {
//     ft::vector<int> myVector;

//     int values[] = {1, 2, 3, 4, 5};
//     myVector.assign(values, values + 5);

//     std::cout << "Vector values: ";
//     for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }
// void	test_equal_operator()
// {
// 	ft::vector<int> a(10, 1);
// 	ft::vector<int>b;
// 	b = a;
// };

// void	test_copy_constructor()
// {
// 	ft::vector<int> a(10,1);
// 	ft::vector<int> b(a);
// 	for ( int i =  0; i < 10; i++)
// 		std::cout << b[i] << std::endl;
// }
// void	test_erase()
// {
//    ft::vector<int> myVector(10, 1);
// //    std::vector<int>::iterator its = myVector.begin();
//    	myVector.erase(myVector.end() - 1);
//     std::cout << "Vector values: ";
//     for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
//         std::cout << *it << " ";

// }

// void	test_erase_with_iter()
// {
// 	//test erase(iterator first, iterator last) of std
// 	ft::vector<int> a(10, 1);
// 	ft::vector<int>::iterator its = a.begin();
// 	a.erase(its + 1, a.end());
// 	std::cout << "Vector values: ";
// 	for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it)
// 		std::cout << *it << " ";

// }
// void	test_swap()
// {
// 	std::vector<int> foo (3,100);   // three ints with a value of 100
//   std::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
// };
// void	test_non_member_swap()
// {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
// };


int main()
{

	test_insert_mli();

}

//test iterator == const_iterator