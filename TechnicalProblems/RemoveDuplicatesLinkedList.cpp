#include "pch.h"
#include "RemoveDuplicatesLinkedList.h"

/**
 * Implementation with a hash map. The space and time complexity of this algorithm
 * are both O(n).
 */
void RemoveDuplicatesLinkedList::removeDuplicates(LinkedList<int> &linkedList)
{
	if (linkedList.getSize() < 2)
	{
		return;
	}

	std::unordered_map<int, bool> seenNumbers;
	LinkedListNode<int> * currentNode = linkedList.getHead();
	seenNumbers.insert(std::pair<int, bool>(currentNode->mData, true));

	int nextNodeIndex = 1;
	while (currentNode->mNextNode != nullptr)
	{
		/* If the number is unique, then add the number to the list of unique 
		 * numbers. All nodes to the left of the most recently added node must
		 * contain unique values. 
		 */
		if (seenNumbers.find(currentNode->mNextNode->mData) == seenNumbers.end())
		{
			seenNumbers.insert(std::pair<int, bool>(currentNode->mNextNode->mData, true));
			currentNode = currentNode->mNextNode;
			++nextNodeIndex;
		}
		/* If the number isn't unique, then remove the node from the list without
		 * advancing the pointer. 
		 */
		else
		{
			linkedList.deleteElement(nextNodeIndex);
		}
	}
}

/**
 * Implementation without a temporary buffer. The space complexity is O(1), while
 * the time complexity is O(n^2).
 */
void RemoveDuplicatesLinkedList::removeDuplicatesNoBuffer(LinkedList<int>& linkedList)
{
	if (linkedList.getSize() < 2)
	{
		return;
	}

	/* All nodes to the left of this node, including this node, hold unique values. */
	LinkedListNode<int> * uniqueNode = linkedList.getElement(0);
	int uniqueNodeIndex = 0;

	while (uniqueNode->mNextNode != nullptr)
	{
		/* Used for looking for duplicates past the unique node marker. */
		LinkedListNode<int> * exploreNode = uniqueNode->mNextNode;

		while (exploreNode != nullptr)
		{
			
		}
	}
}

void RemoveDuplicatesLinkedList::testRemoveDuplicatesLinkedList()
{
}
