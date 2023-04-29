/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:30:31 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/19 06:40:03 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/map/map.hpp"
#include <map>

# include <utility>
# include <cassert>
# include <string>
# include <iterator>
# define TESTED_TYPE ft
# define N 10
int testpair()
{
	// Test default initialization:
	TESTED_TYPE::pair<int, float> p;
	assert(p.first == 0);
	assert(p.second == 0.0f);

	// Test initialization with values:
	TESTED_TYPE::pair<int, std::string> p2(42, "hello");
	assert(p2.first == 42);
	assert(p2.second == "hello");

	// Test copy construction:
	TESTED_TYPE::pair<int, float> p3(42, 3.14f);
	TESTED_TYPE::pair<int, float> p4(p3);
	assert(p4.first == 42);
	assert(p4.second == 3.14f);

	// Test assignment:
	TESTED_TYPE::pair<int, float> p5(42, 3.14f);
	TESTED_TYPE::pair<int, float> p6;
	p6 = p5;
	assert(p6.first == 42);
	assert(p6.second == 3.14f);

	// Test comparison:
	TESTED_TYPE::pair<int, float> p7(42, 3.14f);
	TESTED_TYPE::pair<int, float> p8(42, 3.14f);
	TESTED_TYPE::pair<int, float> p9(42, 2.71f);
	assert(p7 == p8);
	assert(p7 != p9);

	std::cout << "All test cases passed." << std::endl;
	return 0;
}

void test_mypair()
{
	TESTED_TYPE::pair<int, float> a(10, 11.2f);
	TESTED_TYPE::pair<int, float> b(9, 11.2f);
	std::cout << "first = " << a.first << std::endl;
	std::cout << "second = " << a.second << std::endl;
	std::cout << "b  < a =  " << (b < a) << std::endl;
	std::cout << "a  < b =  " << (a < b) << std::endl;
}

void test_make_pair()
{
	TESTED_TYPE::pair<int, int> foo;
	TESTED_TYPE::pair<int, int> bar;

	foo = TESTED_TYPE::make_pair(10, 20);
	bar = TESTED_TYPE::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}

template <class Key, class T>
void	print_tree(TESTED_TYPE::Node<Key, T> *print_me)
{
	if (print_me->empty)
		return ;
	print_tree(print_me->left);
	print_tree(print_me->right);
	std::cout << print_me->key_val.first << " : ";
	std::cout << print_me->key_val.second << std::endl;
}

template <class Key, class T>
void printTree(TESTED_TYPE::Node<Key, T>  *root, std::string indent, bool last) 
{
  if (root != NULL) {
    std::cout << indent;
    if (last) {
      std::cout << "R----";
      indent += "   ";
    } else {
     std:: cout << "L----";
      indent += "|  ";
    }
    std::cout << root->key_val.first << std::endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
  
}
template <class Key, class T>
	 void print2DUtil(TESTED_TYPE::Node<Key, T>*root, int space) 
{
	if (root == NULL)
		return;
	space += 10;
	print2DUtil(root->right, space);
	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	// std::cout << root->key_val.first  << " , h = " << root->height <<  std::endl;
	std::cout << root->key_val.first  << " , height = " << root->height <<   std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	if (root->parent)
		std::cout << "Parent: " << root->parent->key_val.first << std::endl;
	print2DUtil(root->left, space);
}
template <class Key, class T>
void print2D(TESTED_TYPE::Node<Key, T>  *node) {
	std::cout << "Tree:" << std::endl;
	print2DUtil(node, 0);
}

#include <unistd.h>
void	test_insert()
{
	TESTED_TYPE::map<int, std::string> fruits;
	TESTED_TYPE::pair<int, std::string> apple;

	for (int i = 0; i < N; i++)
	{
		apple.first = i;
		apple.second = "apple";
		std::cout << std::endl;
		fruits.insert(apple);
		// std::cout << "\n----------------------------------------\n" << std::endl;
		// sleep(i);
	}
	// printTree(fruits._tree, " ", true);
		print2D(fruits._tree);
	// fruits.test_less();
		// apple.first = 40;
		// fruits.insert(apple);
		// apple.first = 50;
		// fruits.insert(apple);
		// apple.first = 60;
		// fruits.insert(apple);
		// apple.first = 70;
		// fruits.insert(apple);
}

template <class Key, class T>
void my_map_print(TESTED_TYPE::Node<Key, T> *root) 
{
	if (!root)
		return;
	my_map_print(root->left);
	my_map_print(root->right);
	std::cout << "key = " << root->key_val.first;
	if (root->parent)
		std::cout << " parent = " << root->parent->key_val.first << std::endl;
		
}

void	test_iterators()
{
	TESTED_TYPE::map<int, std::string> fruits;
	TESTED_TYPE::pair<int, std::string> apple;
	for (int i = 0; i < N; i++)
	{
		apple.first = i;
		apple.second = "apple";
		// std::cout << std::endl;
		fruits.insert(apple);
	// my_map_print(fruits._tree);

	}
	// my_map_print(fruits._tree);
	print2D(fruits._tree);
	TESTED_TYPE::map<int, std::string>::iterator it;
	it = fruits.begin();
	std::cout << "Begin add " << &it << std::endl;
	std::cout << "Begin add " << it->first << std::endl;
		// std::cout << it->first << std::endl; 
	for (int i = 0; i < N - 1 ; i++)
	{
		std::cout << (++it)->first << std::endl; 
		// std::cout << (it)->first << std::endl; 
	}
	// it = fruits.begin();
	// --it;
	it -= 3;
	 std::cout << "end add " << it->first << std::endl ;
	it -= -3;
	 std::cout << "end add " << it->first << std::endl ;
	// ++it;

}

void 	test_iterators_operators()
{
	TESTED_TYPE::map<int, std::string> fruits;
	TESTED_TYPE::map<int, std::string> veg;
	TESTED_TYPE::pair<int, std::string> apple;
	TESTED_TYPE::pair<int, std::string> carrot;
	for (int i = 0; i < N; i++)
	{
		apple.first = i;
		carrot.first = i;
		apple.second = "apple";
		carrot.second = "Tomato";
		// std::cout << std::endl;
		fruits.insert(apple);
		veg.insert(carrot);
	// my_map_print(fruits._tree);

	}
	// my_map_print(fruits._tree);
	// print2D(fruits._tree);
	TESTED_TYPE::map<int, std::string>::iterator it;
	it = fruits.begin();
	TESTED_TYPE::map<int, std::string>::iterator it2;
	it2 = veg.begin();
	// std::cout << "Begin add " << &it << std::endl;
	// std::cout << "Begin add " << it->first << std::endl;
		// std::cout << it->first << std::endl; 
	// std::cout << "it [] " << it[3]->first << std::endl;
	for (int i = 0; i < N - 1 ; i++)
	{
		++ it2;
		// TESTED_TYPE::map<int, std::string>::iterator tmp = it + it2;
		// std::cout << tmp->first << std::endl; 
		++it; 
		// std::cout << (it)->first << std::endl; 
	}
}


void	original_insert_test()
{
	TESTED_TYPE::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( TESTED_TYPE::pair<char,int>('a',100) );
	mymap.insert ( TESTED_TYPE::pair<char,int>('z',200) );	
	TESTED_TYPE::pair<TESTED_TYPE::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( TESTED_TYPE::pair<char,int>('z',500) );
	// if (ret.second==false) {
	//   std::cout << "element 'z' already existed";
	//   std::cout << " with a value of " << ret.first->second << '\n';
	// }	
	// second insert function version (with hint position):
	TESTED_TYPE::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, TESTED_TYPE::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, TESTED_TYPE::pair<char,int>('c',400));  // no max efficiency inserting	
	// TESTED_TYPE::map<char,int> anothermap;
	// anothermap.insert(mymap.begin(), mymap.find('c'));	
	// it = mymap.begin();
	for (it=mymap.begin(); it != mymap.end(); ++it)
	  std::cout << it->first << " => " << it->second << '\n';	
	// std::cout << "anothermap contains:\n";
	// for (it=anothermap.begin(); it!=anothermap.end(); ++it)
	//   std::cout << it->first << " => " << it->second << '\n';
	it = mymap.end();
	std::cout << "end (end, start)" << it.get_end() << ", " << it.get_before_start() <<  std::endl;
	it--;
	std::cout << "before decrement (end, start)" << it.get_end() << ", " << it.get_before_start() <<  std::endl;
	std::cout << "last item = "<< it->first << " => " << it->second << '\n';	
	it = mymap.begin();
	it--;
	std::cout << "before Begin (end, start)" << it.get_end() << ", " << it.get_before_start() <<  std::endl;
	it++;
	std::cout << "after increment (end, start)" << it.get_end() << ", " << it.get_before_start() <<  std::endl;
	std::cout << "first item = "<< it->first << " => " << it->second << '\n';	
}
void	test_access_operator()
{
	TESTED_TYPE::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( TESTED_TYPE::pair<char,int>('a',100) );
	mymap.insert ( TESTED_TYPE::pair<char,int>('z',200) );	
	TESTED_TYPE::pair<TESTED_TYPE::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( TESTED_TYPE::pair<char,int>('z',500) );
	// second insert function version (with hint position):
	TESTED_TYPE::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, TESTED_TYPE::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, TESTED_TYPE::pair<char,int>('c',400));  // no max efficiency inserting	
	TESTED_TYPE::map<char,int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));	
	it = mymap.begin();
	mymap['x'] = 1;
	std::cout << "second of x = " << mymap['x'] << std::endl;
	for (it=mymap.begin(); it != mymap.end(); ++it)
	  std::cout << it->first << " => " << it->second << '\n';	
	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
	  std::cout << it->first << " => " << it->second << '\n';
}

void	test_copy_constructor()
{
	TESTED_TYPE::map<char,int> first;
  	TESTED_TYPE::map<char,int> second;

  	first['x']=8;
  	first['y']=16;
  	first['z']=32;

  	second=first;                // second now contains 3 ints
  	first=TESTED_TYPE::map<char,int>();  // and first is now empty

  	std::cout << "Size of first: " << first.size() << '\n';
  	std::cout << "Size of second: " << second.size() << '\n';
}

void test_begin()
{
	TESTED_TYPE::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (TESTED_TYPE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}

void test_end()
{
 TESTED_TYPE::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (TESTED_TYPE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

void	test_rbegin()
{
	 
	  ft::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  ft::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';

}

int main()
{
    // std::cout << " -- " << std::endl;
    // std::cout << " -    original_insert_test();- " << std::endl;
	// original_insert_test();;
    // std::cout << " -    test_insert();- " << std::endl;
	// test_insert();;
    // std::cout << " -    test_iterators();- " << std::endl;
	// test_iterators();;
    // std::cout << " -    test_iterators_operators();- " << std::endl;
	// test_iterators_operators();;
    // std::cout << " -    test_access_operator();- " << std::endl;
	// test_access_operator();;
    // std::cout << " -    test_copy_constructor();- " << std::endl;
	// test_copy_constructor();;
    // std::cout << " -    test_begin();- " << std::endl;
	// test_begin();;
    // std::cout << " -    test_end();- " << std::endl;
	// test_end();;
    // std::cout << " -    test_copy_constructor();- " << std::endl;
	// test_copy_constructor();;
    std::cout << " -    test_rbegin();- " << std::endl;
	test_rbegin();;
    // std::cout << " -    test_rend();- " << std::endl;
	// test_rend();;
}































