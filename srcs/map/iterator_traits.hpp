/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:36:34 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/18 15:50:59 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <iostream>
#include <cstddef>

namespace ft
{
	template <class Iterator> class iterator_traits
	{
	    typedef typename Iterator::T         value_type;
	    typedef typename Iterator::Distance  difference_type;
	    typedef typename Iterator::Pointer   pointer;
	    typedef typename Iterator::Reference reference;
	    typedef typename Iterator::Category  iterator_category;
	};
	
	template <class T> class iterator_traits<T*>
	{
	    typedef T  value_type;
	    typedef T *pointer;
	    typedef T & reference;
	    typedef std::ptrdiff_t  difference_type;
	    typedef std::random_access_iterator_tag  iterator_category;
	};
	template <class T> class iterator_traits<const T*>
	{
	    typedef T  value_type;
	    typedef const T *pointer;
	    typedef const T & reference;
	    typedef std::ptrdiff_t  difference_type;
	    typedef std::random_access_iterator_tag  iterator_category;
	};
}

#endif