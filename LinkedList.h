#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <string>
using namespace std;
class ListNode
{

public:
	ListNode(ListNode *left, ListNode *right, int val) //constructor
	{
		leftNode = left; //reference to the left node in the sequential order (in the direction of the first node in a non-reversed list)
		rightNode = right; //reference to the right node in the sequential order (in the direction of the last node in a non-reversed list)
		nodeVal = val; //value held by the node
	}
	~ListNode(){}; //Destructor - No specific actions need to be taken
	ListNode* getLeftNode(){return leftNode;} //returns a reference to the left node
	ListNode* getRightNode(){return rightNode;} //returns a reference to the next node
	int getValue() {return nodeVal;} //returns the value of the node
	void setValue(int value) {nodeVal = value;} //sets the value of the node
	void setLeftNode(ListNode* newLeftNode){leftNode = newLeftNode;} //updates leftNode
	void setRightNode(ListNode* newRightNode){rightNode = newRightNode;} //updates rightNode
private:
	ListNode *leftNode = NULL;
	ListNode *rightNode = NULL;
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
	void clear(); //clear the list - used by the destructor to erase all elements - this is critical to avoid memnory leaks since all of the list nodes are on the heap and will not be automatically deleted

	void append(int value); //appends a value to the end of the list
	void insert(int position, int value); //inserts a value at the specified location within the list
	int pop(); //removes the value at the end of the list and returns it
	void del(int position); //deletes a value at the specified location within the list
	int getVal(int position); //returns the value at the specified location within the list
	void setVal(int position, int value); //sets the value at an existing position in the list to the specified value
	void printer(); //prints out all of the values within the list
	void reverse(); //reverses the list in constant time
private:
	ListNode* leftmostNode = NULL;
	ListNode* rightmostNode = NULL;
	int size = 0;
	bool isReversed = false;
};
#endif
