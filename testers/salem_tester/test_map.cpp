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
	if (root && root->parent)
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
	// print2D(fruits._tree);
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
  ft::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

void test_end()
{
  ft::map<char,int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  ft::map<char,int>::iterator it=mymap.begin();
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

void	test_rbegin()
{
	 
 std::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  std::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';

}

void	test_rend()
{
	std::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  std::map<char,int>::reverse_iterator rit;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
}

void	test_empty()
{
	 ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    // mymap.erase(mymap.begin());
  }

}

void	test_size()
{
	ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  std::cout << "mymap.size() is " << mymap.size() << '\n';

}

void	test_max_size()
{
  int i;
  std::map<int,int> mymap;

	std::cout << "max size is " << mymap.max_size() << std::endl;
  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";

}

void	test_original_delete()
{
	 std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;

  it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  
  mymap.erase(it);
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

}

template <class k, class t>
void	iterator_vis(typename ft::map<k, t> &vis)
{
	for (typename ft::map<k, t>::iterator it = vis.begin(); it != vis.end(); it++)
		std::cout << it->first << "  =>  " << it->second << std::endl;
}
void	test_delete()
{
	TESTED_TYPE::map<int, std::string> fruits;
	TESTED_TYPE::pair<int, std::string> apple;
	int n = 1000;
	for (int i = 0; i < n; i++)
	{
		apple.first = i;
		apple.second = "apple";
		std::cout << std::endl;
		fruits.insert(apple);
		// std::cout << "\n----------------------------------------\n" << std::endl;
		// sleep(i);
	}
	// std::cout <<"before deletion" << std::endl;
	// printTree(fruits._tree, " ", false);
	// std::cout << "\n\n\n";
	print2D(fruits._tree);

	// TESTED_TYPE::map<int, std::string>::iterator it;
		TESTED_TYPE::map<int, std::string>::iterator it;
	// while (!fruits.empty())
	// {
	// 	std::cout << "map empty = " << fruits.empty() << std::endl;
		for (int i = 0; i < n; i++)
		{
			// int i = -2;
			//---------------//
			std::cout << "finding " << i << std::endl; 
			it = fruits.find(i);
			std::cout << "found " << i << std::endl; 
			if (it == fruits.end())
				std::cout << "item not in the map " << std::endl;
			if (it != fruits.end())
			{
					// sleep(2);
				if (1)
				{
					std::cout << "Deleting " << i << std::endl;
					fruits.erase(it);
					usleep(1000);
					if (i > n - 5)
						print2D(fruits._tree);
				}
			// iterator_vis<int, std::string>(fruits);
			}
			else
				std::cout << i << " is not root, will not delete it for now" << std::endl;
		}
	// }
}

void	original_test_erase()
{
 	 std::map<char,int> mymap;
 	 std::map<char,int>::iterator it;

 	 // insert some values:
 	 mymap['a']=10;
 	 mymap['b']=20;
 	 mymap['c']=30;
 	 mymap['d']=40;
 	 mymap['e']=50;
 	 mymap['f']=60;

 	 it=mymap.find('b');
 	 mymap.erase (it);                   // erasing by iterator

 	 mymap.erase ('c');                  // erasing by key

 	 it=mymap.find ('e');
 	 mymap.erase ( it, mymap.end() );    // erasing by range

 	//  // show content:
 	 for (it=mymap.begin(); it!=mymap.end(); ++it)
 	   std::cout << it->first << " => " << it->second << '\n';


}

void	test_accessor()
{
	ft::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';

  std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}
void	test_at()
{
 ft::map<std::string,int> mymap;
 
	mymap["alpha"] = 0;
	mymap["beta"] = 0;
	mymap["gamma"] = 0;

  mymap.at("alpha") = 10;
  mymap.at("beta") = 20;
  mymap.at("gamma") = 30;

	ft::map<std::string,int>::iterator it = mymap.begin();

  for (it = mymap.begin(); it != mymap.end(); it++) {
    std::cout << it->first << ": " << it->second << '\n';
  }

}

void	test_swap()
{
	ft::map<char,int> foo,bar;

  	foo['x']=100;
  	foo['y']=200;

  	bar['a']=11;
  	bar['b']=22;
  	bar['c']=33;

  	foo.swap(bar);

  	std::cout << "foo contains:\n";
  	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  	  std::cout << it->first << " => " << it->second << '\n';

  	std::cout << "bar contains:\n";
  	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
  	  std::cout << it->first << " => " << it->second << '\n';
}

void	test_equal()
{
	ft::map<char,int> first;
	ft::map<char,int> second;

  	first['x']=8;
  	first['y']=16;
  	first['z']=32;

  	second = first;                // second now contains 3 ints
  	first = ft::map<char,int>();  // and first is now empty

  	std::cout << "Size of first: " << first.size() << '\n';
  	std::cout << "Size of second: " << second.size() << '\n';
}

void	test_clear()
{
	  std::map<char,int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;

  std::cout << "mymap contains:\n";
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
}
void	test_comp()
{
	 ft::map<char,int> mymap;

  ft::map<char,int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  std::cout << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';
}

void	test_value_comp()
{
  std::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  std::cout << "mymap contains:\n";

  std::pair<char,int> highest = *(--mymap.end());          // last element

  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );
}

void	test_count()
{
	std::map<char,int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c = 'a'; c < 'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c) > 0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
}

void	test_allocator()
{
	int psize;
  ft::map<char,int> mymap;
  ft::pair<const char,int>* p;

  // allocate an array of 5 elements using mymap's allocator:
  p=mymap.get_allocator().allocate(5);

  // assign some values to array
  psize = sizeof(ft::map<char,int>::value_type)*5;

  std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  mymap.get_allocator().deallocate(p,5);
}

void	test_square()
{
	ft::map<int, std::string> mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
}

#define T1 float
#define T2 int
#include <list>
typedef ft::pair<const T1, T2> T3;
void 	test_range_rev_iter_const()
{


	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(2.5 - i, (i + 1) * 7));

	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::reverse_iterator it(mp.rbegin());
	ft::map<T1, T2>::const_reverse_iterator ite(mp.rbegin());
	it++;
	ite++;

}
void	test_find()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	  mymap['a']=50;
	  mymap['b']=100;
	  mymap['c']=150;
	  mymap['d']=200;

	  it = mymap.find('b');
	  if (it != mymap.end())
	    mymap.erase (it);

	ft::map<char,int>::const_iterator ite = mymap.find('a');
	  // print content:
	  std::cout << "elements in mymap:" << '\n';
	  std::cout << "a => " << ite->second << '\n';
	  std::cout << "a => " << mymap.find('a')->second << '\n';
	  std::cout << "c => " << mymap.find('c')->second << '\n';
	  std::cout << "d => " << mymap.find('d')->second << '\n';
}

void	tet_lower_upper_bound()
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow,itup;

 	 mymap['a']=20;
 	 mymap['b']=40;
 	 mymap['c']=60;
 	 mymap['d']=80;
 	 mymap['e']=100;

 	 itlow=mymap.lower_bound ('b');  // itlow points to b
 	std::map<char,int>::const_iterator it=mymap.lower_bound ('b');  // itlow points to b
	 std::cout << "const " << it->first << " => " << it->second << std::endl;
 	std::map<char,int>::const_iterator itu=mymap.upper_bound ('d');  // itlow points to b
 	 itup=mymap.upper_bound ('d');   // itup points to e (not d!)
	 std::cout << "const " << itu->first << " => " << itu->second << std::endl;

 	 mymap.erase(itlow,itup);        // erases [itlow,itup)

 	 // print content:
 	 for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
 	   std::cout << it->first << " => " << it->second << '\n';

}
void	test_equal_range()
{
	 ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('b');

  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';

  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';
}
int main()
{
	ft::map<char,int> mymap;

  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;

  ft::map<char,int>::const_iterator it = mymap.begin();
  it ++;
  ft::map<char,int>::const_reverse_iterator cp = it;
 
 std::cout << " was" << it->second << std::endl;
// 	it->second = 4;
	std::cout << "now" << cp->second << std::endl;

	if (&*it == &*cp)
	{
		std::cout << "k" << std::endl;
	}
	// test_allocator();
	// test_find();
	// test_iterators();

	// test_accessor();
	// test_equal();
	// test_swap();
	// test_key_comp();
	// original_test_erase();
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
    // // std::cout << " -    test_copy_constructor();- " << std::endl;
	// // test_copy_constructor();;
    // std::cout << " -    test_rbegin();- " << std::endl;
	// test_rbegin();;
    // std::cout << " -    test_rend();- " << std::endl;
	// test_rend();;
    // std::cout << " -    test_empty();- " << std::endl;
	// test_empty();

    // std::cout << " -    test_size();- " << std::endl;
	// test_size();

//     std::cout << " -    test_max_size();- " << std::endl;
// 	test_max_size();
	
    // std::cout << " -    test_delete();- " << std::endl;
	// test_delete();
    // std::cout << " -    test_original_delete();- " << std::endl;
	// test_original_delete();
}































