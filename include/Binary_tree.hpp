/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsharony <gsharony@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:17:05 by gsharony          #+#    #+#             */
/*   Updated: 2021/04/05 09:34:20 by gsharony         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <cstddef>
# include "Algorithm.hpp"
# include "Functional.hpp"
# include "Utility.hpp"
# include "Iterator.hpp"
# include "TypeTraits.hpp"
# include "Node.hpp"

namespace ft
{
	template <typename T>
	class Binary_tree_iterator
	{
		public:
			typedef T 											value_type;
			typedef T& 											reference;
			typedef T* 											pointer;

			typedef ft::Binary_tree_iterator<T>					self;
			typedef ft::bidirectional_iterator_tag				iterator_category;
			typedef ptrdiff_t									difference_type;

			typedef ft::Binary_tree_node<T>*					node_type;

			Binary_tree_iterator()
			: _node()
			{ }

			Binary_tree_iterator(node_type src)
			: _node(src)
			{ }

			self&						operator++(void)
			{
				if (_node->right)
				{
					get_right(_node);
					most_left(_node);
				}
				else
				{
					while (is_on_right(_node)) get_parent(_node);
					
					if (_node->right != _node->parent) get_parent(_node);
				}
				return (*this);
			}

			self						operator++(int)
			{
				self	tmp(*this);
				operator++();
				return (tmp);
			}

			self&						operator--(void)
			{
				if (!_node->color && _node->parent->parent == _node) get_right(_node);
				else if (_node->left)
				{
					most_right(_node->left);
					get_left(_node);
				}
				else
				{
					while (is_on_left(_node)) get_parent(_node);
					
					if (_node->left != _node->parent) get_parent(_node);
				}
				
				return (*this);
			}

			self						operator--(int)
			{
				self	tmp(*this);
				operator--();
				return (tmp);
			}

			reference					operator*() const
			{
				return (_node->value);
			}

			pointer						operator->() const
			{
				return &(_node->value);
			}

			bool 						operator==(const self& n) const
			{
				return (_node == n._node);
			}

			bool 						operator!=(const self& n) const
			{
				return (_node != n._node);
			}

			node_type					_node;

		private:
			bool						is_on_left(node_type& node)
			{
				return (node == node->parent->left);
			}

			bool						is_on_right(node_type& node)
			{
				return (node == node->parent->right);
			}

			void						get_parent(node_type& node)
			{
				node = node->parent;
			}

			void						get_right(node_type& node)
			{
				node = node->right;
			}

			void						get_left(node_type& node)
			{
				node = node->left;
			}

			void						most_left(node_type& node)
			{
				while (node->left) get_left(node);
			}

			void						most_right(node_type& node)
			{
				while (node->right) get_right(node);
			}
	};

	template <typename T>
	class Binary_tree_const_iterator
	{
		public:
			typedef T 											value_type;
			typedef const T& 									reference;
			typedef const T* 									pointer;

			typedef ft::Binary_tree_const_iterator<T>			self;
			typedef ft::bidirectional_iterator_tag				iterator_category;
			typedef ptrdiff_t									difference_type;

			typedef ft::Binary_tree_node<T>*					node_type;

			Binary_tree_const_iterator()
			: _node()
			{ }

			Binary_tree_const_iterator(node_type src)
			: _node(src)
			{ }

			Binary_tree_const_iterator(const Binary_tree_node<T>& src)
			: _node(src._node)
			{ }

			self&						operator++(void)
			{
				if (_node->right)
				{
					get_right(_node);
					most_left(_node);
				}
				else
				{
					while (is_on_right(_node)) get_parent(_node);
					
					if (_node->right != _node->parent) get_parent(_node);
				}
				return (*this);
			}

			self						operator++(int)
			{
				self	tmp(*this);
				operator++();
				return (tmp);
			}

			self&						operator--(void)
			{
				if (!_node->color && _node->parent->parent == _node) get_right(_node);
				else if (_node->left)
				{
					most_right(_node->left);
					get_left(_node);
				}
				else
				{
					while (is_on_left(_node)) get_parent(_node);
					
					if (_node->left != _node->parent) get_parent(_node);
				}
				
				return (*this);
			}

			self						operator--(int)
			{
				self	tmp(*this);
				operator--();
				return (tmp);
			}

			reference					operator*() const
			{
				return (_node->value);
			}

			pointer						operator->() const
			{
				return &(_node->value);
			}

			bool 						operator==(const self& n) const
			{
				return (_node == n._node);
			}

			bool 						operator!=(const self& n) const
			{
				return (_node != n._node);
			}

			node_type					_node;
		
		private:
			bool						is_on_left(node_type& node)
			{
				return (node == node->parent->left);
			}

			bool						is_on_right(node_type& node)
			{
				return (node == node->parent->right);
			}

			void						get_parent(node_type& node)
			{
				node = node->parent;
			}

			void						get_right(node_type& node)
			{
				node = node->right;
			}

			void						get_left(node_type& node)
			{
				node = node->left;
			}

			void						most_left(node_type& node)
			{
				while (node->left) get_left(node);
			}

			void						most_right(node_type& node)
			{
				while (node->right) get_right(node);
			}
	};

	template <class Key, class Value, class Compare = ft::less<Value>, class Node = ft::Binary_tree_node<Value>, class Node_Alloc = std::allocator<Node> >
	class Binary_tree
	{		
		public:
			typedef Key 													key_type;
			typedef Value 													value_type;
			typedef Compare													key_compare;
			typedef value_type*												pointer;
			typedef value_type& 											reference;
			typedef Node													node_type;
			typedef node_type*												node_pointer;
			typedef size_t													size_type;
			typedef Node_Alloc												allocator_type;
			typedef ft::Binary_tree_iterator<Value>							iterator;
			typedef ft::Binary_tree_const_iterator<Value>					const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef ptrdiff_t												difference_type;
			typedef ft::pair<iterator, bool>								result_type;

			Binary_tree(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			:
				_size(0),
				_compare(comp),
				_allocator(alloc)
			{
				initialize_node();
			}

			Binary_tree(const Binary_tree& x)
			:
				_size(0),
				_compare(x._compare),
				_allocator(x._allocator)
			{
				initialize_node(x.begin(), x.end());
			}

			~Binary_tree()
			{
				this->remove(begin(), end());
				destroy_node(_node);
			}

			Binary_tree& 								operator=(const Binary_tree& x)
			{
				this->remove(begin(), end());
				this->insert(x.begin(), x.end());
				return (*this);
			}

			iterator									begin()
			{
				return (iterator(this->_node->left));
			}

			const_iterator								begin() const
			{
				return (const_iterator(this->_node->left));
			}

			iterator									end()
			{
				return (iterator(this->_node));
			}

			const_iterator								end() const
			{
				return (const_iterator(this->_node));
			}

			reverse_iterator							rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator						rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator							rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator						rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			node_pointer								most_begin()
			{
				return (_node->parent);
			}

			const node_pointer							most_begin() const
			{
				return (_node->parent);
			}

			node_pointer								most_end()
			{
				return (_node);
			}

			const node_pointer							most_end() const
			{
				return (_node);
			}

			bool 										empty() const
			{
				return (_size == 0);
			}

			size_type 									size() const
			{
				return (_size);
			}

			size_type 									max_size() const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(node_type));
			}

			node_pointer								most_left(node_pointer _ptr)
			{
				while (_ptr->left) _ptr = _ptr->left;

				return (_ptr);
			}

			node_pointer								most_right(node_pointer _ptr)
			{
				while (_ptr->right) _ptr = _ptr->right;

				return (_ptr);
			}

			bool										scan_tree(node_pointer& _parent, node_pointer& _cursor, value_type value)
			{
				bool _comp = true;

				while (_cursor)
				{
					_parent = _cursor;
					_cursor = (_comp = compaire_keys(value, _cursor)) ? _cursor->left : _cursor->right;
				}

				return (_comp);
			}

			ft::pair<iterator, bool>					insert(value_type value)
			{
				node_pointer	_cursor = most_begin();
				node_pointer	_parent = most_end();
				bool 			_cursor_side = scan_tree(_parent, _cursor, value);
				iterator		_temp = iterator(_parent);
				
				if (_cursor_side && _temp == begin() || compaire_keys(((_cursor_side) ? --_temp : _temp), value))
					return (result_type(repair_insert(insert_node(value, _parent, _cursor)), true));

				return (result_type(iterator(_parent), false));
			}

			iterator									insert(iterator position, value_type value)
			{
				return (this->insert(value).first);
			}

			void										insert(iterator first, iterator second)
			{
				for (; first != second; first++)
					this->insert(*first);
			}

			void										insert(const_iterator first, const_iterator second)
			{
				while (first != second)
					insert(*first++);
			}

			iterator									find(const key_type& k)
			{
				iterator _cursor = begin();

				while (_cursor->first != k && _cursor != end())
					_cursor++;
				
				return (_cursor);
			}

			void										swap(Binary_tree& x)
			{
				node_pointer	_old_node;
				size_type		_old_size;
				key_compare		_old_comp;

				_old_node = x._node;
				_old_size = x._size;
				_old_comp = x._compare;

				x._node = _node;
				x._size = _old_size;
				x._compare = _compare;

				_node = _old_node;
				_size = _old_size;
				_compare = _old_comp;
			}

			const_iterator								find(const key_type& k) const
			{
				const_iterator _cursor = begin();

				while (_cursor->first != k && _cursor != end())
					_cursor++;
				
				return (_cursor);
			}

			void										remove(iterator position)
			{
				node_pointer	_old = position._node;
				node_pointer	_successor = remove_successor(_old);
				node_pointer	_successor_parent = remove_successor_parent(_successor, _old, position._node);

				if (is_black(_old)) repair_remove(_successor, _successor_parent);

				_node->value.first = --_size;
				destroy_node(_old);
			}

			void										remove(iterator first, iterator last)
			{
				while (first != last)
					remove(first++);
			}

			iterator 									lower_bound(const key_type& k)
			{	
				iterator _begin = begin();

				while (_begin != end() && _compare(_begin->first, k))
					_begin++;

				return (_begin);
			}

			iterator 									upper_bound(const key_type& k)
			{	
				iterator _begin = begin();

				while (_begin != end() && !_compare(k, _begin->first))
					_begin++;

				return (_begin);
			}

		private:
			node_pointer								_node;
			size_type									_size;
			allocator_type								_allocator;
			key_compare									_compare;

			node_pointer								create_node(value_type value, node_pointer parent=nullptr)
			{
				node_pointer _tmp = _allocator.allocate(1);
				_allocator.construct(_tmp, Node(false, value));

				_tmp->parent = parent;
				_tmp->left = _tmp->right = 0;

				return (_tmp);
			}

			node_pointer								insert_node(value_type value, node_pointer parent, node_pointer child)
			{
				node_pointer _tmp = create_node(value, parent);

				bool pside = (child || parent == _node || compaire_keys(value, parent));
				bool nlevl = (pside && _tmp->parent == _node);

				((pside) ? push_left(_tmp) : push_right(_tmp));
				((nlevl) ? set_node_end(_tmp) : ((pside) ? set_node_left(_tmp) : set_node_right(_tmp)));

				return (_tmp);
			}

			void										destroy_node(node_pointer& _ptr)
			{
				_allocator.destroy(_ptr);
				_allocator.deallocate(_ptr, 1);
			}

			void										initialize_node(void)
			{
				_node = create_node(value_type(4, 0));
				_node->left = _node->right = _node;
			}

			void										initialize_node(const_iterator first, const_iterator second)
			{
				initialize_node();
				this->insert(first, second);
			}

			bool										compaire_keys(value_type value, node_pointer _ptr)
			{
				return (_compare(value.first, _ptr->value.first));
			}

			bool										compaire_keys(iterator _ptr, value_type value)
			{
				return (_compare(_ptr->first, value.first));
			}

			void										set_node_end(node_pointer& _ptr)
			{
				_node->parent = _node->right = _ptr;
			}

			void										set_node_left(node_pointer& _ptr)	
			{
				if (_ptr->parent == _node->left) _node->left = _ptr;
			}

			void										set_node_right(node_pointer& _ptr)	
			{
				if (_ptr->parent == _node->right) _node->right = _ptr;
			}

			void										push_right(node_pointer& _ptr)
			{
				_ptr->parent->right = _ptr;
			}

			void										push_left(node_pointer& _ptr)
			{
				_ptr->parent->left = _ptr;
			}

			node_pointer								remove_successor(node_pointer& _old)
			{
				if (_old->right && _old->left)
					return (_old = most_left(_old = _old->right))->right;

				return ((!_old->left) ? _old->right : _old->left);
			}

			node_pointer								remove_successor_parent(node_pointer& _successor, node_pointer& _old, node_pointer& _position)
			{
				node_pointer	_parent = ((_old == _position->right) ? _old : _old->parent);

				if (_successor && (_old == _position || _old != _position->right)) _successor->parent = _old->parent;

				node_pointer	_next = ((_old == _position) ? _successor : _old);
				node_pointer&	_brother = ((is_on_left(_position)) ? _position->parent->left : _position->parent->right);

				((most_begin() == _position) ? _node->parent = _next : _brother = _next);

				if (_old == _position)
				{
					if (_node->left == _position) _node->left = ((_position->right) ? most_left(_successor) : _position->parent);
					else if (_node->right == _position) _node->right = ((_position->left) ? most_right(_successor) : _position->parent);

					return (_parent);
				}

				if (_old != _position->right)
				{
					_old->parent->left = _successor;
					switch_child_right(_old, _position);
				}

				switch_child_left(_old, _position);

				_old->parent = _position->parent;

				switch_color(_old, _position);

				_old = _position;

				return (_parent);
			}

			void										switch_color(node_pointer& _dest, node_pointer& _src)
			{
				bool _tmp = _dest->color;
				_dest->color = _src->color;
				_src->color = _tmp;
			}

			void										switch_child_right(node_pointer& _dest, node_pointer& _src)
			{
				_src->right->parent = _dest;
				_dest->right = _src->right;
			}

			void										switch_child_left(node_pointer& _dest, node_pointer& _src)
			{
				_src->left->parent = _dest;
				_dest->left = _src->left;
			}

			node_pointer								get_right(node_pointer& _ptr)
			{
				return (_ptr = _ptr->right);
			}

			node_pointer								get_left(node_pointer& _ptr)
			{
				return (_ptr = _ptr->left);
			}

			node_pointer								get_parent(node_pointer& _ptr)
			{
				return (_ptr = _ptr->parent);
			}

			bool										is_on_right(node_pointer _ptr)
			{
				return (_ptr == _ptr->parent->right);
			}

			bool										is_on_left(node_pointer _ptr)
			{
				return (_ptr == _ptr->parent->left);
			}

			bool										is_red(node_pointer _ptr)
			{
				return (_ptr && _ptr->color == false);
			}

			bool										is_black(node_pointer _ptr)
			{
				return (_ptr && _ptr->color == true);
			}

			iterator									repair_insert(node_pointer _new)
			{
				iterator result = iterator(_new);

				while (_new != most_begin() && is_red(_new->parent))
				{
					bool _side = is_on_left(_new->parent);

					node_pointer _parent = _new->parent->parent;
					node_pointer _child = ((_side) ? _parent->right : _parent->left);

					if (is_red(_child))
					{
						_parent->color >>= _new->parent->color = _child->color = true;
						_new = _parent;
					}
					else
					{
						if (_side & is_on_right(_new)) switch_side(get_parent(_new), _side);
						switch_side(_parent, !_side);

						_parent->color >>= _new->parent->color = true;
					}
					
				}
				
				_node->parent->color = true;

				_node->value.first = ++_size;
				return (result);
			}

			void										repair_remove(node_pointer& _successor, node_pointer& _successor_parent)
			{
				while ((_successor != most_begin() && (!_successor || is_black(_successor))))
				{
					bool _side = (_successor == _successor_parent->left);

					node_pointer& _child = ((_side) ? _successor_parent->right : _successor_parent->left);

					if (is_red(_child)) {
						_successor_parent->color >>= _child->color = true;
						switch_side(_successor_parent, _side);
					}

					node_pointer& _first = ((_side) ? _child->right : _child->left);
					node_pointer& _second = ((_side) ? _child->left : _child->right);

					if (is_red(_first) && is_red(_second))
					{
						_child->color = _successor_parent->color;
						_successor_parent->color = true;

						if (_first) _first->color = true;

						switch_side(_successor_parent, _side);
						
						break;
					}

					_child->color = false;
					_successor = _successor_parent;
					get_parent(_successor_parent);
				
				}
				if (_successor) _successor->color = true;
			}

			void										switch_side(node_pointer const _ptr, bool _side)
			{
				node_pointer const _cursor = ((_side) ? _ptr->right : _ptr->left);
				node_pointer& _second = ((_side) ? _cursor->left : _cursor->right);

				((_side) ? get_left(_ptr->right) : get_right(_ptr->left));

				if (_second) _second->parent = _ptr;
				_cursor->parent = _ptr->parent;

				if (_ptr == _node->parent) _node->parent = _cursor;
				else ((is_on_left(_ptr)) ? _ptr->parent->left : _ptr->parent->right) = _cursor;
				
				_second = _ptr;
				_ptr->parent = _cursor;
			}

	};
}