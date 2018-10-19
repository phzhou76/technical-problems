#pragma once
#ifndef _TREE_LINK_NODE_H_
#define _TREE_LINK_NODE_H_

struct TreeLinkNode
{
	int val;
	TreeLinkNode * left;
	TreeLinkNode * right;
	TreeLinkNode * next;

	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) { }
};

#endif	// _TREE_LINK_NODE_H_