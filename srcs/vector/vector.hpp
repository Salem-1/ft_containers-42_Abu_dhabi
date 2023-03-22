/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:51:11 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/22 13:29:10 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>

namespace ft{
template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		typedef Alloc										allocator_type;
	protected:
		typedef T											value_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::max_size			max_capacity;
		size_t												_capacity;
		size_t												_size;
		value_type											*arr;
		allocator_type										allocator;



		//---------------HELPER_FUNCTIONS--------------------//
		size_t		update_capacity(size_t n)
		{
			if ((n + (_capacity + 1)) * 2 < SIZE_MAX )
				return ((n + (_capacity + 1)) * 2);
			else
				return (SIZE_MAX);
		};
		// void	vec_realloc()
		// {
		// 	T	*tmp= allocator_type.allocate(_capacity);
		// 	std::copy (T[0], T[_size], );
		// }


	public:
	//---------------------------CONSTRUCTORS---------------------//
		vector(){
			_capacity = 0;
			_size = 0;
		};
		vector		operator= (const vector &v2);
		// vector(size_t n, value_type val);
		// vector(const vector& v2){};



		//----------------------MEMBER_TYPE---------------------------//
		typedef size_t										size_type;
		
		//--------------------MEMBER_FUNTIONS---------------------//
		size_type	size()
		{
			return (_size);
		};
		size_type	capacity()const
		{
			return (_capacity);
		};
		// size_type	max_size()
		// {
		// 	return (max_capacity / sizeof(value_type));
		// };
		//TBC inshalla
		void push_back (const value_type& val)
		{
			arr = allocator_type.allocate(1);
			//inshalla just fill first element and print it
			//then do realloc for second element
			//then scale it
			//why not doing iterators first
			// if (size == _capacity)
			// {
			// 	_capacity = update_capacity();
			// 	vec_realloc();
			// }
			// else if (size < _capacity)
			// {
			// 	T[_size + 1] = val;
			// }
			// size++;
			// // else
			// // 	throw (index out of range exception);
		};
		void		resize();
		bool		empty() const;
		void		reserve(size_type n);
		void		shrink_to_fit();
		
		//--------------------ELEMENT_ACCESS---------------------//
		value_type&										operator[] (size_type n);
		const value_type&								operator[] (size_type n) const;
		value_type&										at (size_type n);
		const value_type&								at (size_type n) const;
		value_type&										front();
		const value_type&								front() const;
		value_type&										back();
		const value_type&								back() const;

};
}

#endif
