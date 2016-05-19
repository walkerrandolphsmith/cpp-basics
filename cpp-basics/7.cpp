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

int parseString(char *string)
{
	int nSpaces;
	int sLength;
	char **pieces;
	int i, index;

	nSpaces = numberOf(string, ' ');
	sLength = length(string);
	pieces = (char **)malloc(sizeof(char *) * (nSpaces + 1));
	printf("\nThe number of spaces is %i.\n", nSpaces);
	printf("\nThe length of the string is %i.\n", sLength);
	index = 0;
	*pieces[index++] = string[0];
	printf("Past the first assignment.\n");

	for(i = 0; i < sLength; i++)
	{
		printf("Working on %i.\n", i);
		if(string[i] == ' ')
		{
			string[i] = 0;
			*pieces[index++] = string[i + 1];
		}
	}
	for(i = 0; i < nSpaces + 1; i++)
	{
		printf("Word at position %i is %s.\n", i, *pieces[i]);
	}

	return 0;
	
}

/*int main()
{
	char ** tokens;
	char myString[] = {"This is a test string."};
	char otherString[] = {"Mary had a little lamb and it was white as snow."};

	parseString(myString);
	parseString(otherString);

}*/