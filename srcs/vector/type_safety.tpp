/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_safety.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahsalem <ahsalem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:27:02 by ahsalem           #+#    #+#             */
/*   Updated: 2023/03/26 16:37:33 by ahsalem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_SAFETY_TPP
# define TYPE_SAFETY_TPP
# include <iostream>

namespace ft{
	//enable_if in C++98
	template<bool Cond, typename T = void>
	struct enable_if 
	{
		typedef T type;
	};
	template<typename T>
	struct enable_if <false, T> 
	{};
	
    template<typename T>
    struct is_integral {
        static const bool value = false;
    };

	template<>
	struct is_integral<bool> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<char> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<wchar_t> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<signed char> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<short int> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<int> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<long int> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<long long int> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned char> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned short int> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned int> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned long int> 
	{
		static const bool value = true;
	};
	template<>
	struct is_integral<unsigned long long int> 
	{
		static const bool value = true;
	};
};
#endif
