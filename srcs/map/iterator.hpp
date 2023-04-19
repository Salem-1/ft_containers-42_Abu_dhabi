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
		class tree,
		class Category = std::random_access_iterator_tag,
		class Distance = ptrdiff_t,
		class Pointer = tree*,
		class Reference = tree&
	> class iterator
	{
		public:
	    	typedef tree			value_type;
	    	typedef Distance 	difference_type;
	    	typedef tree		*pointer;
	    	typedef tree&			reference;
	    	typedef Category	iterator_category;
		
		protected:
			pointer	_node;
		public:
			iterator(): _node(NULL){};
			iterator(pointer ptr) : _node(ptr){};
			~iterator(){};

			pointer	operator->() const
			{
				return (_node);
			}
 	};
}
#endif