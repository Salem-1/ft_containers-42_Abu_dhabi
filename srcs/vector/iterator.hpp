/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 22:22:00 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/20 22:25:19 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <iostream>

template < class T>
class iterator
{
	public:
		T*	begin();
		T*	end();
		T*	rbegin();
		T*	rend();
		T*	cbegin();
		T*	cend();
		T*	crbegin();
		T*	crend();
};
#endif