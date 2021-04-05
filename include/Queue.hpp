/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:00:14 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/05 11:40:58 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "List.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
		public:
			typedef T 			value_type;
			typedef Container 	container_type;
			typedef size_t		size_type;

		protected:
			container_type		c;

		public:
			explicit 			queue(const container_type& ctnr = container_type())
			:
				c(ctnr)
			{}

			queue(const queue& x)
			:
				c(x.c)
			{}

			~queue()
			{}

			queue 				&operator=(const queue &other)
			{
				this->c = other.c;
				return (*this);
			}

			bool 				empty() const
			{
				return (this->c.empty());
			}

			size_type 			size() const
			{
				return (this->c.size());
			}

			value_type& 		front()
			{
				return (this->c.front());
			}

			const value_type& 	front() const
			{
				return (this->c.front());
			}

			value_type& 		back()
			{
				return (this->c.back());
			}

			const value_type& 	back() const
			{
				return (this->c.back());
			}

			void 				push(const value_type& val)
			{
				return (this->c.push_back(val));
			}

			void 				pop()
			{
				return (this->c.pop_front());
			}

			template <class fT, class fContainer>
  			friend bool operator==(const ft::queue<fT,fContainer>& lhs, const ft::queue<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator!=(const ft::queue<fT,fContainer>& lhs, const ft::queue<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator<(const ft::queue<fT,fContainer>& lhs, const ft::queue<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator<=(const ft::queue<fT,fContainer>& lhs, const ft::queue<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator>(const ft::queue<fT,fContainer>& lhs, const ft::queue<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator>=(const ft::queue<fT,fContainer>& lhs, const ft::queue<fT,fContainer>& rhs);
	};

	template <class T, class Container>
  	bool 	operator==(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
  	bool 	operator!=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
  	bool 	operator<(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
  	bool 	operator<=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
	{
		return !(rhs.c < lhs.c);
	}

	template <class T, class Container>
  	bool 	operator>(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
	{
		return (rhs.c < lhs.c);
	}

	template <class T, class Container>
  	bool 	operator>=(const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
	{
		return !(lhs.c < rhs.c);
	}

}

#endif
