/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functional.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 09:06:51 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/05 11:32:10 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 	first_argument_type;
		typedef Arg2 	second_argument_type;
		typedef Result 	result_type;
	};

	template <class T>
	struct less: ft::binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const
		{
			return (x < y);
		}
	};

	template <class T>
	struct greater: ft::binary_function<T, T, bool>
	{
		bool operator() (const T& x, const T& y) const
		{
			return (x > y);
		}
	};
}

#endif