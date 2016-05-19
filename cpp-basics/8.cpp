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
	char ** tokens = NULL; // Changed
	int nTokens, i;
	char myString[] = {"This is a test string."};
	char otherString[] = {"Mary had a little lamb and it was white as snow."};

	tokens = parseString(myString, &nTokens);
	printf("The number of tokens is %i. \n", nTokens);
	for(i = 0; i < nTokens; i++)
	{
		printf("The token %i is '%s'.\n", i, tokens[i]);
	}
	printf("The original string is %s.\n", myString);

	printf("\n\n");
	tokens = parseString(otherString, &nTokens);
	printf("The number of tokens is %i. \n", nTokens);
	for(i = 0; i < nTokens; i++)
	{
		printf("The token %i is '%s'.\n", i, tokens[i]);
	}

	printf("The original string is %s.\n", otherString);

}*/