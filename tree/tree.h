#pragma once

template <class T>
struct _tree_node
{
	using value_type	= T;
	using pself_type	= _tree_node*;

	pself_type	parent;
	pself_type	child;
	pself_type	brother;
	value_type	value;
};

template <class T>
class _tree
{
	using node_type = _tree_node;
	using pnode_type = node_type*;

public:
	_tree();

protected:
	node_type root;
};
