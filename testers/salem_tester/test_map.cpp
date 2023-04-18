/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:30:31 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/18 18:34:31 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/map/map.hpp"
#include <map>

# include <utility>
# include <cassert>
# include <string>
# include <iterator>
int testpair()
{
	// Test default initialization:
	ft::pair<int, float> p;
	assert(p.first == 0);
	assert(p.second == 0.0f);

	// Test initialization with values:
	ft::pair<int, std::string> p2(42, "hello");
	assert(p2.first == 42);
	assert(p2.second == "hello");

	// Test copy construction:
	ft::pair<int, float> p3(42, 3.14f);
	ft::pair<int, float> p4(p3);
	assert(p4.first == 42);
	assert(p4.second == 3.14f);

	// Test assignment:
	ft::pair<int, float> p5(42, 3.14f);
	ft::pair<int, float> p6;
	p6 = p5;
	assert(p6.first == 42);
	assert(p6.second == 3.14f);

	// Test comparison:
	ft::pair<int, float> p7(42, 3.14f);
	ft::pair<int, float> p8(42, 3.14f);
	ft::pair<int, float> p9(42, 2.71f);
	assert(p7 == p8);
	assert(p7 != p9);

	std::cout << "All test cases passed." << std::endl;
	return 0;
}

void test_mypair()
{
	ft::pair<int, float> a(10, 11.2f);
	ft::pair<int, float> b(9, 11.2f);
	std::cout << "first = " << a.first << std::endl;
	std::cout << "second = " << a.second << std::endl;
	std::cout << "b  < a =  " << (b < a) << std::endl;
	std::cout << "a  < b =  " << (a < b) << std::endl;
}

void test_make_pair()
{
	ft::pair<int, int> foo;
	ft::pair<int, int> bar;

	foo = ft::make_pair(10, 20);
	bar = ft::make_pair(10.5, 'A'); // ok: implicit conversion from pair<double,char>

	std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
	std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
}

template <class Key, class T>
void	print_tree(ft::Node<Key, T> *print_me)
{
	if (print_me->empty)
		return ;
	print_tree(print_me->left);
	print_tree(print_me->right);
	std::cout << print_me->key_val.first << " : ";
	std::cout << print_me->key_val.second << std::endl;
}

template <class Key, class T>
void printTree(ft::Node<Key, T>  *root, std::string indent, bool last) 
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
	 void print2DUtil(ft::Node<Key, T>*root, int space) 
{
	if (root == NULL)
		return;
		space += 10;
	print2DUtil(root->right, space);
	std::cout << std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
	// std::cout << root->key_val.first  << " , h = " << root->height <<  std::endl;
	std::cout << root->key_val.first  <<  std::endl;
	for (int i = 10; i < space; i++)
		std::cout << " ";
		if (root->parent)
			std::cout << "Parent: " << root->parent->key_val.first << std::endl;
	print2DUtil(root->left, space);
}
template <class Key, class T>
void print2D(ft::Node<Key, T>  *node) {
	std::cout << "Tree:" << std::endl;
	print2DUtil(node, 0);
}

#include <unistd.h>
void	test_insert()
{
	ft::map<int, std::string> fruits;
	ft::pair<int, std::string> apple;
	for (int i = 0; i < 20; i++)
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

void	test_iterators()
{
	std::map<int, std::string> fruits;
	std::pair<int, std::string> apple;
	for (int i = 0; i < 10; i++)
	{
		apple.first = i;
		apple.second = "apple";
		std::cout << std::endl;
		fruits.insert(apple);
	}
	
	for(std::map<int, std::string>::iterator it = fruits.begin();
		it != fruits.end();
		++it)
	{
		std::cout << it->second << std::endl;
	}
}

int main()
{
	// test_iterators();
	test_insert();
}
