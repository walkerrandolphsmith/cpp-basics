#include <stdio.h>
#include <stdlib.h>

const unsigned int FLAG0 = 1; //00000000000000000000000000000001
const unsigned int FLAG1 = 2; //00000000000000000000000000000010
const unsigned int FLAG2 = 4; //00000000000000000000000000000100
const unsigned int FLAG3 = 8; //00000000000000000000000000001000

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

/*int main()
{

	unsigned int flags = FLAG0 | FLAG1 | FLAG2 | FLAG3;

	if(flags & FLAG0)
	{
		printf("The FLAG0 is set\n");
	}
	else
	{
		printf("The FLAG0 is not set.\n");
	}

	if(flags & FLAG1)
	{
		printf("The FLAG1 is set\n");
	}
	else
	{
		printf("The FLAG1 is not set.\n");
	}

	if(flags & FLAG2)
	{
		printf("The FLAG2 is set\n");
	}
	else
	{
		printf("The FLAG2 is not set.\n");
	}

	if(flags & FLAG3)
	{
		printf("The FLAG3 is set\n");
	}
	else
	{
		printf("The FLAG3 is not set.\n");
	}

	flags = flags & ~FLAG1;

	printf("After reseting FLAG1.\n");

	if(flags & FLAG0)
	{
		printf("The FLAG0 is set\n");
	}
	else
	{
		printf("The FLAG0 is not set.\n");
	}

	if(flags & FLAG1)
	{
		printf("The FLAG1 is set\n");
	}
	else
	{
		printf("The FLAG1 is not set.\n");
	}

	if(flags & FLAG2)
	{
		printf("The FLAG2 is set\n");
	}
	else
	{
		printf("The FLAG2 is not set.\n");
	}

	if(flags & FLAG3)
	{
		printf("The FLAG3 is set\n");
	}
	else
	{
		printf("The FLAG3 is not set.\n");
	}

}*/