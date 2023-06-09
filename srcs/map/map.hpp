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
# include "const_iterator.hpp"
# include "../vector/reverse_iterator.hpp"
# include <unistd.h>

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
			typedef	typename	ft::iterator<tree>					iterator;
			typedef 	 ft::reverse_iterator<iterator>             reverse_iterator;
			typedef typename	ft::const_iterator<tree>			const_iterator;
			typedef 	ft::reverse_iterator<const_iterator>		const_reverse_iterator;	
	//do the const iterator in the iterator class and here inshalla
	
		// typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
		// typedef _VSTD::reverse_iterator<const_iterator>         const_reverse_iterator;
			tree							*_tree; 
			protected:
			key_compare						comp;
			allocator_type					allocator;
			// tree							min_left;
			// tree							max_right;
		private:	
			tree										*_root;
			size_type										_size;
			
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
		size_type max_size() const
		{
			return (allocator.max_size());
		};
		size_type size() const
		{
			return (_size);
		};
		bool empty() const
		{
			if (!_size)
				return (1);
			return (0);
		}
		key_compare get_comp() const
		{
			return (comp);
		}
		allocator_type get_allocator() const
		{
			return (allocator);
		}
			//---------------------------MODIFIERES------------------------------------//
		private:
			// typedef typename	std::allocator<tree>	tree_alloc;
			// typedef typename	std::allocator<ft::Node<key_type, mapped_type> >	tree_alloc;
			typedef typename 	allocator_type::template rebind<ft::Node<key_type, mapped_type> >::other	tree_alloc;
			tree_alloc									tree_allocator;
			tree *search(const value_type &val, tree *root)
			{
				
				if (!root || val.first == root->key_val.first)
					return (root);
				else if (comp(val.first, root->key_val.first))
					return (search(val, root->left));
				else
					return (search(val, root->right));

			}
		//---------------------------Moves_UTILS-----------------------------------//
		
		tree	*new_node(const value_type &val)
		{
			tree	*inserted = tree_allocator.allocate(1);
			tree_allocator.construct(inserted, Node<Key, T>());
			inserted->key_val = val;
			inserted->height = 1;
			inserted->left = NULL;
			inserted->right = NULL;
			inserted->parent = NULL;
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
			////std::cout << "y " << y->key_val.first << std::endl;
			////std::cout << "Before Rotation" <<//std::cout;
			// visualize_node(y, "y", "   ");
			// visualize_node(x, "x", "   ");
			////std::cout << "x " << x->key_val.first << std::endl;

			x->right = y;
			y->left = T2;
			if (y->parent)
			{
				if (y == y->parent->left)
					y->parent->left = x;
				else 
					y->parent->right = x;
			}
			x->parent = y->parent;
			y->parent = x;
			// if (y->parent)
			// {
			// 	if (y == y->parent->left)
			// 		y->parent->left = x;
			// 	else
			// 		y->parent->right = x;
			// }

			y->height = max_height(height(y->left), height(y->right)) + 1;
			x->height = max_height(height(x->left), height(x->right)) + 1;
			////std::cout << "After  Rotation" <<//std::cout;
			// visualize_node(y, "y", "   ");
			// visualize_node(x, "x", "   ");
			// std::cout << " 4 insinde RR seg" << std::endl;
			if (y->left)
					y->left->parent = y;
			// std::cout << " 5 insinde RR seg" << std::endl;
			return (x);
		}

		tree	*LL_rotate(tree *x)
		{
			tree*	y = x->right;
			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			if (x->parent)
			{
				if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
			}
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
				////std::cout << "makeing new node" << std::endl;
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
			////std::cout << "for node " << node->key_val.first << "  Blance factor = " << balance_factor << std::endl;
			if (balance_factor < -1)
			{
				
				if (comp(node->right->key_val.first, val.first))
				{
			////std::cout << "\nrotating around " << node->key_val.first;
			// 		std::cout << " LL Rotate val = " << val.first << std::endl;
					return (LL_rotate(node));
				}
				else if (comp(val.first, node->right->key_val.first))
				{
					////std::cout << "\n\nRL Rotating node with val = " << node->key_val.first << ", val = " << val.first<< std::endl;
					node->right = RR_rotate(node->right);
					return (LL_rotate(node));
					// return (RL_rotate(node));
				}
			}
			else if (balance_factor > 1)
			{
				if (comp(val.first, node->left->key_val.first))
				{
					// std::cout << "2-inserting "<< val.first << " => " << val.second << std::endl;
					////std::cout << "RR Rotate val = " << val.first << std::endl;
					return (RR_rotate(node));
				
				}
				else if (comp(node->left->key_val.first, val.first))
				{
					////std::cout << "LR Rotate val = " << val.first << std::endl;
					
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
		//-------------------------------INSERTION----------------//
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
				insert (*first);
				first++;
			}
		}
		//--------------------------END INSERT---------------------//
	private:
		tree	*do_find(const key_type &k, tree *root) const
		{
			if (!root || k == root->key_val.first)
				return (root);
			else if (comp(k, root->key_val.first))
				return (do_find(k, root->left));
			else
				return (do_find(k, root->right));
		}
	public:
		iterator find (const key_type& k)
		{
			// std::cout << "\nNormal find" << std::endl;
			tree *searched_node = do_find(k, get_root());
			if (!searched_node)
			{
				return (end());
			}
			return (iterator(searched_node));
		};
		const_iterator find (const key_type& k) const
		{
			// std::cout << "\nconst find" << std::endl;
			tree *searched_node = do_find(k, get_root());
			if (!searched_node)
				return (end());
			return (const_iterator(searched_node));
		};
		//------------------------DELETION--------------------// 
	private:
		tree	*seek_left_most(tree *seek_my_left)
		{
			tree	*left_most = seek_my_left;
			while(seek_my_left->left)
			{
				seek_my_left = seek_my_left->left;
				left_most = seek_my_left;
			}
			return (left_most);
		}
		void	delete_node(tree *root)
		{
			if (root)
			{
				tree_allocator.destroy(root);
				tree_allocator.deallocate(root, 1);
				root = NULL;
				--_size;
			}
		}
		int	is_root(tree *root)
		{
				if (!root->parent)
					return (1);
				else
					return (0);
		}
		void	delete_root_node(tree *root)
		{
			if (!root->left && !root->right)
			{
				////std::cout << "deleting bold root" << std::endl;
				if (!root->parent)
				{
					delete_node(root);
					root = NULL;
					_tree = NULL;
					return ;
				}
				_tree = get_root();
				if (root->parent)
				{
					if (root == root->parent->left)
						root->parent->left = NULL;
					else
						root->parent->right = NULL;
					_tree = root->parent;
				}
				delete_node(root);
			}
			else if (!root->right)
			{
				tree *successor = root->left;
				root->left->parent = root->parent;
				if (root->parent)
				{
					if (root == root->parent->left)
						root->parent->left = root->left;
					else
						root->parent->right = root->left;
				}
				delete_node(root);
				_tree = successor;
				root = NULL;
			}
			else if (!root->left)
			{
				tree *successor = root->right;
				// visualize_node(root, "node to be deleted", "      ");
				root->right->parent = root->parent;
				if (root->parent)
				{
					if (root == root->parent->left)
						root->parent->left = root->right;
					else
						root->parent->right = root->right;
				}
				delete_node(root);
				_tree = successor;
				////std::cout << "-----------------------" << std::endl;
				// _tree = successor;
				root = NULL;
			}
			else
			{
				tree	*successor = seek_left_most(root->right);

				if (successor == root->right)
				{
					// std::cout << _tree->key_val.first << std::endl;
					successor->left = root->left;
					root->left->parent = successor;
					successor->parent = root->parent;
				}
				else
				{
					if (successor->right)
					{
						successor->right->parent = successor->parent;
						successor->parent->left = successor->right;
					}
					else
					{
						successor->parent->left = root->parent;
					}
					successor->parent = root->parent;
					successor->left = root->left;
					successor->left->parent = successor;
					successor->right = root->right;
					successor->right->parent = successor;
				}
				if (root->parent)
				{
					if (root == root->parent->left)
						root->parent->left = successor;
					else
						root->parent->right = successor;
				}
				delete_node(root);
				root = NULL;
				_tree = successor;
			}
		}
		
		void	delete_tertiary_node(tree *node)
		{
			if (node == node->parent->left)
			{
				node->parent->left = NULL;
			
			}	else
					node->parent->right = NULL;
			delete_node(node);
			node = NULL;
		}

		bool	tertiatry_node(tree *node)
		{
			if (node->parent && !node->right && !node->left)
				return (true);
			else
				return (false);
		}

		tree	*do_delete(tree *root, key_type key)
		{
			if (root == NULL)
    			return root;
  			if (comp(key, root->key_val.first))
    			do_delete(root->left, key);
  			else if (comp(root->key_val.first, key))
    			do_delete(root->right, key);
			else
			{
				// if (is_root(root))
				// {
					delete_root_node(root);

					root = NULL;
					////std::cout << "before balancing" << std::endl;
					// if(_tree)
					// 	visualize_node(_tree->parent, "successor->parent" , " ");
					// visualize_node(_tree, "successor" , " ");
					////std::cout << "------------------------------\n" << "after balancing\n"; 
					
				// }
				// else if (tertiatry_node(root))
				// {
				// 	delete_tertiary_node(root);
				// 	// visualize_node(root->parent, "parent", " ");
				// 	// visualize_node(root->parent->parent, "root", " ");
				// 	root = NULL;
				// }
				// else 
				// {

				// }
				// root = NULL;
				// if ((root->left == NULL) || (root->right == NULL)) 
				// {
		    	// 	tree *tmp;
				// 	if (root->left)
    			// 		tmp = root->left;
				// 	else
				// 		tmp = root->right;
		    	// 	if (tmp == NULL) {
		    	// 	  tmp = root;
		    	// 	  root = NULL;
		    	// 	}
				// 	else
		    	// 	  *root = *tmp;
		    	// 	tree_allocator.destroy(tmp);
				// 	tree_allocator.deallocate(tmp, 1);
		  		// }
				// else 
				// {
		    	// 	tree *tmp = get_min(root->right);
		    	// 	root->key_val.first = tmp->key_val.first;
				// 	//founding the largest node in the left subtree
		    	// 	root->right = do_delete(root->right, tmp->key_val.first);
		  		// }
				// visualize_node(_tree, "successor", "      ");
				// visualize_node(_tree->parent, "successor new parent ", "      ");
				// sleep(1);
				// _tree = get_root();
			}
		  	if (root == NULL)
		  	  return (root);
		  	root->height = 1 + max_height(height(root->left),
		  	             height(root->right));
		  	int balanceFactor = getBalanceFactor(root);
		  	if (balanceFactor > 1) 
			{
		  	  if (getBalanceFactor(root->left) >= 0) {
		  	    return RR_rotate(root);
		  	  } else {
		  	    root->left = LL_rotate(root->left);
		  	    return RR_rotate(root);
		  	  }
		  	}
		  	else if (balanceFactor < -1) 
			{
		  		if (getBalanceFactor(root->right) <= 0)
		  	    	return LL_rotate(root);
		  		else
				{
		  			root->right = RR_rotate(root->right);
		  			return LL_rotate(root);
		  		}
		  	}
		  	return root;
		}
	public:
		void erase (iterator position)
		{
			do_delete(get_root(), position->first);
			////std::cout << "Delete done " << std::endl;
			_tree = get_root();
		};
		size_type erase (const key_type& k)
		{
			tree *delete_me = do_find(k, get_root());
			size_type erased = 0;
			if (delete_me)
			{
				do_delete(get_root(), k);
				++erased;
			}
			_tree = get_root();
			return (erased);
		};
		void erase (iterator first, iterator last)
		{
			iterator tmp = first;
			while(tmp != last)
			{
				
				tmp++; 
				erase(first);
				first = tmp;;
			}
		};
		// size_type erase (const key_type& k);

     	// void erase (iterator first, iterator last);
		//------------------------END DELETION----------------//
		mapped_type	&operator[](key_type const &k)
		{
			tree *searched_node = do_find(k, get_root());
			if (!searched_node)
			{
				value_type	insert_me(k);
				insert(insert_me);
				searched_node = do_find(k, get_root());
			}
			return (searched_node->key_val.second);
		} 
		iterator	begin() 
		{			
			return (iterator(get_min(_tree)));
		}

		const_iterator	begin() const
		{			
			return (const_iterator(get_min(_tree)));
		}
		iterator	end() 
		{
			iterator after_max(get_max(get_root()));
			++after_max;
 			return (after_max);
		}
		const_iterator	end() const
		{
			const_iterator after_max(get_max(get_root()));
			++after_max;
 			return (after_max);
		}
		reverse_iterator rend()
		{
			return (begin());
		}
		const_reverse_iterator rend() const
		{
			return (begin());
		}
		reverse_iterator rbegin()
		{
			return (end());
		}

		const_reverse_iterator rbegin() const
		{
			return (end());
		}
		// const_iterator find (const key_type& k) const;
		//---------------------------------AT-----------------//
		mapped_type& at (const key_type& k)
		{
			tree *tmp = do_find(k, get_root());
			if (!tmp)
				throw (std::out_of_range("Index out of range"));
			return (tmp->key_val.second);
			
		}
		const mapped_type& at (const key_type& k) const
		{
			tree *tmp = do_find(k, get_root());
			if (!tmp)
				throw (std::out_of_range("Index out of range"));
			return (tmp->key_val.second);
			
		}
		public:
		//------------------CONSTRUCTOR-------------------------------------------//
			map(const key_compare& comp = key_compare()
				, const allocator_type& alloc = allocator_type()):_tree(NULL),
					comp(comp), allocator(alloc), _root(get_root()), _size(0)
			{
			};
			template <class InputIterator> 
			map (InputIterator first, InputIterator last, 
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()):_tree(NULL),
					comp(comp), allocator(alloc), _root(get_root()), _size(0)
				{
					////std::cout << "range constructor called" << std::endl;
					insert(first, last);
				};
			map& operator= (const map& x)
			{
				if (this != &x)
				{				
					clear_all(get_root());
					_tree = NULL;
					_root = NULL;
					comp = x.get_comp();
					allocator = x.get_allocator();
					if (x.size())
					{
						
 						insert(x.begin(), x.end());
					}
					else
					{
						_tree = NULL;
						_size = 0;
					}
					_size = x.size();
					// _root = get_root();
					// _size = x.size();
				}
				return (*this);
			}
			map (const map& x)
			{
				if (_size)
					_tree = NULL;
				if (this != &x)
					*this = x;
			}
			void	clear_all(tree *root)
			{
				if (!root)
					return;
				if (root->right)
					clear_all(root->right);
				if (root->left)
					clear_all(root->left);
				_size--;
				tree_allocator.destroy(root);
				tree_allocator.deallocate(root, 1);
				root = NULL;
			}
			void clear()
			{
				tree	*root = get_root();
				clear_all(root);
				_tree= NULL;
				_root = NULL;
				_size = 0;
			};
			void	vis_tree_node_by_node(tree	*root)
			{
				if (!root)
					return;
				if (root->right)
					vis_tree_node_by_node(root->right);
				if (root->left)
					vis_tree_node_by_node(root->left);
				// visualize_node(root, "node", " ");
			};
			~map()
			{
				////std::cout << "Destructor called" << std::endl;
				////std::cout << "visualizing tree node by node" << std::endl;
				// vis_tree_node_by_node(get_root());
				tree	*root = get_root();
				clear_all(root);
			};
			tree *base() const
			{
				return (get_root());
			}
			void	set_size(size_type input)
			{
				_size = input;
			}
			void 	set_base(tree *input)
			{
				_tree = input;
			}
			key_compare key_comp() const
			{
				return (comp);
			}
			void swap (map& x)
			{
				
				tree				*tmp_tree = _tree;
				key_compare			tmp_comp = comp;
				size_type			tmp_size = size();

				_tree = x.base();
				comp =  x.key_comp();
				_root = get_root();
				_size = x.size();

				x.set_base(tmp_tree);
				x.get_comp() = tmp_comp;
				x.set_size(tmp_size);

			}
		tree	const *do_find_const(const key_type &k, tree *root) const
		{
			if (!root || k == root->key_val.first)
				return (root);
			else if (comp(k, root->key_val.first))
				return (do_find_const(k, root->left));
			else
				return (do_find_const(k, root->right));
		}
		size_type count (const key_type& k) const
		{
			// _tree = get_root();
			tree *search_me = get_root();
			if (do_find_const(k, search_me))
				return (1);
			return (0);
		};
		iterator lower_bound (const key_type& k)
		{
			iterator lower = begin();
			
			while (lower != end())
			{
				if(!(comp(lower->first, k)))
					return (lower);
				++lower;
			}
			return (end());
			// for (lower = get_max(get_root()); lower != begin(); lower--)
			// {
			// 	if((comp(lower->first, k)))
			// 		return (lower);
			// }
			
		};
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator lower = begin();
			
			while (lower != end())
			{
				if(!(comp(lower->first, k)))
					return (lower);
				++lower;
			}
			return (end());
			// for (lower = get_max(get_root()); lower != begin(); lower--)
			// {
			// 	if((comp(lower->first, k)))
			// 		return (lower);
			// }
			
		};
		iterator upper_bound (const key_type& k)
		{
			iterator upper;
			for (upper = begin(); upper != end(); upper++)
			{
				if((comp(k, upper->first)))
					return (upper);
			}
			return (end());			
		};
		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator upper;
			for (upper = begin(); upper != end(); upper++)
			{
				if((comp(k, upper->first)))
					return (upper);
			}
			return (end());
		};
		pair<iterator,iterator>             equal_range (const key_type& k)
		{
			pair<iterator, iterator> result;
			result.first = lower_bound(k);
			result.second = upper_bound(k);
			return (result);
		}
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			pair<const_iterator, const_iterator> result;
			result.first = lower_bound(k);
			result.second = upper_bound(k);
			return (result);
		}
		
class value_compare
		{
			friend class map;
			
			protected:
				Compare comp;
				value_compare(Compare c): comp(c) {};
			public:
				typedef bool 		result_type;
				typedef value_type	first_argument;
				typedef value_type	second_argument;
				bool operator ()(const first_argument &x, const second_argument &y)
				{
					return (comp(x.first, y.first));
				}
		};
		
		value_compare value_comp() const
		{
			value_compare val_comp(comp);
			return (val_comp);
		};
	};
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
	bool operator== (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator<  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
	{

		return (ft::lexicographical_compare(
			lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator!= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T, class Alloc>
	bool operator<= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	};
	template <class T, class Alloc>
	bool operator>  (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	};
	template <class T, class Alloc>
	bool operator>= (const map<T,Alloc>& lhs, const map<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	};

	template <class T, class Alloc>
	void	swap(map<T,Alloc>& x, map<T,Alloc>& y)
	{
		x.swap(y);
		// vector<T> tmp(x);

		// x = y;
		// y = tmp;
	};
	template < class iter1, class iter2>
	bool operator==(const iterator<iter2>& rhs, const const_iterator<iter1>& lhs)
	{
			// 	if (lhs.get_before_start() == rhs.get_before_start()
			// 	|| lhs.get_end() == rhs.get_end())
			// return (true);
		if (!lhs.base() && !rhs.base())
			return (true);
			else if (!lhs.base() || !rhs.base())
		{
			if (lhs.get_before_start() == rhs.get_before_start()
				&& lhs.get_end() == rhs.get_end())
				return (true);
			return (false);
		}
		return (lhs.get_before_start() == rhs.get_before_start()
				&& lhs.get_end() == rhs.get_end()
			 	&& lhs.base() == rhs.base());
	};
		template < class iter1, class iter2>
	bool operator!=(const iterator<iter1>& lhs, const const_iterator<iter2>& rhs)
	{
		return (!(lhs == rhs));
	}
	template < class iter1, class iter2>
	bool operator< (const iterator<iter1>& lhs, const const_iterator<iter2>& rhs)
	{
		return (lhs->first < rhs->first);
	};
	
	template < class iter1, class iter2>
	bool operator> (const iterator<iter1>& lhs, const const_iterator<iter2>& rhs)
	{
		return (lhs->first > rhs->first);
	};
	template < class iter1, class iter2>
	bool operator>= (const iterator<iter1>& lhs, const const_iterator<iter2>& rhs)
	{
		return (lhs->first >= rhs->first);
	};
	template < class iter1, class iter2>
	bool operator<= (const iterator<iter1>& lhs, const const_iterator<iter2>& rhs)
	{
		if (lhs == rhs)
			return (true);
		return (lhs < rhs);
	};
	//------------------HORRIBLE HARD CODING AS PRICE FOR NOT USING ONE CLASS FOR CONST AND NORMAL ITERATOR----//
		template < class iter1, class iter2>
	bool operator==(const const_iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
			// 	if (lhs.get_before_start() == rhs.get_before_start()
			// 	|| lhs.get_end() == rhs.get_end())
			// return (true);
		if (!lhs.base() && !rhs.base())
			return (true);
			else if (!lhs.base() || !rhs.base())
		{
			if (lhs.get_before_start() == rhs.get_before_start()
				&& lhs.get_end() == rhs.get_end())
				return (true);
			return (false);
		}
		return (lhs.get_before_start() == rhs.get_before_start()
				&& lhs.get_end() == rhs.get_end()
			 	&& lhs.base() == rhs.base());
	};
		template < class iter1, class iter2>
	bool operator!=(const const_iterator<iter2>& rhs, const iterator<iter1>& lhs)
	{
		return (!(lhs == rhs));
	}
	template < class iter1, class iter2>
	bool operator< (const const_iterator<iter2>& rhs, const iterator<iter1>& lhs)
	{
		return (lhs->first < rhs->first);
	};
	
	template < class iter1, class iter2>
	bool operator> (const const_iterator<iter2>& rhs, const iterator<iter1>& lhs)
	{
		return (lhs->first > rhs->first);
	};
	template < class iter1, class iter2>
	bool operator>= (const const_iterator<iter2>& rhs, const iterator<iter1>& lhs)
	{
		return (lhs->first >= rhs->first);
	};
	template < class iter1, class iter2>
	bool operator<= (const const_iterator<iter2>& rhs, const iterator<iter1>& lhs)
	{
		if (lhs == rhs)
			return (true);
		return (lhs < rhs);
	};
}
#endif


//TODO inshalla
//public
	//constructors
	// template <class InputIterator>  map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
		// //copy const
	// map (const map& x);
	