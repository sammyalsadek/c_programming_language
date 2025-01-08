#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 1000
#define HEX_BASE 16

long int htoi(char hex_string[]);
unsigned short int get_string_length(const char *string);
unsigned short int is_valid_hex(const char *string);
void to_lower(char string[]);
short int ctoi(char character);

int main()
{
	char temp[MAX_STRING_LENGTH];

	strcpy(temp, "0XFA90");
	printf("%ld\n", htoi(temp));

	strcpy(temp, "0xfa90");
	printf("%ld\n", htoi(temp));

	strcpy(temp, "FA90");
	printf("%ld\n", htoi(temp));

	strcpy(temp, "fa90");
	printf("%ld\n", htoi(temp));

	strcpy(temp, "wa90");
	printf("%ld\n", htoi(temp));

	strcpy(temp, "");
	printf("%ld\n", htoi(temp));

	return 0;
}

long int htoi(char hex_string[])
{
	to_lower(hex_string);

	long int value = 0;
	unsigned short int string_length = get_string_length(hex_string);

	if(!string_length) return -1;
	if(string_length >= 2 &&
			hex_string[0] == '0' &&
			hex_string[1] == 'x'
	  )
		hex_string[1] = '0';
	if(!is_valid_hex(hex_string)) return -1;

	for(short int i = string_length - 1, j = 0; i >= 0; i--, j++)
	{
		value += ctoi(hex_string[i]) * (long int)pow(HEX_BASE, j);
	}

	return value;
}

unsigned short int get_string_length(const char *string)
{
	unsigned short int string_length = 0;
	while(string[string_length] != '\0') string_length++;
	return string_length;
}

unsigned short int is_valid_hex(const char *string)
{
	for(unsigned short int i = 0; string[i] != '\0'; i++)
		if(!((string[i] >= '0' && string[i] <= '9') ||
					(string[i] >= 'a' && string[i] <= 'f')))
			return 0;
	return 1;
}

void to_lower(char string[])
{
	for(unsigned short int i = 0; string[i] != '\0'; i++)
	{
		if(string[i] >= 'A' && string[i] <= 'Z') string[i] += 'a' - 'A';
	}
}

short int ctoi(char character)
{
	if(character >= '0' && character <= '9') return (short int) character - '0';
	if(character >= 'a' && character <= 'f') return (short int) character - 'a' + 10;
	return -1;
}
