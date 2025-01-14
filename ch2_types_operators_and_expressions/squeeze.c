/* this program will remove all characters in string_1 that
 * that are found in string_2
 */

#include <stdio.h>

#define MAX_STRING_LENGTH 20

void squeeze(char string_1[], char string_2[]);
unsigned short int is_char_in_str(char character, char string[]);

int main()
{
	char string_1[MAX_STRING_LENGTH];
	char string_2[MAX_STRING_LENGTH];

	printf("Enter string: ");
	fgets(string_1, sizeof(string_1), stdin);

	printf("Enter string of character to remove: ");
	fgets(string_2, sizeof(string_2), stdin);

	squeeze(string_1, string_2);

	printf("Final string with characters removed: %s\n", string_1);
}

void squeeze(char string_1[], char string_2[])
{
	unsigned short int j = 0;
	short int first_match_index = -1;

	for(unsigned short int i = 0; string_1[i] != '\0'; i++)
	{
		if(!is_char_in_str(string_1[i], string_2))
		{
			string_1[j++] = string_1[i];
		}
		else if(first_match_index < 0) first_match_index = i;
	}
	string_1[j] = '\0';

	printf("First matched index: %d\n", first_match_index);
}

unsigned short int is_char_in_str(char character, char string[])
{
	for(unsigned short int i = 0; string[i] != '\0'; i++)
	{
		if(string[i] == character) return 1;
	}
	return 0;
}
