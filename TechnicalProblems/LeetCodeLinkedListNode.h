#pragma once
#ifndef _LEET_CODE_LINKED_LIST_NODE_H_
#define _LEET_CODE_LINKED_LIST_NODE_H_

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(nullptr) { }
};

#endif	// _LEET_CODE_LINKED_LIST_NODE_H_