#include "LinkedList.h"
#include "testCase.h"
void testCaseSix()
{
  //test on deleting values in a non-reversed list - I delete values and replace them exactly to make sure that deletion is done properly and to avoid having to recreate the list every time or using several lists.
  cout << endl << "TEST 6 ROUND 1" << endl << endl;
  DoublyLinkedList testSix;
  testSix.append(0);
  testSix.append(1);
  testSix.append(2);
  testSix.append(3);
  testSix.append(4);
  testSix.printer();
  cout << endl;

  testSix.del(0);
  testSix.printer();
  testSix.insert(0,0);
  testSix.printer();
  cout << endl;

  testSix.del(1);
  testSix.printer();
  testSix.insert(1,1);
  testSix.printer();
  cout << endl;

  testSix.del(2);
  testSix.printer();
  testSix.insert(2,2);
  testSix.printer();
  cout << endl;

  testSix.del(3);
  testSix.printer();
  testSix.insert(3,3);
  testSix.printer();
  cout << endl;

  testSix.del(4);
  testSix.printer();
  testSix.insert(4,4);
  testSix.printer();
  cout << endl;

  //test on deleting values in a reversed list - I delete values and replace them exactly to make sure that deletion is done properly and to avoid having to recreate the list every time or using several lists.
  cout << endl << "TEST 6 ROUND 2" << endl << endl;
  testSix.reverse();
  testSix.printer();
  cout << endl;

  testSix.del(0);
  testSix.printer();
  testSix.insert(0,4);
  testSix.printer();
  cout << endl;

  testSix.del(1);
  testSix.printer();
  testSix.insert(1,3);
  testSix.printer();
  cout << endl;

  testSix.del(2);
  testSix.printer();
  testSix.insert(2,2);
  testSix.printer();
  cout << endl;

  testSix.del(3);
  testSix.printer();
  testSix.insert(3,1);
  testSix.printer();
  cout << endl;

  testSix.del(4);
  testSix.printer();
  testSix.insert(4,0);
  testSix.printer();
  cout << endl;
}
