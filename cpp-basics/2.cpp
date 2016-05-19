#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
float average(int nElements, float *theArray)
{
	float sum = 0.0f;
	int i;
	for( i = 0; i < nElements; i++)
	{
		sum += *theArray;
		theArray++;
	}
	sum /= nElements;
	return sum;
}

/*
int main()
{
	int i;
	float numbers[20];
	float sum = 0.0f;

	for(i = 0; i < 20; i++)
	{
		numbers[i] = rand();
	}

	for(i = 0; i < 20; i++)
	{
		printf("\n numbers[%i] = %f", i, numbers[i]);
	}

	for(i = 0; i < 20; i++)
	{
		sum += numbers[i];
	}
	sum /= 20;

	printf("\n\nThe average in the array is %f", sum);

	sum = average(20, numbers);

	printf("\n\nThe average from the function is %f\n", sum);

	sum = average(30, &numbers[5]);

	printf("\n\nThe average of the 10 elements from the 6th to the 16th is %f.\n", sum);

	int age; 
	cin >> age;
	return 0;
}*/