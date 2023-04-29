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
# include "iterator.hpp"
# include "../vector/reverse_iterator.hpp"
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
			typedef	typename	ft::iterator<tree>							iterator;
		// typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
			typedef reverse_iterator<iterator>               reverse_iterator;
		// typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;
			protected:
			key_compare						comp;
			allocator_type					allocator;
			tree							sentinile;
		private:	
			tree										*_root;
			size_t										_size;
			
			tree *get_root() const
			{
				tree *root = _tree;
				if (!root)
					return (NULL);
				while (root->parent)
					root = root->parent;
				return (root);
			}
		public:
		key_compare get_comp() const
		{
			return (comp);
		}
		allocator_type get_allocator() const
		{
			return (allocator);
		}
		size_t	size() const
		{
			return (_size);
		}
			//---------------------------MODIFIERES------------------------------------//
		private:
			typedef typename	std::allocator<tree>	tree_alloc;
			tree_alloc									tree_allocator;
			tree *search(const value_type &val, tree *root)
			{
				
				if (!root || val.first == root->key_val.first)
					return (root);
				else if (val.first < root->key_val.first)
					return (search(val, root->left));
				else
					return (search(val, root->right));

			}
		//---------------------------Moves_UTILS-----------------------------------//
		
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
			// std::cout << "Before Rotation" << std::cout;
			// visualize_node(y, "y", "   ");
			// visualize_node(x, "x", "   ");
			x->right = y;
			y->left = T2;
			x->parent = y->parent;
			y->parent = x;
			
			y->height = max_height(height(y->left), height(y->right)) + 1;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			// std::cout << "After  Rotation" << std::cout;
			// visualize_node(y, "y", "   ");
			// visualize_node(x, "x", "   ");
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
			// std::cout << "\nrotating around " << node->key_val.first;
			// 		std::cout << " LL Rotate val = " << val.first << std::endl;
					return (LL_rotate(node));
				}
				else if (comp(val.first, node->right->key_val.first))
				{
					// std::cout << "\n\nRL Rotating node with val = " << node->key_val.first << ", val = " << val.first<< std::endl;
					node->right = RR_rotate(node->right);
					return (LL_rotate(node));
					// return (RL_rotate(node));
				}
			}
			else if (balance_factor > 1)
			{
// std::cout << "\nBalance factor " << balance_factor << " (val, node->left->val)  = ";
// std::cout << val.first << "  " << node->left->key_val.first << std::endl;
	 
				if (comp(val.first, node->left->key_val.first))
				{
					// std::cout << "RR Rotate val = " << val.first << std::endl;

					return (RR_rotate(node));
				
				}
				else if (comp(node->left->key_val.first, val.first))
				{
					// std::cout << "LR Rotate val = " << val.first << std::endl;
					
					// return (LR_rotate(node));
					node->left = LL_rotate(node->left);
					return (RR_rotate(node));
				}
			}
			// if (node->parent)
			// 	std::cout << " parent = " << node->parent->key_val.first << " ";
			
			return (node);
		}
//----------ITERATOR_UTILS----------//
	private:
		tree	*get_min(tree *min_node) const
		{
			if (!min_node)
				return (NULL);
			while (min_node->left)
				min_node = min_node->left;
			return (min_node);			
		}
		tree	*get_max(tree *max_node) const
		{
			if (!max_node)
				return (NULL);
			while (max_node->right)
				max_node = max_node->right;
			return (max_node);			
		}
	public:

		ft::pair<iterator, bool> 
		insert(const value_type &val)
		{
			ft::pair<iterator, bool>  result;
			tree 	*seek_val = search(val, get_root());
			if (seek_val)
			{
				result.first = iterator(seek_val);
				result.second = false;
				return (result);
			}
			_tree = do_insert(_tree, val, NULL);
			tree *searched_node = search(val, get_root());
			iterator tmp(searched_node);
			result.first = tmp;
			result.second = true;
			_size++;
			return (result);
		}
		iterator insert (iterator position, const value_type& val)
		{
			tree	*tmp = search(val, get_root());
			if (tmp)
				return (iterator(tmp));
			_tree = do_insert(_tree, val, NULL);
			_size++;
			(void)position; 
			return (iterator(search(val, get_root())));
		}

		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert (first, first.base()->key_val);
				first++;
			}
		}
		tree	*do_find(const key_type &k, tree *root)
		{
			if (!root || k == root->key_val.first)
				return (root);
			else if (k < root->key_val.first)
				return (do_find(k, root->left));
			else
				return (do_find(k, root->right));
		}
		iterator find (const key_type& k)
		{

			tree *searched_node = do_find(k, get_root());
			if (!searched_node)
				return (end());
			return (iterator(searched_node));
		};
		mapped_type	&operator[](key_type const &k)
		{
			tree *searched_node = do_find(k, get_root());
			// std::cout << "seg" << std::endl;
			if (!searched_node)
			{
				value_type	insert_me(k);
				insert(insert_me);
				searched_node = do_find(k, get_root());
			}
			return (searched_node->key_val.second);
		} 
		// const_iterator find (const key_type& k) const;
		iterator	begin() const
		{
			return (iterator(get_min(_tree)));
		}

		iterator	end() const
		{
			iterator after_max(get_max(get_root()));
			after_max.set_max(1);
			return (after_max);
		}
		reverse_iterator rend()
		{
			return (begin());
		}
		//TBC
		reverse_iterator rbegin()
		{
			reverse_iterator before_begin(get_min(get_root()));
			return --before_begin;
		}
		void	clear()
		{
			_size = 0;
			//while _tree: delete(node);
		}
		public:
		//------------------CONSTRUCTOR-------------------------------------------//
			map(const key_compare& comp = key_compare()
				, const allocator_type& alloc = allocator_type()):_tree(NULL),
					comp(comp), allocator(alloc), _root(get_root()), _size(0)
			{
				sentinile.is_sentinel = 1;
			};
			template <class InputIterator> 
			map (InputIterator first, InputIterator last, 
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):_tree(NULL),
					comp(comp), allocator(alloc), _root(get_root()), _size(0)
				{
					insert(first, last);
				};
			map& operator= (const map& x)
			{
				if (this != &x)
				{
					// if (!x.size())
					// 	retu
					clear();
					_tree = NULL;
					comp = x.get_comp();
					allocator = x.get_allocator();
					insert(x.begin(), x.end());
					_root = get_root();
				}
				return (*this);
			}

			~map()
			{
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
	