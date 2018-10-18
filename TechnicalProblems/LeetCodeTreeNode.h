#pragma once
#ifndef _LEET_CODE_TREE_NODE_H_
#define _LEET_CODE_TREE_NODE_H_

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#endif	// _LEET_CODE_TREE_NODE_H_