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
	struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Iterator> struct iterator_traits
	{
	    typedef typename Iterator::T         value_type;
	    typedef typename Iterator::Distance  difference_type;
	    typedef typename Iterator::Pointer   pointer;
	    typedef typename Iterator::Reference reference;
	    typedef typename Iterator::Category  iterator_category;
	};
	
	template <class T>
	struct iterator_traits<T*>
	{
	    typedef T  value_type;
	    typedef T *pointer;
	    typedef T & reference;
	    typedef std::ptrdiff_t  difference_type;
	    typedef ft::random_access_iterator_tag  iterator_category;
	};
	template <class T>
	struct iterator_traits<const T*>
	{
	    typedef T  value_type;
	    typedef const T *pointer;
	    typedef const T & reference;
	    typedef std::ptrdiff_t  difference_type;
	    typedef ft::random_access_iterator_tag  iterator_category;
	};
}

#endif