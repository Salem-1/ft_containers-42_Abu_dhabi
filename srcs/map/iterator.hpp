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
		class Category = ft::random_access_iterator_tag,
		class Distance = ptrdiff_t,
		class Pointer = tree*,
		class Reference = tree&
	> class iterator
	{
		public:
	    	typedef typename tree::value_type		value_type;
			typedef			const value_type		const_value_type;
	    	typedef Distance 				difference_type;
	    	typedef tree					*pointer;
			typedef pointer			const_pointer_type;
	    	typedef tree&					reference;
	    	typedef Category				iterator_category;
		
		protected:
			pointer						_node;
			int							is_end;
			int							before_start;
			value_type					_val;
		public:
			pointer	base() const
			{
				return (_node);
			}
			int	get_end() const
			{
				return (is_end);
			}
			int	get_before_start() const
			{
				return (before_start);
			}
			void	set_end(int input)
			{
				is_end = input;
			}
			void	set_before_start(int input)
			{
				before_start = input;
			}
			iterator(): _node(pointer()), is_end(0), before_start(0), _val(value_type()) {};
			iterator(pointer ptr) : _node(ptr), is_end(0), before_start(0)
			{
				if (ptr)
					_val = ptr->key_val;
				else
					_val = value_type();
			};

// //const iterator
// 			iterator(const_pointer ptr): _node(ptr), is_end(0), before_start(0){};
// 			iterator(const iterator& it): _node(it.base()), is_end(it.end), before {};
			template <typename input_iterator>		
			iterator(const iterator<input_iterator>& it): _node(it.base()), is_end(it.get_end()), before_start(it.get_before_start())
			{
				std::cout << "called this constructor" << std::endl;
				if (it.base())
					_val = it.base()->key_val;
				else
					_val = value_type();
			};
			
			iterator &operator= (iterator const &ptr)
			{
				if (this != &ptr)
				{
					this->_node = ptr.base();
					this->is_end = ptr.get_end();
					this->before_start = ptr.get_before_start();
					this->_val = ptr.get_val();
				}
				return (*this);
			};
			value_type get_val() const 
			{
				return (_val);
			}
			iterator(iterator const &ptr)
			{
				*this = ptr;
			}
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
		//-----------------DECREMENTER----------------------//
			tree	*decrement_of_right_child(void)
			{
				if (!_node->left)
					return (_node->parent);
				if (!_node->left->right)
					return (_node->left);
				return seek_right_most(_node->left);
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
					{
						before_start = 1;
						return (_node);
					}
					return (seek_parent_of_first_right(_node));
				}
			}
			tree	*decrement_root(tree *root)
			{
				if (!root)
					return (--root);
				else if(!root->left)
				{
					before_start = 1;
					return (root);
				}
				else if (root->left && !root->left->right)
					return (root->left);
				else
					return (seek_right_most(root->left));
			}
			tree	*decrement_end()
			{
				is_end = 0;
				return (_node);
			}
			tree	*decrement_first_node()
			{
				before_start = 1;
				return (_node);
			}
			//------------------END-DECREMENTER---------------//
			//-----------------INCREMENTERS-------------------//
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
					{
						is_end = 1;
						return (_node);
					}	// return (_node++);
					return (seek_parent_of_first_left(_node));
				}
			}
			
			tree	*increment_of_left_child(void)
			{
				if (!_node->right)
					return (_node->parent);
				if (!_node->right->left)
					return (_node->right);
				return seek_left_most(_node->right);
			}

			tree	*increment_root(tree *root)
			{
				tree	*result = NULL;
				if (!root)
					return (++root);
				if (!root->right)
					result = root;;
				if (!root->right->left)
					result = root->right;
				else
				{
					return (seek_left_most(root->right));
				}
				if (result == get_max())
					is_end = 1;
				return(result);
			}
			iterator	increment_after_end()
			{
				iterator after_last;
				after_last.set_end(0);
				return (after_last);
			}
			tree	*increment_before_start()
			{
				before_start = 0;
				return (_node);
			}
			//-----------------END-INCREMENTERS-------------------//
			//-----------------OPERATORS------------------------//
		public:
			inline value_type	*operator->() const
			{
				// if (is_end || before_start)
				// 	return (NULL);
				return &(_node->key_val);
			}
			inline value_type	&operator*() const
			{
				// value_type &trash;
				// if (is_end || before_start)
				// 	return (trash);
				return (_node->key_val);
			}
			iterator &operator++()
			{
				if (before_start)
					*this  = iterator(increment_before_start());
				else if (is_end)
					*this = increment_after_end();
				else if (_node == get_max())
					is_end = 1;
				else if (is_root())
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
				if (is_end)
				{
					// std::cout << "case print after end "<< std::endl;
					is_end = 0;
					// *this = iterator(decrement_end());
				}
				else if (_node == get_min())
				{
					*this =  iterator(decrement_first_node());
					before_start = 1;
				}
				else if (is_root())
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
		// if ((lhs.get_before_start() == rhs.get_before_start()
		// 		|| lhs.get_end() == rhs.get_end()))
		// {
		// 	return (true);
		// }
		if (!lhs.base() && !rhs.base())
		{
			std::cout << "no base" << std::endl;
			return (true);
		}
		else if (!lhs.base() || !rhs.base())
		{
			if (lhs.get_before_start() == rhs.get_before_start()
				&& lhs.get_end() == rhs.get_end())
				return (true);
			// std:: cout << "one without base" << std::endl;
			return (false);
		}
	
			
		return (lhs.get_before_start() == rhs.get_before_start()
				&& lhs.get_end() == rhs.get_end()
			 	&& lhs.base() == rhs.base());
	};
	template < class iter1, class iter2>
	bool operator!=(const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		return (!(lhs == rhs));
	}
	template < class iter1, class iter2>
	bool operator< (const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};
	
	template < class iter1, class iter2>
	bool operator> (const iterator<iter1>& lhs, const iterator<iter2>& rhs)
	{
		return (lhs.base() > rhs.base());
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