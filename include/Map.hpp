/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:37:28 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/12 10:41:13 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "Binary_tree.hpp"

namespace ft
{	
	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{			
		public:
			typedef Key 												key_type;
			typedef T 													mapped_type;
			typedef ft::pair<const Key, T>								value_type;
			typedef Compare												key_compare;
			class 	value_compare: public ft::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c)
					: comp(c) {}

				public:
					~value_compare() {};
					
					bool operator() (const value_type& x, const value_type& y) const
					{ return comp(x.first, y.first); }
			};
			typedef Alloc												allocator_type;

		private:
			typedef ft::Binary_tree<key_type, value_type, key_compare>	tree_type;
			
		public:
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename tree_type::iterator						iterator;
			typedef typename tree_type::const_iterator					const_iterator;
			typedef typename tree_type::reverse_iterator				reverse_iterator;
			typedef typename tree_type::const_reverse_iterator			const_reverse_iterator;

			typedef ptrdiff_t 											difference_type;
			typedef size_t												size_type;
			
			explicit 	map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:
				_node(comp, alloc)
			{}

			template <class InputIterator>
  			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:
				_node(comp, alloc)
			{
				this->insert(first, last);
			}

			map(const map& x)
			:
				_node(x._node)
			{}

			~map()
			{}

			map& 										operator=(const map& x)
			{
				this->_node = x._node;
				return (*this);
			}

			iterator									begin()
			{
				return (_node.begin());
			}

			const_iterator								begin() const
			{
				return (_node.begin());
			}

			iterator									end()
			{
				return (_node.end());
			}

			const_iterator								end() const
			{
				return (_node.end());
			}

			reverse_iterator							rbegin()
			{
				return (_node.rbegin());
			}

			const_reverse_iterator						rbegin() const
			{
				return (_node.rbegin());
			}

			reverse_iterator							rend()
			{
				return (_node.rend());
			}

			const_reverse_iterator						rend() const
			{
				return (_node.rend());
			}

			bool 										empty() const
			{
				return (_node.empty());
			}

			size_type 									size() const
			{
				return (_node.size());
			}

			size_type 									max_size() const
			{
				return (_node.max_size());
			}

			iterator 									find(const key_type& k)
			{
				return (_node.find(k));
			}

			const_iterator 								find(const key_type& k) const
			{
				return (_node.find(k));
			}

			ft::pair<iterator, bool> 					insert(const value_type& val)
			{
				return (_node.insert(val));
			}

			iterator 									insert(iterator position, const value_type& val)
			{
				return (_node.insert(position, val));
			}

			template <class InputIterator>
  			void 										insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					this->insert(*first++);
			}

			void 										clear()
			{
				_node.remove(begin(), end());
			}

			mapped_type& 								operator[](const key_type& k)
			{
				if (find(k) == end()) insert(value_type(k, mapped_type()));
				return (find(k)->second);
			}

			size_type 									count(const key_type& k) const
			{
				if (find(k) == end())
					return (0);
				return (1);
			}

			void 										swap(map& x)
			{
				_node.swap(x._node);
			}

			void 										erase(iterator position)
			{
				_node.remove(position);
			}

			size_type 									erase(const key_type& k)
			{
				iterator tmp = find(k);

				if (tmp != end()) {
					this->erase(tmp);
					return (1);
				}
				return (0);
			}

			void 										erase(iterator first, iterator last)
			{
				while (first != last)
					this->erase(first++);
			}

			key_compare 								key_comp() const
			{
				return (key_compare());
			}

			value_compare 								value_comp() const
			{
				return (value_compare(key_compare()));
			}

			iterator 									lower_bound(const key_type& k)
			{	
				return (iterator(_node.lower_bound(k)));
			}

			const_iterator 								lower_bound(const key_type& k) const
			{	
				return (const_iterator(_node.lower_bound(k)));
			}

			iterator 									upper_bound(const key_type& k)
			{	
				return (iterator(_node.upper_bound(k)));
			}

			const_iterator 								upper_bound(const key_type& k) const
			{	
				return (const_iterator(_node.upper_bound(k)));
			}

			ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{
				return (ft::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

			ft::pair<iterator, iterator>				equal_range(const key_type& k)
			{
				return (ft::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

		private:
			tree_type									_node;
	};

	template < class Key, class T, class Compare, class Alloc >
  	bool 	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename map<Key, T, Compare, Alloc>::const_iterator first1 = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator first2 = rhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator last1 = lhs.end();
		typename map<Key, T, Compare, Alloc>::const_iterator last2 = rhs.end();
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template < class Key, class T, class Compare, class Alloc >
  	bool 	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template < class Key, class T, class Compare, class Alloc >
  	bool 	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template < class Key, class T, class Compare, class Alloc >
  	bool 	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template < class Key, class T, class Compare, class Alloc >
  	bool 	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template < class Key, class T, class Compare, class Alloc >
  	bool 	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template < class Key, class T, class Compare, class Alloc >
  	void	swap(map<Key, T, Compare, Alloc>& lhs, map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}

}

#endif