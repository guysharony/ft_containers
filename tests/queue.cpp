#include "../include/Queue.hpp"
#include <iostream>
#include <queue>

static void		empty(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	std::queue<int>			queue1;

	out1 << queue1.empty() << std::endl;

	for (int i = 0; i < 10; i++) queue1.push(i);

	out1 << queue1.empty() << std::endl;

	while (!queue1.empty()) queue1.pop();

	out1 << queue1.empty() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	ft::queue<int>			queue2;

	out2 << queue2.empty() << std::endl;
	
	for (int i = 0; i < 10; i++) queue2.push(i);

	out2 << queue2.empty() << std::endl;

	while (!queue2.empty()) queue2.pop();

	out2 << queue2.empty() << std::endl;

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

static void		size(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	std::queue<int>			queue1;

	out1 << queue1.size() << std::endl;

	for (int i = -10; i < 10; i++) queue1.push(i);

	out1 << queue1.size() << std::endl;

	while (queue1.size() > 10) queue1.pop();

	out1 << queue1.size() << std::endl;

	while (queue1.size() > 5) queue1.pop();

	out1 << queue1.size() << std::endl;

	while (queue1.size()) queue1.pop();

	out1 << queue1.size() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	ft::queue<int>			queue2;

	out2 << queue2.size() << std::endl;

	for (int i = -10; i < 10; i++) queue2.push(i);

	out2 << queue2.size() << std::endl;

	while (queue2.size() > 10) queue2.pop();

	out2 << queue2.size() << std::endl;

	while (queue2.size() > 5) queue2.pop();

	out2 << queue2.size() << std::endl;

	while (queue2.size()) queue2.pop();

	out2 << queue2.size() << std::endl;

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

static void		front(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	ft::queue<int>			queue1;

	for (int i = 0; i < 10; i++) queue1.push(i);

	out1 << queue1.front() << std::endl;

	queue1.front() -= 3;

	out1 << queue1.front() << std::endl;

	queue1.pop();

	out1 << queue1.front() << std::endl;

	queue1.front() -= 567;

	out1 << queue1.front() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	std::queue<int>			queue2;

	for (int i = 0; i < 10; i++) queue2.push(i);

	out2 << queue2.front() << std::endl;

	queue2.front() -= 3;

	out2 << queue2.front() << std::endl;

	queue2.pop();

	out2 << queue2.front() << std::endl;

	queue2.front() -= 567;

	out2 << queue2.front() << std::endl;

	b = out2.str();

	std::cout << "front: [";
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

static void		back(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	ft::queue<int>			queue1;

	for (int i = 0; i < 10; i++) queue1.push(i);

	out1 << queue1.back() << std::endl;

	queue1.back() -= 3;

	out1 << queue1.back() << std::endl;

	queue1.pop();

	out1 << queue1.back() << std::endl;

	queue1.back() -= 567;

	out1 << queue1.back() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	std::queue<int>			queue2;

	for (int i = 0; i < 10; i++) queue2.push(i);

	out2 << queue2.back() << std::endl;

	queue2.back() -= 3;

	out2 << queue2.back() << std::endl;

	queue2.pop();

	out2 << queue2.back() << std::endl;

	queue2.back() -= 567;

	out2 << queue2.back() << std::endl;

	b = out2.str();

	std::cout << "back: [";
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

static void		push(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	std::queue<int>			queue1;

	for (int i = 0; i < 10; i++) queue1.push(i);

	while (!queue1.empty())
	{
		out1 << queue1.front() << std::endl;
		queue1.pop();
	}

	a = out1.str();

	std::stringstream 		out2;
	ft::queue<int>			queue2;

	for (int i = 0; i < 10; i++) queue2.push(i);

	while (!queue2.empty())
	{
		out2 << queue2.front() << std::endl;
		queue2.pop();
	}

	b = out2.str();

	std::cout << "push: [";
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

static void		pop(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	std::queue<int>			queue1;

	for (int i = -50; i < 10; i++) queue1.push(i);

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	queue1.pop();

	out1 << "[" << queue1.size() << "] : " << queue1.front() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	ft::queue<int>			queue2;

	for (int i = -50; i < 10; i++) queue2.push(i);

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	queue2.pop();

	out2 << "[" << queue2.size() << "] : " << queue2.front() << std::endl;

	b = out2.str();

	std::cout << "pop: [";
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

static void		operators(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	std::queue<int>			queue1a;
	for (int i = -50; i < 10; i++) queue1a.push(i);

	std::queue<int>			queue1b(queue1a);

	out1 << (queue1a == queue1b) << std::endl;
	out1 << (queue1a != queue1b) << std::endl;
	out1 << (queue1a < queue1b) << std::endl;
	out1 << (queue1a <= queue1b) << std::endl;
	out1 << (queue1a > queue1b) << std::endl;
	out1 << (queue1a >= queue1b) << std::endl;

	a = out1.str();

	std::stringstream 		out2;

	ft::queue<int>			queue2a;
	for (int i = -50; i < 10; i++) queue2a.push(i);

	ft::queue<int>			queue2b(queue2a);

	out2 << (queue2a == queue2b) << std::endl;
	out2 << (queue2a != queue2b) << std::endl;
	out2 << (queue2a < queue2b) << std::endl;
	out2 << (queue2a <= queue2b) << std::endl;
	out2 << (queue2a > queue2b) << std::endl;
	out2 << (queue2a >= queue2b) << std::endl;

	b = out2.str();

	std::cout << "operators & constructors: [";
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

void			test_queue(bool show_errors)
{
	std::cout << "<=== Testing queue ===>" << std::endl;
	empty(show_errors);
	size(show_errors);
	front(show_errors);
	back(show_errors);
	push(show_errors);
	pop(show_errors);
	operators(show_errors);
}