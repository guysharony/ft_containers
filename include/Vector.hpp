/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:00:14 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/09 13:08:19 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include "Algorithm.hpp"
# include "Iterator.hpp"
# include "TypeTraits.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T 												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::random_iterator<pointer>					iterator;
			typedef ft::random_iterator<const_pointer>				const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

			explicit 	vector(const allocator_type& alloc = allocator_type())
			:
				_allocator(alloc),
				_begin(0),
				_end(0),
				_available(0)
			{
				return;
			}

			explicit 	vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			:
				_allocator(alloc),
				_begin(0),
				_end(0),
				_available(0)
			{
				_init(n);
				_fill(n, val);
				return;
			}

			template <class InputIterator>
         	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			:
				_allocator(alloc),
				_begin(0),
				_end(0),
				_available(0)
			{
				typedef typename ft::is_integral<InputIterator>::type 	type;
				_fill(first, last, type());
				return;
			}

			vector(const vector& x)
			:
				_allocator(x._allocator),
				_begin(0),
				_end(0),
				_available(0)
			{
				this->insert(this->begin(), x.begin(), x.end());
			}

			~vector()
			{
				this->clear();
				_allocator.deallocate(this->_begin, this->capacity());
			}

			vector 					&operator=(const vector& x)
			{
				this->clear();
				this->insert(this->end(), x.begin(), x.end());
				return (*this);
			}

			iterator 				begin()
			{
				return (iterator(this->_begin));
			}

			const_iterator 			begin() const
			{
				return (const_iterator(this->_begin));
			}

			iterator 				end()
			{
				return (iterator(this->_end));
			}

			const_iterator 			end() const
			{
				return (const_iterator(this->_end));
			}

			reverse_iterator 		rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator 	rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator 		rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator 	rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			size_type 				size() const
			{
				return (this->_end - this->_begin);
			}

			size_type 				max_size() const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			}

			void 					resize(size_type n, value_type val = value_type())
			{
				size_type _size = size();

				if (n < _size)
				{
					for (size_type i = 0; i < (_size - n); i++, this->_end--)
						_allocator.destroy(this->_end);
				}
				else if (n > _size)
					this->insert(this->end(), n - _size, val);
			}

			size_type 				capacity()
			{
				return (this->_available - this->_begin);
			}

			bool 					empty() const
			{
				return (!this->size());
			}

			void 					reserve(size_type n)
			{
				if (n > this->max_size())
					throw (std::length_error("vector::reserve"));
				else if (this->capacity() < n)
				{
					pointer _nbegin = _allocator.allocate(n);
					pointer _nend = _nbegin;

					_nend = this->_copy(this->_begin, this->_end, _nend);

					if (this->_begin)
						_allocator.deallocate(this->_begin, this->capacity());

					this->_begin = _nbegin;
					this->_end = _nend;
					this->_available = this->_begin + n;
				}
			}

			reference 				operator[](size_type n)
			{
				return *(this->_begin + n);
			}

			const_reference 		operator[](size_type n) const
			{
				return *(this->_begin + n);
			}

			reference 				at(size_type n)
			{
				_range_check(n);
				return (*this)[n];
			}

			const_reference 		at(size_type n) const
			{
				_range_check(n);
				return (*this)[n];
			}

			reference 				front()
			{
				return *(begin());
			}

			const_reference 		front() const
			{
				return *(begin());
			}

			reference 				back()
			{
				return *(end() - 1);
			}

			const_reference 		back() const
			{
				return *(end() - 1);
			}

			template <class InputIterator>
  			void 					assign(InputIterator first, InputIterator last)
			{
				typedef typename ft::is_integral<InputIterator>::type 	type;
				
				this->_assign(first, last, type());
			}

			void 					assign(size_type n, const value_type& val)
			{
				this->_assign(n, val, true_type());
			}

			void 					push_back(const value_type& val)
			{
				if (this->_end != this->_available)
					this->_insert_end(val);
				else
					this->_insert(end(), val);
			}

			void 					pop_back()
			{
				_allocator.destroy(this->_end);
				--this->_end;
			}

			iterator 				insert(iterator position, const value_type& val)
			{
				size_type _len = position - begin();

				if (this->_end != this->_available && position == end())
					this->_insert_end(val);
				else
					this->_insert(position, val);
				return (iterator(this->_begin + _len));
			}

			void 					insert(iterator position, size_type n, const value_type& val)
			{
				size_type _len = this->_available - this->_end;
				
				size_type _len_f = end() - position;

				if (!n)
					return;
				if (n == 1)
					this->insert(position, val);
				else if (_len >= n)
				{
					pointer _oend = this->_end;
					if (_len_f > n)
					{
						this->_move_end(n);
						this->_move_back(position.base(), _oend - n, _oend);
						this->_fill(position.base(), position.base() + n, val);
					}
					else
					{
						this->_copy(this->_end, n - _len_f, val);
						this->_end += n - _len_f;
						this->_move_back(position.base(), _oend, this->_end);
						this->_end += _len_f;
						this->_fill(position.base(), _oend, val);
					}
				}
				else
					_insert_new(position, n, val);
			}

			template <class InputIterator>
    		void 					insert(iterator position, InputIterator first, InputIterator last)
			{
				size_type _len = this->_available - this->_end;

				size_type _len_f = end() - position;

				size_type _size = last - first;
				
				if (first == last)
					return;
				else if (_len >= _size)
				{
					pointer _oend = this->_end;
					if (_len_f > _size)
					{
						this->_move_end(_size);
						this->_move_back(position.base(), _oend - _size, _oend);
						while (first != last)
							*(position++) = *(first++);
					}
					else
					{
						InputIterator _tmp = first;
						for (size_type i = 0; i < _len_f; i++)
							_tmp++;
						this->_copy(_tmp, last, this->_end);
						this->_end += _size - _len_f;
						this->_move_back(position.base(), _oend, this->_end);
						this->_end += _len_f;
						while (first != _tmp)
							*(position++) = *(first++);
					}
				}
				else
					this->_insert_range(position, first, last);
			}

			iterator 				erase(iterator position)
			{
				return (this->erase(position, position + 1));
			}

			iterator 				erase(iterator first, iterator last)
			{
				pointer 	_first = &(*first);
				pointer 	_last = &(*last);
				size_type	_size = _last - _first;

				if (first != last)
				{
					if (_last != this->_end)
						this->_shift(_first, this->_end, _size);
					this->_remove_end(_size);
				}
				return (first);
			}

			void 					swap(vector& x)
			{
				pointer _nbegin = this->_begin;
				pointer _nend = this->_end;
				pointer _navailable = this->_available;

				this->_begin = x._begin;
				this->_end = x._end;
				this->_available = x._available;

				x._begin = _nbegin;
				x._end = _nend;
				x._available = _navailable;
			}

			void 					clear()
			{
				size_type _size = this->size();
				
				if (_size)
				{
					for (size_type i = 0; i < _size; i++, this->_end--)
						_allocator.destroy(this->_end);
				}
			}

		private:
			allocator_type			_allocator;
			pointer					_begin;
			pointer					_end;
			pointer					_available;

			void					_init(size_type n)
			{
				this->_begin = _allocator.allocate(n);
				this->_end = this->_begin;
				this->_available = this->_begin + n;
			}

			void					_fill(size_type n, value_type const & val)
			{
				while (n)
				{
					push_back(val);
					n--;
				}
			}

			void					_fill(size_type n, value_type const & val, true_type)
			{
				this->_init(n);
				this->_fill(n, val);
			}

			template <class InputIterator>
			void					_fill(InputIterator first, InputIterator last, false_type)
			{
				while (first != last)
					push_back(*(first++));
			}

			void					_insert_end(value_type const & val)
			{
				_allocator.construct(this->_end, val);
				++this->_end;
			}

			void					_remove_end(size_type n)
			{
				for (size_type i = n; i < this->size(); i++)
					_allocator.destroy(this->_begin + i);
				this->_end -= n;
			}

			void					_insert(iterator position, value_type const & val)
			{
				if (this->_end != this->_available)
				{
					_allocator.construct(this->_end, *(this->_end - 1));
					++this->_end;
					value_type _tmp = val;
					*position = _tmp;
				}
				else
					this->_insert_new(position, 1, val);
			}

			template <class InputIterator>
			void					_assign(InputIterator first, InputIterator last, false_type)
			{
				size_type _len = last - first;

				this->resize(0);
				if (this->capacity() > _len)
					this->_end = this->_copy(first, last, this->_end);
				else
				{
					while (first < last)
						push_back(*(first++));
				}
			}

			void					_assign(size_type n, const value_type& val, true_type)
			{
				this->resize(0);
				if (this->capacity() > n)
					this->_end = this->_copy(this->_end, n, val);
				else
				{
					while (n--)
						push_back(val);
				}
			}

			void					_insert_new(iterator position, size_type n, value_type const & val)
			{
				size_type _len = this->size() + ((this->size() > size_type(n)) ? this->size() : size_type(n));
				size_type _len_b = position - begin();
				
				pointer _nbegin = _allocator.allocate(_len);
				pointer _nend = _nbegin;

				this->_copy(_nbegin + _len_b, n, val);
				_nend = 0;
				_nend = this->_copy(this->_begin, position.base(), _nbegin);
				_nend += n;
				_nend = this->_copy(position.base(), this->_end, _nend);

				this->clear();
				_allocator.deallocate(this->_begin, this->capacity());

				this->_begin = _nbegin;
				this->_end = _nend;
				this->_available = _nbegin + _len;
			}

			template <class InputIterator>
			void					_insert_range(iterator position, InputIterator first, InputIterator last)
			{
				size_type _len = this->size() + ((this->size() > size_type(last - first)) ? this->size() : size_type(last - first));
				
				pointer _nbegin = _allocator.allocate(_len);
				pointer _nend = _nbegin;

				_nend = this->_copy(this->_begin, position.base(), _nbegin);
				_nend = this->_copy(first, last, _nend);
				_nend = this->_copy(position.base(), this->_end, _nend);

				this->clear();
				_allocator.deallocate(this->_begin, this->capacity());

				this->_begin = _nbegin;
				this->_end = _nend;
				this->_available = _nbegin + _len;
			}

			void					_move_end(size_type n)
			{
				this->_copy(this->_end - n, this->_end, this->_end);
				this->_end += n;
			}

			void					_move_back(pointer first, pointer last, pointer result)
			{
				while (first != last)
					*(--result) = *(--last);
			}

			void					_move(pointer dest, pointer src)
			{
				this->_duplicate(dest, src);
				this->_remove(src);
			}

			void					_duplicate(pointer dest, pointer src)
			{
				_allocator.construct(dest, *(src));
			}

			void					_remove(pointer src)
			{
				_allocator.destroy(src);
			}

			void					_fill(pointer first, pointer last, value_type const & val)
			{
				while (first != last)
				{
					*first = val;
					++first;
				}
			}

			void					_shift(pointer first, pointer last, size_type n)
			{
				this->_remove(first);
				for (size_type i = 0; first + n + i != last; i++)
					this->_move(first + i, first + n + i);
			}

			pointer					_copy(pointer first, size_type n, value_type const & val)
			{
				pointer	_tmp = first;
				
				for (; n > 0; --n, ++_tmp)
					_allocator.construct(&(*_tmp), val);
				return (_tmp);
			}

			pointer					_copy(pointer first, pointer last, pointer result)
			{
				pointer	_tmp = result;
				
				for (; first != last; ++first, (void)++_tmp)
					_allocator.construct(&(*_tmp), *first);
				return (_tmp);
			}

			template <class InputIterator>
			pointer					_copy(InputIterator first, InputIterator last, pointer result)
			{
				pointer	_tmp = result;
				
				for (; first != last; ++first, (void)++_tmp)
					_allocator.construct(&(*_tmp), *first);
				return (_tmp);
			}

			void					_range_check(size_type n)
			{
				if (n >= this->size())
					throw std::out_of_range("vector index n is out of range.");
			}
	};

	template <class T, class Alloc>
  	bool 	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename vector<T>::const_iterator first1 = lhs.begin();
		typename vector<T>::const_iterator first2 = rhs.begin();
		typename vector<T>::const_iterator last1 = lhs.end();
		typename vector<T>::const_iterator last2 = rhs.end();
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
  	bool 	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
  	bool 	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
  	bool 	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
  	bool 	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T, class Alloc>
  	bool 	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T, typename Alloc>
  	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

}

#endif
