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
			typedef pair<Key, T> value_type;
			pair<Key, T> key_val;
			Node	*left;
			Node	*right;
			Node	*parent;
			int		height;
			int		is_sentinel;
			int		empty;
	
			Node(pair<Key, T> given_key_val, Node *l, Node *r, Node *p) 
			:  left(l), right(r), parent(p), height(1), is_sentinel(0), empty(0)
			{
				this>key_val = given_key_val;
			};
			Node() :left(NULL), right(NULL), parent(NULL), height(1), is_sentinel(1), empty(1)
			{};
			Node(pair<Key, T> val):key_val(val), left(NULL), right(NULL), parent(NULL), height(1), is_sentinel(0), empty(0)
			{};
			
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
		pair()
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
		pair& operator= (const pair& pr)
		{
			if (this != &pr)
			{
				this->first = pr.first;
				this->second = pr.second;
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
