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
#include "iterator.hpp"
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
		// typedef __map_iterator<typename __base::iterator>	           iterator;
		// typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
		// typedef _VSTD::reverse_iterator<iterator>               reverse_iterator;
		// typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;
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
			typedef	typename	ft::iterator<tree>							iterator;
			protected:
			key_compare						comp;
			allocator_type					allocator;
			tree							sentinile;
			
		
		//empty
		public:
			map(const key_compare& comp = key_compare()
				, const allocator_type& alloc = allocator_type()):_tree(NULL),
					comp(comp), allocator(alloc)
			{
				sentinile.is_sentinel = 1;
			};
			~map()
			{
			};

			//---------------------------MODIFIERES------------------------------------//
	private:
			typedef typename	std::allocator<tree>	tree_alloc;
			tree_alloc						tree_allocator;
			//---------------------------Moves_UTILS-----------------------------------//
		
		void	visualize_node(tree *y, std::string name, std::string indent)

		{
			std::cout << indent;
			std::cout << "    " << name << std::endl;
			std::cout << indent;
			if (y->parent)
				std ::cout << "    " << y->parent->key_val.first << std::endl;
			else
				std::cout << "   root" << std::endl;
			std::cout << indent;
			
			std::cout << "    ^" << std::endl;
			std::cout << indent;
			
			std::cout << "    | " << std::endl;
			std::cout << indent;
			
			std::cout << "    "<< y->key_val.first << std::endl;
			std::cout << indent;
			
			std::cout << " /    \\" << std::endl;
			std::cout << indent;
			
			if (y->left)
				std::cout  << y->left->key_val.first;
			else
				std::cout <<"(null)";
			std::cout << "      ";
			if (y->right)
				std::cout << y->right->key_val.first << std::endl;
			else
				std::cout << "(null)" << std::endl;
		}
		tree	*new_node(const value_type &val)
		{
			tree	*inserted = tree_allocator.allocate(1);
			inserted->key_val = val;
			inserted->height = 1;
			return (inserted);
		}

		tree	*LR_rotate(tree *y)
		{
			tree *new_root = y->left->right;
			tree *middle = y->left;

			middle->right = new_root->left;
			new_root->left = middle;
			y->left = new_root->right;
			new_root->right = y;
			new_root->parent = y->parent;
			middle->parent = new_root;
			y->parent = new_root;
			y->height = max_height(height(y->left), height(y->right)) + 1;
			middle->height = max_height(height(middle->left), height(middle->right)) + 1;
			new_root->height = max_height(height(new_root->left), height(middle->right)) + 1;
			return (new_root);
		}
		
		tree	*RL_rotate(tree *x)
		{
			tree	*new_root = x->right->left;
			tree	*middle = x->right;

			middle->left = new_root->right;
			x->right = new_root->left;
			new_root->left = x;
			new_root->right = middle;
			new_root->parent = x->parent;
			x->parent = new_root;
			middle->parent = new_root;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			middle->height = max_height(height(middle->left), height(middle->right)) + 1;
			new_root->height = max_height(height(new_root->left), height(middle->right)) + 1;
			return (new_root);
		}
		tree	*RR_rotate(tree *y)
		{
			tree	*x = y->left;
			tree	*T2 = x->right;
			std::cout << "Before Rotation" << std::cout;
			visualize_node(y, "y", "   ");
			visualize_node(x, "x", "   ");
			x->right = y;
			y->left = T2;
			x->parent = y->parent;
			y->parent = x;
			
			y->height = max_height(height(y->left), height(y->right)) + 1;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			std::cout << "After  Rotation" << std::cout;
			visualize_node(y, "y", "   ");
			visualize_node(x, "x", "   ");
			if (y->left)
					y->left->parent = y;
			return (x);
		}

		tree	*LL_rotate(tree *x)
		{
			tree*	y = x->right;
			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->left = x;
			y->parent = x->parent;
			x->parent = y;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			y->height = max_height(height(y->left), height(y->right)) + 1;
			return (y);
		}

		int	getBalanceFactor(tree *N)
		{
			if (!N)
				return (0);
			return (height(N->left) - height(N->right));
		}
		tree	*do_insert(
			tree *node, const value_type &val, tree *parent)
		{
			if (!node)
			{
				// std::cout << "makeing new node" << std::endl;
				tree *tmp = new_node(val);
				tmp->parent = parent;
				return (tmp);
			}
			else if (comp(val.first, node->key_val.first))
			{
				node->left = do_insert(node->left, val, node);
			}
			// else if (val.first > node->key_val.first)
			else if (comp(node->key_val.first, val.first))
			{
				node->right = do_insert(node->right, val, node);
			}
			else
				return (node);
			node->height = max_height(height(node->left), height(node->right)) + 1;
			int	balance_factor = getBalanceFactor(node);
			// std::cout << "for node " << node->key_val.first << "  Blance factor = " << balance_factor << std::endl;
			if (balance_factor < -1)
			{
				if (comp(node->right->key_val.first, val.first))
				{
			std::cout << "\nrotating around " << node->key_val.first;
					std::cout << " LL Rotate val = " << val.first << std::endl;
					return (LL_rotate(node));
				}
				else if (comp(val.first, node->right->key_val.first))
				{
					std::cout << "\n\nRL Rotating node with val = " << node->key_val.first << ", val = " << val.first<< std::endl;
					node->right = RR_rotate(node->right);
					return (LL_rotate(node));
					// return (RL_rotate(node));
				}
			}
			else if (balance_factor > 1)
			{
std::cout << "\nBalance factor " << balance_factor << " (val, node->left->val)  = ";
std::cout << val.first << "  " << node->left->key_val.first << std::endl;
	 
				if (comp(val.first, node->left->key_val.first))
				{
					std::cout << "RR Rotate val = " << val.first << std::endl;

					return (RR_rotate(node));
				
				}
				else if (comp(node->left->key_val.first, val.first))
				{
					std::cout << "LR Rotate val = " << val.first << std::endl;
					
					// return (LR_rotate(node));
					node->left = LL_rotate(node->left);
					return (RR_rotate(node));
				}
			}
			if (node->parent)
				std::cout << " parent = " << node->parent->key_val.first << " ";
			
			return (node);
		}
//----------ITERATOR_UTILS----------//
	private:
		tree	*get_min(tree *min_node)
		{
			if (!min_node)
				return (NULL);
			while (min_node->left)
				min_node = min_node->left;
			return (min_node);			
		}
		tree	*get_max(tree *max_node)
		{
			if (!max_node)
				return (NULL);
			while (max_node->right)
				max_node = max_node->right;
			return (max_node);			
		}
	public:

		tree	*insert(const value_type &val)
		{
			if (_tree)
				std::cout << "root = " << _tree->key_val.first <<" inserting val " << val.first << std::endl;

			_tree = do_insert(_tree, val, NULL);
			std::cout << std::endl;
			return (_tree);
		};
		iterator	begin()
		{
			//returning the smallest pointer
			
			return (iterator(get_min(_tree)));
		}

		iterator	end()
		{			
			return (iterator(get_max(_tree)->right));
		}
	};
}
#endif


//TODO inshalla
//public
	//constructors
	// template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		// //copy const
	// map (const map& x);
	