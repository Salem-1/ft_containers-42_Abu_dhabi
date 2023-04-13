/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:55:31 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/13 06:27:30 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>

namespace ft
{
	template <class Key,
			  class T>
	class Node
	{
	public:
		Key key;
		T val;
		Node *left;
		Node *right;
		Node *parent;
		int height;
		Node(Key k, T v, Node *l, Node *r, Node *p) : key(k), val(v), left(l), right(r), parent(p), height(0){};
		Node() : left(NULL), right(NULL), parent(NULL), height(0){};
	};

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
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second)
		{
		}
		pair(const first_type &a, const second_type &b) : first(a), second(b)
		{
		}
		pair &operator=(const pair &pr)
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
