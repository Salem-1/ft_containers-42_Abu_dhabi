/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:51:11 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/23 01:35:37 by ahsalem          ###   ########.fr       */
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
		allocator_type										allocator;
		size_t 												max_capacity;
		size_t												_capacity;
		size_t												old_capacity;
		size_t												_size;
		value_type											*arr;



		//---------------HELPER_FUNCTIONS--------------------//
		size_t		update_capacity(size_t n)
		{
			if ((n + (_capacity + 1)) * 2 < max_capacity )
				return ((n + (_capacity + 1)) * 2);
			else
				return (max_capacity);
		};
		value_type	*vec_realloc()
		{
			value_type	*tmp = allocator.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				tmp[i] = arr[i];
			if (old_capacity)
			{
				allocator.destroy(arr);
				allocator.deallocate(arr, old_capacity);
			}
			return (tmp);
		}


	public:
		//---------------------------CONSTRUCTORS---------------------//
		vector(): max_capacity(allocator.max_size()), _capacity(0), _size(0){};
		~vector()
		{
			std::cout << "Destructor called !" <<std::endl;
			if (_capacity)
			{
				allocator.destroy(arr);
				allocator.deallocate(arr, _capacity);
			}
		}
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
		size_type	max_size()
		{
			return (max_capacity);
		};
		void push_back (const value_type& val)
		{
			if (_size == _capacity)
			{
				old_capacity = _capacity;
				_capacity = update_capacity(1);
				arr = vec_realloc();
			}
			arr[_size] = val;
			_size++;
		};
		void resize (size_type n, value_type val = value_type())
		{
			if (n < _size)
				_size = n;
			else if (n > _size)
			{
				reserve(n);
				for (size_t i = _size; i < _capacity; i++)
					arr[i] = val;
			}
		};
		void	resize(size_type n)
		{
			if (n < _size)
				_size = n;
			else if (n > _size)
				reserve(n);
		};
		bool	empty() const
		{
			if (_size)
				return (false);
			else
				return (true);
		};
		void	reserve(size_type n)
		{
			if (n <= _capacity)
				return ;
			old_capacity = _capacity;
			_capacity = update_capacity(n - _capacity);
			arr = vec_realloc();
		};
		//--------------------ELEMENT_ACCESS---------------------//
		value_type	&operator[] (size_type n)
		{
			return (&arr[n]);
		};
		const value_type&	operator[] (size_type n) const
		{
			return (&arr[n]);
		};
		value_type&			at (size_type n)
		{
			if (n < _size)
				return (&arr[n]);
			else
				throw (std::out_of_range("Index out of range"));
		};
		const value_type&	at (size_type n) const
				{
			if (n < _size)
				return (&arr[n]);
			else
				throw (std::out_of_range("Index out of range"));
		};
		value_type&			front()
		{
			return (&arr[0]);
		};
		const value_type&	front() const
		{
			return (&arr[0]);
		};
		value_type&	back()
		{
			return (&arr[_size - 1])
		};
		const value_type&	back() const
		{
			return (&arr[_size - 1])
		};

};
}

#endif
