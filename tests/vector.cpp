/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 09:23:47 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/09 17:53:58 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Vector.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string		print_list(std::vector<T> vec)
{
	std::stringstream out;
	typename std::vector<T>::iterator tmp1 = vec.begin();

	out << "[";
	while (tmp1 != vec.end())
	{
		out << *tmp1;
		++tmp1;
		if (tmp1 != vec.end())
			out << ", ";
	}
	out << "]" << std::endl;
	return (out.str());
}

template <typename T>
std::string		print_list(ft::vector<T> vec)
{
	std::stringstream out;
	typename ft::vector<T>::iterator tmp1 = vec.begin();

	out << "[";
	while (tmp1 != vec.end())
	{
		out << *tmp1;
		++tmp1;
		if (tmp1 != vec.end())
			out << ", ";
	}
	out << "]" << std::endl;
	return (out.str());
}

static void			begin(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::vector<int>		vec1;

	for (int i = 1; i < 6; i++)
		vec1.push_back(i);
		
	out1 << print_list(vec1) << std::endl;

	out1 << "begins with " << *vec1.begin() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>	vec2;

	for (int i = 1; i < 6; i++)
		vec2.push_back(i);

	out2 << print_list(vec2) << std::endl;
	out2 << "begins with " << *vec2.begin() << std::endl;
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
	ft::vector<int>		vec1;
	for (int i = -5; i < 1; i++)
		vec1.push_back(i);
	out1 << print_list(vec1) << std::endl;
	out1 << "ends with " << *--vec1.end() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>	vec2;
	for (int i = -5; i < 1; i++)
		vec2.push_back(i);
	out2 << print_list(vec2) << std::endl;
	out2 << "ends with " << *--vec2.end() << std::endl;
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
	ft::vector<int>		vec1;
	for (int i = 1; i < 6; i++)
		vec1.push_back(i);
	out1 << print_list(vec1) << std::endl;
	out1 << "begins with " << *vec1.rbegin() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>	vec2;
	for (int i = 1; i < 6; i++)
		vec2.push_back(i);
	out2 << print_list(vec2) << std::endl;
	out2 << "begins with " << *vec2.rbegin() << std::endl;
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
	ft::vector<int>		vec1;
	for (int i = 1; i < 6; i++)
		vec1.push_back(i);
	out1 << print_list(vec1) << std::endl;
	out1 << "ends with " << *--vec1.rend() << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>	vec2;
	for (int i = 1; i < 6; i++)
		vec2.push_back(i);
	out2 << print_list(vec2) << std::endl;
	out2 << "ends with " << *--vec2.rend() << std::endl;
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

static void			size(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 	out1;
	ft::vector<int>		vec1;
	for (int i = -5; i < 0; i++)
		vec1.push_back(i);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>	vec2;
	for (int i = -5; i < 0; i++)
		vec2.push_back(i);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::vector<int>		vec3;
	out3 << print_list(vec3) << std::endl;
	out3 << "vector contains " << vec3.size() << " elements." << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::vector<int>	vec4;
	out4 << print_list(vec4) << std::endl;
	out4 << "vector contains " << vec4.size() << " elements." << std::endl;
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
	ft::vector<int>		vec1;
	for (int i = -5; i < 0; i++)
		vec1.push_back(i);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector can contain " << vec1.max_size() << " elements." << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>		vec2;
	for (int i = -5; i < 0; i++)
		vec2.push_back(i);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector can contain " << vec2.max_size() << " elements." << std::endl;
	b = out2.str();

	std::stringstream 	out3;
	ft::vector<int>		vec3;
	out3 << print_list(vec3) << std::endl;
	out3 << "vector can contain " << vec3.max_size() << " elements." << std::endl;
	c = out3.str();

	std::stringstream 	out4;
	std::vector<int>	vec4;
	out4 << print_list(vec4) << std::endl;
	out4 << "vector can contain " << vec4.max_size() << " elements." << std::endl;
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

static void			resize(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::vector<int>		vec1;
	for (int i = 0; i < 50; i++)
		vec1.push_back(i);

	
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	vec1.resize(49);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	vec1.resize(25);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	vec1.resize(10);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	vec1.resize(0);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	vec1.resize(50, 42);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	vec1.resize(10, 21);
	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.size() << " elements." << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>		vec2;
	for (int i = 0; i < 50; i++)
		vec2.push_back(i);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
	vec2.resize(49);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
	vec2.resize(25);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
	vec2.resize(10);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
	vec2.resize(0);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
	vec2.resize(50, 42);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
	vec2.resize(10, 21);
	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.size() << " elements." << std::endl;
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

static void			empty(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::vector<int>		vec1;

	out1 << "vector is ";
	if (!vec1.empty()) out1 << "not ";
	out1 << "empty." << std::endl;

	for (int i = 2; i < 50; i++)
		vec1.push_back(i);
		
	vec1.resize(0);
	
	out1 << print_list(vec1) << std::endl;
	
	out1 << "vector is ";
	if (!vec1.empty()) out1 << "not ";
	out1 << "empty." << std::endl;

	out1 << print_list(vec1) << std::endl;
	out1 << "vector contains " << vec1.empty() << " elements." << std::endl;
	
	a = out1.str();

	std::stringstream 	out2;
	std::vector<int>	vec2;
	
	out2 << "vector is ";
	if (!vec2.empty()) out2 << "not ";
	out2 << "empty." << std::endl;
	
	for (int i = 2; i < 50; i++)
		vec2.push_back(i);

	vec2.resize(0);

	out2 << print_list(vec2) << std::endl;

	out2 << "vector is ";
	if (!vec2.empty()) out2 << "not ";
	out2 << "empty." << std::endl;

	out2 << print_list(vec2) << std::endl;
	out2 << "vector contains " << vec2.empty() << " elements." << std::endl;

	b = out2.str();

	std::cout << "empty: [";
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

static void			reserve(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1;
	ft::vector<int>::size_type		size1;

	size1 = vec1.capacity();
	out1 << "making foo grow:\n";
	for (int i=0; i<100; ++i)
	{
		vec1.push_back(i);
		if (size1 != vec1.capacity()) {
			size1 = vec1.capacity();
			out1 << "capacity changed: " << size1 << '\n';
		}
	}

	ft::vector<int>					vec2;

	size1 = vec2.capacity();
	vec2.reserve(100);
	out1 << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		vec2.push_back(i);
		if (size1 != vec2.capacity()) {
			size1 = vec2.capacity();
			out1 << "capacity changed: " << size1 << '\n';
		}
	}

	try {
		vec2.reserve(vec2.max_size() * 2);
	} catch(std::exception& e) {
		out1 << e.what();
	}
	
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec3;
	std::vector<int>::size_type		size2;

	size2 = vec3.capacity();
	out2 << "making foo grow:\n";
	for (int i=0; i<100; ++i)
	{
		vec3.push_back(i);
		if (size2 != vec3.capacity()) {
			size2 = vec3.capacity();
			out2 << "capacity changed: " << size2 << '\n';
		}
	}

	std::vector<int>				vec4;

	size2 = vec4.capacity();
	vec4.reserve(100);
	out2 << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		vec4.push_back(i);
		if (size2 != vec4.capacity()) {
			size2 = vec4.capacity();
			out2 << "capacity changed: " << size2 << '\n';
		}
	}

	try {
		vec4.reserve(vec4.max_size() * 2);
	} catch(std::exception& e) {
		out2 << e.what();
	}
	
	b = out2.str();

	std::cout << "reserve: [";
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

static void			operate(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1(10);
	ft::vector<int>::size_type		size1;

	size1 = vec1.size();
	for (unsigned i = 0; i < 10; i++)
		vec1[i] = i;
	for (unsigned i = 0; i < size1; i++)
		out1 << "vec[" << i << "]: " << vec1[i] << std::endl;
	for (unsigned i = 0; i < size1 / 2; i++)
	{
		int temp;
		temp = vec1[size1 - 1 - i];
		out1 << "temp: " << temp << std::endl;
		vec1[size1 - 1 - i] = vec1[i];
		out1 << "vec[" << size1 - 1 - i << "]: " << vec1[size1 - 1 - i] << std::endl;
		vec1[i] = temp;
		out1 << "vec[" << i << "]: " << vec1[i] << std::endl;
	}
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2(10);
	std::vector<int>::size_type		size2;

	size2 = vec2.size();
	for (unsigned i = 0; i < 10; i++)
		vec2[i] = i;
	for (unsigned i = 0; i < size2; i++)
		out2 << "vec[" << i << "]: " << vec2[i] << std::endl;
	for (unsigned i = 0; i < size2 / 2; i++)
	{
		int temp;
		temp = vec2[size2 - 1 - i];
		out2 << "temp: " << temp << std::endl;
		vec2[size2 - 1 - i] = vec2[i];
		out2 << "vec[" << size2 - 1 - i << "]: " << vec2[size2 - 1 - i] << std::endl;
		vec2[i] = temp;
		out2 << "vec[" << i << "]: " << vec2[i] << std::endl;
	}
	b = out2.str();

	std::cout << "operator[]: [";
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

void	at(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1(10);

	for (unsigned i = 0; i < vec1.size(); i++)
    	vec1.at(i) = i * 3;
	out1 << print_list(vec1) << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2(10);

	for (unsigned i = 0; i < vec2.size(); i++)
    	vec2.at(i) = i * 3;
	out2 << print_list(vec2) << std::endl;
	b = out2.str();

	std::cout << "at: [";
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

void 	front(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1;

	for (int i = -5; i < 5; i++)
		vec1.push_back(i * 5);
	out1 << print_list(vec1) << std::endl;
	out1 << vec1.front() << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2;

	for (int i = -5; i < 5; i++)
		vec2.push_back(i * 5);
	out2 << print_list(vec2) << std::endl;
	out2 << vec2.front() << std::endl;
	b = out2.str();

	std::cout << "front: [";
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

void 	back(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1;

	for (int i = -5; i < 5; i++)
		vec1.push_back(i * 5);
	out1 << print_list(vec1) << std::endl;
	out1 << vec1.back() << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2;

	for (int i = -5; i < 5; i++)
		vec2.push_back(i * 5);
	out2 << print_list(vec2) << std::endl;
	out2 << vec2.back() << std::endl;
	b = out2.str();

	std::cout << "back: [";
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

void 	assign(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 				out1;
	ft::vector<int>					vec1a;
	ft::vector<int>					vec1b;

	for (int i = -5; i < 5; i++)
		vec1a.push_back(i * 3);
		
	for (int i = -20; i < 20; i++)
		vec1b.push_back(i);

	out1 << print_list(vec1a) << std::endl;
	vec1a.assign(vec1a.begin() + 2, vec1a.end() - 2);
	
	out1 << print_list(vec1a) << std::endl;
	vec1a.assign(vec1b.begin() + 3, vec1b.end() - 3);
	
	out1 << print_list(vec1a) << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2a;
	std::vector<int>				vec2b;

	for (int i = -5; i < 5; i++)
		vec2a.push_back(i * 3);
		
	for (int i = -20; i < 20; i++)
		vec2b.push_back(i);

	out2 << print_list(vec2a) << std::endl;
	vec2a.assign(vec2a.begin() + 2, vec2a.end() - 2);

	out2 << print_list(vec2a) << std::endl;
	vec2a.assign(vec2b.begin() + 3, vec2b.end() - 3);
	
	out2 << print_list(vec2a) << std::endl;
	b = out2.str();

	std::stringstream 				out3;
	ft::vector<int>					vec3;

	for (int i = -5; i < 5; i++)
		vec3.push_back(i * 3);

	out3 << print_list(vec3) << std::endl;
	vec3.assign(42, 42);
	out3 << print_list(vec3) << std::endl;

	c = out3.str();

	std::stringstream 				out4;
	std::vector<int>				vec4;

	for (int i = -5; i < 5; i++)
		vec4.push_back(i * 3);

	out4 << print_list(vec4) << std::endl;
	vec4.assign(42, 42);
	out4 << print_list(vec4) << std::endl;

	d = out4.str();

	std::cout << "assign: [";
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

void 	push_back(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1;

	vec1.push_back(-2147483648);
	for (int i = -5; i < 5; i++)
		vec1.push_back(i * 5);
	vec1.push_back(2147483647);
	out1 << print_list(vec1) << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2;

	vec2.push_back(-2147483648);
	for (int i = -5; i < 5; i++)
		vec2.push_back(i * 5);
	vec2.push_back(2147483647);
	out2 << print_list(vec2) << std::endl;
	b = out2.str();

	std::cout << "push_back: [";
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

void 	pop_back(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1;

	for (int i = -10; i < 10; i++)
		vec1.push_back(i * 10);
	out1 << print_list(vec1) << std::endl;
	out1 << vec1.size() << std::endl;
	for (int i = 10; i > 0; i--)
		vec1.pop_back();
	out1 << print_list(vec1) << std::endl;
	out1 << vec1.size() << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2;

	for (int i = -10; i < 10; i++)
		vec2.push_back(i * 10);
	out2 << print_list(vec2) << std::endl;
	out2 << vec2.size() << std::endl;
	for (int i = 10; i > 0; i--)
		vec2.pop_back();
	out2 << print_list(vec2) << std::endl;
	out2 << vec2.size() << std::endl;
	b = out2.str();

	std::cout << "pop_back: [";
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

void	insert(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::string	e;
	std::string	f;

	std::stringstream			out1;
	ft::vector<int>				vec1;
	ft::vector<int>::iterator 	it1;

	out1 << print_list(vec1) << std::endl;
	it1 = vec1.begin();
	it1 = vec1.insert(it1, 5);
	out1 << print_list(vec1) << std::endl;
	out1 << "iterator pointing on number " << *it1 << std::endl;
	it1 = vec1.insert(it1, -5);
	out1 << print_list(vec1) << std::endl;
	out1 << "iterator pointing on number " << *it1 << std::endl;
	++it1;
	it1 = vec1.insert(it1, 10);
	out1 << print_list(vec1) << std::endl;
	out1 << "iterator pointing on number " << *it1 << std::endl;
	it1 = vec1.begin();
	vec1.insert(it1, 5, 'a');
	out1 << print_list(vec1) << std::endl;
	vec1.insert(it1, 0, 'a');
	out1 << print_list(vec1) << std::endl;
	it1 = vec1.begin();
	out1 << "iterator pointing on number " << *it1 << std::endl;
	vec1.insert(it1, vec1.begin() + 2, vec1.begin() + 6);
	out1 << print_list(vec1) << std::endl;
	it1 = vec1.begin();
	out1 << "iterator pointing on number " << *it1 << std::endl;
	a = out1.str();
	
	std::stringstream			out2;
	std::vector<int>			vec2;
	std::vector<int>::iterator 	it2;

	out2 << print_list(vec2) << std::endl;
	it2 = vec2.begin();
	it2 = vec2.insert(it2, 5);
	out2 << print_list(vec2) << std::endl;
	out2 << "iterator pointing on number " << *it2 << std::endl;
	it2 = vec2.insert(it2, -5);
	out2 << print_list(vec2) << std::endl;
	out2 << "iterator pointing on number " << *it2 << std::endl;
	++it2;
	it2 = vec2.insert(it2, 10);
	out2 << print_list(vec2) << std::endl;
	out2 << "iterator pointing on number " << *it2 << std::endl;
	it2 = vec2.begin();
	vec2.insert(it2, 5, 'a');
	out2 << print_list(vec2) << std::endl;
	vec2.insert(it2, 0, 'a');
	out2 << print_list(vec2) << std::endl;
	it2 = vec2.begin();
	out2 << "iterator pointing on number " << *it2 << std::endl;
	vec2.insert(it2, vec2.begin() + 2, vec2.begin() + 6);
	out2 << print_list(vec2) << std::endl;
	it2 = vec2.begin();
	out2 << "iterator pointing on number " << *it2 << std::endl;
	b = out2.str();

	std::stringstream			out3;
	ft::vector<int>				vec3;
	ft::vector<int>::iterator 	it3;

	out3 << print_list(vec3) << std::endl;
	it3 = vec3.end();
	it3 = vec3.insert(it3, 5);
	out3 << print_list(vec3) << std::endl;
	out3 << "iterator pointing on number " << *it3 << std::endl;
	it3 = vec3.insert(it3, -5);
	out3 << print_list(vec3) << std::endl;
	out3 << "iterator pointing on number " << *it3 << std::endl;
	++it3;
	it3 = vec3.insert(it3, 10);
	out3 << print_list(vec3) << std::endl;
	it3 = vec3.end() - 1;
	out3 << "iterator pointing on number " << *it3 << std::endl;
	vec3.insert(it3, 150, 'z');
	out3 << print_list(vec3) << std::endl;
	it3 = vec3.end() - 1;
	out3 << "iterator pointing on number " << *it3 << std::endl;
	vec3.insert(it3, 0, 'z');
	out3 << print_list(vec3) << std::endl;
	out3 << "iterator pointing on number " << *it3 << std::endl;
	vec3.insert(it3, vec3.begin() + 1, vec3.begin() + 50);
	out3 << print_list(vec3) << std::endl;
	it3 = vec3.end() - 1;
	out3 << "iterator pointing on number " << *it3 << std::endl;
	c = out3.str();
	
	std::stringstream			out4;
	std::vector<int>			vec4;
	std::vector<int>::iterator 	it4;

	out4 << print_list(vec4) << std::endl;
	it4 = vec4.end();
	it4 = vec4.insert(it4, 5);
	out4 << print_list(vec4) << std::endl;
	out4 << "iterator pointing on number " << *it4 << std::endl;
	it4 = vec4.insert(it4, -5);
	out4 << print_list(vec4) << std::endl;
	out4 << "iterator pointing on number " << *it4 << std::endl;
	++it4;
	it4 = vec4.insert(it4, 10);
	out4 << print_list(vec4) << std::endl;
	it4 = vec4.end() - 1;
	out4 << "iterator pointing on number " << *it4 << std::endl;
	vec4.insert(it4, 150, 'z');
	out4 << print_list(vec4) << std::endl;
	it4 = vec4.end() - 1;
	out4 << "iterator pointing on number " << *it4 << std::endl;
	vec4.insert(it4, 0, 'z');
	out4 << print_list(vec4) << std::endl;
	out4 << "iterator pointing on number " << *it4 << std::endl;
	vec4.insert(it4, vec4.begin() + 1, vec4.begin() + 50);
	out4 << print_list(vec4) << std::endl;
	it4 = vec4.end() - 1;
	out4 << "iterator pointing on number " << *it4 << std::endl;
	d = out4.str();

	std::stringstream			out5;
	ft::vector<int> 			vec5(3,100);
	ft::vector<int>::iterator 	it5;

	it5 = vec5.begin();
	it5 = vec5.insert(it5, 200);

	vec5.insert(it5,2,300);

	it5 = vec5.begin();

	ft::vector<int> 			vec5a(2,400);
	vec5.insert(it5+2, vec5a.begin(), vec5a.end());

	int myarray [] = { 501,502,503 };
	vec5.insert(vec5.begin(), myarray, myarray+3);

	for (it5 = vec5a.begin(); it5 < vec5a.end(); it5++)
		out5 << ' ' << *it5;
	out5 << '\n';
	e = out5.str();
	
	std::stringstream			out6;
	std::vector<int> 			vec6(3,100);
	std::vector<int>::iterator 	it6;

	it6 = vec6.begin();
	it6 = vec6.insert(it6, 200);

	vec6.insert(it6,2,300);

	it6 = vec6.begin();

	std::vector<int> 			vec6a(2,400);
	vec6.insert(it6+2, vec6a.begin(), vec6a.end());

	vec6.insert(vec6.begin(), myarray, myarray+3);

	for (it6 = vec6a.begin(); it6 < vec6a.end(); it6++)
		out6 << ' ' << *it6;
	out6 << '\n';
	f = out6.str();
	
	std::cout << "insert: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "---" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

void 	erase(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::stringstream 				out1;
	ft::vector<int>					vec1;

	for (int i = -10; i < 10; i++)
		vec1.push_back(i);
	out1 << print_list(vec1) << std::endl;
	vec1.erase(vec1.begin() + 5);
	out1 << print_list(vec1) << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2;

	for (int i = -10; i < 10; i++)
		vec2.push_back(i);
	out2 << print_list(vec2) << std::endl;
	vec2.erase(vec2.begin() + 5);
	out2 << print_list(vec2) << std::endl;
	b = out2.str();

	std::stringstream 				out3;
	ft::vector<int>					vec3;

	for (int i = -10; i < 10; i++)
		vec3.push_back(i);
	out3 << print_list(vec3) << std::endl;
	vec3.erase(vec3.begin() + 2, vec3.begin() + 5);
	out3 << print_list(vec3) << std::endl;
	c = out3.str();

	std::stringstream 				out4;
	std::vector<int>				vec4;

	for (int i = -10; i < 10; i++)
		vec4.push_back(i);
	out4 << print_list(vec4) << std::endl;
	vec4.erase(vec4.begin() + 2, vec4.begin() + 5);
	out4 << print_list(vec4) << std::endl;
	d = out4.str();

	std::cout << "erase: [";
	std::cout << (!(a.compare(b)) ? "ok" : "error") << "][" << (!(c.compare(d)) ? "ok" : "error") << "]" << std::endl;
	if (show_errors)
	{
		if (a.compare(b)) {
			std::cout << "---" << std::endl;
			std::cout << a;
			std::cout << "-" << std::endl;
			std::cout << b;
			std::cout << "---" << std::endl;
		}
		if (c.compare(d)) {
			std::cout << "---" << std::endl;
			std::cout << c;
			std::cout << "-" << std::endl;
			std::cout << d;
			std::cout << "---" << std::endl;
		}
	}
}

void	swap(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1a(5, 100);
	ft::vector<int>					vec1b(10, 200);

	out1 << print_list(vec1a) << std::endl;
	out1 << print_list(vec1b) << std::endl;
	vec1a.swap(vec1b);
	out1 << print_list(vec1a) << std::endl;
	out1 << print_list(vec1b) << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2a(5, 100);
	std::vector<int>				vec2b(10, 200);

	out2 << print_list(vec2a) << std::endl;
	out2 << print_list(vec2b) << std::endl;
	vec2a.swap(vec2b);
	out2 << print_list(vec2a) << std::endl;
	out2 << print_list(vec2b) << std::endl;
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

void 	clear(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1;

	for (int i = -25; i < 25; i++)
		vec1.push_back(i * 5);

	out1 << vec1.size() << std::endl;
	out1 << vec1.capacity() << std::endl;
	out1 << print_list(vec1) << std::endl;

	vec1.clear();

	out1 << vec1.size() << std::endl;
	out1 << vec1.capacity() << std::endl;

	out1 << print_list(vec1) << std::endl;

	a = out1.str();

	std::stringstream 				out2;
	std::vector<int>				vec2;

	for (int i = -25; i < 25; i++)
		vec2.push_back(i * 5);

	out2 << vec2.size() << std::endl;
	out2 << vec2.capacity() << std::endl;
	out2 << print_list(vec2) << std::endl;

	vec2.clear();

	out2 << vec2.size() << std::endl;
	out2 << vec2.capacity() << std::endl;
	out2 << print_list(vec2) << std::endl;
	
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

static void	inception(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::vector<int>					vec1(3, 3);

	ft::vector<ft::vector<int> >	vec2;
	ft::vector<ft::vector<int> >	*ptr1 = &vec2;
	ft::vector<ft::vector<int> >	*ptr2 = &vec2;

	vec2.assign(4, vec1);
	*ptr1 = *ptr2;

	out1 << std::boolalpha << (*ptr1 == *ptr2) << '\n';

	ft::vector<ft::vector<int> > 	vec3;
	ft::vector<ft::vector<int> >	vec4(5, vec1);
	
	for (size_t i = 0; i < vec4.size(); i++)
	{
		for (size_t j = 0; j < vec4[i].size(); j++)
			out1 << vec4[i][j] << ' ';
		out1 << '\n';
	}
	ft::vector<ft::vector<int> > 	vec5(vec4);

	out1 << "Empty is empty ? " << std::boolalpha << vec3.empty() << '\n';
	out1 << "vec3 is empty? " << vec3.empty() << '\n';

	out1 << "Size of vec3 " << vec3.size() << std::endl;
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	out1 << "Size of vec5 " << vec5.size() << std::endl;

	size_t	vec3_resize = 2;
	vec3.resize(vec3_resize);
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3_resize)
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	out1 << "Size of vec5 " << vec5.size() << std::endl;
	if (vec5.capacity() >= vec5.size())
		out1 << "Capacity of vec5 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	vec5_resize = 9;
	vec3_resize = 0;
	
	vec3.resize(vec3_resize);
	out1 << "vec3 is empty now ? " << vec3.empty() << '\n';
	vec5.resize(vec5_resize, vec1);
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3_resize)
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	out1 << "Size of vec5 " << vec5.size() << std::endl;
	if (vec5.capacity() >= vec5_resize)
		out1 << "Capacity of vec5 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < vec5.size(); i++)
	{
		for (size_t j = 0; j < vec5[i].size(); j++)
		{
			out1 << vec5[i][j] << ' ';
		}
	out1 << std::endl;
	}

	size_t	vec3_reserve = 0;
	size_t	vec4_reserve = 3;
	size_t	vec5_reserve = 4;

	vec3.reserve(vec3_reserve);
	vec4.reserve(vec4_reserve);
	vec5.reserve(vec5_reserve);
	
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3_reserve)
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec4.capacity() >= vec4_reserve)
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	out1 << "Size of vec5 " << vec5.size() << std::endl;
	if (vec5.capacity() >= vec5_reserve)
		out1 << "Capacity of vec5 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < vec5.size(); i++)
	{
		for (size_t j = 0; j < vec5[i].size(); j++)
			out1 << vec5[i][j] << ' ';
	out1 << std::endl;
	}

	try
	{
		out1 << vec5.at(2).front() << '\n';
		out1 << vec5.at(87).back() << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		out1 << "OOR error caught\n";
	}
	
	out1 << "front() of vec5 : " << vec5.front().front() << '\n';
	out1 << "back() of vec5 : " << vec5.back().back() << '\n';

	vec1.assign(3, 17);
	vec3.assign(3, vec1);

	ft::vector<ft::vector<int> >	assign_range;
	assign_range.assign(8, vec1);
	assign_range.assign(vec3.begin() + 1, vec3.end() - 2);

	out1 << "vec3 is empty ? " << vec3.empty() << '\n';
	out1 << "vec3 at(1) : " << vec3.at(1).front() << '\n';

	vec1.assign(2, 42);
	vec3.push_back(vec1);
	out1 << "last elem of vec3 : " << vec3.back().back() << '\n';
	vec3.pop_back();
	out1 << "last elem of vec3 : " << vec3.back().back() << '\n';

	ft::vector<ft::vector<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		ft::vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			out1 << insert_in_me.at(i).at(j) << ' ';
		out1 << '\n';
	}

	ft::vector<ft::vector<int> >::iterator	tmp;
	vec1.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, vec1);
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			out1 << insert_in_me.at(i).at(j) << ' ';
		out1 << '\n';
	}

	ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
	out1 << "Const it.front() : " << std::endl;
	out1 << (*const_it).front() << '\n';

	ft::vector<ft::vector<int> >	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(vec1);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		out1 << std_insert_in_me.at(i).front() << ' ';
	out1 << '\n';

	ft::vector<ft::vector<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, vec1);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		out1 << std_insert_in_me.at(i).back() << ' ';
	out1 << '\n';

	ft::vector<ft::vector<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		ft::vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		out1 << insert_bis[i].back() << ' ';
	out1 << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		out1 << insert_bis[i].back() << ' ';
	out1 << '\n';

	ft::vector<ft::vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		ft::vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		out1 << erase_in_me.at(i).front() << ' ';
	out1 << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		out1 << erase_in_me.at(i).front() << ' ';
	
	out1 << '\n';

	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	
	for (size_t i = 0; i < erase_in_me.size(); i++)
	{
		out1 << erase_in_me.at(i).front() << ' ';
		std::cout << "loop" << std::endl;
	}
	out1 << '\n';

	std::cout << "looper" << std::endl;

	vec3_reserve = 4;
	vec3.reserve(vec3_reserve);
	vec3.swap(vec5);
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	out1 << "Size of vec5 " << vec5.size() << std::endl;
	if (vec5.capacity() >= vec5.size())
		out1 << "Capacity of vec5 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < vec5.size(); i++)
	{
		for (size_t j = 0; j < vec5[i].size(); j++)
			out1 << vec5[i][j] << ' ';
	out1 << std::endl;
	}

	vec5.swap(vec3);
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	out1 << "Size of vec5 " << vec5.size() << std::endl;
	if (vec5.capacity() >= vec5.size())
		out1 << "Capacity of vec5 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < vec5.size(); i++)
	{
		for (size_t j = 0; j < vec5[i].size(); j++)
			out1 << vec5[i][j] << ' ';
	out1 << std::endl;
	}

	vec3.clear();
	vec5.clear();
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	out1 << "Size of vec5 " << vec5.size() << std::endl;
	if (vec5.capacity() >= vec5.size())
		out1 << "Capacity of vec5 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < vec5.size(); i++)
	{
		for (size_t j = 0; j < vec5[i].size(); j++)
			out1 << vec5[i][j] << ' ';
	out1 << std::endl;
	}

	swap(vec3, vec5);
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	out1 << "Size of vec3 " << vec3.size() << std::endl;
	if (vec3.capacity() >= vec3.size())
		out1 << "Capacity of vec3 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	out1 << "Size of vec5 " << vec5.size() << std::endl;
	if (vec5.capacity() >= vec5.size())
		out1 << "Capacity of vec5 is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < vec5.size(); i++)
	{
		for (size_t j = 0; j < vec5[i].size(); j++)
			out1 << vec5[i][j] << ' ';
	out1 << std::endl;
	}
	
	ft::vector<ft::vector<int> > vec5_2(vec5);
	out1 << "vec5 and vec3 are equal ? " << (vec5 == vec3) << '\n';
	out1 << "vec5 and vec5_2 are equal ? " << (vec5 == vec5_2) << '\n';

	out1 << "\nReal Vector\n";
	ft::vector<ft::vector<int> > real;
	real.assign(5, vec1);
	for (ft::vector<ft::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
		out1 << (*it).front() << " ";
	out1 << '\n';

	out1 << std::endl;
	a = out1.str();
	
	std::stringstream 				out2;
	
	b = out2.str();
	
	std::cout << "inseption: [";
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

void	test_vector(bool show_errors)
{
	std::cout << "<=== Testing vector ===>" << std::endl;
	/*begin(show_errors);
	end(show_errors);
	rbegin(show_errors);
	rend(show_errors);
	size(show_errors);
	max_size(show_errors);
	resize(show_errors);
	empty(show_errors);
	reserve(show_errors);
	operate(show_errors);
	at(show_errors);
	front(show_errors);
	back(show_errors);
	assign(show_errors);
	push_back(show_errors);
	pop_back(show_errors);
	insert(show_errors);
	erase(show_errors);
	swap(show_errors);
	clear(show_errors);*/
	inception(show_errors);
	std::cout << std::endl;
}