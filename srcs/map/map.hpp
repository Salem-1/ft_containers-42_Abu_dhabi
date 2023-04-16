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
# include "map_utils.hpp"

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
		class Allocator = std::allocator<ft::pair<const Key, T> >
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
			typedef typename ft::Node<key_type, mapped_type>		tree;
		
			tree							*_tree;
		protected:
			key_compare						keycomp;
			allocator_type					allocator;
			tree							sentinile;
			
		
		//empty
		public:
			map(const key_compare& comp = key_compare()
				, const allocator_type& alloc = allocator_type()):_tree(NULL),
					keycomp(comp), allocator(alloc)
			{
				// _tree.parent = &sentinile;
				// _tree.left = &sentinile;
				// _tree.right = &sentinile;
			};
			~map()
			{
			};

			//-----------------------MODIFIERES------------------------------------//
	private:
	//--------------------------------Moves_UTILS-----------------------------------//
		
		// key_compare comp;
		tree	*new_node(const value_type &val)
		{
			// comp()
			//use allocator instead of new here;
			tree	*inserted = new tree;
			inserted->key_val = val;
			
			return (inserted);
		}

		tree	*right_rotate(tree *y)
		{
			tree	*x = y->left;
			tree	*T2 = x->right;

			x->right = y;
			y->left = T2;
			y->height = max_height(height(y->left), height(y->right)) + 1;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			return (x);
		}
		tree	*left_rotate(tree *x)
		{
			tree	*y = x->right;
			tree	*T2 = x->left;

			y->left = x;
			x->right = T2;
			y->height = max_height(height(y->left), height(y->right)) + 1;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			return (y);
		}

		int	getBalanceFactor(tree *N)
		{
			if (!N)
				return (0);
			return (height(N->left) - height(N->right));
		}
		tree	*do_insert(
			tree *node, const value_type &val)
		{
			// std::cout << "inserting " << val.first << " : " << val.second << std::endl;
			if (!node)
				return (new_node(val));
			if (val.first < node->key_val.first)
				node->left = do_insert(node->left, val);
			if (val.first > node->key_val.first)
				node->right = do_insert(node->right, val);
			else
				return (node);
			node->height = 1 + max_height(height(node->left), height(node->right));
			int balance_factor = getBalanceFactor(node);
			if (balance_factor > 1)
			{
				if (val.first < node->left->key_val.first)
					return (right_rotate(node));
				else if (val.first > node->left->key_val.first)
				{
					node->left = left_rotate(node->left);
					return (right_rotate(node));
				}
			}
			else if (balance_factor < -1)
			{
				if (val.first > node->right->key_val.first)
					return (left_rotate(node));
				else if (val.first < node->right->key_val.first)
				{
					node->right = right_rotate(node->right);
					return (left_rotate(node));
				}
			}
			return (node);
		}
	public:
		tree	*insert(const value_type &val)
		{
			_tree = do_insert(_tree, val);
			return (_tree);
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