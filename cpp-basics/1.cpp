#include <stdio.h>
#include <iostream>
using namespace std;

int multiplyByTwo(int theNumber)
{
	return theNumber * 2;
}

void multiplyByTwoRef(int *theNumber)
{
	*theNumber = *theNumber * 2;
}

/*int main()
{
	int enteredNumber = 2;
	int otherNumber = 5;
	printf("\nEntered Number before function is %i.\n", enteredNumber);
	enteredNumber = multiplyByTwo(enteredNumber);
	printf("\nOther number before function is %i.\n", otherNumber);
	multiplyByTwoRef(&otherNumber);

	printf("\nEntered Number after function is %i\n The multiplied number is %i.\n", enteredNumber, enteredNumber);
	printf("\nOther Number after function is %i\n The multiplied number is %i.\n", otherNumber, otherNumber);

	
	int age; 
	cin >> age;
	return 0;
}*/