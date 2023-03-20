/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:51:11 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/20 22:50:26 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		vector();
		vector();
		vector(const vector& v2);
		
		//----------------------MEMBER_TYPE---------------------------//
		typedef _Allocator								allocator_type;
		typedef __wrap_iter<pointer>					iterator;
		typedef __wrap_iter<const_pointer>				const_iterator;
		typedef _VSTD::reverse_iterator<iterator>		reverse_iterator;
		typedef typename __base::difference_type		difference_type;
		typedef typename __base::size_type				size_type;
		typedef _VSTD::reverse_iterator<const_iterator>	const_reverse_iterator;
		
		//--------------------MEMBER_FUNTIONS---------------------//
		vector											operator= (const vector &v2);
		size_type										size();
		size_type										max_size();
		void											resize();
		size_type										capacity()const;
		bool											empty() const;
		void											reserve(size_type n);
		void											shrink_to_fit();
		
		//--------------------ELEMENT_ACCESS---------------------//
		reference		operator[] (size_type n);
		const_reference	operator[] (size_type n) const;
		reference		at (size_type n);
		const_reference	at (size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;
		
		//---------------------MODIFIERS-----------------------//
		void		assign (size_type n, const value_type& val);
		void		push_back (const value_type& val);
		void		pop_back();
		void		insert (iterator position, size_type n, const value_type& val);
		iterator 	erase (iterator position);
		iterator 	erase (iterator first, iterator last);
		void		swap (vector& x);
		void		clear();
		void		push_back (const value_type& val);
		// template <class... Args>iterator emplace (const_iterator position, Args&&... args);??
		// template <class... Args>  void emplace_back (Args&&... args);??
		//--------------------------ALLOCATOR--------------------//
		allocator_type	get_allocator() const;
		//------------------NON_MEMBER_FUNTION_OVERLOAD----------//
		// template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
		template <class T, class Alloc> bool	operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc> bool	operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc> bool	operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc> bool	operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc> bool	operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		template <class T, class Alloc> bool	operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
		//----------------------TEMPLATE_SPECIALIZATION-----------//
		template < class T, class Alloc = allocator<T> > class vector; 
	protected:
		typedef T										value_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename __alloc_traits::pointer		pointer;
		typedef typename __alloc_traits::const_pointer	const_pointer;
		typedef pointer									iterator;
		typedef const_pointer							const_iterator;

};

#endif

/*
public:
    typedef allocator_traits<allocator_type>         __alloc_traits;
    typedef typename __alloc_traits::size_type       size_type;
	typedef vector                                   __self;
    typedef _Tp                                      value_type;
    typedef _Allocator                               allocator_type;
    typedef typename __base::__alloc_traits          __alloc_traits;
    typedef typename __base::reference               reference;
    typedef typename __base::const_reference         const_reference;
    typedef typename __base::pointer                 pointer;
    typedef typename __base::const_pointer           const_pointer;



protected:
    typedef typename __alloc_traits::difference_type difference_type;


private:
    typedef __vector_base<_Tp, _Allocator>           __base;
    typedef allocator<_Tp>                           __default_allocator_type;


*/