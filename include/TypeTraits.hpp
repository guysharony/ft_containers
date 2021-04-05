/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeTraits.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:47:15 by gsharony          #+#    #+#             */
/*   Updated: 2020/12/30 08:21:42 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPETRAITS_HPP
# define TYPETRAITS_HPP

# include <iostream>

namespace ft
{
	template <typename T, T v>
	struct integral_constant {
		static const T value = v;
		typedef T 							value_type;
		typedef ft::integral_constant<T, v>	type;
		operator T() {return v; }
	};

	template <class T>
	struct is_integral : public integral_constant<bool, false> {};

	template <>
	struct is_integral<bool> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<char> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<signed char> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<short int> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<int> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<long int> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<long long int> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned char> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned short int> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned int> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long int> : public integral_constant<bool, true> {};

	template <>
	struct is_integral<unsigned long long int> : public integral_constant<bool, true> {};

	template <class T>
	struct is_float : public integral_constant<bool, false> {};

	template <>
	struct is_float<float> : public integral_constant<bool, true> {};

	template <class T>
	struct is_double : public integral_constant<bool, false> {};

	template <>
	struct is_double<double> : public integral_constant<bool, true> {};

	typedef ft::integral_constant<bool, true> 								true_type;
	typedef ft::integral_constant<bool, false> 								false_type;
}

#endif
