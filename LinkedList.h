#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <string>
using namespace std;
class ListNode
{
	
public:
	ListNode(ListNode *prev, ListNode *next, int val) //constructor
	{
		previousNode = prev;
		nextNode = next;
		nodeVal = val;
	}
	~ListNode(){}; //Destructor - No specific actions need to be taken
	ListNode* getNextNode(bool reversed) //returns a reference to the next node
	{
		if (reversed) 
			return previousNode;
		else
			return nextNode;
	} 
	ListNode* getPrevNode(bool reversed) //returns a reference to the previous node
	{
		if (reversed)
			return nextNode;
		else
			return previousNode;
	} 
	int getValue() {return nodeVal;} //returns the value of the node
	void setValue(int value) {nodeVal = value;} //sets the value of the node
	void setPrevNode(ListNode *node, bool reversed) //sets the previous node reference
	{
		if (reversed)
			nextNode = node;
		else
			previousNode = node;
	}  
	void setNextNode(ListNode *node, bool reversed) //sets the next node reference
	{
		if (reversed)
			previousNode = node;
		else
			nextNode = node;
	} 
private:
	ListNode *previousNode = NULL;
	ListNode *nextNode = NULL;
	int nodeVal;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList(){}; //constructor - Currently the list starts as being empty and integers are appended to it by calling functions
	~DoublyLinkedList() //destructor - iterates over all of the nodes, deleting them until there are no remaining nodes 
	{
	clear(); //call the clear function to delete all elements of the list
	}
	void clear() //clear the list - used by the destructor to erase all elements
	{
		ListNode* curNode = startNode;
		if (isReversed)
			ListNode* curNode = endNode;
		else
			ListNode* curNode = startNode;
		
		ListNode* nextNode = NULL;
		while (curNode != NULL)
		{
			nextNode = curNode -> getNextNode(isReversed); //if the current node is not empty, obtain the reference to the next node that comes after it
			delete curNode; //delete the current node 
			curNode = nextNode; //set the current node to the next node 
			size -= 1;
		}
		startNode = NULL;
	}
	
	void append(int value); //appends a value to the end of the list
	void insert(int position, int value); //inserts a value at the specified location within the list
	int pop(); //removes the value at the end of the list and returns it 
	void del(int position); //deletes a value at the specified location within the list 
	int getVal(int position); //returns the value at the specified location within the list 
	void setVal(int position, int value); //sets the value at an existing position in the list to the specified value 
	void printer(); //prints out all of the values within the list 
	void reverse(); //reverses the list
	ListNode *getStartNode(){}; //gets the start node
	ListNode *getEndNode(){}; //gets the end node 
private:
	ListNode* startNode = NULL;
	ListNode* endNode = NULL;
	int size = 0;
	bool isReversed = false;
};
#endif