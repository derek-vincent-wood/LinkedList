#include <iostream>
#include <string>
#include "LinkedList.h"
void DoublyLinkedList :: append(int value) //appends a value to the end of the list
{
  if (size == 0) //if there are no nodes in the list, the new node being appended is the only node in the list and is both the leftmost and the rightmost node
  {
    ListNode* newNode = new ListNode(NULL, NULL, value); //create a new node with no connections to other nodes
    leftmostNode = newNode; //set the leftmost node to the new node
    rightmostNode = newNode; //set the rightmost node to the new node
    size++; //increment the size
  }
  else if (isReversed == false) //otherwise, if size is greater than 0 and if the list is not reversed, append the new node to the rightmost node
  {
      ListNode* newNode = new ListNode(rightmostNode, NULL, value); //create a new node whose left node is the current node at the rightmost end of the list
      rightmostNode->setRightNode(newNode); //set the rightmost node's right node to be the new node
      rightmostNode = newNode; //set the rightmost node to be the new node
      size++; //increment size
  }
  else //otherwise, if size is greater than 0 and if the list is reversed, append the new node to the leftmost node
  {
    ListNode* newNode = new ListNode(NULL, leftmostNode, value); //create a new node whose right node is the current node at the rightmost end of the list
    leftmostNode->setLeftNode(newNode); //set the leftmost node's left node to be the new node
    leftmostNode = newNode; //set the leftmost node to be the new node
    size++; //increment size
  }
}

int DoublyLinkedList :: pop() //removes the value at the end of the list and returns it. Fully deletes the node
{
  if (size == 0) //if there is nothing that can be popped, print and throw a warning
  {
    cout << "ERROR: No elements in list" << endl;
    throw("ERROR: No elements in list");
  }
  else if (size == 1) //if there is one element in the list, then the leftmost and rightmost nodes are the same node and both need to be addressed
  {
    int value = leftmostNode->getValue(); //store the value
    delete leftmostNode; //note: hypothetically I could have used rightmostNode here, it was just a matter of preference
    leftmostNode = NULL;
    rightmostNode = NULL; //set the references to null
    size--; //decrement the size
    return value; //return the value
  }
  else if (isReversed == false) //if the list is not reversed
  {
    ListNode* newRightNode = rightmostNode->getLeftNode(); //the new rightmost node will be the node to the left of the current rightmost node
    int value = rightmostNode->getValue(); //store the value
    delete rightmostNode; //delete the rightmost node
    rightmostNode = newRightNode; //set rightmostNode to the now rightmost node
    rightmostNode->setRightNode(NULL); //set the rightmost node's right node to be NULL
    size--; //decrement the size
    return value; //return the value
  }
  else //if the list is reversed
  {
    ListNode* newLeftNode = leftmostNode->getRightNode(); //the new leftmost node will be the node to the left of the current leftmost node
    int value = leftmostNode->getValue(); //store the value
    delete leftmostNode; //delete the leftmost node
    leftmostNode = newLeftNode; //set the leftmostNode to the now leftmost node
    leftmostNode->setLeftNode(NULL); //set the leftmost node's left node to be NULL
    size--; //decrement size
    return value; //return the stored value;
  }
}

int DoublyLinkedList :: getVal(int position) //returns the value at the specified location within the list
{
  if (size == 0) //if the size of the list is 0, print and throw an error
  {
    cout << "ERROR: No elements in list to access" << endl;
    throw("ERROR: No elements in list to access");
  }
  else if (position < 0 || position >= size) //if the position is out of bounds, print and throw an error
  {
    cout << "ERROR: Index out of bounds" << endl;
    throw("ERROR: Index out of bounds");
  }
  else if (isReversed == false) //if the position is valid and if the list is not reversed:
  {
    int index;
    ListNode* currentNode = leftmostNode;
    for(index = 0; index != position; index++) //while the current node is not the node located at the specified position, set the current node to its right node
    {
      currentNode = currentNode->getRightNode();
    }
    return currentNode->getValue(); //once the current node is the node located at the specified position, return the value stored in it;
  }
  else
  {
    int index;
    ListNode* currentNode = rightmostNode;
    for(index = 0; index != position; index++)//while the current node is not the node located at the specified position, set the current node to its left node
    {
      currentNode = currentNode -> getLeftNode();
    }
    return currentNode->getValue(); //once the current node is the node located at the specified position, return the value stored in it;
  }
}

void DoublyLinkedList :: setVal(int position, int value) //sets the value at an existing position in the list to the specified value - uses the same traversal mechanism as getVal - in hindsight, this traversal could have been codified into its own internal function, that takes a position and passes the reference to the node located at it.
                                     //Also worth noting that I never do any position checks to see if values at either end of the list are being accessed.
                                     //I have the references to the leftmost and rightmost ends, so why aren't I just checking "if position == 0, get leftmost (rightmost if reversed) node, else if position == size - 1, get rightmost (leftmost if reversed) node"
{
  if (size == 0) //if the size of the list is 0, print and throw an error
  {
    cout << "ERROR: No elements in list to access" << endl;
    throw("ERROR: No elements in list to access");
  }
  else if (position < 0 || position >= size) //if the position is out of bounds, print and throw an error
  {
    cout << "ERROR: Index out of bounds" << endl;
    throw("ERROR: Index out of bounds");
  }
  else if (isReversed == false) //if the position is valid and if the list is not reversed:
  {
    int index;
    ListNode* currentNode = leftmostNode;
    for(index = 0; index != position; index++) //while the current node is not the node located at the specified position, set the current node to its right node
    {
      currentNode = currentNode->getRightNode();
    }
    return currentNode->setValue(value); //once the current node is the node located at the specified position, set the value stored in it;
  }
  else
  {
    int index;
    ListNode* currentNode = rightmostNode;
    for(index = 0; index != position; index++)//while the current node is not the node located at the specified position, set the current node to its left node
    {
      currentNode = currentNode -> getLeftNode();
    }
    return currentNode->setValue(value); //once the current node is the node located at the specified position, set the value stored in it;
  }
}

void DoublyLinkedList :: insert(int position, int value) //inserts a value at the specified location within the list
{
  if (position == 0 && size == 0) //if the list is empty and the position is 0, then the leftmost and rightmost nodes are going to be the same new node with the specified value
  {
    leftmostNode = new ListNode(NULL, NULL, value); //create the new node and set it to the left node
    rightmostNode = leftmostNode; //set the rightmost node to be the leftmost node
    size++; //increment the size
  }
  else if (position < 0 || position > size) //if the position is less than 0 or greater than the size of the list, print and throw a boundary error
  {
    cout << "ERROR: Index out of bounds" << endl;
    throw("ERROR: Index out of bounds");
  }
  else if (isReversed == false) //if the list is not reversed
  {
    if (position == 0) //if the element is being inserted at position 0, then inserting is equivalent to inserting to the end of the reversed list
    {
      isReversed = true;
      append(value);
      isReversed = false;
    }
    else if (position == size) //if the element is being added after the last element, then inserting is the same as appending
    {
      append(value);
    }
    else //otherwise, traversal is needed to do insertion. Values will be pushed to the right (ex. if I have [0, 1, 2, 3], and I insert 300 at position 2, the list should become [0, 1, 300, 2, 3])
    {
      int index; //index of the current node
      ListNode* currentNode = leftmostNode; //referece to the current node
      for (index = 0; index < position -1; index++) //for loop to move from one node to the next, stopping one node short of the position specified
      {
        currentNode = currentNode->getRightNode();
      }
      ListNode* newNode = new ListNode(currentNode, currentNode->getRightNode(), value); //create a new node, whose left node is the current node, whose right node is the current node's right node, and whose value is the value specified
      currentNode->getRightNode()->setLeftNode(newNode); //set the node after the current node's left node to the new node
      currentNode->setRightNode(newNode); //set the current node's right node to the new node
      size++; //increment the size
    }
  }
  else //if the list is reversed - reverse insertion is the same as normal inserting if you can adjust the index. To find the non-reversed index given a reversed index, the formula is size - index - 1. The -1 gets dropped to ensure that proper "bumping" behavior (ex. inserting 3 at position 1 in [10,20,30] should yield [10,3,20,30]). This is a nice solution that uses recursion to allow me to avoid coding for additional cases.
  {
    //the one exception is if a new node is being added to the end of a reversed list. If the position is the size of the list, append to the reversed list.
    if (position == size)
    {
      append(value);
    }
    else
    {
      isReversed = false; //disable the reversed flag temporarily
      int nonReversedIndex = size - position; //calculate the non-reversed index
      cout<<to_string(size)<<","<<to_string(position)<<","<<to_string(nonReversedIndex)<<endl;
      insert(nonReversedIndex, value);
      isReversed = true;
    }
  }
}
void DoublyLinkedList :: printer() //generic printer function - meant to print out the list in order with respect to it being (not) reversed as needed to support debugging. Formats the list using brackets and commas, with the size of the list following the print out
{
  cout << "[";
  ListNode* currentNode;
  if (size == 0) //if there are no elements in the list, print an empty list with the size being 0
    cout << "] | 0" << endl;
  else if (isReversed == false) //if the list is not reversed
  {
    currentNode = leftmostNode; //set the current node to the leftmost node
    while (currentNode != NULL) //while there is still a node to read data from
    {
      if (currentNode->getRightNode() != NULL) //check to see if the node has an upcoming neighbor to decide if the printout of the value needs a comma after it or if it needs a right bracket
        cout << to_string(currentNode->getValue()) << ",";
      else
        cout << to_string(currentNode->getValue()) << "] | " << to_string(size) << endl;
      currentNode = currentNode->getRightNode(); //update the current node - the next node is the right node since the list is not reversed
    }
  }
  else //if the list is reversed
  {
    currentNode = rightmostNode; //set the current node to the rightmost node
    while (currentNode != NULL) //while there is still a node to read data from
    {
      if (currentNode->getLeftNode() != NULL) //check to see if the node has an upcoming neighbor to decide if the printout of the value needs a comma after it or if it needs a right bracket
        cout << to_string(currentNode->getValue()) << ",";
      else
        cout << to_string(currentNode->getValue()) << "] | " << to_string(size) <<endl;
    currentNode = currentNode->getLeftNode(); //update the current node - the next node is the left node since the list is reversed
    }
  }

}
void DoublyLinkedList :: reverse()
{
  isReversed = !isReversed;
}
