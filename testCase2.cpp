#include "LinkedList.h"
#include "testCase.h"
void testCaseTwo()
{
  //test on popping a non-reversed list until it is empty
  cout << endl << "TEST 2 ROUND 1" << endl << endl;
  DoublyLinkedList testTwo;
  testTwo.append(0);
  testTwo.append(1);
  testTwo.append(2);
  testTwo.append(3);
  testTwo.append(4);
  testTwo.append(5);
  testTwo.append(6);
  testTwo.append(7);
  testTwo.printer();
  for (int i = 0; i != 8; i++)
  {
    cout << to_string(testTwo.pop()) << ",";
  }
  cout << endl;
  //cout << to_string(testTwo.pop()) << ","; //uncomment to throw an error for popping from an empty list
  testTwo.printer();


  //test on popping a reversed list until it is empty
  cout << endl << "TEST 2 ROUND 2" << endl << endl;
  testTwo.append(0);
  testTwo.append(1);
  testTwo.append(2);
  testTwo.append(3);
  testTwo.append(4);
  testTwo.append(5);
  testTwo.append(6);
  testTwo.append(7);
  testTwo.reverse();
  testTwo.printer();
  for (int i = 0; i != 8; i++)
  {
    cout << to_string(testTwo.pop()) << ",";
  }
  cout << " dsad" << endl;
}
