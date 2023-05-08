/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:55:31 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/16 08:14:11 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>

namespace ft
{
	template <class T1, class T2> struct pair;
	template <class Key,
			  class T>
	class Node
	{
		public:
			typedef pair<Key, T> 	value_type;        
			pair<Key, T>			key_val;        
			Node					*left;        
			Node					*right;        
			Node					*parent;        
			int						height;        
			int						is_sentinel;        
			int						empty;        
	




			Node() :key_val(value_type()), left(NULL), right(NULL), parent(NULL), height(1), is_sentinel(1), empty(1)
			{};
			Node(pair<Key, T> given_key_val, Node *l, Node *r, Node *p) 
			:  left(l), right(r), parent(p), height(1), is_sentinel(0), empty(0)
			{
				this->key_val = given_key_val;
			};
			Node(pair<Key, T> val):key_val(val), left(NULL), right(NULL), parent(NULL), height(1), is_sentinel(0), empty(0)
			{};
			// Node(const pair<Key, T> val):key_val(val), left(NULL), right(NULL), parent(NULL), height(1),  empty(0)
			// {};
			Node	&operator=(Node const &obj2)
			{
				if (this != &obj2)
				{
					key_val = obj2.key_val;        
					left = obj2.left;            
					right = obj2.right;          
					parent = obj2.parent;        
					height = obj2.height;          
					is_sentinel = obj2.is_sentinel;
					empty = obj2.empty;            
				}
				return (*this);
			}
			~Node(){
			};
	};
	
	template <class Key, class T>
	int height(Node<Key, T> *N)
	{
		if (!N)
			return (0);
		return (N->height);
	}
	template <class T1, class T2>
	struct pair
	{
		// public:
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;
		pair():first(first_type()), second(second_type())
		{
		}
		template <class first_type, class second_type>
		pair(const pair<first_type, second_type> &pr) : first(pr.first), second(pr.second)
		{
			
		}
		
		// template <class first_type, class second_type>
		// pair( pair<first_type, second_type> &pr) : first(pr.first), second(pr.second)
		// {
		// }
		pair(const first_type &a, const second_type &b) : first(a), second(b)
		{
		}
		pair(const first_type &a) : first(a), second(second_type())
		{
		}
		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				// std::cout << "this->second = " << this->second << std::endl;
				this->first = pr.first;
				this->second = pr.second;
				// std::cout << "pr->second = " << pr.second << std::endl;
			}
			return (*this);
		}
	};

	template <class T1, class T2> 
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2> (x, y));
	}

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T1, class T2>
	bool operator< (const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (lhs.first < rhs.first
			|| (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}
}
#endif
