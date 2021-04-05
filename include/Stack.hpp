/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:00:14 by gsharony          #+#    #+#             */
/*   Updated: 2021/03/16 10:18:24 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "List.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class stack
	{
		public:
			typedef T 			value_type;
			typedef Container 	container_type;
			typedef size_t		size_type;

		protected:
			container_type		c;

		public:
			explicit 			stack(const container_type& ctnr = container_type())
			:
				c(ctnr)
			{}

			stack(const stack& x)
			:
				c(x.c)
			{}

			~stack()
			{}

			stack 				&operator=(const stack &other)
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

			value_type& 		top()
			{
				return (this->c.back());
			}

			const value_type& 	top() const
			{
				return (this->c.back());
			}

			void 				push(const value_type& val)
			{
				return (this->c.push_back(val));
			}

			void 				pop()
			{
				return (this->c.pop_back());
			}

			template <class fT, class fContainer>
  			friend bool operator==(const ft::stack<fT,fContainer>& lhs, const ft::stack<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator!=(const ft::stack<fT,fContainer>& lhs, const ft::stack<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator<(const ft::stack<fT,fContainer>& lhs, const ft::stack<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator<=(const ft::stack<fT,fContainer>& lhs, const ft::stack<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator>(const ft::stack<fT,fContainer>& lhs, const ft::stack<fT,fContainer>& rhs);

			template <class fT, class fContainer>
  			friend bool operator>=(const ft::stack<fT,fContainer>& lhs, const ft::stack<fT,fContainer>& rhs);
	};

	template <class T, class Container>
  	bool 	operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
  	bool 	operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}

	template <class T, class Container>
  	bool 	operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}

	template <class T, class Container>
  	bool 	operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return !(rhs.c < lhs.c);
	}

	template <class T, class Container>
  	bool 	operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return (rhs.c < lhs.c);
	}

	template <class T, class Container>
  	bool 	operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
	{
		return !(lhs.c < rhs.c);
	}

}

#endif
