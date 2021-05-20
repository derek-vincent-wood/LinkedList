#include <iostream>
#include "LinkedList.h"
using namespace std;
void DoublyLinkedList :: append(int value) //appends a value to the end of the list
{
	if (size == 0) //an empty list is a special case since the start and end node would be the same, and both links of the node are NULL
	{
		ListNode *newNode = new ListNode(NULL, NULL, value);
		startNode = newNode;
		endNode = newNode;
	}
	else
	{
		ListNode *newNode = new ListNode(endNode, NULL, value); //create a new node who's previous node is the current end node of the list, and who's next node is NULL
		endNode->setNextNode(newNode, isReversed); //update the link of the current end node to be the new node 
		endNode = newNode; //set the end node to be the new node
	}
	size++;
}
void DoublyLinkedList :: insert(int position, int value) //inserts a value at the specified location within the list
{
	if (position > size || position < 0)
	{
		cout << "invalid insertion: out of bounds" << endl; //print a warning
		throw "invalid insertion: out of bounds"; //throw the error
	}
	if (position == 0) //if the element is being inserted at position 0
	{
		if (size == 0) //if the list is empty, use the append function
		{
			append(value);
		}
		else //otherwise, create a new node with the value, setting its previous node to NULL and its next node to the current start node. Set the current start node's previous node to the new node. Update the new start node to be the new node 
		{
			ListNode *newNode = new ListNode(NULL, startNode, value); //create new node. Previous node is NULL, next node is the start node 
			startNode -> setPrevNode(newNode, isReversed); //set the start node's previous node to be the new node 
			startNode = newNode; //set the start node to be the new node 
			size++; //increment the size 
		}
	}
	else if (position == size) //if the element is being added after the last element of the list, use append to add it to the end of the list 
	{
		append(value);
	}
	else //if the element is being added at some middle point in the list in between two existing nodes
	{
		ListNode *curNode = startNode;
		ListNode *previousNode = curNode -> getPrevNode(isReversed);
		int index = 0;
		while (index != position)
		{
			previousNode = curNode;
			curNode = curNode->getNextNode(isReversed);
			index++;
		}
		ListNode *newNode = new ListNode(previousNode, curNode, value);
		previousNode -> setNextNode(newNode, isReversed);
		curNode -> setPrevNode(newNode, isReversed);
		size += 1;
		
	}
}
int DoublyLinkedList :: pop() //removes the value at the end of the list and returns it
{
	if (size < 1) //if the list is empty, it should not pop anything and throw an error
	{
		cout << "invalid pop: empty list" << endl; //print a warning
		throw "invalid pop: empty list"; //throw the error
	}
	if (size == 1) //if there is only one node in the list, then the statNode and endNode need to be reset 
	{
		int nodeValue = startNode -> getValue(); //store the value of the endnode 
		delete startNode; //delete the node 
		startNode = NULL; //set the startNode to NULL 
		endNode = NULL; //set the endNode to NULL
		size --; //decrement size
		return nodeValue; //return the value 
	}
	else //generic case, only the end node needs to be adjusted 
	{
		int nodeValue = endNode -> getValue(); //store the value of the end node 
		ListNode *newEnd = endNode -> getPrevNode(isReversed); //the new end node is the node prior to the end node 
		delete endNode; //delete the existing end node 
		endNode = newEnd; //set the end of the list to the new end node 
		endNode -> setNextNode(NULL, isReversed); //link the new end node's next node to NULL 
		size--; //decrement size
		return nodeValue; //return the value
	}
}

void DoublyLinkedList :: del(int position) //deletes a value at the specified location within the list
{
	if (position >= size || position < 0) //if the position is greater than or equal to the size of the list, or if the position is less than 0, then it is out of bounds
	{
		cout << "invalid deletion: out of bounds" << endl; //print a warning
		throw "invalid deletion: out of bounds";
	}
	if (position == size - 1) //if the element being deleted is at the end of the list, call the pop() function. Also handles the case where the start of the list is being deleted and there is only one node in the list
	{
		pop(); 
	}
	else if (position == 0) //if the element being deleted is at the start of the list
	{
		//if the start node of the list is not the only element, then the node following it must become the new start node. This is done by setting the startNode's nextNode to be the new startNode, and having that node's previousNode be set to NULL
		ListNode *newStart = startNode -> getNextNode(isReversed); //acquire new start node 
		delete startNode; //delete the existing start node;
		startNode = newStart; //set the startNode equal to the new start node
		startNode -> setPrevNode(NULL, isReversed); //set the previous node of the start node to be NULL
		size--;
		
	}
	else //if the element being deleted is somewhere in the middle of the list, then the node prior to it needs to be linked to the node after it, and the node after it needs to be linked to the node prior to it, then the node can be deleted and the size of the list decremented
	{
		int curIndex = 0;
		ListNode *curNode = startNode;
		while (curIndex != position)
		{
			curIndex++;
			curNode = curNode -> getNextNode(isReversed);
		}
		ListNode *prev = curNode -> getPrevNode(isReversed);
		ListNode *next = curNode -> getNextNode(isReversed);
		prev -> setNextNode(next, isReversed);
		next -> setPrevNode(prev, isReversed);
		delete curNode;
		size--;
	}
} 
int DoublyLinkedList :: getVal(int position) //returns the value at the specified location within the list 
{
	if (position >= size || position < 0) //if the position is greater than or equal to the size of the list, or if the position is less than 0, then it is out of bounds
	{
		cout << "invalid element acccess: out of bounds" << endl; //print a warning
		throw "invalid element access: out of bounds";
	}
	
	int curIndex = 0;
	ListNode *curNode = startNode;
	while (curIndex != position)
	{
		curIndex++;
		curNode = curNode -> getNextNode(isReversed);
	}
	return curNode -> getValue();
}
void DoublyLinkedList :: setVal(int position, int value) //sets the value at an existing position in the list to the specified value 
{
	if (position >= size || position < 0) //if the position is greater than or equal to the size of the list, or if the position is less than 0, then it is out of bounds
	{
		cout << "invalid element acccess: out of bounds" << endl; //print a warning
		throw "invalid element access: out of bounds";
	}
	
	int curIndex = 0;
	ListNode *curNode = startNode;
	while (curIndex != position)
	{
		curIndex++;
		curNode = curNode -> getNextNode(isReversed);
	}
	curNode -> setValue(value);
}
void DoublyLinkedList :: printer() //prints out all of the values within the list
{
	ListNode *curNode = startNode;
	string out = "[";
	while (curNode != NULL)
	{
		if ((curNode -> getNextNode(isReversed)) != NULL)
		{
			out += to_string(curNode -> getValue()) + ",";
			curNode = curNode -> getNextNode(isReversed);
		}
		else
		{
			out += to_string(curNode -> getValue());
			curNode = curNode -> getNextNode(isReversed);
		}
	}
	out = out + "]" + " | size: " + to_string(size);
	cout << out << endl;
}
int main()
{
	DoublyLinkedList test;
	//initial round of tests for appending and popping
	test.append(0);
	test.printer();
	test.append(1);
	test.printer();
	test.append(2);
	test.printer();
	test.append(3);
	test.printer();
	cout << test.pop() << " | ";
	test.printer();
	cout << test.pop() << " | ";
	test.printer();
	cout << test.pop() << " | ";
	test.printer();
	cout << test.pop() << " | ";
	test.printer();
	//cout << test.pop() << " | "; uncomment these two lines to make the program throw an error for trying to pop from an empty list
	//test.printer();
	
	cout << endl << endl << endl;
	//test deleting the first node of the list until the list is empty
	test.append(0);
	test.append(1);
	test.append(2);
	test.append(3);
	test.printer();
	
	test.del(0);
	test.printer();
	test.del(0);
	test.printer();
	test.del(0);
	test.printer();
	test.del(0);
	test.printer();
	
	cout << endl << endl << endl;
	//test deleting arbitrary middle nodes
	test.append(0);
	test.append(1);
	test.append(2);
	test.append(3);
	test.append(4);
	test.append(5);
	test.printer();
	test.del(1);
	test.printer();
	test.del(3);
	test.printer();
	test.del(2);
	test.printer();
	test.del(1);
	test.printer();
	test.del(1);
	test.printer();
	test.del(0);
	test.printer();
//	test.del(-1); //test on bounds, uncomment to throw an error
//	test.del(0);
	cout << endl << endl << endl;
	//test element access
	test.append(0);
	test.append(1);
	test.append(2);
	test.append(3);
	test.append(4);
	test.append(5);
	test.printer();
	cout << test.getVal(0) << "," << test.getVal(1) << "," << test.getVal(2) << "," << test.getVal(3) << "," << test.getVal(4) << "," << test.getVal(5) << endl;
	//test.getVal(-1); //test on bounds, uncomment to throw an error
	//test.getVal(6);
	
	//test element setting
	cout << endl << endl << endl;
	test.setVal(0, -1);
	test.setVal(1, -2);
	test.setVal(2, -3);
	test.setVal(3, -4);
	test.setVal(4, -5);
	test.setVal(5, -6);
	test.printer();
	
	//test adding an element to the start of the list using insert, clearing the list via the clear function, and building it up via the insert function 
	cout << endl << endl << endl;
	test.insert(0, 0);
	test.printer();
	test.clear();
	test.printer();
	
	cout << endl << endl << endl << 276 << endl;;//test building up the list by using insert, then adding an element at the end of the list using insert, then adding elements at arbitrary middle points
	
	test.insert(0, 5);
	test.insert(0, 4);
	test.insert(0, 3);
	test.insert(0, 2);
	test.insert(0, 1);
	test.insert(0, 0);
	test.insert(6, 6);
	test.insert(3, 300);
	test.insert(4, 400);
	test.printer();
	return 0;
}