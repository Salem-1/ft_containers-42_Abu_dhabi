/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 23:11:09 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/02 02:20:31 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
#include <iostream>
# include "iterator.hpp"
namespace ft
{
template <class iterator>
	class reverse_iterator
	{
		public:
			typedef iterator						iterator_type;
			typedef typename iterator::value_type	value_type;
			typedef value_type*						pointer_type;
			typedef const value_type*				const_pointer_type;
			typedef value_type&						refrence_type;
			typedef typename std::ptrdiff_t			difference_type;
			
			reverse_iterator(): _ptr(NULL) {};
			reverse_iterator(pointer_type ptr): _ptr(ptr) {};
			// reverse_iterator(const_pointer_type cptr): _ptr(cptr) {};
			reverse_iterator(const reverse_iterator& it): _ptr(it.base()) {};
			reverse_iterator(const iterator& it): _ptr(it) {};
			
			template <class T>
			reverse_iterator(const reverse_iterator<T>& it): _ptr(it.base()) {};
			~reverse_iterator(){};
			reverse_iterator& operator=(const reverse_iterator& rhs)
			{
				_ptr = rhs.base();
				return (*this);
			};
			reverse_iterator& operator++()
			{
				--_ptr;
				return (*this);
			};
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp(*this);
				--_ptr;
				return (tmp);
			};
			reverse_iterator& operator+=(int n)
			{
				_ptr -= n;
				return (*this);
			};
			reverse_iterator& operator-=(int n)
			{
				_ptr += n;
				return (*this);
			};
			reverse_iterator& operator--()
			{
				++_ptr;
				return (*this);
			};

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp(*this);
				++_ptr;
				return (tmp);
			};
			// reverse_iterator operator+ (difference_type n) const
		 	// { 
			// 	return reverse_iterator(_ptr - n);
			// }
			// reverse_iterator operator- (difference_type n) const
		 	// { 
			// 	return reverse_iterator(_ptr + n);
			// }
			reverse_iterator operator- (difference_type n) const
			{
				 return reverse_iterator(_ptr + n);
			}
			reverse_iterator operator+ (difference_type n) const
			{
				return reverse_iterator(_ptr - n); 
			}

			refrence_type operator[](difference_type n) const 
			{
				return *(*this + n); 
			}
			refrence_type operator*() const
			{
				iterator tmp = _ptr;
				--tmp;
				return (*tmp);
			};
			pointer_type operator->() const
			{
				iterator tmp = _ptr;
				--tmp;
				return ((tmp).operator->());
			};
			iterator_type	base() const
			{
				return (_ptr);
			}
		protected:
			iterator_type _ptr;
	};

	template < class iter1, class iter2>
	bool operator==(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (lhs.base() == rhs.base());
	};
	// template < class iter1>
	// bool operator==(const reverse_iterator<iter1>& lhs, 
	// 	typename reverse_iterator<iter1>::difference_type d)
	// {
	// 	return (lhs.base() == d);
	// };
	template < class iter1, class iter2>
	bool operator!=(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template < class iter1, class iter2>
	bool operator>(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template < class iter1, class iter2>
	bool operator<(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template < class iter1, class iter2>
	bool operator<=(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template < class iter1, class iter2>
	bool operator>=(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template < class iter1, class iter2>
	int operator-(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (rhs.base() - lhs.base());
	}
	template < class iter1, class iter2>
	size_t operator+(const reverse_iterator<iter1>& lhs, const reverse_iterator<iter2>& rhs)
	{
		return (lhs.base() + rhs.base());
	}
	template < class iter1>
	reverse_iterator<iter1> operator+ (
		typename reverse_iterator<iter1>::difference_type d, const reverse_iterator<iter1>& lhs)
	{
		return (lhs.base() - d);
	}
	template < class iter1>
	reverse_iterator<iter1> operator- (
		typename reverse_iterator<iter1>::difference_type d, const reverse_iterator<iter1>& lhs)
	{
		return (lhs.base() + d);
	}
	
};
#endif


// template <class _Iter>
// inline _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_AFTER_CXX14
// 	reverse_iterator<_Iter>
// 	operator+(typename reverse_iterator<_Iter>::difference_type __n, const reverse_iterator<_Iter> &__x)
// {
// 	return reverse_iterator<_Iter>(__x.base() - __n);
// }