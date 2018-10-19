#pragma once
#ifndef _SIMPLIFY_PATH_H_
#define _SIMPLIFY_PATH_H_

#include "pch.h"

/**
 * Problem: Given an absolute path for a file (Unix-style), simplify it.
 */
class SimplifyPath
{
public:

	/* This problem can be solved with a string parser and a stack. The string 
	 * parser should scan along the string. Possible cases:
	 *	1. If a '/' is encountered, then ignore it. 
	 *	2. If a '.' is encountered, then ignore it, since it doesn't do anything
	 *		in simplifying the path.
	 *	3. If a '..' is encountered, then pop the top element in the stack, if
	 *		the stack isn't empty.
	 *	4. If a series of characters that aren't the above 3 are encountered, then
	 *		scan ahead until the end of the string or until a '/' is encountered,
	 *		and push that substring to the stack.
	 *
	 * When the entire string has been parsed, the simplified contents of the
	 * path are contained within the stack, where the top of the stack is the 
	 * back of the path, and the bottom of the stack is the front of the path. 
	 * Be sure to attach a '/' to the front of the string path.
	 * 
	 * Note: You can use a list instead of a stack for this problem, and just keep
	 * pushing and popping from the back of the list. This can make sweeping
	 * through the list of directories easier, since we can directly start from
	 * the beginning and go to the end. 
	 */
	std::string simplifyPath(std::string path)
	{

	}
};

#endif	// _SIMPLIFY_PATH_H_