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

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
}


int test_swap_mli ()
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> foo(3, 15);
	TESTED_NAMESPACE::vector<TESTED_TYPE> bar(5, 42);

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_foo = foo.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator it_bar = bar.begin();

	std::cout << "BEFORE SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;

	std::cout << "foo contains:" << std::endl;
	printSize(foo);
	std::cout << "bar contains:" << std::endl;
	printSize(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << "it_foo = " << it_foo.base() << " bar.begin = " <<  bar.begin().base() << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << "it_foo = " << it_bar.base() << " bar.begin = " <<  foo.begin().base() << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;

	return (0);
}
int		rev_operators(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it_mid;

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_1;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	printSize(vct, 1);
	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	ft_eq_ope(it_0 + 3, it_mid);
	// ft_eq_ope(it_0, it_1);
	// ft_eq_ope(it_1 - 3, it_mid);
	// // const it
	// ft_eq_ope(cit_0 + 3, cit_mid);
	// ft_eq_ope(cit_0, cit_1);
	// ft_eq_ope(cit_1 - 3, cit_mid);
	// // both it
	// ft_eq_ope(it_0 + 3, cit_mid);
	// ft_eq_ope(it_mid, cit_0 + 3);
	// ft_eq_ope(it_0, cit_1);
	// ft_eq_ope(it_1, cit_0);
	// ft_eq_ope(it_1 - 3, cit_mid);
	// ft_eq_ope(it_mid, cit_1 - 3);

	return (0);
}
int		rev_mli_comp(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct;
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit = vct.begin();

	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit(it);

	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit(rit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_(it);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator crit_2(cit);

	/* error expected
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit_(crit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator rit2(cit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it2(rit);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator cit2(crit);
	*/

	std::cout << "OK" << std::endl;
	return (0);
}
int		ret2(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();
std::cout << "size, capacity = " << vct.size() << "   " <<vct.capacity() << std::endl;
	std::cout << "begin, end " << vct.begin().base() << " " << vct.end().base() << std::endl;
	std::cout << "it , ite " << it.base().base() << ", " << ite.base().base() << std::endl; 
	for (int i = 0; i < size; ++i)
    {
	   it[i] = (size - i) * 5;
	 }
	printSize(vct, true);
	std::cout << "address "<< it.base().base() << " it = " << *it << "   ,  it + 5 = ";
	it = it + 5;
	std::cout << *it << std::endl;
	std::cout << "address "<< it.base().base() << " it = " << *it << "   ,  1 + it = ";
	it = 1 + it;
	std::cout << *it << std::endl;
	std::cout << "address "<< it.base().base() << " it = " << *it << "   ,  it - 4 = ";
	it = it - 4;
	std::cout << *it << std::endl;

	std::cout << "address "<< it.base().base() << " it = " << *it << " , *(it += 2) = " << *(it += 2) << std::endl;
	std::cout << "address "<< it.base().base() << " it = " << *it << " , *(it -= 1) = " << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printSize(vct, true);
	return (0);
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
void	checkErase(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct,
					TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator const &it)
{
	static int i = 0;
	std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
	printSize(vct);
}

void test_erase_mli(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = i + 65;
	// printSize(vct);

	checkErase(vct, vct.erase(vct.begin() + 2));

	checkErase(vct, vct.erase(vct.begin()));
	checkErase(vct, vct.erase(vct.end() - 1));

	checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
	checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

	vct.push_back(15);
	vct.push_back(16);
	printSize(vct);
	checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

	vct.push_back(17);
	vct.push_back(18);
	vct.push_back(19);
	vct.push_back(20);
	printSize(vct);
	checkErase(vct, vct.erase(vct.begin(), vct.end()));

}

void test_copy_constructor_mli()
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	printSize(vct);
	printSize(vct_range);
	printSize(vct_copy);

	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	printSize(vct);
	printSize(vct_range);
	printSize(vct_copy);
}

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

int		test_at_mli(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);

	for (unsigned long int i = 0; i < vct.size(); ++i)
	{
		vct.at(i) = (vct.size() - i) * 3;
		std::cout << "vct.at(): " << vct.at(i) << " | ";
		std::cout << "vct[]: " << vct[i] << std::endl;
	}
	// printSize(vct);

	TESTED_NAMESPACE::vector<TESTED_TYPE> const vct_c(vct);

	std::cout << "front(): " << vct.front() << " " << vct_c.front() << std::endl;
	std::cout << "back(): " << vct.back() << " " <<  vct_c.back() << std::endl;

	try {
		vct.at(10) = 42;
	}
	catch (std::out_of_range &e) {
		std::cout << "Catch out_of_range exception!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Catch exception: " << e.what() << std::endl;
	}
	return (0);
}
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
	ft::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 10;i ++)
	{
		brand.push_back(i);
		copy.push_back(i);
	}
	// brand.push_back(1);
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
void	test_crbegin_crend()
{
	ft::vector<int> a;
	ft::vector<int>::const_reverse_iterator it;
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

void	test_smaller()
{
	ft::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 10;i ++)
	{
		brand.push_back(0);
		copy.push_back(0);
	}
	copy.push_back(0);
	copy.push_back(0);
	copy.push_back(0);
	if (copy < brand)
		std::cout << "smaller" << std::endl;
	else
		std::cout << "Not smaller" << std::endl;
}
void	test_larger()
{
	ft::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 10;i ++)
	{
		brand.push_back(0);
		copy.push_back(0);
	}
	copy.push_back(0);
	copy.push_back(0);
	copy.push_back(0);
	if (copy > brand)
		std::cout << "larger" << std::endl;
	else
		std::cout << "Not larger" << std::endl;
}
void	test_larger_or_equal()
{
	ft::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 10;i ++)
	{
		brand.push_back(0);
		copy.push_back(0);
	}
	copy.push_back(0);
	copy.push_back(0);
	copy.push_back(0);
	if (copy >= brand)
		std::cout << "larger" << std::endl;
	else
		std::cout << "Not larger" << std::endl;
}
void	test_less_or_equal()
{
	ft::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 10;i ++)
	{
		brand.push_back(0);
		copy.push_back(0);
	}
	copy.push_back(0);
	copy.push_back(0);
	copy.push_back(0);
	if (copy <= brand)
		std::cout << "larger" << std::endl;
	else
		std::cout << "Not larger" << std::endl;
}
void	test_not_equal()
{
	ft::vector<int> brand;
	ft::vector<int> copy;
	for (int i = 0; i < 10;i ++)
	{
		brand.push_back(0);
		copy.push_back(0);
	}
	copy.push_back(0);
	copy.push_back(0);
	copy.push_back(0);
	if (copy != brand)
		std::cout << "not equal" << std::endl;
	else
		std::cout << "equal" << std::endl;
}

void	test_insert()
{
	std::vector<int> a(10, 12);
	std::vector<int> b(10, 12);
	a.insert(a.begin() + 10 , 25 );
	std::cout << "inserted " << a[10] << std::endl;
}

void	test_my_insert()
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
	ft::vector<int> a(10, 1);
	ft::vector<int>::iterator its = a.begin();
	a.erase(its + 1, a.end());
	std::cout << "Vector values: ";
	for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it)
		std::cout << *it << " ";

}
void	test_swap()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
};
void	test_non_member_swap()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
};


int main()
{
	std::cout << " -- " << std::endl;
	;
	std::cout << " -	rev_operators()- " << std::endl;
		rev_operators();
	std::cout << " -rev_mli_comp()- " << std::endl;
	rev_mli_comp();
	std::cout << " -ret2()- " << std::endl;
	ret2();
	std::cout << " -test_insert_mli()- " << std::endl;
	test_insert_mli();
	std::cout << " -test_erase_mli()- " << std::endl;
	test_erase_mli();
	std::cout << " -test_copy_constructor_mli()- " << std::endl;
	test_copy_constructor_mli();
	std::cout << " -test_biderection_at()- " << std::endl;
	test_biderection_at();
	std::cout << " -test_at_mli()- " << std::endl;
	test_at_mli();
	std::cout << " -test_at()- " << std::endl;
	test_at();
	std::cout << " -test_push_back()- " << std::endl;
	test_push_back();
	std::cout << " -test_pop()- " << std::endl;
	test_pop();
	std::cout << " -test_clear()- " << std::endl;
	test_clear();
	std::cout << " -test_equalibrium()- " << std::endl;
	test_equalibrium();
	std::cout << " -test_begin_end()- " << std::endl;
	test_begin_end();
	std::cout << " -test_rbegin_rend()- " << std::endl;
	test_rbegin_rend();
	std::cout << " -test_crbegin_crend()- " << std::endl;
	test_crbegin_crend();
	std::cout << " -test_const_iter()- " << std::endl;
	test_const_iter();
	std::cout << " -test_smaller()- " << std::endl;
	test_smaller();
	std::cout << " -test_larger()- " << std::endl;
	test_larger();
	std::cout << " -test_larger_or_equal()- " << std::endl;
	test_larger_or_equal();
	std::cout << " -test_less_or_equal()- " << std::endl;
	test_less_or_equal();
	std::cout << " -test_not_equal()- " << std::endl;
	test_not_equal();
	std::cout << " -test_insert()- " << std::endl;
	test_insert();
	std::cout << " -test_my_insert()- " << std::endl;
	test_my_insert();
	std::cout << " -test_my_insert_iter()- " << std::endl;
	test_my_insert_iter();
	std::cout << " -test_allocator_const()- " << std::endl;
	test_allocator_const();
	std::cout << " -test_fill_vec_constr()- " << std::endl;
	test_fill_vec_constr();
	std::cout << " -test_fill_vec_iter_constr()- " << std::endl;
	test_fill_vec_iter_constr();
	std::cout << " -test_assign()- " << std::endl;
	test_assign();
	std::cout << " -test_assign2()- " << std::endl;
	test_assign2();
	std::cout << " -test_equal_operator()- " << std::endl;
	test_equal_operator();
	std::cout << " -test_copy_constructor()- " << std::endl;
	test_copy_constructor();
	std::cout << " -test_erase()- " << std::endl;
	test_erase();
	std::cout << " -test_erase_with_iter()- " << std::endl;
	test_erase_with_iter();
	std::cout << " -test_swap()- " << std::endl;
	test_swap();
	std::cout << " -test_non_member_swap()- " << std::endl;
	test_non_member_swap();

}

//test iterator == const_iterator