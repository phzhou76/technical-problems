#pragma once
#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif	// _TREE_NODE_H_