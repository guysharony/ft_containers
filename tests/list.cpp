/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 11:15:32 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/12 11:27:11 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/List.hpp"
#include "../include/Functional.hpp"
#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <cmath>

template <typename T>
std::string		print_list(std::list<T> lst)
{
	std::stringstream out;
	typename std::list<T>::iterator tmp1 = lst.begin();

	out << "[";
	while (tmp1 != lst.end())
	{
		out << *tmp1;
		++tmp1;
		if (tmp1 != lst.end())
			out << ", ";
	}
	out << "]" << std::endl;
	return (out.str());
}

template <typename T>
std::string		print_list(ft::list<T> lst)
{
	std::stringstream out;
	typename ft::list<T>::iterator tmp1 = lst.begin();

	out << "[";
	while (tmp1 != lst.end())
	{
		out << *tmp1;
		++tmp1;
		if (tmp1 != lst.end())
			out << ", ";
	}
	out << "]" << std::endl;
	return (out.str());
}

template <class T>
std::string	print_list(ft::list<ft::list<T> > lst)
{
	std::stringstream out;
	for (typename ft::list<ft::list<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename ft::list<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			out << *it2 << ' ';
		out << '\n';
	}
	return (out.str());
}

template <class T>
std::string	print_list(std::list<std::list<T> > lst)
{
	std::stringstream out;
	for (typename std::list<std::list<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename std::list<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			out << *it2 << ' ';
		out << '\n';
	}
	return (out.str());
}

bool 			single_digit(const int& value)
{
	return (value < 10);
}

struct is_odd
{
  	bool 			operator() (const int& value)
	{
		return (value % 2) == 1;
	}
};

bool 			same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

struct is_near
{
  bool			operator() (double first, double second)
  {
		return (fabs(first - second) < 5.0);
	}
};

bool 			less(double first, double second)
{
	return (int(first) < int(second));
}

bool 			greater(double first, double second)
{
	return (int(first) > int(second));
}

static void			begin(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::list<int>		lst1;

	for (int i = 1; i < 6; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	out1 << "begins with " << *lst1.begin() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;

	for (int i = 1; i < 6; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	out2 << "begins with " << *lst2.begin() << std::endl;
	b = out2.str();
	std::cout << "begin: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors && a.compare(b))
	{
		std::cout << "---" << std::endl;
		std::cout << a;
		std::cout << "-" << std::endl;
		std::cout << b;
		std::cout << "---" << std::endl;
	}
}

static void			end(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 1; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 1; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	b = out2.str();
	std::cout << "end: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors && a.compare(b))
	{
		std::cout << "---" << std::endl;
		std::cout << a;
		std::cout << "-" << std::endl;
		std::cout << b;
		std::cout << "---" << std::endl;
	}
}

static void			rbegin(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	
	for (int i = 1; i < 6; i++)
		lst1.push_back(i);

	for (ft::list<int>::reverse_iterator it1 = lst1.rbegin(); it1 != lst1.rend(); ++it1)
    	out1 << ' ' << *it1;

	out1 << "begins with " << *lst1.rbegin() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;

	for (int i = 1; i < 6; i++)
		lst2.push_back(i);

	for (std::list<int>::reverse_iterator it2 = lst2.rbegin(); it2 != lst2.rend(); ++it2)
    	out2 << ' ' << *it2;

	out2 << "begins with " << *lst2.rbegin() << std::endl;
	b = out2.str();
	
	std::cout << "rbegin: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors && a.compare(b))
	{
		std::cout << "---" << std::endl;
		std::cout << a;
		std::cout << "-" << std::endl;
		std::cout << b;
		std::cout << "---" << std::endl;
	}
}

static void			rend(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = 1; i < 6; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = 1; i < 6; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	b = out2.str();
	std::cout << "rend: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors && a.compare(b))
	{
		std::cout << "---" << std::endl;
		std::cout << a;
		std::cout << "-" << std::endl;
		std::cout << b;
		std::cout << "---" << std::endl;
	}
}

static void			empty(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -2; i < 15; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	out1 << ((lst1.empty()) ? "list is empty" : "list is not empty") << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -2; i < 15; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	out2 << ((lst2.empty()) ? "list is empty" : "list is not empty") << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	out3 << print_list(lst3) << std::endl;
	out3 << ((lst3.empty()) ? "list is empty" : "list is not empty") << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	out4 << print_list(lst4) << std::endl;
	out4 << ((lst4.empty()) ? "list is empty" : "list is not empty") << std::endl;
	d = out4.str();

	std::cout << "empty: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			size(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	out1 << "list contains " << lst1.size() << " elements." << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	out2 << "list contains " << lst2.size() << " elements." << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	out3 << print_list(lst3) << std::endl;
	out3 << "list contains " << lst3.size() << " elements." << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	out4 << print_list(lst4) << std::endl;
	out4 << "list contains " << lst4.size() << " elements." << std::endl;
	d = out4.str();

	std::cout << "size: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			max_size(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	out1 << "list can contain " << lst1.max_size() << " elements." << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	out2 << "list can contain " << lst2.max_size() << " elements." << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	out3 << print_list(lst3) << std::endl;
	out3 << "list can contain " << lst3.max_size() << " elements." << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	out4 << print_list(lst4) << std::endl;
	out4 << "list can contain " << lst4.max_size() << " elements." << std::endl;
	d = out4.str();

	std::cout << "max_size: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			front(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	out1 << "the element at the front of list is " << lst1.front() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	out2 << "the element at the front of list is " << lst2.front() << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	out3 << print_list(lst3) << std::endl;
	out3 << "the element at the front of list is " << lst3.front() << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	out4 << print_list(lst4) << std::endl;
	out4 << "the element at the front of list is " << lst4.front() << std::endl;
	d = out4.str();

	std::cout << "front: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			back(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;

	out1 << "the element at the back of list is " << lst1.back() << std::endl;

	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	
	out1 << "the element at the back of list is " << lst1.back() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;

	out2 << "the element at the back of list is " << lst2.back() << std::endl;

	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;

	out2 << "the element at the back of list is " << lst2.back() << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	out3 << print_list(lst3) << std::endl;
	out3 << "the element at the back of list is " << lst3.back() << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	out4 << print_list(lst4) << std::endl;
	out4 << "the element at the back of list is " << lst4.back() << std::endl;
	d = out4.str();

	std::cout << "back: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			assign(bool show_errors)
{
	std::string	a;
	std::string	b;

	int myints[] = {1776,7,4};
	
	std::stringstream 	out1;
	ft::list<int>		lst1;
	ft::list<int>		lst2;

	lst1.assign(7,100);
	out1 << print_list(lst1);

	lst2.assign(lst1.begin(), lst1.end());
	out1 << print_list(lst2);
	
	lst1.assign(myints,myints+3);
	out1 << print_list(lst2);

	out1 << "Size of first: " << int (lst1.size()) << '\n';
	out1 << "Size of second: " << int (lst2.size()) << '\n';

	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst3;
	std::list<int>		lst4;

	lst3.assign(7,100);
	out2 << print_list(lst3);

	lst4.assign(lst3.begin(), lst3.end());
	out2 << print_list(lst4);
	
	lst3.assign(myints,myints+3);
	out2 << print_list(lst4);

	out2 << "Size of first: " << int (lst3.size()) << '\n';
	out2 << "Size of second: " << int (lst4.size()) << '\n';

	b = out2.str();

	std::cout << "assign: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void			push_front(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 0; i++)
		lst1.push_front(i);
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 0; i++)
		lst2.push_front(i);
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	for (int i = -100; i < 100; i++)
		lst3.push_front(i);
	out3 << print_list(lst3) << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	for (int i = -100; i < 100; i++)
		lst4.push_front(i);
	out4 << print_list(lst4) << std::endl;
	d = out4.str();

	std::cout << "push_front: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			pop_front(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 0; i++)
		lst1.push_front(i);
	lst1.pop_front();
	lst1.pop_front();
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 0; i++)
		lst2.push_front(i);
	lst2.pop_front();
	lst2.pop_front();
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	for (int i = -100; i < 100; i++)
		lst3.push_front(i);
	for (int i = 0; i < 100; i++)
		lst3.pop_front();
	out3 << print_list(lst3) << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	for (int i = -100; i < 100; i++)
		lst4.push_front(i);
	for (int i = 0; i < 100; i++)
		lst4.pop_front();
	out4 << print_list(lst4) << std::endl;
	d = out4.str();

	std::cout << "pop_front: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			push_back(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	for (int i = -100; i < 100; i++)
		lst3.push_back(i);
	out3 << print_list(lst3) << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	for (int i = -100; i < 100; i++)
		lst4.push_back(i);
	out4 << print_list(lst4) << std::endl;
	d = out4.str();

	std::cout << "push_back: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			pop_back(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::list<int>		lst1;
	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	lst1.pop_back();
	lst1.pop_back();
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::list<int>		lst2;
	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	lst2.pop_back();
	lst2.pop_back();
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::list<int>		lst3;
	for (int i = -100; i < 100; i++)
		lst3.push_back(i);
	for (int i = 0; i < 100; i++)
		lst3.pop_back();
	out3 << print_list(lst3) << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::list<int>		lst4;
	for (int i = -100; i < 100; i++)
		lst4.push_back(i);
	for (int i = 0; i < 100; i++)
		lst4.pop_back();
	out4 << print_list(lst4) << std::endl;
	d = out4.str();

	std::cout << "pop_back: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void			insert(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::string	e;
	std::string	f;

	std::stringstream 			out1;
	ft::list<int>				lst1;
	ft::list<int>::iterator		it1;

	for (int i = -5; i < 5; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	it1 = lst1.begin();
	out1 << "iterator points to " << *it1 << std::endl;
	++it1;
	out1 << "iterator points to " << *it1 << std::endl;
	lst1.insert(it1, 10);
	out1 << print_list(lst1) << std::endl;
	--it1;
	out1 << "iterator points to " << *it1 << std::endl;
	a = out1.str();

	std::stringstream 			out2;
	std::list<int>				lst2;
	std::list<int>::iterator	it2;

	for (int i = -5; i < 5; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	it2 = lst2.begin();

	out2 << "iterator points to " << *it2 << std::endl;
	++it2;
	out2 << "iterator points to " << *it2 << std::endl;
	lst2.insert(it2, 10);
	out2 << print_list(lst2) << std::endl;
	--it2;
	out2 << "iterator points to " << *it2 << std::endl;
	b = out2.str();

	std::stringstream 			out3;
	ft::list<float>				lst3;
	ft::list<float>::iterator	it3;

	for (int i = -5; i < 5; i++)
		lst3.push_back(i);
	out3 << print_list(lst3) << std::endl;
	it3 = lst3.begin();
	out3 << "iterator points to " << *it3 << std::endl;
	++it3;
	out3 << "iterator points to " << *it3 << std::endl;
	for (float i = -5.258; i < 5; i++)
		lst3.insert(it3, 2, i);
	out3 << print_list(lst3) << std::endl;
	--it3;
	out3 << "iterator points to " << *it3 << std::endl;
	c = out3.str();

	std::stringstream 			out4;
	std::list<float>			lst4;
	std::list<float>::iterator	it4;

	for (int i = -5; i < 5; i++)
		lst4.push_back(i);
	out4 << print_list(lst4) << std::endl;
	it4 = lst4.begin();
	out4 << "iterator points to " << *it4 << std::endl;
	++it4;
	out4 << "iterator points to " << *it4 << std::endl;
	for (float i = -5.258; i < 5; i++)
		lst4.insert(it4, 2, i);
	out4 << print_list(lst4) << std::endl;
	--it4;
	out4 << "iterator points to " << *it4 << std::endl;
	d = out4.str();

	std::stringstream 			out5;
	ft::list<int>				lst5;
	ft::list<int>::iterator		it5;

	for (int i = -5; i < 5; i++)
		lst5.push_back(i);
	out5 << print_list(lst5) << std::endl;
	it5 = lst5.begin();
	out5 << "iterator points to " << *it5 << std::endl;
	++it5;
	out5 << "iterator points to " << *it5 << std::endl;
	lst5.insert(it5, 2, 64);
	lst5.insert(it5, 2, -42);
	lst5.insert(it5, lst3.begin(), lst3.end());
	out5 << print_list(lst5) << std::endl;
	--it5;
	out5 << "iterator points to " << *it5 << std::endl;
	e = out5.str();

	std::stringstream 			out6;
	std::list<int>				lst6;
	std::list<int>::iterator	it6;

	for (int i = -5; i < 5; i++)
		lst6.push_back(i);
	out6 << print_list(lst6) << std::endl;
	it6 = lst6.begin();
	out6 << "iterator points to " << *it6 << std::endl;
	++it6;
	out6 << "iterator points to " << *it6 << std::endl;
	lst6.insert(it6, 2, 64);
	lst6.insert(it6, 2, -42);
	lst6.insert(it6, lst4.begin(), lst4.end());
	out6 << print_list(lst6) << std::endl;
	--it6;
	out6 << "iterator points to " << *it6 << std::endl;
	f = out6.str();

	std::cout << "insert: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "][" << (!(e.compare(f)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/3 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/3 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
		if (e.compare(f)) {
			std::cout << "- 3/3 -" << std::endl;
			std::cout << e;
			std::cout << "-" << std::endl;
			std::cout << f;
			std::cout << "---" << std::endl;
		}
	}
}

static void			erase(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream			out1;
	ft::list<int>				lst1;
	ft::list<int>::iterator		it1;

	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	it1 = lst1.begin();
	out1 << "iterator points to " << *it1 << std::endl;
	++it1;
	out1 << "iterator points to " << *it1 << std::endl;
	++it1;
	out1 << "iterator points to " << *it1 << std::endl;
	it1 = lst1.erase(it1);
	out1 << "iterator points to " << *it1 << std::endl;
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream 			out2;
	std::list<int>				lst2;
	std::list<int>::iterator	it2;

	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	it2 = lst2.begin();
	out2 << "iterator points to " << *it2 << std::endl;
	++it2;
	out2 << "iterator points to " << *it2 << std::endl;
	++it2;
	out2 << "iterator points to " << *it2 << std::endl;
	it2 = lst2.erase(it2);
	out2 << "iterator points to " << *it2 << std::endl;
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::stringstream 			out3;
	ft::list<int>				lst3;
	ft::list<int>::iterator		it3;

	for (int i = -100; i < 100; i++)
		lst3.push_back(i);
	out3 << print_list(lst3) << std::endl;
	it3 = lst3.begin();
	out3 << "iterator points to " << *it3 << std::endl;
	++it3;
	out3 << "iterator points to " << *it3 << std::endl;
	++it3;
	out3 << "iterator points to " << *it3 << std::endl;
	it3 = lst3.erase(it3, lst3.end());
	out3 << print_list(lst3) << std::endl;
	c = out3.str();

	std::stringstream 			out4;
	std::list<int>				lst4;
	std::list<int>::iterator	it4;

	for (int i = -100; i < 100; i++)
		lst4.push_back(i);
	out4 << print_list(lst4) << std::endl;
	it4 = lst4.begin();
	out4 << "iterator points to " << *it4 << std::endl;
	++it4;
	out4 << "iterator points to " << *it4 << std::endl;
	++it4;
	out4 << "iterator points to " << *it4 << std::endl;
	it4 = lst4.erase(it4, lst4.end());
	out4 << print_list(lst4) << std::endl;
	d = out4.str();

	std::cout << "erase: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			swap(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream	out1;
	ft::list<int> 		first1(3,100);
	ft::list<int> 		second1(5,200);

	first1.swap(second1);

	out1 << "first contains:";
	for (ft::list<int>::iterator it = first1.begin(); it != first1.end(); it++)
		out1 << ' ' << *it;
	out1 << '\n';

	out1 << "second contains:";
	for (ft::list<int>::iterator it = second1.begin(); it != second1.end(); it++)
		out1 << ' ' << *it;
	out1 << '\n';

	a = out1.str();

	std::stringstream	out2;
	std::list<int> 		first2(3,100);
	std::list<int> 		second2(5,200);

	first2.swap(second2);

	out2 << "first contains:";
	for (std::list<int>::iterator it = first2.begin(); it != first2.end(); it++)
		out2 << ' ' << *it;
	out2 << '\n';

	out2 << "second contains:";
	for (std::list<int>::iterator it = second2.begin(); it != second2.end(); it++)
		out2 << ' ' << *it;
	out2 << '\n';
	b = out2.str();

	std::cout << "swap: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			resize(bool show_errors)
{
	std::string a;
	std::string b;

	std::stringstream	out1;
	ft::list<int>		lst1;

	for (int i = -5; i < 5; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	lst1.resize(5);
	out1 << print_list(lst1) << std::endl;
	lst1.resize(10);
	out1 << print_list(lst1) << std::endl;
	lst1.resize(20, 5);
	out1 << print_list(lst1) << std::endl;
	lst1.resize(0);
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream	out2;
	std::list<int>		lst2;

	for (int i = -5; i < 5; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	lst2.resize(5);
	out2 << print_list(lst2) << std::endl;
	lst2.resize(10);
	out2 << print_list(lst2) << std::endl;
	lst2.resize(20, 5);
	out2 << print_list(lst2) << std::endl;
	lst2.resize(0);
	out2 << print_list(lst2) << std::endl;
	b = out2.str();
	std::cout << "resize: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			clear(bool show_errors)
{
	std::string a;
	std::string b;

	std::stringstream		out1;
	ft::list<int> 			lst1;
	ft::list<int>::iterator it1;

	lst1.push_back(100);
	lst1.push_back(200);
	lst1.push_back(300);

	out1 << "mylist contains:";
	for (it1 = lst1.begin(); it1 != lst1.end(); ++it1)
		out1 << ' ' << *it1;
	out1 << '\n';

	lst1.clear();

	out1 << '[';
	for (it1 = lst1.begin(); it1 != lst1.end(); ++it1)
		out1 << ' ' << *it1;
	out1 << "]\n";
	
	lst1.push_back(1101);
	lst1.push_back(2202);

	out1 << "mylist contains:";
	for (it1 = lst1.begin(); it1 != lst1.end(); ++it1)
		out1 << ' ' << *it1;
	out1 << '\n';
	a = out1.str();

	std::stringstream			out2;
	std::list<int> 				lst2;
	std::list<int>::iterator 	it2;

	lst2.push_back(100);
	lst2.push_back(200);
	lst2.push_back(300);

	out2 << "mylist contains:";
	for (it2 = lst2.begin(); it2 != lst2.end(); ++it2)
		out2 << ' ' << *it2;
	out2 << '\n';

	lst2.clear();

	out2 << '[';
	for (it2 = lst2.begin(); it2 != lst2.end(); ++it2)
		out2 << ' ' << *it2;
	out2 << "]\n";
	
	lst2.push_back(1101);
	lst2.push_back(2202);

	out2 << "mylist contains:";
	for (it2 = lst2.begin(); it2 != lst2.end(); ++it2)
		out2 << ' ' << *it2;
	out2 << '\n';
	b = out2.str();

	std::cout << "clear: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			splice(bool show_errors)
{
	std::string a;
	std::string b;
	std::string	c;
	std::string	d;
	std::string	e;
	std::string	f;

	std::stringstream			out1;
	ft::list<int>::iterator		it1;
	ft::list<int>				lst1a;
	ft::list<int>				lst1b;

	for (int i = -5; i < 5; i++)
		lst1a.push_back(i);
	for (int i = 50; i < 100; i++)
		lst1b.push_back(i * 5);
	out1 << print_list(lst1a) << std::endl;
	it1 = lst1a.begin();
	++it1;
	lst1a.splice(it1, lst1b);
	out1 << print_list(lst1a) << std::endl;
	out1 << print_list(lst1b) << std::endl;
	a = out1.str();

	std::stringstream			out2;
	std::list<int>::iterator	it2;
	std::list<int>				lst2a;
	std::list<int>				lst2b;

	for (int i = -5; i < 5; i++)
		lst2a.push_back(i);
	for (int i = 50; i < 100; i++)
		lst2b.push_back(i * 5);
	out2 << print_list(lst2a) << std::endl;
	it2 = lst2a.begin();
	++it2;
	lst2a.splice(it2, lst2b);
	out2 << print_list(lst2a) << std::endl;
	out2 << print_list(lst2b) << std::endl;
	b = out2.str();

	std::stringstream			out3;
	ft::list<int>::iterator		it3;
	ft::list<int>				lst3a;
	ft::list<int>				lst3b;

	for (int i = -5; i < 5; i++)
		lst3a.push_back(i);
	for (int i = 50; i < 100; i++)
		lst3b.push_back(i * 5);
	out3 << print_list(lst3a) << std::endl;
	it3 = lst3a.begin();
	++it3;
	out3 << print_list(lst3a) << std::endl;
	out3 << print_list(lst3b) << std::endl;
	lst3b.splice(lst3b.begin(), lst3a, it3);
	out3 << print_list(lst3a) << std::endl;
	out3 << print_list(lst3b) << std::endl;
	c = out3.str();

	std::stringstream			out4;
	std::list<int>::iterator	it4;
	std::list<int>				lst4a;
	std::list<int>				lst4b;

	for (int i = -5; i < 5; i++)
		lst4a.push_back(i);
	for (int i = 50; i < 100; i++)
		lst4b.push_back(i * 5);
	out4 << print_list(lst4a) << std::endl;
	it4 = lst4a.begin();
	++it4;
	out4 << print_list(lst4a) << std::endl;
	out4 << print_list(lst4b) << std::endl;
	lst4b.splice(lst4b.begin(), lst4a, it4);
	out4 << print_list(lst4a) << std::endl;
	out4 << print_list(lst4b) << std::endl;
	d = out4.str();

	std::stringstream			out5;
	ft::list<int>::iterator		it5;
	ft::list<int>				lst5a;

	for (int i = -5; i < 5; i++)
		lst5a.push_back(i);
	it5 = lst5a.begin();
	++it5;
	out5 << print_list(lst5a) << std::endl;
	lst5a.splice(lst5a.begin(), lst5a, it5, lst5a.end());
	out5 << print_list(lst5a) << std::endl;
	e = out5.str();

	std::stringstream			out6;
	std::list<int>::iterator	it6;
	std::list<int>				lst6a;

	for (int i = -5; i < 5; i++)
		lst6a.push_back(i);
	it6 = lst6a.begin();
	++it6;
	out6 << print_list(lst6a) << std::endl;
	lst6a.splice(lst6a.begin(), lst6a, it6, lst6a.end());
	out6 << print_list(lst6a) << std::endl;
	f = out6.str();

	std::cout << "splice: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "][" << (!(e.compare(f)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/3 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/3 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
		if (e.compare(f)) {
			std::cout << "- 3/3 -" << std::endl;
			std::cout << e;
			std::cout << "-" << std::endl;
			std::cout << f;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			remove(bool show_errors)
{
	std::string a;
	std::string b;

	std::stringstream	out1;
	ft::list<int>		lst1;

	for (int i = -5; i < 5; i++)
		lst1.push_back(i);

	out1 << print_list(lst1) << std::endl;
	lst1.remove(-5);
	lst1.remove(1);
	lst1.remove(4);
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream	out2;
	std::list<int>		lst2;

	for (int i = -5; i < 5; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	lst2.remove(-5);
	lst2.remove(1);
	lst2.remove(4);
	out2 << print_list(lst2) << std::endl;
	b = out2.str();
	std::cout << "remove: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			remove_if(bool show_errors)
{
	std::string a;
	std::string b;

	std::stringstream	out1;
	ft::list<int>		lst1;

	for (int i = -15; i < 15; i++)
		lst1.push_back(i);
	for (int i = -15; i < 15; i++)
		lst1.push_back(i);
	out1 << print_list(lst1) << std::endl;
	lst1.remove_if(single_digit);
	out1 << print_list(lst1) << std::endl;
	lst1.remove_if(is_odd());
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream	out2;
	std::list<int>		lst2;

	for (int i = -15; i < 15; i++)
		lst2.push_back(i);
	for (int i = -15; i < 15; i++)
		lst2.push_back(i);
	out2 << print_list(lst2) << std::endl;
	lst2.remove_if(single_digit);
	out2 << print_list(lst2) << std::endl;
	lst2.remove_if(is_odd());
	out2 << print_list(lst2) << std::endl;
	b = out2.str();
	std::cout << "remove_if: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			unique(bool show_errors)
{
	std::string a;
	std::string b;

	std::string c;
	std::string d;

	std::stringstream	out1;
	ft::list<int>		lst1;

	for (int i = -5; i < 0; i++)
		lst1.push_back(i);
	lst1.push_back(1);
	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(2);
	lst1.push_back(2);
	lst1.push_back(1);
	out1 << print_list(lst1) << std::endl;
	lst1.unique();
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream	out2;
	std::list<int>		lst2;

	for (int i = -5; i < 0; i++)
		lst2.push_back(i);
	lst2.push_back(1);
	lst2.push_back(1);
	lst2.push_back(2);
	lst2.push_back(2);
	lst2.push_back(2);
	lst2.push_back(1);
	out2 << print_list(lst2) << std::endl;
	lst2.unique();
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::stringstream	out3;
	ft::list<int>		lst3;

	for (int i = -5; i < 0; i++)
		lst3.push_back(i);
	lst3.push_back(1);
	lst3.push_back(1);
	lst3.push_back(-5);
	lst3.push_back(2);
	lst3.push_back(2);
	lst3.push_back(2);
	lst3.push_back(-2);
	lst3.push_back(-2);
	lst3.push_back(51);
	lst3.push_back(-6);
	lst3.push_back(-6);
	lst3.push_back(-6);
	out3 << print_list(lst3) << std::endl;
	lst3.unique(same_integral_part);
	out3 << print_list(lst3) << std::endl;
	lst3.unique(is_near());
	out3 << print_list(lst3) << std::endl;
	c = out3.str();

	std::stringstream	out4;
	std::list<int>		lst4;

	for (int i = -5; i < 0; i++)
		lst4.push_back(i);
	lst4.push_back(1);
	lst4.push_back(1);
	lst4.push_back(-5);
	lst4.push_back(2);
	lst4.push_back(2);
	lst4.push_back(2);
	lst4.push_back(-2);
	lst4.push_back(-2);
	lst4.push_back(51);
	lst4.push_back(-6);
	lst4.push_back(-6);
	lst4.push_back(-6);
	out4 << print_list(lst4) << std::endl;
	lst4.unique(same_integral_part);
	out4 << print_list(lst4) << std::endl;
	lst4.unique(is_near());
	out4 << print_list(lst4) << std::endl;
	d = out4.str();

	std::cout << "unique: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "- 1/2 -" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "- 2/2 -" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			merge(bool show_errors)
{
	std::string a;
	std::string b;

	std::string c;
	std::string d;

	std::stringstream	out1;
	ft::list<double>	lst1a;
	ft::list<double>	lst1b;

	lst1a.push_back(3.1);
	lst1a.push_back(2.2);
	lst1a.push_back(2.9);

	lst1b.push_back(3.7);
	lst1b.push_back(7.1);
	lst1b.push_back(1.4);

	out1 << print_list(lst1a) << std::endl;
	out1 << print_list(lst1b) << std::endl;

	lst1a.merge(lst1b);
	
	out1 << print_list(lst1a) << std::endl;
	out1 << print_list(lst1b) << std::endl;
	lst1b.push_back(2.1);
	out1 << print_list(lst1a) << std::endl;
	out1 << print_list(lst1b) << std::endl;
	lst1a.merge(lst1b,less);
	out1 << print_list(lst1a) << std::endl;
	out1 << print_list(lst1b) << std::endl;
	a = out1.str();

	std::stringstream	out2;
	std::list<double>	lst2a;
	std::list<double>	lst2b;

	lst2a.push_back(3.1);
	lst2a.push_back(2.2);
	lst2a.push_back(2.9);

	lst2b.push_back(3.7);
	lst2b.push_back(7.1);
	lst2b.push_back(1.4);

	out2 << print_list(lst2a) << std::endl;
	out2 << print_list(lst2b) << std::endl;
	lst2a.merge(lst2b);
	out2 << print_list(lst2a) << std::endl;
	out2 << print_list(lst2b) << std::endl;
	lst2b.push_back(2.1);
	out2 << print_list(lst2a) << std::endl;
	out2 << print_list(lst2b) << std::endl;
	lst2a.merge(lst2b,less);
	out2 << print_list(lst2a) << std::endl;
	out2 << print_list(lst2b) << std::endl;
	b = out2.str();

	std::cout << "merge: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			sort(bool show_errors)
{
	std::string a;
	std::string b;

	std::stringstream		out1;
	ft::list<int>			lst1;

	lst1.push_back(5);
	lst1.push_back(25);
	lst1.push_back(-35);
	lst1.push_back(0);
	lst1.push_back(-1);
	lst1.push_back(10);
	lst1.push_back(9);

	out1 << print_list(lst1) << std::endl;
	lst1.sort();
	out1 << print_list(lst1) << std::endl;
	lst1.sort(less);
	out1 << print_list(lst1) << std::endl;
	lst1.sort(greater);
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream		out2;
	std::list<int>			lst2;

	lst2.push_back(5);
	lst2.push_back(25);
	lst2.push_back(-35);
	lst2.push_back(0);
	lst2.push_back(-1);
	lst2.push_back(10);
	lst2.push_back(9);

	out2 << print_list(lst2) << std::endl;
	lst2.sort();
	out2 << print_list(lst2) << std::endl;
	lst2.sort(less);
	out2 << print_list(lst2) << std::endl;
	lst2.sort(greater);
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::cout << "sort: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

static void 			reverse(bool show_errors)
{
	std::string a;
	std::string b;

	std::stringstream		out1;
	ft::list<int>			lst1;

	for (int i = 0; i < 10; i++)
		lst1.push_back(i * 5);

	out1 << print_list(lst1) << std::endl;
	lst1.reverse();
	out1 << print_list(lst1) << std::endl;
	a = out1.str();

	std::stringstream		out2;
	std::list<int>			lst2;

	for (int i = 0; i < 10; i++)
		lst2.push_back(i * 5);

	out2 << print_list(lst2) << std::endl;
	lst2.reverse();
	out2 << print_list(lst2) << std::endl;
	b = out2.str();

	std::cout << "reverse: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

void	operators(bool show_errors)
{
	std::string a;
	std::string b;

	std::stringstream		out1;
	ft::list<int> 			lst1, lst2, lst3;
	
	lst1.push_back(10);
	lst1.push_back(20);
	lst1.push_back(30);

	lst2.push_back(10);
	lst2.push_back(20);
	lst2.push_back(30);

	lst3.push_back(30);
	lst3.push_back(20);
	lst3.push_back(10);

	if (lst1 == lst2) out1 << "a and b are equal\n";
	if (lst2 != lst3) out1 << "b and c are not equal\n";
	if (lst2 < lst3) out1 << "b is less than c\n";
	if (lst3 > lst2) out1 << "c is greater than b\n";
	if (lst1 <= lst2) out1 << "a is less than or equal to b\n";
	if (lst1 >= lst2) out1 << "a is greater than or equal to b\n";

	a = out1.str();

	std::stringstream		out2;
	std::list<int> 			lst4, lst5, lst6;
	
	lst4.push_back(10);
	lst4.push_back(20);
	lst4.push_back(30);

	lst5.push_back(10);
	lst5.push_back(20);
	lst5.push_back(30);

	lst6.push_back(30);
	lst6.push_back(20);
	lst6.push_back(10);

	if (lst4 == lst5) out2 << "a and b are equal\n";
	if (lst5 != lst6) out2 << "b and c are not equal\n";
	if (lst5 < lst6) out2 << "b is less than c\n";
	if (lst6 > lst5) out2 << "c is greater than b\n";
	if (lst4 <= lst5) out2 << "a is less than or equal to b\n";
	if (lst4 >= lst5) out2 << "a is greater than or equal to b\n";

	b = out2.str();

	std::cout << "operators: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

void	reverse_iterator(bool show_errors)
{
	std::string a;
	std::string b;
	
	std::stringstream					out1;
	ft::list<float> 					lst1;

	for (int i = 0; i < 7; i++)
		lst1.push_back(i * 3.75f);

	ft::list<float>::reverse_iterator	rit1(lst1.begin());
	ft::list<float>::reverse_iterator	rit2(lst1.end());

	rit1--;
	rit2--;
	while (rit1 != rit2)
	{
		out1 << *rit1 << ' ' << '\n';
		--rit1;
	}
	a = out1.str();

	std::stringstream					out2;
	std::list<float> 					lst2;

	for (int i = 0; i < 7; i++)
		lst2.push_back(i * 3.75f);

	std::list<float>::reverse_iterator	rit3(lst2.begin());
	std::list<float>::reverse_iterator	rit4(lst2.end());

	rit3--;
	rit4--;
	while (rit3 != rit4)
	{
		out2 << *rit3 << ' ' << '\n';
		--rit3;
	}
	b = out2.str();

	std::cout << "reverse_iterator: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

void	inception(bool show_errors)
{
	std::string a;
	std::string b;
	
	std::stringstream			out1;
	ft::list<int>				list1(3, 3);
	//ft::list<ft::list<int> > 	list2;
	ft::list<ft::list<int> > 	list3(5, list1);

	out1 << "BOB(5, test(test, 5)) : \n";
	//ft::list<ft::list<int> > 	list4(list3);

	/*out1 << print_list(list2);
	out1 << print_list(list3);
	out1 << print_list(list4);*/
	out1 << print_list(list1);

	/*out1 << "\nCTORS\n";
	out1 << "Empty is empty ? " << std::boolalpha << list1.empty() << '\n';
	out1 << "BOB is empty? " << list3.empty() << '\n';

	out1 << "Size of JOHN " << list1.size() << std::endl;
	out1 << "Size of BOB " << list3.size() << std::endl;
	out1 << "Size of MIKE " << list4.size() << std::endl;*/

	/*out1 << print_list(list2);
	out1 << print_list(list3);
	out1 << print_list(list4);
	out1 << print_list(list1);*/
	a = out1.str();

	std::stringstream			out2;
	std::list<int>				list5(3, 3);
	//std::list<std::list<int> > 	list6;
	std::list<std::list<int> > 	list7(5, list5);

	out2 << "BOB(5, test(test, 5)) : \n";
	//std::list<std::list<int> > 	list8(list7);
	/*out2 << print_list(list6);
	out2 << print_list(list7);
	out2 << print_list(list7);*/
	out2 << print_list(list5);

	/*out2 << "\nCTORS\n";
	out2 << "Empty is empty ? " << std::boolalpha << list5.empty() << '\n';
	out2 << "BOB is empty? " << list7.empty() << '\n';

	out2 << "Size of JOHN " << list5.size() << std::endl;
	out2 << "Size of BOB " << list7.size() << std::endl;
	out2 << "Size of MIKE " << list7.size() << std::endl;*/

	/*out2 << print_list(list6);
	out2 << print_list(list7);
	out2 << print_list(list7);
	out2 << print_list(list5);*/
	b = out2.str();

	std::cout << "inception: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
	}
}

void	test_list(bool show_errors)
{
	std::cout << "<=== Testing list ===>" << std::endl;
	begin(show_errors);
	end(show_errors);
	rbegin(show_errors);
	rend(show_errors);
	empty(show_errors);
	size(show_errors);
	max_size(show_errors);
	front(show_errors);
	back(show_errors);
	assign(show_errors);
	push_front(show_errors);
	pop_front(show_errors);
	push_back(show_errors);
	pop_back(show_errors);
	insert(show_errors);
	erase(show_errors);
	swap(show_errors);
	resize(show_errors);
	clear(show_errors);
	splice(show_errors);
	remove(show_errors);
	remove_if(show_errors);
	unique(show_errors);
	merge(show_errors);
	sort(show_errors);
	reverse(show_errors);
	operators(show_errors);
	reverse_iterator(show_errors);
	inception(show_errors);
	std::cout << std::endl;
}