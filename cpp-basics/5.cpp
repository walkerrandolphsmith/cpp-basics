#include <stdio.h>
#include <stdlib.h>


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

/*int main()
{
	char myString[] = {"This is a test string."};

	printf("\nThe string is '%s'\n\n", myString);

	printf("\nThe number of characters in the string is %i.\n", length(myString));

	printf("\nThe first position of 't' in the string is %i.\n", indexOf(myString, 't'));

	printf("\nThe number of 'e' character in the string is %i. \n", numberOf(myString, 'e'));
	printf("\nThe number of 't' character in the string is %i. \n", numberOf(myString, 't'));
	printf("\nThe number of 'z' character in the string is %i. \n", numberOf(myString, 'z'));
}*/