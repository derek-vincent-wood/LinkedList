#include "LinkedList.h"
#include "testCase.h"
bool isNum(char* stringArray); //forward declaration of isNum - a helper function for checking if a C-style string is an integer number or not
int main(int argc, char *argv[] )
{
  void (*testCases[6])(); //create an array of function pointers
  testCases[0] = testCaseOne;
  testCases[1] = testCaseTwo;
  testCases[2] = testCaseThree;
  testCases[3] = testCaseFour;
  testCases[4] = testCaseFive;
  testCases[5] = testCaseSix;
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
    if(!isNum(argv[1])) //if the single argument is not a number, print a warning and terminate the program
    {
      cout << "Invalid input. You must provide an integer number to use this program" << endl;
      return 0;
    }
    int selection = atoi(argv[1])-1; //convert the argument from a character array to an integer and subtract 1 to make it correspond to the testCases array
    if (selection+1 < 1 || selection+1 > 6) //check if the argument is a valid test case. If not, print a warning and terminate the program Note that the upper bound needs to be updated each time a new test case is added. This could be fixed by using a vector of function pointers rather than an array and caling .size(), however I am partial to keeping the overhead low
    {
      cout << "Invalid test case parameter: " << selection+1 << " is not a valid test case." << endl; //note that because of the -1 for calculationg the selection, +1 is needed to properly display the erroneous selection
      return 0;
    }
    //if it is a valid number, call the appropriate test case
    testCases[selection]();

  }
  if (argc == 3) //if the number of supplied arguments is three
  {
    if ( (!(isNum(argv[1]))) || (!(isNum(argv[2])))) //if either or both arguments are not integer numbers, print a warning and terminate the program
    {
      cout << "Invalid input. You must provide integer numbers to use this program" << endl;
      return 0;
    }
    int selectionOne =  atoi(argv[1])-1; //convert the first argument from a character array to an integer and subtract 1 to make it correspond to the testCases array
    int selectionTwo =  atoi(argv[2])-1; //convert the second argument from a character array to an integer and subtract 1 to make it correspond to the testCases array
    if (selectionOne+1 < 1 || selectionOne+1 > 6) //check if the first argument is a valid test case. If not, print a warning and terminate the program
    {
      cout << "Invalid test case parameter: " << selectionOne+1 << " is not a valid test case." << endl;
      return 0;
    }

    if (selectionTwo+1 < 1 || selectionTwo+1 > 6) //check if thesecond argument is a valid test case. If not, print a warning and terminate the program
    {
      cout << "Invalid test case parameter: " << selectionTwo+1 << " is not a valid test case." << endl;
      return 0;
    }

    if (selectionOne > selectionTwo) //if one of the arguments is greater than the other one, swap them using the standard library's swap function
      swap(selectionOne, selectionTwo);
    for (int i = selectionOne; i <= selectionTwo; i++)
    {
      testCases[i]();
    }
  }
  return 0;
}

bool isNum(char* charArray) //checks if a given c-style string is an integer number or not
{
  for(int i = 0; charArray[i]!='\0'; i++) //check if the input is a valid number by checking each character in the supplied argument to see if it is a digit. Returns true if it is, false if it is not
  {
    if (!isdigit(charArray[i]))
    {
      cout << "ERROR: The provided argument must be an integer number!" << endl;
      return false;
    }
  }
  return true;
}
