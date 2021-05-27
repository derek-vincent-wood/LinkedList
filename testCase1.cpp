#include "LinkedList.h"
#include "testCase.h"
void testCaseOne()
{
  DoublyLinkedList test;
	//initial round of tests for appending and printing - first round of appending appends in normal order, second round of appending appends in reversed order;
  cout << endl << "TEST 1 ROUND 1" << endl << endl;//first round
  test.printer();
  test.reverse();
  test.printer();
  test.reverse();

  test.append(0);
	test.printer();
  test.reverse();
  test.printer();
  test.reverse();

	test.append(1);
	test.printer();
  test.reverse();
  test.printer();
  test.reverse();

	test.append(2);
	test.printer();
  test.reverse();
  test.printer();
  test.reverse();

	test.append(3);
	test.printer();
  test.reverse();
  test.printer();
  test.reverse();

  test.append(4);
	test.printer();
  test.reverse();
  test.printer();
  test.reverse();

  cout << endl << "TEST 1 ROUND 2" << endl << endl;//second round
  test.reverse();
  test.append(-1);
  test.printer();
  test.reverse();
  test.printer();
  test.reverse();

  test.append(-2);
  test.printer();
  test.reverse();
  test.printer();
  test.reverse();

  test.append(-3);
  test.printer();
  test.reverse();
  test.printer();
  test.reverse();

  test.append(-4);
  test.printer();
  test.reverse();
  test.printer();
  test.reverse();

  test.append(-5);
  test.printer();
  test.reverse();
  test.printer();
  test.reverse();
}
