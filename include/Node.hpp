/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:25:33 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/09 06:15:51 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include <limits>

namespace ft
{
	template <typename T>
	struct Node
	{
		Node*		prev;
		Node*		next;
		T			data;

		Node() : prev(), next(), data() {}
		Node(T const & value) : data(value) {}
	};
		
	template <typename T>
	struct Binary_tree_node
	{
		typedef T 			value_type;

		bool				color;
		Binary_tree_node*	parent;
		Binary_tree_node*	left;
		Binary_tree_node* 	right;
		value_type			value;

		Binary_tree_node()
		:
			color(false),
			parent(NULL),
			left(NULL),
			right(NULL),
			value()
		{}

		Binary_tree_node(bool c, const value_type& v)
		:
			color(c),
			parent(NULL),
			left(NULL),
			right(NULL),
			value(v)
		{}
	};

}

#endif
