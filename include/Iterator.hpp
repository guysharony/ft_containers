/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 15:29:27 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/05 11:20:18 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "Node.hpp"

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T										value_type;
		typedef Distance								difference_type;
		typedef Pointer									pointer;
		typedef Reference								reference;
		typedef Category								iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef ft::random_access_iterator_tag			iterator_category;
	};

	template <typename T>
	class list_iterator
	{
		public:
			ft::Node<T>									*node;
			
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef T*									pointer;
			typedef T&									reference;
			typedef ft::bidirectional_iterator_tag		iterator_category;

			list_iterator() : node() {}
			list_iterator(ft::Node<T>* src) : node(src) {}
			list_iterator(list_iterator const & src) {*this = src;}
			~list_iterator() {}

			reference				operator*() const
			{
				return (node->data);
			}

			pointer					operator->(void)
			{
				return (&(node->data));
			}

			list_iterator<T>&		operator++()
			{
				this->node = this->node->next;
				return (*this);
			}

			list_iterator<T>		operator++(int)
			{
				list_iterator<T>		tmp = *this;
				this->node = this->node->next;
				return (tmp);
			}

			list_iterator<T>&		operator--()
			{
				this->node = this->node->prev;
				return (*this);
			}

			list_iterator<T>		operator--(int)
			{
				list_iterator<T>		tmp = *this;
				this->node = this->node->prev;
				return (tmp);
			}

			bool 					operator==(list_iterator<T> const & src) const
			{
				return (node == src.node);
			}

			bool 					operator!=(list_iterator<T> const & src) const
			{
				return (node != src.node);
			}
	};

	template <typename T>
	class list_const_iterator
	{
		public:
			const ft::Node<T>							*node;
			
			typedef ptrdiff_t							difference_type;
			typedef T									value_type;
			typedef const T*							pointer;
			typedef const T&							reference;
			typedef ft::bidirectional_iterator_tag		iterator_category;

			list_const_iterator() : node() {}
			list_const_iterator(ft::Node<T>* src) : node(src) {}
			list_const_iterator(list_const_iterator const & src) {*this = src;}
			~list_const_iterator() {}

			reference					operator*() const
			{
				return (node->data);
			}

			pointer						operator->(void)
			{
				return (&(node->data));
			}

			list_const_iterator<T>&		operator++()
			{
				this->node = this->node->next;
				return (*this);
			}

			list_const_iterator<T>		operator++(int)
			{
				list_const_iterator<T>		tmp = *this;
				this->node = this->node->next;
				return (tmp);
			}

			list_const_iterator<T>&		operator--()
			{
				this->node = this->node->prev;
				return (*this);
			}

			list_const_iterator<T>		operator--(int)
			{
				list_const_iterator<T>		tmp = *this;
				this->node = this->node->prev;
				return (tmp);
			}

			bool 						operator==(list_const_iterator<T> const & src) const
			{
				return (node == src.node);
			}

			bool 						operator!=(list_const_iterator<T> const & src) const
			{
				return (node != src.node);
			}
	};

	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			reverse_iterator (void) : _iterator() {}

			explicit reverse_iterator (iterator_type it) : _iterator(it) {}

			template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it) : _iterator(rev_it.base()) {}

			~reverse_iterator() {}

			iterator_type 		base(void) const
			{
				return (_iterator);
			}

			reference 			operator*(void) const
			{
				iterator_type 	tmp = _iterator;
				return (*(--tmp));
			}

			reverse_iterator 	operator+(difference_type n) const
			{
				return (reverse_iterator(_iterator - n));
			}

			reverse_iterator& 	operator++(void)
			{
				--_iterator;
				return (*this);
			}

			reverse_iterator  	operator++(int)
			{
				reverse_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			reverse_iterator& 	operator+=(difference_type n)
			{
				_iterator -= n;
				return (*this);
			}

			reverse_iterator 	operator-(difference_type n) const
			{
				return (reverse_iterator(_iterator + n));
			}

			reverse_iterator& 	operator--(void)
			{
				++_iterator;
				return (*this);
			}

			reverse_iterator  	operator--(int)
			{
				reverse_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			reverse_iterator& 	operator-=(difference_type n)
			{
				_iterator += n;
				return (*this);
			}

			pointer 			operator->() const
			{
				return &(operator*());
			}

			reference 			operator[](difference_type n) const
			{
				return (base()[-n - 1]);
			}

		private:
			iterator_type		_iterator;
	};

	template <class Iterator>
  	bool 	operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
  	bool 	operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
  	bool 	operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
  	bool 	operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
  	bool 	operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
  	bool 	operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
  	reverse_iterator<Iterator> 								operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template <class Iterator>
  	typename reverse_iterator<Iterator>::difference_type 	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template <typename Iterator>
	class random_iterator
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;

			random_iterator(void) : _iterator(Iterator()) {}

			explicit random_iterator(iterator_type it) : _iterator(it) {}

			template <class Iter>
  			random_iterator(const random_iterator<Iter>& it) : _iterator(it.base()) {}

			~random_iterator() {}

			iterator_type 		base(void) const
			{
				return (_iterator);
			}

			reference 			operator*(void) const
			{
				return (*_iterator);
			}

			random_iterator 	operator+(difference_type n) const
			{
				return (random_iterator(_iterator + n));
			}

			random_iterator& 	operator++(void)
			{
				++_iterator;
				return (*this);
			}

			random_iterator  	operator++(int)
			{
				random_iterator	tmp = *this;
				++(*this);
				return (tmp);
			}

			random_iterator& 	operator+=(difference_type n)
			{
				_iterator += n;
				return (*this);
			}

			random_iterator 	operator-(difference_type n) const
			{
				return (random_iterator(_iterator - n));
			}

			random_iterator& 	operator--(void)
			{
				--_iterator;
				return (*this);
			}

			random_iterator  	operator--(int)
			{
				random_iterator	tmp = *this;
				--(*this);
				return (tmp);
			}

			random_iterator& 	operator-=(difference_type n)
			{
				_iterator -= n;
				return (*this);
			}

			pointer 			operator->() const
			{
				return &(operator*());
			}

			reference 			operator[](difference_type n) const
			{
				return (base()[n]);
			}

		private:
			Iterator			_iterator;
	};

	template <class Iterator>
  	bool 	operator==(const random_iterator<Iterator>& lhs, const random_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template <class Iterator>
  	bool 	operator!=(const random_iterator<Iterator>& lhs, const random_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <class Iterator>
  	bool 	operator<(const random_iterator<Iterator>& lhs, const random_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>
  	bool 	operator<=(const random_iterator<Iterator>& lhs, const random_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
  	bool 	operator>(const random_iterator<Iterator>& lhs, const random_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>
  	bool 	operator>=(const random_iterator<Iterator>& lhs, const random_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template <class Iterator>
  	random_iterator<Iterator> 								operator+(typename random_iterator<Iterator>::difference_type n, const random_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	}

	template <class Iterator>
  	typename random_iterator<Iterator>::difference_type		operator-(const random_iterator<Iterator>& lhs, const random_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}
}

#endif
