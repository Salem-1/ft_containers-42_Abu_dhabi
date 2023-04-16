/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 06:29:45 by ahsalem           #+#    #+#             */
/*   Updated: 2023/04/15 19:55:01 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTISL_HPP
# define MAP_UTISL_HPP
#include "tree.hpp"

namespace ft
{
	int	max_height(int a, int b)
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	template<class T1, class T2>
	int	get_balance(Node<T1, T2> root)
	{
		if(root.empty)
 			return 0;
		return (root.left->height - root.right->height);
	}

}
#endif