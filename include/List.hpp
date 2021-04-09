/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:00:14 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/09 12:37:27 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <cstddef>
# include "Algorithm.hpp"
# include "Iterator.hpp"
# include "TypeTraits.hpp"
# include "Functional.hpp"
# include "Node.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T 												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::list_iterator<T>							iterator;
			typedef ft::list_const_iterator<T>						const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

			explicit list (const allocator_type& alloc = allocator_type())
			:
				_allocator(alloc),
				_size(0)
			{
				_node_init();
			}

			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			:
				_allocator(alloc),
				_size(0)
			{
				_node_init();
				_node->data = static_cast<value_type>(this->_new_size(n));
				
				_init_fill(n, val);
			}

			template <class InputIterator>
  			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			:
				_allocator(alloc),
				_size(0)
			{
				typedef typename ft::is_integral<InputIterator>::type 	type;

				_node_init();
				_init_fill(first, last, type());
			}

			list (const list& x)
			:
				_allocator(x._allocator),
				_size(0)
			{
				_node_init();
				_init_fill(x.begin(), x.end(), false_type());
			}

			~list()
			{
				this->_clear();
				delete _node;
			}

			list& 							operator=(const list & x)
			{
				this->assign(x.begin(), x.end());
				return (*this);
			}

			iterator						begin(void)
			{
				return (iterator(_node->next));
			}

			const_iterator					begin(void) const
			{
				return (const_iterator(_node->next));
			}

			iterator						end(void)
			{
				return (iterator(_node));
			}

			const_iterator					end(void) const
			{
				return (const_iterator(_node));
			}

			reverse_iterator 				rbegin(void)
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator			rbegin(void) const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator 				rend(void)
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator 			rend(void) const
			{
				return (const_reverse_iterator(begin()));
			}

			size_type						size(void) const
			{
				return (_size);
			}

			size_type 						max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(Node<T>));
			}

			bool 							empty(void) const
			{
				return ((!_size) ? true : false);
			}

			reference 						front(void)
			{
				return (*begin());
			}

			const_reference 				front(void) const
			{
				return (*begin());
			}

			reference 						back(void)
			{
				iterator			tmp = end();
				return (*(--tmp));
			}

			const_reference 				back(void) const
			{
				const_iterator		tmp = end();
				return (*(--tmp));
			}

			template <class InputIterator>
  			void 							assign(InputIterator first, InputIterator last)
			{
				typedef typename ft::is_integral<InputIterator>::type	type;
				this->_node_fill(first, last, type());
			}

			void 							assign(size_type n, const value_type& val)
			{
				this->_node_fill(n, val, true_type());
			}

			void 							push_front(const value_type& val)
			{
				this->_insert(begin(), val);
			}

			void 							pop_front(void)
			{
				this->_remove(begin());
			}

			void 							push_back(const value_type& val)
			{
				this->_insert(end(), val);
			}

			void							pop_back(void)
			{
				this->_remove(iterator(_node->prev));
			}

			iterator 						insert(iterator position, const value_type& val)
			{
				this->_insert(position, val);
				return (iterator(position.node->prev));
			}

			void 							insert(iterator position, size_type n, const value_type& val)
			{
				while (n--)
					this->_insert(position.node, val);
			}

			template <class InputIterator>
    		void 							insert(iterator position, InputIterator first, InputIterator last)
			{
				typedef typename ft::is_integral<InputIterator>::type type;
				this->_node_insert(position, first, last, type());
			}

			iterator 						erase(iterator position)
			{
				iterator			tmp(position.node->next);
				this->_remove(position.node);
				return (tmp);
			}

			iterator 						erase(iterator first, iterator last)
			{
				while (first != last)
					first = this->erase(first);
				return (last);
			}

			void 							swap(list& x)
			{
				Node<T>*					_x_node = x._node;
				size_type					_x_size = x._size;

				x._node = this->_node;
				x._size = this->_size;

				this->_node = _x_node;
				this->_size = _x_size;
			}

			void 							resize(size_type n, value_type val = value_type())
			{
				if (n < this->size()) {
					while (n < this->size())
						this->pop_back();
				} else {
					while (n > this->size())
						this->push_back(val);
				}
			}

			void 							clear(void)
			{
				this->_clear();
				_node->next = _node;
				_node->prev = _node;
			}

			void 							splice(iterator position, list& x)
			{
				iterator					tmp = x.begin();

				if (!x.empty()) {
					while (tmp != x.end()) {
						this->_insert(position, *(tmp++));
						x.pop_front();
					}
				}
			}

			void 							splice(iterator position, list& x, iterator i)
			{
				if (!x.empty()) {
					this->_insert(position, *i);
					x.erase(i);
				}
			}

			void 							splice(iterator position, list& x, iterator first, iterator last)
			{
				iterator					tmp;

				if (!x.empty()) {
					while (first != last) {
						tmp = first;
						this->_insert(position, *(first++));
						x.erase(tmp);
					}
				}
			}

			void 							remove(const value_type& val)
			{
				iterator	tmp;

				for (iterator _begin = begin(); _begin != end(); _begin++) {
					if (*_begin == val)
					{
						tmp = ++_begin;
						this->_remove(--_begin);
						_begin = --tmp;
					}
				}
			}

			template <class Predicate>
  			void 							remove_if(Predicate pred)
			{
				iterator	tmp;
				
				for (iterator _begin = begin(); _begin != end(); _begin++) {
					if (pred(*_begin))
					{
						tmp = ++_begin;
						this->_remove(--_begin);
						_begin = --tmp;
					}
				}
			}

			void 							unique()
			{
				iterator					_tmp = begin();
				iterator					_dbl;
				iterator					_del;

				while (_tmp != end()) {
					while (*(_dbl = _tmp) == *(++_tmp)) {
						_del = ++_dbl;
						this->_remove(--_dbl);
						_dbl = --_del;
					}
				}
			}

			template <class BinaryPredicate>
  			void 							unique(BinaryPredicate binary_pred)
			{
				iterator					_tmp = begin();
				iterator					_del;

				while (++_tmp != end()) {
					if (binary_pred(*_tmp, *(--_tmp)++)) {
						_del = ++_tmp;
						this->_remove(--_tmp);
						_tmp = --_del;
					}
				}
			}

			void 							merge(list& x)
			{
				this->merge(x, ft::less<T>());
			}

			template <class Compare>
  			void 							merge(list& x, Compare comp)
			{
				iterator 	_begin = begin();
				iterator 	_x_begin = x.begin();

				while (_x_begin != x.end() && _begin != end())
					if (comp(*_x_begin, *_begin))
						splice(_begin, x, _x_begin++);
					else
						_begin++;

				while (_x_begin != x.end())
					splice(end(), x, _x_begin++);
			}

			void 							sort()
			{
				iterator					_begin = begin();
				iterator					_tmp = _begin;
				Node<T>						_val;

				while (_begin != end()) {
					while (++_tmp != end()) {
						if (*_begin > *_tmp) {
							_val = *_begin.node;
							_begin.node->data = _tmp.node->data;
							_tmp.node->data = _val.data;
						}
					}
					_tmp = ++_begin;
				}
			}

			template <class Compare>
  			void 							sort(Compare comp)
			{
				iterator					_begin = begin();
				iterator					_tmp = _begin;
				Node<T>						_val;

				while (_begin != end()) {
					while (++_tmp != end()) {
						if (comp(*_tmp, *_begin)) {
							_val = *_begin.node;
							_begin.node->data = _tmp.node->data;
							_tmp.node->data = _val.data;
						}
					}
					_tmp = ++_begin;
				}
			}

			void 							reverse()
			{
				Node<T>						*_begin = _node->next;
				Node<T>						*_tmp = _node->next;
				
				_node->next = _node->prev;
				_node->prev = _tmp;
				while (_begin != _node) {
					_tmp = _begin->next;
					_begin->next = _begin->prev;
					_begin->prev = _tmp;
					_begin = _tmp;
				}
			}

		private:
			typedef typename allocator_type::template rebind<Node<T> >::other 	node_allocator;
			typedef typename node_allocator::pointer							_node_pointer;
			
			node_allocator														_allocator;
			Node<T>																*_node;
			size_type															_size;

			void 							_clear(void)
			{
				Node<T> *tmp = _node->next;
				Node<T> *next_tmp;
				while (tmp != _node)
				{
					next_tmp = tmp->next;
					--_size;
					_allocator.destroy(tmp);
					_allocator.deallocate(tmp, 1);
					tmp = next_tmp;
				}
			}

			_node_pointer						_create_node(void)
			{
				_node_pointer	node = _allocator.allocate(1);
				_allocator.construct(node, Node<T>());
				return (node);
			}

			_node_pointer						_create_node(const value_type& val)
			{
				_node_pointer	node = _allocator.allocate(1);
				_allocator.construct(node, Node<T>(val));
				return (node);
			}

			void							_node_init(void)
			{
				_node = _create_node();
				_node->next = _node;
				_node->prev = _node;
			}

			void							_node_init(const value_type& val)
			{
				_node = _create_node(val);
				_node->next = _node;
				_node->prev = _node;
			}

			template <class InputIterator>
			void							_init_fill(InputIterator first, InputIterator last, true_type)
			{
				_init_fill(static_cast<size_type>(first), last);
			}

			template <class InputIterator>
			void							_init_fill(InputIterator first, InputIterator last, false_type)
			{
				for (; first != last; ++first)
					push_back(*first);
			}

			void							_init_fill(size_type n, const value_type& val)
			{
				for (; n; --n)
					push_back(val);
			}

			void							_node_fill(size_type n, const value_type& val, true_type)
			{
				iterator i = begin();
				for (; i != end() && n; ++i, --n)
					*i = val;
				if (n) insert(end(), n, val);
				else erase(i, end());
			}

			template <class InputIterator>
			void							_node_fill(InputIterator first, InputIterator last, false_type)
			{
				iterator first1 = begin();
				iterator last1 = end();

				for (; first1 != last1 && first != last; ++first1, ++first)
					*first1 = *first;
				if (first == last) erase(first1, last1);
				else insert(last1, first, last);
			}

			void							_node_fill(iterator pos, size_type n, const value_type& val, true_type)
			{
				while (n--)
					this->_insert(pos, val);
			}

			template <class InputIterator>
			void							_node_fill(iterator pos, InputIterator first, InputIterator last, false_type)
			{
				while (first != last)
					this->_insert(pos, *(first++));
			}

			void							_node_insert(iterator pos, size_type n, const value_type& val, true_type)
			{
				while (n--)
					this->_insert(pos, val);
			}

			template <class InputIterator>
			void							_node_insert(iterator pos, InputIterator first, InputIterator last, false_type)
			{
				while (first != last)
					this->_insert(pos, *(first++));
			}

			void							_insert(iterator pos, const value_type& val)
			{
				Node<T>*	new_node = new Node<T>;
				Node<T>*	tmp = pos.node;

				new_node->data = val;
				new_node->next = tmp;
				new_node->prev = tmp->prev;
				
				tmp->prev->next = new_node;
				tmp->prev = new_node;

				++_size;
				_node->data = static_cast<value_type>(this->_new_size(_size));
			}

			void							_remove(iterator pos)
			{
				Node<T>*	_tmp = pos.node->next;

				pos.node->prev->next = _tmp;
				_tmp->prev = pos.node->prev;

				_allocator.destroy(pos.node);
				_allocator.deallocate(pos.node, 1);

				--_size;
				_node->data = static_cast<value_type>(this->_new_size(_size));
			}

			size_type 						_new_size(size_type nbr)
			{
				size_type	_tmp = nbr;

				if (ft::is_float<T>::value)
					_tmp *= 1.4013e-45;
				else if (ft::is_double<T>::value)
					_tmp *= 4.94066e-324;
				return (_tmp);
			}
	};

	template <class T, class Alloc>
	bool 	operator==(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename list<T>::const_iterator first1 = lhs.begin();
		typename list<T>::const_iterator first2 = rhs.begin();
		typename list<T>::const_iterator last1 = lhs.end();
		typename list<T>::const_iterator last2 = rhs.end();
		while (first1 != last1)
		{
			if (first2 == last2 || *first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template <class T, class Alloc>
  	bool 	operator!=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
  	bool 	operator<(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
  	bool 	operator<=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
  	bool 	operator>(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
  	bool 	operator>=(const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T, typename Alloc>
  	void	swap(ft::list<T,Alloc>& x, ft::list<T,Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
