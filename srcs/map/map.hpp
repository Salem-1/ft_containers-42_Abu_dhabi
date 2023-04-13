/* ************************************************************************** */
/*		                                                                    */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:23:45 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/11 04:24:06 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
# include <iostream>
# include "tree.hpp"

namespace ft
{
		template <typename _Tp>
		struct __identity {
		  typedef _Tp type;
		};
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef typename __identity<Compare>::type				key_compare;
			typedef typename __identity<Allocator>::type			allocator_type;
			typedef value_type&										reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;
			typedef typename	allocator_type::difference_type		difference_type;
			typedef typename	allocator_type::size_type			size_type;
			typedef				value_type&							tmp_iterator;
			ft::Node<key_type, mapped_type>								tree;
		
		protected:
			key_compare						keycomp;
			allocator_type					allocator;
			ft::Node<key_type, value_type>		_tree;
			
		
		//empty
		public:
			map(const key_compare& comp = key_compare()
				, const allocator_type& alloc = allocator_type()):
					keycomp(comp), allocator(alloc)
			{};
			~map(){};
			ft::pair<tmp_iterator, bool>
			insert (const value_type& val)
			{
				ft::pair<Key, T> tmp = val;
				std::cout << "should insert" << val.first << " = " << val.second << std::endl;

				return (tmp);
			};
	};
}
#endif


//TODO inshalla
//public
	//constructors
	// template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		// //copy const
	// map (const map& x);
	// 	 typedef __map_iterator<typename __base::iterator>	           iterator;
	// typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
	// typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
	// typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;