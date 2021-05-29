#include "LinkedList.h"
#include "testCase.h"
void testCaseSeven()
{
  //test on clearing the list with zero elements - Note that testing reversed lists is not neccessary, since the clear function does not care about whether the list is reversed or not
  cout << endl << "TEST 7 ROUND 1" << endl << endl;
  DoublyLinkedList testSeven;
  testSeven.printer();
  testSeven.clear();
  testSeven.printer();
  cout << endl;

  //test on clearing the list with one element
  cout << endl << "TEST 7 ROUND 2" << endl << endl;
  testSeven.append(0);
  testSeven.printer();
  testSeven.clear();
  testSeven.printer();

  //test on clearing the list with multiple elements
  cout << endl << "TEST 7 ROUND 3" << endl << endl;
  testSeven.append(0);
  testSeven.append(1);
  testSeven.append(2);
  testSeven.append(3);
  testSeven.append(4);
  testSeven.append(5);
  testSeven.append(6);
  testSeven.append(7);
  testSeven.append(8);
  testSeven.append(9);
  testSeven.printer();
  testSeven.clear();
  testSeven.printer();


  //while I stated that checking how clear behaves when reversed is not neccessary, I did not see any harm in checking for posterity since it was a matter of just copying and pasting the above tests and calling reverse() once
  testSeven.reverse();
  cout << endl << "TEST 7 ROUND 4" << endl << endl;
  testSeven.printer();
  testSeven.clear();
  testSeven.printer();
  cout << endl;

  //test on clearing the list with one element
  cout << endl << "TEST 7 ROUND 5" << endl << endl;
  testSeven.append(0);
  testSeven.printer();
  testSeven.clear();
  testSeven.printer();

  //test on clearing the list with multiple elements
  cout << endl << "TEST 7 ROUND 6" << endl << endl;
  testSeven.append(0);
  testSeven.append(1);
  testSeven.append(2);
  testSeven.append(3);
  testSeven.append(4);
  testSeven.append(5);
  testSeven.append(6);
  testSeven.append(7);
  testSeven.append(8);
  testSeven.append(9);
  testSeven.printer();
  testSeven.clear();
  testSeven.printer();
}
