/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:51:11 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/25 16:25:45 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>

namespace ft{

template <typename vector> class iterator;
template <typename vector> class reverse_iterator;

template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		typedef Alloc										allocator_type;
		typedef T											value_type;
		typedef  iterator< vector<T> >						iterator;
		typedef  reverse_iterator< vector<T> >						reverse_iterator;
        // typedef iterator<const vector<T>> 					const_iterator;
	protected:
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
		vector(): max_capacity(allocator.max_size()), _capacity(0), _size(0)
		{};
		~vector()
		{
			if (_capacity)
			{
				allocator.destroy(arr);
				allocator.deallocate(arr, _capacity);
			}
		}
		vector	operator= (const vector &v2);
		// vector(size_t n, value_type val);
		// vector(const vector& v2){};



		//----------------------MEMBER_TYPE---------------------------//
		typedef size_t										size_type;
		
		//----------------------ITERATORS-----------------------------//
		iterator begin()
		{
			return (iterator(arr));
		};
		iterator end()
		{
			return (iterator(arr + _size));
		};
		reverse_iterator	rbegin()
		{
			return (reverse_iterator(arr + _size - 1));
		};
		reverse_iterator	rend()
		{
			return (reverse_iterator(arr - 1));
		};
		// const_iterator begin() const
		// {
		// 	return (const_iterator(arr));
		// };
		// const_iterator end() const
		// {
		// 	return (const_iterator(arr + _size));
		// };
		//--------------------MEMBER_FUNTIONS---------------------//
		size_type	size() const
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
		void pop_back()
		{
			if (_size)
			{
				allocator.destroy(&arr[_size - 1]);
				_size--;
			}
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
			return (arr[n]);
		};
		const value_type&	operator[] (size_type n) const
		{
			return (arr[n]);
		};
		value_type&			at (size_type n)
		{
			if (n < _size)
				return (arr[n]);
			else
				throw (std::out_of_range("Index out of range"));
		};
		const value_type&	at (size_type n) const
				{
			if (n < _size)
				return (arr[n]);
			else
				throw (std::out_of_range("Index out of range"));
		}; 
		value_type&			front()
		{
			return (arr[0]);
		};
		const value_type&	front() const
		{
			return (arr[0]);
		};
		value_type&	back()
		{
			return (arr[_size - 1]);
		};
		const value_type&	back() const
		{
			return (arr[_size - 1]);
		};
	//------------MODIFIRES------------------------//
	void clear()
	{
		if (!_size)
			return ;
		for (size_t i = 0; i < _size; i++)
			allocator.destroy(&arr[i]);
		_size = 0;
	};
	
	//------------ALLOCATOR---------------------//
	allocator_type get_allocator() const
	{
		return (allocator);
	};
};
			//--NON-MEMBERS--//
	//------------RELATIONAL_OPERATORS-------------//

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
	{
		
		if (lhs.at(i) != rhs.at(i))
			return (false);
	}
	return (true);
}

// template <class T, class Alloc>
// bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
// {
// 	std::vector<T>::iterator it1;
// 	std::vector<T>::iterator it2;

// 	size_t	small_size;
// 	if (lhs.size() < rhs.size())
// 		small_size = lhs.size();
// 	else
// 		small_size = rhs.size();
// 	for (size_t i = 0; i < small_size; i++)
// 	{
// 		std::cout << "left = " << lhs.at(i) <<" right = " <<  rhs.at(i) << std::endl;
// 		if (lhs.at(i) < rhs.at(i))
// 			continue;
// 		else
// 			return (false);
// 	}
// 	std::cout << "left =  " << lhs.size() << ", right = " << rhs.size() << std::endl;
// 	if (lhs.size() <= rhs.size())
// 		return (true);
// 	return (false);
// }

// template <class T, class Alloc>
// bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
// bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
// bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
// template <class T, class Alloc>
// bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

template <typename vector>
class iterator
{
	public:
		typedef typename vector::value_type value_type;
		typedef value_type* pointer_type;
		typedef value_type& refrence_type;
		//defining const iterator
		typedef const value_type* const_pointer_type;
		typedef const value_type& const_refrence_type;
		iterator(): _ptr(NULL) {};
		iterator(pointer_type ptr): _ptr(ptr) {};
		iterator(const iterator& it): _ptr(it._ptr) {};
		iterator& operator=(const iterator& rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		};
		iterator& operator=(pointer_type ptr)
		{
			_ptr = ptr;
			return (*this);
		};
		iterator& operator++()
		{
			_ptr++;
			return (*this);
		};
		iterator operator++(int)
		{
			iterator tmp(*this);
			operator++();
			return (tmp);
		};
		iterator& operator--()
		{
			_ptr--;
			return (*this);
		};
		iterator operator--(int)
		{
			iterator tmp(*this);
			operator--();
			return (tmp);
		};
		refrence_type operator*()
		{
			return (*_ptr);
		};
		iterator operator->()
		{
			return (_ptr);
		};
		bool operator==(const iterator& rhs)
		{
			return (_ptr == rhs._ptr);
		};
		bool operator!=(const iterator& rhs)
		{
			return (_ptr != rhs._ptr);
		};
	protected:
		pointer_type _ptr;
};
template <typename vector>
class reverse_iterator
{
	public:
		typedef typename vector::value_type value_type;
		typedef value_type* pointer_type;
		typedef value_type& refrence_type;
		//defining const iterator
		typedef const value_type* const_pointer_type;
		typedef const value_type& const_refrence_type;
		reverse_iterator(): _ptr(NULL) {};
		reverse_iterator(pointer_type ptr): _ptr(ptr) {};
		reverse_iterator(const reverse_iterator& it): _ptr(it._ptr) {};
		reverse_iterator& operator=(const reverse_iterator& rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		};
		reverse_iterator& operator=(pointer_type ptr)
		{
			_ptr = ptr;
			return (*this);
		};
		reverse_iterator& operator++()
		{
			_ptr--;
			return (*this);
		};
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			operator++();
			return (tmp);
		};
		reverse_iterator& operator--()
		{
			_ptr++;
			return (*this);
		};
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);
			operator--();
			return (tmp);
		};
		refrence_type operator*()
		{
			return (*_ptr);
		};
		reverse_iterator operator->()
		{
			return (_ptr);
		};
		bool operator==(const reverse_iterator& rhs)
		{
			return (_ptr == rhs._ptr);
		};
		bool operator!=(const reverse_iterator& rhs)
		{
			return (_ptr != rhs._ptr);
		}
	protected:
		pointer_type _ptr;
};

}

#endif
