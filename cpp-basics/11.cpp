#include <stdio.h>
#include <stdlib.h>

const unsigned int FLAG0 = 1; //00000000000000000000000000000001
const unsigned int FLAG1 = 2; //00000000000000000000000000000010
const unsigned int FLAG2 = 4; //00000000000000000000000000000100
const unsigned int FLAG3 = 8; //00000000000000000000000000001000

typedef int pointCount;
//typedef float real;
//typedef float imaginary;

struct COMPLEX {
	float real;
	float imaginary;
};

typedef struct COMPLEX complex;

int length(char *string)
{
	int counter = 0;
	while(*string != 0)
	{
		counter++;
		string++;
	}
	return counter;
}

int indexOf(char *string, char target)
{
	int position = 0;
	while(*string != 0)
	{
		if(*string == target)
		{
			break;
		}
		string++;
		position++;
	}
	if(*string == 0)
	{
		return -1;
	}
	else
	{
		return position;
	}
}

int numberOf(char *string, char target)
{
	int counter = 0;
	while(*string != 0)
	{
		if(*string == target)
		{
			counter++;
		}
		string++;
	}
	return counter;
}

void copyString(char *original, char *copy)
{
	int index = 0;
	while(original[index] != 0)
	{
		copy[index] = original[index];
		index++;
	}
	copy[index] = 0;
}

char ** parseString(char *string, int *nTokens)
{
	int nSpaces;
	int sLength;
	char **pieces;
	int i, index;
	char *copyOfOriginal;

	nSpaces = numberOf(string, ' ');
	sLength = length(string);
	pieces = (char **)malloc(sizeof(char *) * (nSpaces + 1));
	copyOfOriginal = (char *)malloc(sizeof(char) * (sLength));
	copyString(string, copyOfOriginal);
	printf("\nThe number of spaces is %i.\n", nSpaces);
	printf("\nThe length of the string is %i.\n", sLength);
	index = 0;
	pieces[index++] = copyOfOriginal; // Changed
	printf("Past the first assignment.\n");

	for(i = 0; i < sLength; i++)
	{
		if(copyOfOriginal[i] == ' ')
		{
			copyOfOriginal[i] = 0;
			pieces[index++] = &copyOfOriginal[i + 1]; // Changed
		}
	}
	/*
	for(i = 0; i < nSpaces + 1; i++)
	{
		printf("Word at position %i is %s.\n", i, pieces[i]); // Changed
	}
	*/

	*nTokens = nSpaces + 1;

	return pieces;
	
}

/**
 * Assumes string points to a 33 character buffer
 */
void binaryToString(char *string, unsigned int number)
{
	int i;
	const unsigned int TESTFLAG = 1; //00000000000000000000000000000001

	for(i = 31; i >= 0; i--)
	{
		if(TESTFLAG & number) {
			string[i] = '1';
		}
		else {
			string[i] = '0';
		}
		number = number >> 1;
	}
	string[32] = 0;
}

/**
 * Assumes string points to a 33 character buffer
 * that contains only 0 and 1 characters
 */
unsigned int stringToBinary(char *string)
{
	unsigned int number = 0, power = 1;
	int i;
	const unsigned int TESTFLAG = 1; //00000000000000000000000000000001

	for(i = 31; i >= 0; i--)
	{
		if(string[i] == '1')
		{
			number += power;
		}
		power <<= 1;
	}
	return number;
}

/*
void addComplexNumbers(real *real1, imaginary *imaginary1, real *real2, imaginary *imaginary2)
{
	*real1 += *real2;
	*imaginary1 += *imaginary2;
}
*/

complex addComplexNumbers(complex number1, complex number2)
{
	complex result;
	result.real = number1.real + number2.real;
	result.imaginary = number1.imaginary + number2.imaginary;
	return result;
}

void addComplexNumber(complex *number1, complex *number2)
{
	number1->real += number2->real;
	number1->imaginary += number2->imaginary;
}

complex multiplyComplexNumbers(complex number1, complex number2)
{
	complex result;
	result.real = number1.real * number2.real - number1.imaginary * number2.imaginary;
	result.imaginary = number1.real * number2.imaginary + number1.imaginary * number2.real;
	return result;
}

complex complementComplexNumber(complex number)
{
	complex result;
	result.real = number.real * -1;
	result.imaginary = number.imaginary * -1;
	return result;
}

/*int main()
{
	unsigned int flags = FLAG0 | FLAG1 | FLAG2 | FLAG3;
	char aString[] = {"00000010000000100000000000001000"};
	//unsigned int result = 0;

	complex number1;
	complex number2;
	complex result;

	number1.real = 4.0;
	number1.imaginary = 8.0;
	number2.real = 3.0;
	number2.imaginary = 4.3;
	result = addComplexNumbers(number1, number2);

	printf("The first complex number is %f + i%f.\n", number1.real, number1.imaginary);
	printf("The second complex nubmer is %f + i%f.\n", number2.real, number2.imaginary);
	//addComplexNumbers(&number1.real, &number1.imaginary, &number2.real, &number2.imaginary);
	printf("The sum of the  complex numbers is %f + i%f.\n", result.real, result.imaginary);
}*/