/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:22:00 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/26 04:10:48 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <iostream>

namespace ft
{
// template <typename vector>
// class const_iterator
// {
// 		//defining const iterator
// 		typedef const value_type* const_pointer_type;
// 		typedef const value_type& const_refrence_type;
// };
template <typename vector>
class Veciterator
{
	public:
		typedef typename vector::value_type value_type;
		typedef value_type* pointer_type;
		typedef const value_type* const_pointer_type;
		typedef value_type& refrence_type;
		Veciterator(): _ptr(NULL) {};
		Veciterator(pointer_type ptr): _ptr(ptr) {};
		Veciterator(const_pointer_type cptr): _ptr(cptr) {};
		Veciterator(const Veciterator& it): _ptr(it._ptr) {};
		Veciterator& operator=(const Veciterator& rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		};
		Veciterator& operator=(pointer_type ptr)
		{
			_ptr = ptr;
			return (*this);
		};
		Veciterator& operator++()
		{
			_ptr++;
			return (*this);
		};
		
		Veciterator& operator+(int n)
		{
			_ptr += n;
			return (*this);
		};
		Veciterator& operator-(int n)
		{
			_ptr -= n;
			return (*this);
		};
		
		Veciterator operator++(int)
		{
			Veciterator tmp(*this);
			operator++();
			return (tmp);
		};
		Veciterator& operator--()
		{
			_ptr--;
			return (*this);
		};
		Veciterator operator--(int)
		{
			Veciterator tmp(*this);
			operator--();
			return (tmp);
		};
		refrence_type operator*()
		{
			return (*_ptr);
		};
		Veciterator operator->()
		{
			return (_ptr);
		};
		bool operator==(const Veciterator& rhs)
		{
			return (_ptr == rhs._ptr);
		};
		bool operator!=(const Veciterator& rhs)
		{
			return (_ptr != rhs._ptr);
		};
	protected:
		pointer_type _ptr;
};
template <typename vector>
class Vecreverse_iterator
{
	public:
		typedef typename vector::value_type	value_type;
		typedef value_type*					pointer_type;
		typedef const value_type*			const_pointer_type;
		typedef value_type&					refrence_type;
		Vecreverse_iterator(): _ptr(NULL) {};
		Vecreverse_iterator(pointer_type ptr): _ptr(ptr) {};
		Vecreverse_iterator(const_pointer_type cptr): _ptr(cptr) {};
		Vecreverse_iterator(const Vecreverse_iterator& it): _ptr(it._ptr) {};
		Vecreverse_iterator& operator=(const Vecreverse_iterator& rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		};
		Vecreverse_iterator& operator=(pointer_type ptr)
		{
			_ptr = ptr;
			return (*this);
		};
		Vecreverse_iterator& operator++()
		{
			_ptr--;
			return (*this);
		};
		Vecreverse_iterator operator++(int)
		{
			Vecreverse_iterator tmp(*this);
			operator++();
			return (tmp);
		};
		Vecreverse_iterator& operator--()
		{
			_ptr++;
			return (*this);
		};
		Vecreverse_iterator operator--(int)
		{
			Vecreverse_iterator tmp(*this);
			operator--();
			return (tmp);
		};
		refrence_type operator*()
		{
			return (*_ptr);
		};
		Vecreverse_iterator operator->()
		{
			return (_ptr);
		};
		bool operator==(const Vecreverse_iterator& rhs)
		{
			return (_ptr == rhs._ptr);
		};
		bool operator!=(const Vecreverse_iterator& rhs)
		{
			return (_ptr != rhs._ptr);
		}
	protected:
		pointer_type _ptr;
};

};
#endif