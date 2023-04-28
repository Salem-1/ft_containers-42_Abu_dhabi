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

//modify the max++ and min-- and min-- then ++ and max ++ then --
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
	    	typedef typename tree::value_type		value_type;
	    	typedef Distance 				difference_type;
	    	typedef tree					*pointer;
	    	typedef tree&					reference;
	    	typedef Category				iterator_category;
		
		protected:
			pointer						_node;
		public:
			pointer	base() const
			{
				return (_node);
			}
			iterator(): _node(NULL){};
			iterator(pointer ptr) : _node(ptr){};
			iterator &operator= (iterator const &ptr)
			{
				if (this != &ptr)
				{
					this->_node = ptr.base();
				}
				return (*this);
			};
			~iterator(){};
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
			int	is_root()
			{
				if (!_node || !_node->parent)
					return (1);
				else
					return (0);
			}
			int	is_left_child_and_has_parent(void)
			{
				if (_node->parent && _node == _node->parent->left)
					return (1);
				return (0);
			}
			int		is_right_child_and_has_parent()
			{
				if(_node->parent && _node == _node->parent->right)
					return (1);
				else
					return (0);
			}
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
			tree	*seek_right_most(tree *seek_my_right)
			{
				tree	*right_most = seek_my_right;
				while(seek_my_right->right)
				{
					seek_my_right = seek_my_right->right;
					right_most = seek_my_right;
				}
				return (right_most);
			}
			tree	*increment_of_left_child(void)
			{
				if (!_node->right)
					return (_node->parent);
				if (!_node->right->left)
					return (_node->right);
				return seek_left_most(_node->right);
			}
			tree	*decrement_of_right_child(void)
			{
				if (!_node->left)
					return (_node->parent);
				if (!_node->left->right)
					return (_node->left);
				return seek_right_most(_node->left);
			}


			tree*	seek_parent_of_first_left(tree	*seek_me)
			{
				tree	*tmp = NULL;
				if (!seek_me->parent)
					return (tmp);
				while(seek_me == seek_me->parent->right)
				{
					tmp = seek_me->parent;
					seek_me = seek_me->parent;
					if (!seek_me)
						return (NULL);
					tmp = seek_me->parent;
				}
				return (tmp);
			}
			tree*	seek_parent_of_first_right(tree	*seek_me)
			{
				tree	*tmp = NULL;
				if (!seek_me->parent)
					return (tmp);
				while(seek_me == seek_me->parent->left)
				{
					tmp = seek_me->parent;
					seek_me = seek_me->parent;
					if (!seek_me)
						return (NULL);
					tmp = seek_me->parent;
				}
				return (tmp);
			}
			tree *get_root()
			{
				tree *root = _node;
				if (!root)
					return (NULL);
				while (root->parent)
					root = root->parent;
				return (root);
			}
			tree	*get_min()
			{
				tree *root = get_root();
				if (!root)
					return (NULL);
				while (root->left)
					root = root->left;
				return (root);			
			}
			tree	*get_max()
			{
				tree *root = get_root();
				if (!root)
					return (NULL);
				while (root->right)
					root = root->right;
				return (root);			
			}

			tree	*decrement_of_left_child()
			{
				if (_node->left)
				{
					if (!_node->left->left)
						return (_node->left);
					else
						return (seek_left_most(_node->left));
				}
				else
				{
					if (_node == get_min())
						return (_node--);
					return (seek_parent_of_first_right(_node));
				}
			}
			tree	*increment_of_right_child(void)
			{
				if (_node->right)
				{
					if (!_node->right->left)
						return (_node->right);
					else
						return (seek_left_most(_node->right));
				}
				else
				{
					if (_node == get_max())
						return (NULL);
						// return (_node++);
					return (seek_parent_of_first_left(_node));
				}
			}
			tree	*increment_root(tree *root)
			{
				if (!root)
					return (++root);
				if (!root->right)
					return (++root);
				if (!root->right->left)
					return (root->right);
				else
				{
					return (seek_left_most(root->right));
				}
			}
			tree	*decrement_root(tree *root)
			{
				if (!root || !root->left)
					return (--root);
				else if (root->left && !root->left->right)
					return (root->left);
				else
					return (seek_right_most(root->left));
			}
		public:
			inline value_type	*operator->() const
			{
				return &(_node->key_val);
			}
			iterator &operator++()
			{
				if (is_root())
					*this = iterator(increment_root(_node));
				else if (is_left_child_and_has_parent())
					*this = iterator(increment_of_left_child());
				else if (is_right_child_and_has_parent())
					*this = iterator(increment_of_right_child());
				return (*this);
			}
			iterator operator++(int)
			{
				iterator tmp(*this);
				iterator increment(*this);

				++increment;
				*this = increment;
				return (tmp);
			}
			iterator	&operator--()
			{
				if (is_root())
					*this = iterator(decrement_root(_node));
				else if (is_left_child_and_has_parent())
					*this = iterator(decrement_of_left_child());
				else if (is_right_child_and_has_parent())
					*this = iterator(decrement_of_right_child());
				
				return (*this);
			}
			iterator operator--(int)
			{
				iterator tmp(*this);
				iterator decrement(*this);

				--decrement;
				*this = decrement;
				return (tmp);
			}
			iterator	&operator +=(int inc)
			{
				if (inc == 0)
					return (*this);
				iterator	tmp(*this);
				if (inc > 0)
				{
					while (inc > 0)
					{
						++tmp;
						inc--;
					}
				}
				else
				{
					while (inc < 0)
					{
						--tmp;
						inc++;
					}
				}
				*this = tmp;
				return (*this);
			}
			iterator &operator-= (int dec)
			{
				if (dec == 0)
					return (*this);
				iterator	tmp(*this);
				if (dec > 0)
				{
					while (dec > 0)
					{
						--tmp;
						dec--;
					}
				}
				else
				{
					while (dec < 0)
					{
						++tmp;
						dec++;
					}
				}
				*this = tmp;
				return (*this);
			}
			// bool	operator==(iterator &b)
			// {
			// 	if (!_node && !b.base())
			// 		return (true);
			// 	else if (!_node || !b.base())
			// 		return (false);
			// 	return (_node->key_val.first == b->first);
			// }
			// bool	operator!=(iterator &b)
			// {
			// 	if (!_node && !b.base())
			// 		return (false);
			// 	else if (!_node || !b.base())
			// 		return (true);
			// 	return (_node->key_val.first != b->first);
			// }

 	};

	template < class iter1, class iter2>
	bool operator==(const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		if (!lhs.base() && !rhs.base())
			return (true);
		else if (!lhs.base() || !rhs.base())
			return (false);
		return (lhs.base() == rhs.base());
	};
	template < class iter1, class iter2>
	bool operator!=(const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		return (!(lhs == rhs));
	}
	template < class iter1, class iter2>
	bool operator< (const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		return (lhs->first < rhs->first);
	};
	
	template < class iter1, class iter2>
	bool operator> (const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		return (lhs->first > rhs->first);
	};
	template < class iter1, class iter2>
	bool operator>= (const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		return (lhs->first >= rhs->first);
	};
	template < class iter1, class iter2>
	bool operator<= (const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		if (lhs == rhs)
			return (true);
		return (lhs < rhs);
	};
	

	// template < class iter1, class iter2>
	// std::ptrdiff_t operator-(const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	// {
	// 	return (lhs.base() - rhs.base());
	// }
	// template < class iter1>
	// iterator<iter1> operator+ (
	// 	typename iterator<iter1>::difference_type d, const iterator<iter1>& lhs)
	// {
	// 	return (lhs.base() + d);
	// }

	template < class iter1>
	iterator<iter1> operator+ (const iterator<iter1>& lhs,
		int d)
	{
		return (lhs += d);
	}
	template < class iter1>
	iterator<iter1>  operator- (const iterator<iter1>& lhs,
		typename iterator<iter1>::difference_type d)
	{
		return (lhs -= d);
	}
}
#endif