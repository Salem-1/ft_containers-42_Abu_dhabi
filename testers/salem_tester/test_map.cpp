/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:30:31 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/13 13:15:38 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../srcs/map/map.hpp"
#include <map>

#include <utility>
#include <cassert>
#include <string>

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

void	test_insert()
{
	ft::map<std::string, int> fruits;
	ft::pair<std::string, int> apple;
	apple.first = "apple";
	apple.second = 10;
	fruits.insert(apple);
}
int main()
{
	test_insert();
	// fruits.tree.key = "apple";
	// fruits.tree.val = 10;
	// std::cout << "tree parent is " << fruits.tree.parent << std::endl;
	// std::cout << "tree key is " << fruits.tree.key << std::endl;
	// std::cout << "tree val is " << fruits.tree.val << std::endl;
	// testpair();
	// std::map<std::string, int>  fruits;
	// fruits["orange"] = 2;
	// fruits["orang"] = 2;
	// fruits["orane"] = 2;
	// fruits["apple"] = 2;
	// fruits["aple"] = 2;
	// fruits["a"] = 2;
	// for (std::map<std::string, int>::iterator it = fruits.begin();
	// 	it != fruits.end(); it++)
	// 	std::cout << it->first << " = " << it->second << std::endl;
}
