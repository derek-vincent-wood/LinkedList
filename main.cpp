#include "LinkedList.h"
#include "testCase.h"
int main(int argc, char *argv[] )
{
  void (*testCases[5])(); //create an array of function pointers
  testCases[0] = testCaseOne;
  testCases[1] = testCaseTwo;
  testCases[2] = testCaseThree;
  testCases[3] = testCaseFour;
  testCases[4] = testCaseFive;
  if (argc <= 1) //
  { cout << "Hello!" <<endl;
    cout << "This program is meant to act as the driver for the test cases for the Doubly Linked List implementation that I am working on." << endl;
    cout << "By specifying a number or two numbers to choose one or a range of test cases in the command line, you can selectively run the test cases found in the testCase files." << endl;
    cout << "Entering only one number will just run that specific test case (providing that it exists), while entering two numbers will run all test cases in that range (ranges are inclusive)" << endl;
    cout << "For example:" <<endl;
    cout << "'./LinkedListTest.exe 1' will run the test case found in testCase1.cpp" << endl;
    cout << "'./LinkedListTest.exe 2 4' will run the test cases found in testCase2.cpp, testCase3.cpp, and testCase4.cpp" << endl;
  }
  if (argc == 2) //if the number of supplied arguments is one
  {
    for(int i = 0; argv[1][i]!='\0'; i++) //check if the input is a valid number by checking each character in the supplied argument to see if it is a digit
    {
      if (!isdigit(argv[1][i]))
      {
        cout << "ERROR: The provided argument must be an integer number!" << endl;
        return 0;
      }
    }
    int selection = atoi(argv[1]);
    if (selection < 1 || selection > 5)
    {
      cout << "Invalid test case parameter: " << selection << " is not a valid test case." << endl;
      return 0;
    }
    //if it is a valid number, call the appropriate test case
    testCases[atoi(argv[1])-1]();

  }


  return 0;
}
