/* ************************************************************************** */
/*
                                                                   */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:51:37 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/18 18:21:22 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <
		class Category,
		class T,
		class Distance = ptrdiff_t,
		class Pointer = T*,
		class Reference = T&
	> class iterator
	{
		public:
	    	typedef T			value_type;
	    	typedef Distance 	difference_type;
	    	typedef T*			pointer;
	    	typedef T&			reference;
	    	typedef Category	iterator_category;
		
		protected:
			pointer	_ptr;
		public:
			iterator(): _ptr(NULL){};
			iterator(pointer ptr) : _ptr(ptr){};
			~iterator(){};

			pointer	operator->() const
			{
				return (_ptr);
			}
 	};
}
#endif