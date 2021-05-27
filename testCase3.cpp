#include "LinkedList.h"
#include "testCase.h"
void testCaseThree()
{
  //test on accessing node values in a non-reversed list
  cout << endl << "TEST 3 ROUND 1" << endl << endl;
  DoublyLinkedList testThree;
  //testThree.getVal(0); //uncomment to throw an error for trying to access values from an empty list
  testThree.append(0);
  testThree.append(1);
  testThree.append(2);
  testThree.append(3);
  testThree.append(4);
  testThree.append(5);
  testThree.append(6);
  testThree.append(7);
  testThree.printer();
  //testThree.getVal(8); //uncomment to throw an error for trying to access values outside the bounds of the list
  //testThree.getVal(-1); //uncomment to throw an error for trying to access values outside the bounds of the list
  for (int i = 0; i != 8; i++)
  {
    cout << to_string(testThree.getVal(i)) << ",";
  }
  cout << endl;

  //test on accessing node values in a non-reversed list
  cout << endl << "TEST 3 ROUND 2" << endl << endl;
  testThree.reverse();
  //testThree.getVal(8); //uncomment to throw an error for trying to access values outside the bounds of the list
  //testThree.getVal(-1); //uncomment to throw an error for trying to access values outside the bounds of the list
  for (int i = 0; i != 8; i++)
  {
    cout << to_string(testThree.getVal(i)) << ",";
  }
  cout << endl;
}
