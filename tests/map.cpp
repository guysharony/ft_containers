/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:46:53 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/06 09:21:25 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Map.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

template <typename Key, typename Value, typename Compare=std::less<Key> >
std::string		print_list(std::map<Key, Value, Compare> vec)
{
	std::stringstream out;
	typename std::map<Key, Value, Compare>::iterator tmp1 = vec.begin();

	out << "[";
	while (tmp1 != vec.end())
	{
		out << "(" << tmp1->first << " <> " << tmp1->second << ")";
		++tmp1;
		if (tmp1 != vec.end())
			out << ", ";
	}
	out << "]" << std::endl;
	return (out.str());
}

template <typename Key, typename Value, typename Compare=ft::less<Key>>
std::string		print_list(ft::map<Key, Value, Compare> vec)
{
	std::stringstream out;
	typename ft::map<Key, Value, Compare>::iterator tmp1 = vec.begin();

	out << "[";
	while (tmp1 != vec.end())
	{
		out << "(" << tmp1->first << " <> " << tmp1->second << ")";
		++tmp1;
		if (tmp1 != vec.end())
			out << ", ";
	}
	out << "]" << std::endl;
	return (out.str());
}

static void	begin(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::map<char, int>	map1;

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.begin()->first << ", " << map1.begin()->second << "]" << std::endl;

	out1 << map1.insert(ft::pair<char,int>('Y', 255)).second << std::endl;
	out1 << map1.insert(ft::pair<char,int>('f', -245)).second << std::endl;
	out1 << map1.insert(ft::pair<char,int>('A', 55)).second << std::endl;

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.begin()->first << ", " << map1.begin()->second << "]" << std::endl;

	out1 << map1.insert(ft::pair<char,int>('+', 46)).second << std::endl;
	out1 << map1.insert(ft::pair<char,int>('k', 865)).second << std::endl;
	out1 << map1.insert(ft::pair<char,int>('&', 5633)).second << std::endl;

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.begin()->first << ", " << map1.begin()->second << "]" << std::endl;

	out1 << map1.insert(ft::pair<char,int>('l', 464346)).second << std::endl;
	out1 << map1.insert(ft::pair<char,int>('=', -24254)).second << std::endl;
	out1 << map1.insert(ft::pair<char,int>('d', 4636)).second << std::endl;

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.begin()->first << ", " << map1.begin()->second << "]" << std::endl;

	out1 << map1.insert(ft::pair<char,int>('3', -346)).second << std::endl;
	out1 << map1.insert(ft::pair<char,int>('w', 24566)).second << std::endl;

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.begin()->first << ", " << map1.begin()->second << "]" << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::map<char, int>	map2;

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.begin()->first << ", " << map2.begin()->second << "]" << std::endl;

	out2 << map2.insert(std::pair<char,int>('Y', 255)).second << std::endl;
	out2 << map2.insert(std::pair<char,int>('f', -245)).second << std::endl;
	out2 << map2.insert(std::pair<char,int>('A', 55)).second << std::endl;

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.begin()->first << ", " << map2.begin()->second << "]" << std::endl;

	out2 << map2.insert(std::pair<char,int>('+', 46)).second << std::endl;
	out2 << map2.insert(std::pair<char,int>('k', 865)).second << std::endl;
	out2 << map2.insert(std::pair<char,int>('&', 5633)).second << std::endl;

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.begin()->first << ", " << map2.begin()->second << "]" << std::endl;

	out2 << map2.insert(std::pair<char,int>('l', 464346)).second << std::endl;
	out2 << map2.insert(std::pair<char,int>('=', -24254)).second << std::endl;
	out2 << map2.insert(std::pair<char,int>('d', 4636)).second << std::endl;

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.begin()->first << ", " << map2.begin()->second << "]" << std::endl;

	out2 << map2.insert(std::pair<char,int>('3', -346)).second << std::endl;
	out2 << map2.insert(std::pair<char,int>('w', 24566)).second << std::endl;

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.begin()->first << ", " << map2.begin()->second << "]" << std::endl;
	b = out2.str();

	std::cout << "begin: [";
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

static void	end(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 	out1;
	ft::map<char, int>	map1;

	out1 << print_list(map1) << std::endl;
	out1 << "ends with [" << map1.end()->first << ", " << map1.end()->second << "]" << std::endl;

	map1.insert(ft::pair<char,int>('6', 74));
	map1.insert(ft::pair<char,int>('a', 635));
	map1.insert(ft::pair<char,int>('H', 35));

	out1 << print_list(map1) << std::endl;
	out1 << "ends with [" << map1.end()->first << ", " << map1.end()->second << "]" << std::endl;

	map1.insert(ft::pair<char,int>('U', 1));
	map1.insert(ft::pair<char,int>('k', 0));
	map1.insert(ft::pair<char,int>('o', 3563563));

	out1 << print_list(map1) << std::endl;
	out1 << "ends with [" << map1.end()->first << ", " << map1.end()->second << "]" << std::endl;
	a = out1.str();

	std::stringstream 	out2;
	std::map<char, int>	map2;

	out2 << print_list(map2) << std::endl;
	out2 << "ends with [" << map2.end()->first << ", " << map2.end()->second << "]" << std::endl;

	map2.insert(std::pair<char,int>('6', 74));
	map2.insert(std::pair<char,int>('a', 635));
	map2.insert(std::pair<char,int>('H', 35));

	out2 << print_list(map2) << std::endl;
	out2 << "ends with [" << map2.end()->first << ", " << map2.end()->second << "]" << std::endl;

	map2.insert(std::pair<char,int>('U', 1));
	map2.insert(std::pair<char,int>('k', 0));
	map2.insert(std::pair<char,int>('o', 3563563));

	out2 << print_list(map2) << std::endl;
	out2 << "ends with [" << map2.end()->first << ", " << map2.end()->second << "]" << std::endl;
	b = out2.str();

	std::cout << "end: [";
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

static void	rbegin(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::map<char, int>				map1;

	map1.insert(ft::pair<char,int>('#', -245));
	map1.insert(ft::pair<char,int>('d', 34));
	map1.insert(ft::pair<char,int>('V', 746));

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.rbegin()->first << ", " << map1.rbegin()->second << "]" << std::endl;

	map1.insert(ft::pair<char,int>('a', -357435635));
	map1.insert(ft::pair<char,int>('5', 345345));
	map1.insert(ft::pair<char,int>('#', 34346));

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.rbegin()->first << ", " << map1.rbegin()->second << "]" << std::endl;

	map1.insert(ft::pair<char,int>('f', -34634));
	map1.insert(ft::pair<char,int>('R', 2346));

	out1 << print_list(map1) << std::endl;
	out1 << "begins with [" << map1.rbegin()->first << ", " << map1.rbegin()->second << "]" << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::map<char, int>				map2;

	map2.insert(std::pair<char,int>('#', -245));
	map2.insert(std::pair<char,int>('d', 34));
	map2.insert(std::pair<char,int>('V', 746));

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.rbegin()->first << ", " << map2.rbegin()->second << "]" << std::endl;

	map2.insert(std::pair<char,int>('a', -357435635));
	map2.insert(std::pair<char,int>('5', 345345));
	map2.insert(std::pair<char,int>('#', 34346));

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.rbegin()->first << ", " << map2.rbegin()->second << "]" << std::endl;

	map2.insert(std::pair<char,int>('f', -34634));
	map2.insert(std::pair<char,int>('R', 2346));

	out2 << print_list(map2) << std::endl;
	out2 << "begins with [" << map2.rbegin()->first << ", " << map2.rbegin()->second << "]" << std::endl;
	b = out2.str();

	std::cout << "rbegin: [";
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

static void	rend(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::map<char, int>				map1;

	map1.insert(ft::pair<char,int>('@', 45));
	map1.insert(ft::pair<char,int>('H', 3));
	map1.insert(ft::pair<char,int>('b', -464));

	out1 << print_list(map1) << std::endl;
	out1 << "ends with [" << map1.rend()->first << ", " << map1.rend()->second << "]" << std::endl;

	map1.insert(ft::pair<char,int>('K', 4353356));
	map1.insert(ft::pair<char,int>('%', 23));

	out1 << print_list(map1) << std::endl;
	out1 << "ends with [" << map1.rend()->first << ", " << map1.rend()->second << "]" << std::endl;

	map1.insert(ft::pair<char,int>('-', -0));
	map1.insert(ft::pair<char,int>('3', +5430));

	out1 << print_list(map1) << std::endl;
	out1 << "ends with [" << map1.rend()->first << ", " << map1.rend()->second << "]" << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::map<char, int>				map2;

	map2.insert(std::pair<char,int>('@', 45));
	map2.insert(std::pair<char,int>('H', 3));
	map2.insert(std::pair<char,int>('b', -464));

	out2 << print_list(map2) << std::endl;
	out2 << "ends with [" << map2.rend()->first << ", " << map2.rend()->second << "]" << std::endl;

	map2.insert(std::pair<char,int>('K', 4353356));
	map2.insert(std::pair<char,int>('%', 23));

	out2 << print_list(map2) << std::endl;
	out2 << "ends with [" << map2.rend()->first << ", " << map2.rend()->second << "]" << std::endl;

	map2.insert(std::pair<char,int>('-', -0));
	map2.insert(std::pair<char,int>('3', +5430));

	out2 << print_list(map2) << std::endl;
	out2 << "ends with [" << map2.rend()->first << ", " << map2.rend()->second << "]" << std::endl;
	b = out2.str();

	std::cout << "rend: [";
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

static void	empty(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::map<char, int>				map1;
	
	out1 << "Is empty? " << map1.empty() << std::endl;

	map1.insert(ft::pair<char,int>('4', 53));
	map1.insert(ft::pair<char,int>('R', -354));
	map1.insert(ft::pair<char,int>('?', 45));
	map1.insert(ft::pair<char,int>('e', 3));
	map1.insert(ft::pair<char,int>('F', -45363));
	map1.insert(ft::pair<char,int>('f', 4545));

	out1 << "Is empty? " << map1.empty() << std::endl;

	map1.clear();

	out1 << "Is empty? " << map1.empty() << std::endl;

	map1.insert(ft::pair<char,int>('4', 53));

	out1 << "Is empty? " << map1.empty() << std::endl;

	a = out1.str();

	std::stringstream 				out2;
	std::map<char, int>				map2;

	out2 << "Is empty? " << map2.empty() << std::endl;

	map2.insert(std::pair<char,int>('4', 53));
	map2.insert(std::pair<char,int>('R', -354));
	map2.insert(std::pair<char,int>('?', 45));
	map2.insert(std::pair<char,int>('e', 3));
	map2.insert(std::pair<char,int>('F', -45363));
	map2.insert(std::pair<char,int>('f', 4545));

	out2 << "Is empty? " << map2.empty() << std::endl;

	map2.clear();

	out2 << "Is empty? " << map2.empty() << std::endl;

	map2.insert(std::pair<char,int>('4', 53));

	out2 << "Is empty? " << map2.empty() << std::endl;

	b = out2.str();

	std::cout << "empty: [";
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

static void	size(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::map<char, int>				map1;

	out1 << "Size? " << map1.size() << std::endl;

	map1.insert(ft::pair<char,int>('c', 300));
	map1.insert(ft::pair<char,int>('&', 400));

	out1 << "Size? " << map1.size() << std::endl;

	map1.insert(ft::pair<char,int>('a', 324));
	map1.insert(ft::pair<char,int>('3', 651));

	out1 << "Size? " << map1.size() << std::endl;

	map1.insert(ft::pair<char,int>('t', -6789));
	map1.insert(ft::pair<char,int>('z', 21));

	out1 << "Size? " << map1.size() << std::endl;

	out1 << print_list(map1) << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::map<char, int>				map2;

	out2 << "Size? " << map2.size() << std::endl;

	map2.insert(std::pair<char,int>('c', 300));
	map2.insert(std::pair<char,int>('&', 400));

	out2 << "Size? " << map2.size() << std::endl;

	map2.insert(std::pair<char,int>('a', 324));
	map2.insert(std::pair<char,int>('3', 651));

	out2 << "Size? " << map2.size() << std::endl;

	map2.insert(std::pair<char,int>('t', -6789));
	map2.insert(std::pair<char,int>('z', 21));

	out2 << "Size? " << map2.size() << std::endl;

	out2 << print_list(map2) << std::endl;
	b = out2.str();

	std::cout << "size: [";
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

static void	max_size(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::map<char, int>				map1;

	out1 << "max_size? " << map1.max_size() << std::endl;

	map1.insert(ft::pair<char,int>('4', -5236));
	map1.insert(ft::pair<char,int>('d', 7));

	out1 << "max_size? " << map1.max_size() << std::endl;

	map1.insert(ft::pair<char,int>('y', 635));
	map1.insert(ft::pair<char,int>('t', 13));

	out1 << "max_size? " << map1.max_size() << std::endl;

	map1.insert(ft::pair<char,int>('&', 765));
	map1.insert(ft::pair<char,int>('r', 255));

	out1 << "max_size? " << map1.max_size() << std::endl;

	out1 << print_list(map1) << std::endl;
	a = out1.str();

	std::stringstream 				out2;
	std::map<char, int>				map2;

	out2 << "max_size? " << map2.max_size() << std::endl;

	map2.insert(std::pair<char,int>('4', -5236));
	map2.insert(std::pair<char,int>('d', 7));

	out2 << "max_size? " << map2.max_size() << std::endl;

	map2.insert(std::pair<char,int>('y', 635));
	map2.insert(std::pair<char,int>('t', 13));

	out2 << "max_size? " << map2.max_size() << std::endl;

	map2.insert(std::pair<char,int>('&', 765));
	map2.insert(std::pair<char,int>('r', 255));

	out2 << "max_size? " << map2.max_size() << std::endl;

	out2 << print_list(map2) << std::endl;
	b = out2.str();
	
	std::cout << "max_size: [";
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


static void	find(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::map<char, int>				map1;
	
	out1 << "Exists? " << ((map1.find('?') != map1.end()) ? "true" : "false") << std::endl;

	map1.insert(ft::pair<char,int>('h', 45));
	map1.insert(ft::pair<char,int>('R', 76556));

	out1 << "Exists? " << ((map1.find('?') != map1.end()) ? "true" : "false") << std::endl;

	map1.insert(ft::pair<char,int>('9', 235));
	map1.insert(ft::pair<char,int>('?', -3456));

	out1 << "Exists? " << ((map1.find('?') != map1.end()) ? "true" : "false") << std::endl;

	map1.insert(ft::pair<char,int>('D', 45757));
	map1.insert(ft::pair<char,int>('m', 2345));
	map1.insert(ft::pair<char,int>('!', -34743534));

	out1 << "Exists? " << ((map1.find('!') != map1.end()) ? "true" : "false") << std::endl;

	a = out1.str();

	std::stringstream 				out2;
	std::map<char, int>				map2;

	out2 << "Exists? " << ((map2.find('?') != map2.end()) ? "true" : "false") << std::endl;

	map2.insert(std::pair<char,int>('h', 45));
	map2.insert(std::pair<char,int>('R', 76556));

	out2 << "Exists? " << ((map2.find('?') != map2.end()) ? "true" : "false") << std::endl;

	map2.insert(std::pair<char,int>('9', 235));
	map2.insert(std::pair<char,int>('?', -3456));

	out2 << "Exists? " << ((map2.find('?') != map2.end()) ? "true" : "false") << std::endl;

	map2.insert(std::pair<char,int>('D', 45757));
	map2.insert(std::pair<char,int>('m', 2345));
	map2.insert(std::pair<char,int>('!', -34743534));

	out2 << "Exists? " << ((map2.find('!') != map2.end()) ? "true" : "false") << std::endl;

	b = out2.str();

	std::cout << "find: [";
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

static void	operat(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 				out1;
	ft::map<char, int>				map1;
	
	out1 << (map1['4'] = -263) << std::endl;
  	out1 << (map1['A'] = 53) << std::endl;
  	out1 << (map1['&'] = map1['4']) << std::endl;
	out1 << (map1['4'] = map1['$']) << std::endl;
	out1 << print_list(map1) << std::endl;
	
	map1.clear();

	out1 << (map1['T'] = 3) << std::endl;
  	out1 << (map1['h'] = 0) << std::endl;
  	out1 << (map1['7'] = map1['4']) << std::endl;
	out1 << (map1['T'] = map1['h']) << std::endl;
	out1 << print_list(map1) << std::endl;

	a = out1.str();

	std::stringstream 				out2;
	std::map<char, int>				map2;

	out2 << (map2['4'] = -263) << std::endl;
  	out2 << (map2['A'] = 53) << std::endl;
  	out2 << (map2['&'] = map2['4']) << std::endl;
	out2 << (map2['4'] = map2['$']) << std::endl;
	out2 << print_list(map2) << std::endl;

	map2.clear();

	out2 << (map2['T'] = 3) << std::endl;
  	out2 << (map2['h'] = 0) << std::endl;
  	out2 << (map2['7'] = map2['4']) << std::endl;
	out2 << (map2['T'] = map2['h']) << std::endl;
	out2 << print_list(map2) << std::endl;
	
	b = out2.str();

	std::cout << "operator[]: [";
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

static void		insert(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::string	c;
	std::string	d;

	std::string	e;
	std::string	f;

	std::stringstream 								out1a;
	ft::map<char, int>								map1a;
	ft::pair<ft::map<char, int>::iterator, bool>	result1a;

	result1a = map1a.insert(ft::pair<char,int>('&', 3476));
	out1a << "Inserted? [" << result1a.first->first << " : " << result1a.first->second << "] => " << result1a.second << std::endl;
	out1a << print_list(map1a) << std::endl;

	result1a = map1a.insert(ft::pair<char,int>('d', 7));
	out1a << "Inserted? [" << result1a.first->first << " : " << result1a.first->second << "] => " << result1a.second << std::endl;
	out1a << print_list(map1a) << std::endl;

	result1a = map1a.insert(ft::pair<char,int>('Y', 635));
	out1a << "Inserted? [" << result1a.first->first << " : " << result1a.first->second << "] => " << result1a.second << std::endl;
	out1a << print_list(map1a) << std::endl;

	result1a = map1a.insert(ft::pair<char,int>('6', -13));
	out1a << "Inserted? [" << result1a.first->first << " : " << result1a.first->second << "] => " << result1a.second << std::endl;
	out1a << print_list(map1a) << std::endl;

	result1a = map1a.insert(ft::pair<char,int>('e', 735));
	out1a << "Inserted? [" << result1a.first->first << " : " << result1a.first->second << "] => " << result1a.second << std::endl;
	out1a << print_list(map1a) << std::endl;

	result1a = map1a.insert(ft::pair<char,int>('$', -25245));
	out1a << "Inserted? [" << result1a.first->first << " : " << result1a.first->second << "] => " << result1a.second << std::endl;
	out1a << print_list(map1a) << std::endl;

	result1a = map1a.insert(ft::pair<char,int>('y', 635));
	out1a << "Inserted? [" << result1a.first->first << " : " << result1a.first->second << "] => " << result1a.second << std::endl;
	out1a << print_list(map1a) << std::endl;

	a = out1a.str();

	std::stringstream 								out2a;
	std::map<char, int>								map2a;
	std::pair<std::map<char, int>::iterator, bool>	result2a;

	result2a = map2a.insert(std::pair<char,int>('&', 3476));
	out2a << "Inserted? [" << result2a.first->first << " : " << result2a.first->second << "] => " << result2a.second << std::endl;
	out2a << print_list(map2a) << std::endl;

	result2a = map2a.insert(std::pair<char,int>('d', 7));
	out2a << "Inserted? [" << result2a.first->first << " : " << result2a.first->second << "] => " << result2a.second << std::endl;
	out2a << print_list(map2a) << std::endl;

	result2a = map2a.insert(std::pair<char,int>('Y', 635));
	out2a << "Inserted? [" << result2a.first->first << " : " << result2a.first->second << "] => " << result2a.second << std::endl;
	out2a << print_list(map2a) << std::endl;

	result2a = map2a.insert(std::pair<char,int>('6', -13));
	out2a << "Inserted? [" << result2a.first->first << " : " << result2a.first->second << "] => " << result2a.second << std::endl;
	out2a << print_list(map2a) << std::endl;

	result2a = map2a.insert(std::pair<char,int>('e', 735));
	out2a << "Inserted? [" << result2a.first->first << " : " << result2a.first->second << "] => " << result2a.second << std::endl;
	out2a << print_list(map2a) << std::endl;

	result2a = map2a.insert(std::pair<char,int>('$', -25245));
	out2a << "Inserted? [" << result2a.first->first << " : " << result2a.first->second << "] => " << result2a.second << std::endl;
	out2a << print_list(map2a) << std::endl;

	result2a = map2a.insert(std::pair<char,int>('y', 635));
	out2a << "Inserted? [" << result2a.first->first << " : " << result2a.first->second << "] => " << result2a.second << std::endl;
	out2a << print_list(map2a) << std::endl;
	b = out2a.str();

	std::stringstream 								out1b;
	ft::map<char, int>								map1b;
	ft::map<char, int>::iterator					result1b;

	result1b = map1b.insert(map1b.begin(), ft::pair<char,int>('1', 336));
	out1b << "Inserted? [" << result1b->first << "] => " << result1b->second << std::endl;
	out1b << print_list(map1b) << std::endl;

	result1b = map1b.insert(map1b.begin(), ft::pair<char,int>('d', 7));
	out1b << "Inserted? [" << result1b->first << "] => " << result1b->second << std::endl;
	out1b << print_list(map1b) << std::endl;

	result1b = map1b.insert(map1b.begin(), ft::pair<char,int>('Y', -635));
	out1b << "Inserted? [" << result1b->first << "] => " << result1b->second << std::endl;
	out1b << print_list(map1b) << std::endl;

	result1b = map1b.insert(map1b.begin(), ft::pair<char,int>('t', 13));
	out1b << "Inserted? [" << result1b->first << "] => " << result1b->second << std::endl;
	out1b << print_list(map1b) << std::endl;

	result1b = map1b.insert(map1b.begin(), ft::pair<char,int>('&', 735));
	out1b << "Inserted? [" << result1b->first << "] => " << result1b->second << std::endl;
	out1b << print_list(map1b) << std::endl;

	result1b = map1b.insert(map1b.begin(), ft::pair<char,int>('$', -255));
	out1b << "Inserted? [" << result1b->first << "] => " << result1b->second << std::endl;
	out1b << print_list(map1b) << std::endl;

	result1b = map1b.insert(map1b.begin(), ft::pair<char,int>('y', 635));
	out1b << "Inserted? [" << result1b->first << "] => " << result1b->second << std::endl;
	out1b << print_list(map1b) << std::endl;

	c = out1b.str();

	std::stringstream 								out2b;
	std::map<char, int>								map2b;
	std::map<char, int>::iterator					result2b;

	result2b = map2b.insert(map2b.begin(), std::pair<char,int>('1', 336));
	out2b << "Inserted? [" << result2b->first << "] => " << result2b->second << std::endl;
	out2b << print_list(map2b) << std::endl;

	result2b = map2b.insert(map2b.begin(), std::pair<char,int>('d', 7));
	out2b << "Inserted? [" << result2b->first << "] => " << result2b->second << std::endl;
	out2b << print_list(map2b) << std::endl;

	result2b = map2b.insert(map2b.begin(), std::pair<char,int>('Y', -635));
	out2b << "Inserted? [" << result2b->first << "] => " << result2b->second << std::endl;
	out2b << print_list(map2b) << std::endl;

	result2b = map2b.insert(map2b.begin(), std::pair<char,int>('t', 13));
	out2b << "Inserted? [" << result2b->first << "] => " << result2b->second << std::endl;
	out2b << print_list(map2b) << std::endl;

	result2b = map2b.insert(map2b.begin(), std::pair<char,int>('&', 735));
	out2b << "Inserted? [" << result2b->first << "] => " << result2b->second << std::endl;
	out2b << print_list(map2b) << std::endl;

	result2b = map2b.insert(map2b.begin(), std::pair<char,int>('$', -255));
	out2b << "Inserted? [" << result2b->first << "] => " << result2b->second << std::endl;
	out2b << print_list(map2b) << std::endl;

	result2b = map2b.insert(map2b.begin(), std::pair<char,int>('y', 635));
	out2b << "Inserted? [" << result2b->first << "] => " << result2b->second << std::endl;
	out2b << print_list(map2b) << std::endl;

	d = out2b.str();

	std::stringstream 								out1c;
	ft::map<char, int>								map1c;

	map1c.insert(map1b.begin(), map1b.find('t'));
	map1c.clear();
	map1c.insert(map1b.find('$'), map1b.find('d'));
	map1c.clear();
	map1c.insert(map1b.begin(), map1b.end());
	map1c.clear();
	map1c.insert(map1b.begin()++, map1b.end()--);
	map1c.clear();
	map1c.insert(map1b.find('1'), map1b.find('Y'));

	out1c << print_list(map1c) << std::endl;
	e = out1c.str();

	std::stringstream 								out2c;
	std::map<char, int>								map2c;

	map2c.insert(map2b.begin(), map2b.find('t'));
	map2c.clear();
	map2c.insert(map2b.find('$'), map2b.find('d'));
	map2c.clear();
	map2c.insert(map2b.begin(), map2b.end());
	map2c.clear();
	map2c.insert(map2b.begin()++, map2b.end()--);
	map2c.clear();
	map2c.insert(map2b.find('1'), map2b.find('Y'));

	out2c << print_list(map2c) << std::endl;
	f = out2c.str();

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

static void		count(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	ft::map<char, int>		map1;

	out1 << map1.count('5') << std::endl;
	out1 << map1.count('r') << std::endl;
	out1 << map1.count('&') << std::endl;
	
	map1.insert(ft::pair<char,int>('5', 36));
	map1.insert(ft::pair<char,int>('d', 7));
	map1.insert(ft::pair<char,int>('&', -635));

	out1 << map1.count('5') << std::endl;
	out1 << map1.count('r') << std::endl;
	out1 << map1.count('&') << std::endl;

	map1.insert(ft::pair<char,int>('3', 13));
	map1.insert(ft::pair<char,int>('G', 75365));
	map1.insert(ft::pair<char,int>('r', 25));

	out1 << map1.count('r') << std::endl;
	out1 << map1.count('4') << std::endl;
	out1 << map1.count('G') << std::endl;

	out1 << print_list(map1) << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	std::map<char, int>		map2;

	out2 << map2.count('5') << std::endl;
	out2 << map2.count('r') << std::endl;
	out2 << map2.count('&') << std::endl;
	
	map2.insert(std::pair<char,int>('5', 36));
	map2.insert(std::pair<char,int>('d', 7));
	map2.insert(std::pair<char,int>('&', -635));
	
	out2 << map2.count('5') << std::endl;
	out2 << map2.count('r') << std::endl;
	out2 << map2.count('&') << std::endl;

	map2.insert(std::pair<char,int>('3', 13));
	map2.insert(std::pair<char,int>('G', 75365));
	map2.insert(std::pair<char,int>('r', 25));

	out2 << map2.count('r') << std::endl;
	out2 << map2.count('4') << std::endl;
	out2 << map2.count('G') << std::endl;

	out2 << print_list(map2) << std::endl;

	b = out2.str();

	std::cout << "count: [";
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

static void		swap(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	ft::map<char, int>		map1a;
	ft::map<char, int>		map1b;

	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1a.swap(map1b);
	
	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1a.insert(ft::pair<char,int>('5', 0));

	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1a.swap(map1b);
	
	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1a.insert(ft::pair<char,int>('D', 7));
	map1a.insert(ft::pair<char,int>('y', -635));

	map1b.insert(ft::pair<char,int>('&', 13));

	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1a.swap(map1b);
	
	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1b.insert(ft::pair<char,int>('e', 72351465));
	map1b.insert(ft::pair<char,int>('$', -2324555));
	map1b.insert(ft::pair<char,int>('4', 4555));
	map1b.insert(ft::pair<char,int>('a', -23555));

	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1a.swap(map1b);

	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	std::map<char, int>		map2a;
	std::map<char, int>		map2b;

	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2a.swap(map2b);
	
	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2a.insert(std::pair<char,int>('5', 0));

	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2a.swap(map2b);
	
	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2a.insert(std::pair<char,int>('D', 7));
	map2a.insert(std::pair<char,int>('y', -635));

	map2b.insert(std::pair<char,int>('&', 13));

	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2a.swap(map2b);
	
	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2b.insert(std::pair<char,int>('e', 72351465));
	map2b.insert(std::pair<char,int>('$', -2324555));
	map2b.insert(std::pair<char,int>('4', 4555));
	map2b.insert(std::pair<char,int>('a', -23555));

	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2a.swap(map2b);

	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	b = out2.str();

	std::cout << "swap: [";
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

static void		clear(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	ft::map<char, int>		map1a;

	map1a.insert(ft::pair<char,int>('F', 0));
	map1a.insert(ft::pair<char,int>('$', 7445));
	map1a.insert(ft::pair<char,int>('j', -64524535));
	map1a.insert(ft::pair<char,int>('4', -724));
	map1a.insert(ft::pair<char,int>('y', 634535));

	out1 << print_list(map1a) << std::endl;
	map1a.clear();
	out1 << print_list(map1a) << std::endl;
	map1a.clear();
	out1 << print_list(map1a) << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	std::map<char, int>		map2a;

	map2a.insert(std::pair<char,int>('F', 0));
	map2a.insert(std::pair<char,int>('$', 7445));
	map2a.insert(std::pair<char,int>('j', -64524535));
	map2a.insert(std::pair<char,int>('4', -724));
	map2a.insert(std::pair<char,int>('y', 634535));

	out2 << print_list(map2a) << std::endl;
	map2a.clear();
	out2 << print_list(map2a) << std::endl;
	map2a.clear();
	out2 << print_list(map2a) << std::endl;

	b = out2.str();

	std::cout << "clear: [";
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

static void		erase(bool show_errors)
{
	std::string	a;
	std::string	b;
	std::string	c;
	std::string	d;
	std::string	e;
	std::string	f;

	std::stringstream 		out1a;
	ft::map<char, int>		map1a;

	map1a.insert(ft::pair<char,int>('c', 36));
	map1a.insert(ft::pair<char,int>('d', 7));
	map1a.insert(ft::pair<char,int>('y', 635));

	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.begin());
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.begin());
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.begin());
	out1a << map1a.size() << print_list(map1a) << std::endl;

	map1a.insert(ft::pair<char,int>('c', 36));
	map1a.insert(ft::pair<char,int>('d', 7));
	map1a.insert(ft::pair<char,int>('y', 635));

	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(--map1a.end());
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(--map1a.end());
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(--map1a.end());
	out1a << map1a.size() << print_list(map1a) << std::endl;

	map1a.insert(ft::pair<char,int>('a', 36));
	map1a.insert(ft::pair<char,int>('b', 7));
	map1a.insert(ft::pair<char,int>('c', 635));
	map1a.insert(ft::pair<char,int>('d', 654));
	map1a.insert(ft::pair<char,int>('e', 4356));
	map1a.insert(ft::pair<char,int>('f', 65));
	map1a.insert(ft::pair<char,int>('g', 45));
	map1a.insert(ft::pair<char,int>('h', 4356));
	map1a.insert(ft::pair<char,int>('i', 65));
	map1a.insert(ft::pair<char,int>('j', 45));
	map1a.insert(ft::pair<char,int>('k', 45));
	map1a.insert(ft::pair<char,int>('l', 45));
	map1a.insert(ft::pair<char,int>('m', 45));
	map1a.insert(ft::pair<char,int>('n', 45));
	map1a.insert(ft::pair<char,int>('o', 45));
	map1a.insert(ft::pair<char,int>('p', 45));
	map1a.insert(ft::pair<char,int>('q', 45));
	map1a.insert(ft::pair<char,int>('r', 45));
	map1a.insert(ft::pair<char,int>('s', 45));

	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.find('e'));
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.find('k'));
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.find('q'));
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.find('m'));
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.find('r'));
	out1a << map1a.size() << print_list(map1a) << std::endl;
	map1a.erase(map1a.find('g'));
	out1a << map1a.size() << print_list(map1a) << std::endl;

	a = out1a.str();


	std::stringstream 		out2a;
	std::map<char, int>		map2a;

	map2a.insert(std::pair<char,int>('c', 36));
	map2a.insert(std::pair<char,int>('d', 7));
	map2a.insert(std::pair<char,int>('y', 635));

	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.begin());
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.begin());
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.begin());
	out2a << map2a.size() << print_list(map2a) << std::endl;

	map2a.insert(std::pair<char,int>('c', 36));
	map2a.insert(std::pair<char,int>('d', 7));
	map2a.insert(std::pair<char,int>('y', 635));

	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(--map2a.end());
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(--map2a.end());
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(--map2a.end());
	out2a << map2a.size() << print_list(map2a) << std::endl;

	map2a.insert(std::pair<char,int>('a', 36));
	map2a.insert(std::pair<char,int>('b', 7));
	map2a.insert(std::pair<char,int>('c', 635));
	map2a.insert(std::pair<char,int>('d', 654));
	map2a.insert(std::pair<char,int>('e', 4356));
	map2a.insert(std::pair<char,int>('f', 65));
	map2a.insert(std::pair<char,int>('g', 45));
	map2a.insert(std::pair<char,int>('h', 4356));
	map2a.insert(std::pair<char,int>('i', 65));
	map2a.insert(std::pair<char,int>('j', 45));
	map2a.insert(std::pair<char,int>('k', 45));
	map2a.insert(std::pair<char,int>('l', 45));
	map2a.insert(std::pair<char,int>('m', 45));
	map2a.insert(std::pair<char,int>('n', 45));
	map2a.insert(std::pair<char,int>('o', 45));
	map2a.insert(std::pair<char,int>('p', 45));
	map2a.insert(std::pair<char,int>('q', 45));
	map2a.insert(std::pair<char,int>('r', 45));
	map2a.insert(std::pair<char,int>('s', 45));

	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.find('e'));
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.find('k'));
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.find('q'));
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.find('m'));
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.find('r'));
	out2a << map2a.size() << print_list(map2a) << std::endl;
	map2a.erase(map2a.find('g'));
	out2a << map2a.size() << print_list(map2a) << std::endl;

	b = out2a.str();

	std::stringstream 		out1b;
	ft::map<char, int>		map1b;

	map1b.insert(ft::pair<char,int>('c', 36));
	map1b.insert(ft::pair<char,int>('d', 7));
	map1b.insert(ft::pair<char,int>('y', 635));

	out1b << print_list(map1b) << std::endl;
	out1b << map1b.erase('c') << print_list(map1b) << std::endl;
	out1b << map1b.erase('d') << print_list(map1b) << std::endl;
	out1b << map1b.erase('y') << print_list(map1b) << std::endl;

	map1b.insert(ft::pair<char,int>('c', 36));
	map1b.insert(ft::pair<char,int>('d', 7));
	map1b.insert(ft::pair<char,int>('y', 635));

	out1b << print_list(map1b) << std::endl;
	out1b << map1b.erase('y') << print_list(map1b) << std::endl;
	out1b << map1b.erase('d') << print_list(map1b) << std::endl;
	out1b << map1b.erase('c') << print_list(map1b) << std::endl;

	map1b.insert(ft::pair<char,int>('a', 36));
	map1b.insert(ft::pair<char,int>('b', 7));
	map1b.insert(ft::pair<char,int>('c', 635));
	map1b.insert(ft::pair<char,int>('d', 654));
	map1b.insert(ft::pair<char,int>('e', 4356));
	map1b.insert(ft::pair<char,int>('f', 65));
	map1b.insert(ft::pair<char,int>('g', 45));
	map1b.insert(ft::pair<char,int>('h', 4356));
	map1b.insert(ft::pair<char,int>('i', 65));
	map1b.insert(ft::pair<char,int>('j', 45));
	map1b.insert(ft::pair<char,int>('k', 45));
	map1b.insert(ft::pair<char,int>('l', 45));
	map1b.insert(ft::pair<char,int>('m', 45));
	map1b.insert(ft::pair<char,int>('n', 45));
	map1b.insert(ft::pair<char,int>('o', 45));
	map1b.insert(ft::pair<char,int>('p', 45));
	map1b.insert(ft::pair<char,int>('q', 45));
	map1b.insert(ft::pair<char,int>('r', 45));
	map1b.insert(ft::pair<char,int>('s', 45));

	out1b << print_list(map1b) << std::endl;
	out1b << map1b.erase('c') << print_list(map1b) << std::endl;
	out1b << map1b.erase('d') << print_list(map1b) << std::endl;
	out1b << map1b.erase('e') << print_list(map1b) << std::endl;
	out1b << map1b.erase('k') << print_list(map1b) << std::endl;
	out1b << map1b.erase('q') << print_list(map1b) << std::endl;
	out1b << map1b.erase('m') << print_list(map1b) << std::endl;
	out1b << map1b.erase('r') << print_list(map1b) << std::endl;
	out1b << map1b.erase('g') << print_list(map1b) << std::endl;

	c = out1b.str();

	std::stringstream 		out2b;
	std::map<char, int>		map2b;

	map2b.insert(std::pair<char,int>('c', 36));
	map2b.insert(std::pair<char,int>('d', 7));
	map2b.insert(std::pair<char,int>('y', 635));

	out2b << print_list(map2b) << std::endl;
	out2b << map2b.erase('c') << print_list(map2b) << std::endl;
	out2b << map2b.erase('d') << print_list(map2b) << std::endl;
	out2b << map2b.erase('y') << print_list(map2b) << std::endl;

	map2b.insert(std::pair<char,int>('c', 36));
	map2b.insert(std::pair<char,int>('d', 7));
	map2b.insert(std::pair<char,int>('y', 635));

	out2b << print_list(map2b) << std::endl;
	out2b << map2b.erase('y') << print_list(map2b) << std::endl;
	out2b << map2b.erase('d') << print_list(map2b) << std::endl;
	out2b << map2b.erase('c') << print_list(map2b) << std::endl;

	map2b.insert(std::pair<char,int>('a', 36));
	map2b.insert(std::pair<char,int>('b', 7));
	map2b.insert(std::pair<char,int>('c', 635));
	map2b.insert(std::pair<char,int>('d', 654));
	map2b.insert(std::pair<char,int>('e', 4356));
	map2b.insert(std::pair<char,int>('f', 65));
	map2b.insert(std::pair<char,int>('g', 45));
	map2b.insert(std::pair<char,int>('h', 4356));
	map2b.insert(std::pair<char,int>('i', 65));
	map2b.insert(std::pair<char,int>('j', 45));
	map2b.insert(std::pair<char,int>('k', 45));
	map2b.insert(std::pair<char,int>('l', 45));
	map2b.insert(std::pair<char,int>('m', 45));
	map2b.insert(std::pair<char,int>('n', 45));
	map2b.insert(std::pair<char,int>('o', 45));
	map2b.insert(std::pair<char,int>('p', 45));
	map2b.insert(std::pair<char,int>('q', 45));
	map2b.insert(std::pair<char,int>('r', 45));
	map2b.insert(std::pair<char,int>('s', 45));

	out2b << print_list(map2b) << std::endl;
	out2b << map2b.erase('c') << print_list(map2b) << std::endl;
	out2b << map2b.erase('d') << print_list(map2b) << std::endl;
	out2b << map2b.erase('e') << print_list(map2b) << std::endl;
	out2b << map2b.erase('k') << print_list(map2b) << std::endl;
	out2b << map2b.erase('q') << print_list(map2b) << std::endl;
	out2b << map2b.erase('m') << print_list(map2b) << std::endl;
	out2b << map2b.erase('r') << print_list(map2b) << std::endl;
	out2b << map2b.erase('g') << print_list(map2b) << std::endl;

	d = out2b.str();

	std::stringstream 		out1c;
	ft::map<char, int>		map1c;

	map1c.insert(ft::pair<char,int>('a', 36));
	map1c.insert(ft::pair<char,int>('b', 7));
	map1c.insert(ft::pair<char,int>('c', 635));
	map1c.insert(ft::pair<char,int>('d', 654));
	map1c.insert(ft::pair<char,int>('e', 4356));
	map1c.insert(ft::pair<char,int>('f', 65));
	map1c.insert(ft::pair<char,int>('g', 45));
	map1c.insert(ft::pair<char,int>('h', 4356));
	map1c.insert(ft::pair<char,int>('i', 65));
	map1c.insert(ft::pair<char,int>('j', 45));
	map1c.insert(ft::pair<char,int>('k', 45));
	map1c.insert(ft::pair<char,int>('l', 45));
	map1c.insert(ft::pair<char,int>('m', 45));
	map1c.insert(ft::pair<char,int>('n', 45));
	map1c.insert(ft::pair<char,int>('o', 45));
	map1c.insert(ft::pair<char,int>('p', 45));
	map1c.insert(ft::pair<char,int>('q', 45));
	map1c.insert(ft::pair<char,int>('r', 45));
	map1c.insert(ft::pair<char,int>('s', 45));

	out1c << print_list(map1c) << std::endl;
	map1c.erase(map1c.find('c'), map1c.find('o'));
	out1c << print_list(map1c) << std::endl;
	map1c.erase(map1c.find('o'), map1c.find('o'));
	out1c << print_list(map1c) << std::endl;
	map1c.erase(map1c.find('a'), map1c.find('p'));
	out1c << print_list(map1c) << std::endl;
	map1c.erase(map1c.find('p'), map1c.end());
	out1c << print_list(map1c) << std::endl;

	e = out1c.str();

	std::stringstream 		out2c;
	std::map<char, int>		map2c;

	map2c.insert(std::pair<char,int>('a', 36));
	map2c.insert(std::pair<char,int>('b', 7));
	map2c.insert(std::pair<char,int>('c', 635));
	map2c.insert(std::pair<char,int>('d', 654));
	map2c.insert(std::pair<char,int>('e', 4356));
	map2c.insert(std::pair<char,int>('f', 65));
	map2c.insert(std::pair<char,int>('g', 45));
	map2c.insert(std::pair<char,int>('h', 4356));
	map2c.insert(std::pair<char,int>('i', 65));
	map2c.insert(std::pair<char,int>('j', 45));
	map2c.insert(std::pair<char,int>('k', 45));
	map2c.insert(std::pair<char,int>('l', 45));
	map2c.insert(std::pair<char,int>('m', 45));
	map2c.insert(std::pair<char,int>('n', 45));
	map2c.insert(std::pair<char,int>('o', 45));
	map2c.insert(std::pair<char,int>('p', 45));
	map2c.insert(std::pair<char,int>('q', 45));
	map2c.insert(std::pair<char,int>('r', 45));
	map2c.insert(std::pair<char,int>('s', 45));

	out2c << print_list(map2c) << std::endl;
	map2c.erase(map2c.find('c'), map2c.find('o'));
	out2c << print_list(map2c) << std::endl;
	map2c.erase(map2c.find('o'), map2c.find('o'));
	out2c << print_list(map2c) << std::endl;
	map2c.erase(map2c.find('a'), map2c.find('p'));
	out2c << print_list(map2c) << std::endl;
	map2c.erase(map2c.find('p'), map2c.end());
	out2c << print_list(map2c) << std::endl;

	f = out2c.str();

	std::cout << "erase: [";
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
			std::cout << "- 2/3 -" << std::endl;
			std::cout << e;
			std::cout << "-" << std::endl;
			std::cout << f;
			std::cout << "---" << std::endl;
		}
	}
}

static void		key_comp(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 					out1;
	ft::map<char, int>					map1;
	ft::map<char, int>::key_compare		cpr1 = map1.key_comp();

	map1.insert(ft::pair<char,int>('c', 300));
	map1.insert(ft::pair<char,int>('d', 400));
	map1.insert(ft::pair<char,int>('b', 200));
	map1.insert(ft::pair<char,int>('a', 100));

	ft::map<char, int>::iterator		itr1 = map1.begin();

	out1 << print_list(map1) << std::endl;

	char highest1 = map1.rbegin()->first;

	out1 << "highest: [" << highest1 << "]" << std::endl;

	out1 << std::endl;

	do {
		out1 << itr1->first << " => " << itr1->second << std::endl;
	} while (cpr1((*itr1++).first, highest1));

	a = out1.str();

	std::stringstream 					out2;
	std::map<char, int>					map2;
	std::map<char, int>::key_compare	cpr2 = map2.key_comp();

	map2.insert(std::pair<char,int>('c', 300));
	map2.insert(std::pair<char,int>('d', 400));
	map2.insert(std::pair<char,int>('b', 200));
	map2.insert(std::pair<char,int>('a', 100));

	std::map<char, int>::iterator		itr2 = map2.begin();

	out2 << print_list(map2) << std::endl;

	char highest2 = map2.rbegin()->first;

	out2 << "highest: [" << highest2 << "]" << std::endl;

	out2 << std::endl;

	do {
		out2 << itr2->first << " => " << itr2->second << std::endl;
	} while (cpr2((*itr2++).first, highest2));

	b = out2.str();

	std::cout << "key_comp: [";
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

static void		value_comp(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 					out1;
	ft::map<char, int>					map1;

	map1.insert(ft::pair<char,int>('c', 300));
	map1.insert(ft::pair<char,int>('d', 400));
	map1.insert(ft::pair<char,int>('b', 200));
	map1.insert(ft::pair<char,int>('a', 100));

	ft::map<char, int>::iterator		itr1 = map1.begin();

	out1 << print_list(map1) << std::endl;

	ft::pair<char,int> highest1 = *map1.rbegin();

	out1 << "highest: [" << highest1.first << ", " << highest1.second << "]" << std::endl;

	out1 << std::endl;

	do {
		out1 << itr1->first << " => " << itr1->second << std::endl;
	} while (map1.value_comp()(*itr1++, highest1));

	a = out1.str();

	std::stringstream 					out2;
	std::map<char, int>					map2;

	map2.insert(std::pair<char,int>('c', 300));
	map2.insert(std::pair<char,int>('d', 400));
	map2.insert(std::pair<char,int>('b', 200));
	map2.insert(std::pair<char,int>('a', 100));

	std::map<char, int>::iterator		itr2 = map2.begin();

	out2 << print_list(map2) << std::endl;

	std::pair<char,int> highest2 = *map2.rbegin();

	out2 << "highest: [" << highest2.first << ", " << highest2.second << "]" << std::endl;

	out2 << std::endl;

	do {
		out2 << itr2->first << " => " << itr2->second << std::endl;
	} while (map2.value_comp()(*itr2++, highest2));

	b = out2.str();

	std::cout << "value_comp: [";
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

static void		lower_bound(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 					out1;
	ft::map<char, int>					map1;
	ft::map<char, int>::iterator		itr1;

	map1.insert(ft::pair<char,int>('c', 300));
	map1.insert(ft::pair<char,int>('d', 400));
	map1.insert(ft::pair<char,int>('b', 200));
	map1.insert(ft::pair<char,int>('a', 100));

	out1 << print_list(map1) << std::endl;

	itr1 = map1.lower_bound('b');

	map1.erase(itr1, map1.end());

	out1 << print_list(map1) << std::endl;

	a = out1.str();

	std::stringstream 					out2;
	std::map<char, int>					map2;
	std::map<char, int>::iterator		itr2;

	map2.insert(std::pair<char,int>('c', 300));
	map2.insert(std::pair<char,int>('d', 400));
	map2.insert(std::pair<char,int>('b', 200));
	map2.insert(std::pair<char,int>('a', 100));

	out2 << print_list(map2) << std::endl;

	itr2 = map2.lower_bound('b');

	map2.erase(itr2, map2.end());

	out2 << print_list(map2) << std::endl;

	b = out2.str();

	std::cout << "lower_bound: [";
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

static void		upper_bound(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 					out1;
	ft::map<char, int>					map1;
	ft::map<char, int>::iterator		itr1;

	map1.insert(ft::pair<char,int>('c', 300));
	map1.insert(ft::pair<char,int>('d', 400));
	map1.insert(ft::pair<char,int>('b', 200));
	map1.insert(ft::pair<char,int>('a', 100));

	out1 << print_list(map1) << std::endl;

	itr1 = map1.upper_bound('c');

	map1.erase(map1.begin(), itr1);

	out1 << print_list(map1) << std::endl;

	a = out1.str();

	std::stringstream 					out2;
	std::map<char, int>					map2;
	std::map<char, int>::iterator		itr2;

	map2.insert(std::pair<char,int>('c', 300));
	map2.insert(std::pair<char,int>('d', 400));
	map2.insert(std::pair<char,int>('b', 200));
	map2.insert(std::pair<char,int>('a', 100));

	out2 << print_list(map2) << std::endl;

	itr2 = map2.upper_bound('c');

	map2.erase(map2.begin(), itr2);

	out2 << print_list(map2) << std::endl;

	b = out2.str();

	std::cout << "upper_bound: [";
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

static void		equal_range(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 															out1;
	ft::map<char, int>															map1;
	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>		res1;

	map1.insert(ft::pair<char,int>('c', 300));
	map1.insert(ft::pair<char,int>('d', 400));
	map1.insert(ft::pair<char,int>('b', 200));
	map1.insert(ft::pair<char,int>('a', 100));

	out1 << print_list(map1) << std::endl;

	res1 = map1.equal_range('c');

	out1 << "[" << res1.first->first << ", " << res1.first->second << "]" << std::endl;
	out1 << "[" << res1.second->first << ", " << res1.second->second << "]" << std::endl;

	a = out1.str();

	std::stringstream 															out2;
	std::map<char, int>															map2;
	std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator>		res2;

	map2.insert(std::pair<char,int>('c', 300));
	map2.insert(std::pair<char,int>('d', 400));
	map2.insert(std::pair<char,int>('b', 200));
	map2.insert(std::pair<char,int>('a', 100));

	out2 << print_list(map2) << std::endl;

	res2 = map2.equal_range('c');

	out2 << "[" << res2.first->first << ", " << res2.first->second << "]" << std::endl;
	out2 << "[" << res2.second->first << ", " << res2.second->second << "]" << std::endl;

	b = out2.str();

	std::cout << "equal_range: [";
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

static void		constructors(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	ft::map<char, int>		map1a;

	map1a.insert(ft::pair<char,int>('a', 2233));
	map1a.insert(ft::pair<char,int>('r', 636));
	map1a.insert(ft::pair<char,int>('3', 467567));
	map1a.insert(ft::pair<char,int>('M', 34635));
	map1a.insert(ft::pair<char,int>('e', 4556));
	map1a.insert(ft::pair<char,int>('d', 356));
	map1a.insert(ft::pair<char,int>('$', 6367));
	map1a.insert(ft::pair<char,int>('%', 46436));

	ft::map<char, int>		map1b(map1a.begin(), map1a.end());

	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	map1a = map1b;

	out1 << print_list(map1a) << std::endl;
	out1 << print_list(map1b) << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	std::map<char, int>		map2a;

	map2a.insert(std::pair<char,int>('a', 2233));
	map2a.insert(std::pair<char,int>('r', 636));
	map2a.insert(std::pair<char,int>('3', 467567));
	map2a.insert(std::pair<char,int>('M', 34635));
	map2a.insert(std::pair<char,int>('e', 4556));
	map2a.insert(std::pair<char,int>('d', 356));
	map2a.insert(std::pair<char,int>('$', 6367));
	map2a.insert(std::pair<char,int>('%', 46436));

	std::map<char, int>		map2b(map2a.begin(), map2a.end());

	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	map2a = map2b;

	out2 << print_list(map2a) << std::endl;
	out2 << print_list(map2b) << std::endl;

	b = out2.str();

	std::cout << "constructors: [";
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

void	test_map(bool show_errors)
{
	std::cout << "<=== Testing Map ===>" << std::endl;
	begin(show_errors);
	end(show_errors);
	rbegin(show_errors);
	rend(show_errors);
	empty(show_errors);
	size(show_errors);
	max_size(show_errors);
	operat(show_errors);
	insert(show_errors);
	erase(show_errors);
	swap(show_errors);
	clear(show_errors);
	key_comp(show_errors);
	value_comp(show_errors);
	find(show_errors);
	count(show_errors);
	lower_bound(show_errors);
	upper_bound(show_errors);
	equal_range(show_errors);
	constructors(show_errors);
	std::cout << std::endl;
}