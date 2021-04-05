#include "../include/Stack.hpp"
#include <iostream>
#include <stack>

static void		empty(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	std::stack<int>			stack1;

	out1 << stack1.empty() << std::endl;

	for (int i = 0; i < 10; i++) stack1.push(i);

	out1 << stack1.empty() << std::endl;

	while (!stack1.empty()) stack1.pop();

	out1 << stack1.empty() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	ft::stack<int>			stack2;

	out2 << stack2.empty() << std::endl;
	
	for (int i = 0; i < 10; i++) stack2.push(i);

	out2 << stack2.empty() << std::endl;

	while (!stack2.empty()) stack2.pop();

	out2 << stack2.empty() << std::endl;

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
	std::stack<int>			stack1;

	out1 << stack1.size() << std::endl;

	for (int i = -10; i < 10; i++) stack1.push(i);

	out1 << stack1.size() << std::endl;

	while (stack1.size() > 10) stack1.pop();

	out1 << stack1.size() << std::endl;

	while (stack1.size() > 5) stack1.pop();

	out1 << stack1.size() << std::endl;

	while (stack1.size()) stack1.pop();

	out1 << stack1.size() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	ft::stack<int>			stack2;

	out2 << stack2.size() << std::endl;

	for (int i = -10; i < 10; i++) stack2.push(i);

	out2 << stack2.size() << std::endl;

	while (stack2.size() > 10) stack2.pop();

	out2 << stack2.size() << std::endl;

	while (stack2.size() > 5) stack2.pop();

	out2 << stack2.size() << std::endl;

	while (stack2.size()) stack2.pop();

	out2 << stack2.size() << std::endl;

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

static void		top(bool show_errors)
{
	std::string	a;
	std::string	b;

	std::stringstream 		out1;
	ft::stack<int>			stack1;

	for (int i = 0; i < 10; i++) stack1.push(i);

	out1 << stack1.top() << std::endl;

	stack1.top() -= 3;

	out1 << stack1.top() << std::endl;

	stack1.pop();

	out1 << stack1.top() << std::endl;

	stack1.top() -= 567;

	out1 << stack1.top() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	std::stack<int>			stack2;

	for (int i = 0; i < 10; i++) stack2.push(i);

	out2 << stack2.top() << std::endl;

	stack2.top() -= 3;

	out2 << stack2.top() << std::endl;

	stack2.pop();

	out2 << stack2.top() << std::endl;

	stack2.top() -= 567;

	out2 << stack2.top() << std::endl;

	b = out2.str();

	std::cout << "top: [";
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
	std::stack<int>			stack1;

	for (int i = 0; i < 10; i++) stack1.push(i);

	while (!stack1.empty())
	{
		out1 << stack1.top() << std::endl;
		stack1.pop();
	}

	a = out1.str();

	std::stringstream 		out2;
	ft::stack<int>			stack2;

	for (int i = 0; i < 10; i++) stack2.push(i);

	while (!stack2.empty())
	{
		out2 << stack2.top() << std::endl;
		stack2.pop();
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
	std::stack<int>			stack1;

	for (int i = -50; i < 10; i++) stack1.push(i);

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	stack1.pop();

	out1 << "[" << stack1.size() << "] : " << stack1.top() << std::endl;

	a = out1.str();

	std::stringstream 		out2;
	ft::stack<int>			stack2;

	for (int i = -50; i < 10; i++) stack2.push(i);

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

	stack2.pop();

	out2 << "[" << stack2.size() << "] : " << stack2.top() << std::endl;

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
	std::stack<int>			stack1a;
	for (int i = -50; i < 10; i++) stack1a.push(i);

	std::stack<int>			stack1b(stack1a);

	out1 << (stack1a == stack1b) << std::endl;
	out1 << (stack1a != stack1b) << std::endl;
	out1 << (stack1a < stack1b) << std::endl;
	out1 << (stack1a <= stack1b) << std::endl;
	out1 << (stack1a > stack1b) << std::endl;
	out1 << (stack1a >= stack1b) << std::endl;

	a = out1.str();

	std::stringstream 		out2;

	ft::stack<int>			stack2a;
	for (int i = -50; i < 10; i++) stack2a.push(i);

	ft::stack<int>			stack2b(stack2a);

	out2 << (stack2a == stack2b) << std::endl;
	out2 << (stack2a != stack2b) << std::endl;
	out2 << (stack2a < stack2b) << std::endl;
	out2 << (stack2a <= stack2b) << std::endl;
	out2 << (stack2a > stack2b) << std::endl;
	out2 << (stack2a >= stack2b) << std::endl;

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

void			test_stack(bool show_errors)
{
	std::cout << "<=== Testing stack ===>" << std::endl;
	empty(show_errors);
	size(show_errors);
	top(show_errors);
	push(show_errors);
	pop(show_errors);
	operators(show_errors);
	std::cout << std::endl;
}