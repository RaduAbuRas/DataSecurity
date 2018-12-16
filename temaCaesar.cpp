#include <stdio.h>
#include<stdlib.h>
#include <string.h>

void encode(char* initialText,char *resultText, int lenght, int offset)
{
	for (int i = 0; i < lenght; ++i)
	{
		if (initialText[i] >= 'a' && initialText[i] <= 'z')					//lower case
			resultText[i] = 'a' + (initialText[i] - 'a' + (char)offset) % 26;
		else if (initialText[i] >= 'A' && initialText[i] <= 'Z')			//upper case
			resultText[i] = 'A' + (initialText[i] - 'A' + (char)offset) % 26;
		else
			resultText[i] = initialText[i];									//numbers and simbols
	}
}

int main()
{
	char example[99];
	char encodedText[99];
	char decodedText[99];

	gets_s(example, sizeof(example));

	int length = strlen(example);

	encode(example, encodedText, length, 3);

	encodedText[length] = '\0';


	printf("%s\n", encodedText);

	encode(encodedText, decodedText,length, -3);

	decodedText[length] = '\0';

	printf("%s", decodedText);

	

	return 0;
}
