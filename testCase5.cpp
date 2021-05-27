#include "LinkedList.h"
#include "testCase.h"
void testCaseFive()
{
  //test on inserting node values in a non-reversed list
  cout << endl << "TEST 5 ROUND 1" << endl << endl;
  DoublyLinkedList testFive;
  testFive.append(0);
  testFive.append(1);
  testFive.append(2);
  testFive.append(3);
  testFive.printer(); //outputs [0,1,2,3] | 4 - to make testing easier, uncomment one of the following statements and comment the rest to see how the list should transform
  testFive.insert(0,300);// - list becomes [300,0,1,2,3] | 5
  //testFive.insert(1,300);// - list becomes [0,300,1,2,3] | 5
  //testFive.insert(2,300);// - list becomes [0,1,300,2,3] | 5
  //testFive.insert(3,300);// - list becomes [0,1,2,300,3] | 5
  //testFive.insert(4,300);// - list becomes [0,1,2,3,300] | 5
  testFive.printer();

  //test on inserting node values in a reversed list
  cout << endl << "TEST 5 ROUND 2" << endl << endl;
  DoublyLinkedList testFiveReversed; //I wrote this test case before developing the clear function. If I had written that sooner, I would have just cleared the list and reinserted the values (I wanted to make sure I wouldn't crash the program if I forgot to (un)comment out one of the lines above)
  testFiveReversed.append(0);
  testFiveReversed.append(1);
  testFiveReversed.append(2);
  testFiveReversed.append(3);
  testFiveReversed.reverse();
  testFiveReversed.printer(); //outputs [3,2,1,0] | 4 - to make testing easier, uncomment one of the following statements and comment the rest to see how the list should transform
  //testFiveReversed.insert(0,400);// - list becomes [400,3,2,1,0] | 5
  //testFiveReversed.insert(1,400);// - list becomes [3,400,2,1,0] | 5
  //testFiveReversed.insert(2,400);// - list becomes [3,2,400,1,0] | 5
  //testFiveReversed.insert(3,400);// - list becomes [3,2,1,400,0] | 5
  //testFiveReversed.insert(4,400);// - list becomes [3,2,1,0, 400] | 5
  testFiveReversed.printer();

  //test on inserting node values on invalid locations and inserting into an empty list. Also performed on a reversed list
  cout << endl << "TEST 5 ROUND 3" << endl << endl;
  DoublyLinkedList testFiveEmpty;
  //testFiveEmpty.insert(-1, 500); //uncomment to throw an error
  //testFiveEmpty.insert(1, 500); //uncomment to throw an error
  testFiveEmpty.insert(0, 500);
  testFiveEmpty.printer();
  //testFiveEmpty.insert(-1, 500); //uncomment to throw an error
  //testFiveEmpty.insert(2, 500); //uncomment to throw an error

  cout << endl << "TEST 5 ROUND 4" << endl << endl;
  DoublyLinkedList testFiveEmptyReversed;
  testFiveEmptyReversed.reverse();
  //testFiveEmptyReversed.insert(-1, 500); //uncomment to throw an error
  //testFiveEmptyReversed.insert(1, 500); //uncomment to throw an error
  testFiveEmptyReversed.insert(0, 500);
  testFiveEmptyReversed.printer();
  //testFiveEmptyReversed.insert(-1, 500); //uncomment to throw an error
  //testFiveEmptyReversed.insert(2, 500); //uncomment to throw an error
}
