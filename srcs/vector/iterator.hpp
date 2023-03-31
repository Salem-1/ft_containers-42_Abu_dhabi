/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:22:00 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/31 22:22:37 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <iostream>
# include <cstddef>
namespace ft
{
// template 
// 	<class Category,
// 	 // iterator::iterator_category class T,
// 	 // iterator::value_type class Distance = ptrdiff_t,
// 	 // iterator::difference_type  class Pointer = T*,
// 	 // iterator::pointer        class Reference = T&         //
// 	  iterator::reference  > class iterator;
/*
iterator_type	Iterator	Iterator's type
iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
value_type	iterator_traits<Iterator>::value_type	Preserves Iterator's value type
difference_type	iterator_traits<Iterator>::difference_type	Preserves Iterator's difference type
pointer	iterator_traits<Iterator>::pointer	Preserves Iterator's pointer type
reference	iterator_traits<Iterator>::referenc
	*/
	template <typename T>
	class Veciterator
	{
		public:
			typedef T								value_type;
			typedef value_type* 					pointer_type;
			typedef const value_type*				const_pointer_type;
			typedef value_type&						refrence_type;
			typedef typename std::ptrdiff_t			difference_type;
			
			Veciterator(): _ptr(NULL) {};
			Veciterator(pointer_type ptr): _ptr(ptr) {};

			// Veciterator(const_pointer_type cptr): _ptr(cptr) {};
			
			Veciterator(const Veciterator& it): _ptr(it.base()) {};
			template <typename iterator>		
			Veciterator(const Veciterator<iterator>& it): _ptr(it.base()) {};
			~Veciterator(){};
			Veciterator& operator=(const Veciterator& rhs)
			{
				_ptr = rhs.base();
				return (*this);
			};
			// Veciterator& operator=(pointer_type ptr)
			// {
			// 	_ptr = ptr;
			// 	return (*this);
			// };
			Veciterator& operator++()
			{
				_ptr++;
				return (*this);
			};
			
			// Veciterator& operator+(int n)
			// {
			// 	_ptr += n;
			// 	return (*this);
			// };
			Veciterator& operator-(int n)
			{
				_ptr -= n;
				return (*this);
			};
			Veciterator& operator+=(int n)
			{
				_ptr += n;
				return (*this);
			};
			Veciterator& operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			};
			Veciterator operator++(int)
			{
				Veciterator tmp(*this);
				_ptr++;
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
				_ptr--;
				return (tmp);
			};
			refrence_type operator*()
			{
				return (*_ptr);
			};
			value_type &operator[](const size_t i)
			{
				// pointer_type tmp;
				// tmp = _ptr + i;
				return (*( _ptr + i));
			};
			pointer_type operator->()
			{
				return (_ptr);
			};
			pointer_type	base() const
			{
				return (_ptr);
			}
		protected:
			pointer_type _ptr;
	};
	/*
	iterator_type	Iterator	Iterator's type
iterator_category	iterator_traits<Iterator>::iterator_category	Preserves Iterator's category
value_type	iterator_traits<Iterator>::value_type	Preserves Iterator's value type
difference_type	iterator_traits<Iterator>::difference_type	Preserves Iterator's difference type
pointer	iterator_traits<Iterator>::pointer	Preserves Iterator's pointer type
reference	iterator_traits<Iterator>::referenc
*/
	template < class iter1, class iter2>
	bool operator==(const Veciterator<iter1>& lhs, const Veciterator<iter2>& rhs)
	{
		return (lhs.base() == rhs.base());
	};
	template < class iter1, class iter2>
	bool operator!=(const Veciterator<iter1>& lhs, const Veciterator<iter2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	// template < class iter1, class iter2>
	// bool operator==(const Veciterator<iter1>& lhs, size_t rhs_base)
	// {
	// 	return (lhs.base() == rhs_base);
	// };
	template < class iter1, class iter2>
	bool operator< (const Veciterator<iter1>& lhs, const Veciterator<iter2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};
	
	template < class iter1, class iter2>
	bool operator> (const Veciterator<iter1>& lhs, const Veciterator<iter2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};
	template < class iter1, class iter2>
	bool operator>= (const Veciterator<iter1>& lhs, const Veciterator<iter2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};
	template < class iter1, class iter2>
	bool operator<= (const Veciterator<iter1>& lhs, const Veciterator<iter2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};
	

	template < class iter1, class iter2>
	std::ptrdiff_t operator-(const Veciterator<iter1>& lhs, const Veciterator<iter2>& rhs)
	{
		return (lhs.base() - rhs.base());
	}
	// template < class iter1>
	// size_t operator+ (const Veciterator<iter1>& lhs,
	// 	typename Veciterator<iter1>::difference_type d)
	// {
	// 	return (lhs.base() + d);
	// }
		template < class iter1>
	Veciterator<iter1> operator+ (
		typename Veciterator<iter1>::difference_type d, const Veciterator<iter1>& lhs)
	{
		return (lhs.base() + d);
	}
	template < class iter1>
	Veciterator<iter1> operator+ (const Veciterator<iter1>& lhs,
		int d)
	{
		return (lhs.base() + d);
	}
	template < class iter1>
	size_t operator- (const Veciterator<iter1>& lhs,
		typename Veciterator<iter1>::difference_type d)
	{
		return (lhs.base() - d);
	}
};
#endif