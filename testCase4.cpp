#include "LinkedList.h"
#include "testCase.h"
void testCaseFour()
{
  //test on setting node values in a non-reversed list
  cout << endl << "TEST 4 ROUND 1" << endl << endl;
  DoublyLinkedList testFour;
  //testFour.setVal(0, -5); //uncomment to throw an error for trying to set values from an empty list
  testFour.append(0);
  testFour.append(1);
  testFour.append(2);
  testFour.append(3);
  testFour.append(4);
  testFour.append(5);
  testFour.append(6);
  testFour.append(7);
  testFour.printer();
  for (int i = 0; i != 8; i++)
  {
    testFour.setVal(i, testFour.getVal(i)+i+1); //basically this test works by setting the values at each element to the sum of their current value, their position, and 1. The 1 is to make sure something is added to the element whose value is 0.
  }
  testFour.printer();

  //test on setting node values in a reversed list
  cout << endl << "TEST 4 ROUND 2" << endl << endl;
  testFour.reverse();
  testFour.printer();
  for (int i = 0; i != 8; i++)
  {
    testFour.setVal(i, testFour.getVal(i)+i+1); //Same structure as above. The first element should have a value of 15 to start, which should become 16.
  }
  testFour.printer();
}
