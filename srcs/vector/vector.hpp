/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:51:11 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/27 07:09:58 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include "iterator.tpp"
#include "type_safety.tpp"

namespace ft{

template <typename vector> class Veciterator;
template <typename vector> class Vecreverse_iterator;
// template <typename vector> class const_iterator;
template < class T, class Alloc = std::allocator<T> >
class vector
{
	public:
		typedef Alloc										allocator_type;
		typedef T											value_type;
		typedef Veciterator< vector<T> >					iterator;
		typedef iterator									const_iterator;
		typedef Vecreverse_iterator< vector<T> >			reverse_iterator;
		typedef reverse_iterator							const_reverse_iterator;
		typedef size_t										size_type;
	protected:
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::const_reference	const_reference;
		allocator_type										allocator;
		size_type 											max_capacity;
		size_type												_capacity;
		size_type												old_capacity;
		size_type												_size;
		value_type												*arr;
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
			//allocator_type::construct(&tmp[i],&arr[i]);
			//std::allocator_traits::construct
			if (old_capacity)
			{
				allocator.destroy(arr);
				allocator.deallocate(arr, old_capacity);
			}
			return (tmp);
		}
	public:
		void	push_back (const value_type& val)
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
		//---------------------------CONSTRUCTORS---------------------//
		
		explicit vector (const allocator_type& alloc = allocator_type()) : allocator(alloc), 
		max_capacity(allocator.max_size()), _capacity(0), _size(0)
		{};
		explicit vector (size_type n,
			const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type()) : allocator(alloc),
				max_capacity(allocator.max_size()),  _capacity(0), _size(n)
			{
				_capacity = update_capacity(n);
				arr = allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					arr[i] = val;
			};
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()):
			allocator(alloc), max_capacity(allocator.max_size()),
			 _capacity(0), _size(0)
		{
			assign(first, last);
		}
		vector	&operator= (const vector &v2)
		{
			std::cout<< std::endl;
			if (this != &v2)
			{
				assign(v2.begin(), v2.end());
			}
			return (*this);
		}
		vector (const vector& x):  allocator(x.get_allocator()), 
		max_capacity(allocator.max_size()), _capacity(0), _size(0)
		{
			*this = x;
		};
		~vector()
		{
			if (_capacity)
			{
				clear(); //I doubt this linewill cause leaks.
				allocator.deallocate(arr, _capacity);
			}
		}
		//----------------------ITERATORS-----------------------------//
		iterator begin()
		{
			return (iterator(arr));
		};
		iterator end()
		{
			return (iterator(arr + _size));
		};
		const_iterator begin() const
		{
			return (const_iterator(arr));
		};
		const_iterator end() const
		{
			return (const_iterator(arr + _size));
		};
		reverse_iterator	rbegin()
		{
			return (reverse_iterator(arr + _size - 1));
		};
		reverse_iterator	rend()
		{
			return (reverse_iterator(arr - 1));
		};
		reverse_iterator	rbegin() const
		{
			return (reverse_iterator(arr + _size - 1));
		};
		reverse_iterator	rend() const
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
	//----------------------MODIFIRES------------------------//
	iterator erase (iterator position)
	{
		iterator it = position;
		if (it == end() - 1)
		{
			pop_back();
			return (position);
		}
		*it = *(it + 1);
		it++;
		while (it != end())
		{
			*it = *(it + 1);
			it++;
		}
		_size--;
		return (position);
	};
	
	// iterator erase (iterator first, iterator last)
	// {
	// 	if (last != )
		
	// };
	void clear()
	{
		if (!_size)
			return ;
		for (size_t i = 0; i < _size; i++)
			allocator.destroy(&arr[i]);
		_size = 0;
	};
	template <class InputIterator>
	typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type 
		 assign (InputIterator first, InputIterator last)
	{
		clear();
		while(first != last)
		{
			push_back(*first);
			first++;
		}
	};
	void assign (size_type n, const value_type& val)
	{
		clear();
		for (size_t i = 0; i < n; i++)
			push_back(val);
	};

iterator insert (iterator position, const value_type& val)
{
	value_type	*tmp;
	size_t		new_capacity = _capacity;
	if (_capacity == _size)
		tmp = allocator.allocate(++new_capacity);
	iterator it = begin();
	int	i = 0;
	while (it != position)
	{
		tmp[i] = arr[i];
		it++; i++;
	}
	size_t location = i;
	tmp[i++] = val;
	while (it != end())
	{
		tmp[i] = arr[i - 1];
		it++; i++;
	}
	size_t	old_size = _size;
	clear();
	allocator.deallocate(arr, _capacity);
	_size = old_size + 1;
	_capacity = new_capacity;
	arr = tmp;
	return (begin() + location);
};

void insert (iterator position, size_type n, const value_type& val)
{
	value_type	*tmp;
	size_t		new_capacity = _capacity;
	if (_capacity < _size + n)
	{
		new_capacity += n;
		tmp = allocator.allocate(new_capacity);
	}
	iterator it = begin();
	size_t	i = 0;
	while (it != position)
	{
		tmp[i] = arr[i];
		it++; i++;
	}
	size_t location = i;
	while (i < location + n)
		tmp[i++] = val;
	while (it != end())
	{
		tmp[i] = arr[i - n];
		it++; i++;
	}
	size_t	old_size = _size;
	clear();
	allocator.deallocate(arr, _capacity);
	_size = old_size + n;
	_capacity = new_capacity;
	arr = tmp;
};

//modify the function below to use std::enable_if and std::is_integral

template <class InputIterator>
typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type 
insert(iterator position, InputIterator first, InputIterator last)
{
	value_type	*tmp;
	int		range = 0;
	while ((first + range) != last)
		range++;
	size_t		new_capacity = _capacity;
	if (_capacity < _size + range)
	{
		new_capacity += range;
		tmp = allocator.allocate(new_capacity);
	}
	iterator it = begin();
	size_t	i = 0;
	while (it != position)
	{
		tmp[i] = arr[i];
		it++; i++;
	}
	while (first != last)
	{
		allocator.construct(&tmp[i++], first);
		first++;
	}
	while (it != end())
	{
		tmp[i] = arr[i - range];
		it++; i++;
	}
	size_t	old_size = _size;
	clear();
	allocator.deallocate(arr, _capacity);
	_size = old_size + (size_t)range;
	_capacity = new_capacity;
	arr = tmp;
};
	
	//------------ALLOCATOR---------------------//
	allocator_type get_allocator() const
	{
		return (allocator);
	};
};
			//--NON-MEMBERS--//
	//------------RELATIONAL_OPERATORS-------------//

template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (*first1 != *first2)
			return (false);
		first1++;
		first2++;
	}
	return (true);
}

template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1<*first2)
			return true;
		first1++;
		first2++;
	}
	return (first2!=last2);
}

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{

	return (ft::lexicographical_compare(
		lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
};

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
};
template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
};
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs < rhs));
};

}

#endif

// |--------------------------------|
// |operation | equivelant operation|
// |--------------------------------|
// |a!=b	  | !(a==b)             |
// |a>b	      | b<a                 |
// |a<=b	  | !(b<a)              |
// |a>=b	  | !(a<b)              |
// |--------------------------------|