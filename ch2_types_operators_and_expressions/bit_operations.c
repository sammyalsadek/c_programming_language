/* this program will contain a list of programs a user can select to
 * perform a specific bit operation on a number value.
 */
#include <stdio.h>

#define BYTE_TO_BIT_CONVERSION_RATE 8

typedef enum menu_option {SET_BITS, INVERT, RIGHT_ROTATE, TWOS_COMPLEMENT} menu_option;

void itob(unsigned short int number, char binary_number[]);

int main()
{
	menu_option option;
	unsigned short int number;
	char binary_number[(sizeof(number) * BYTE_TO_BIT_CONVERSION_RATE) + 1];

	printf("Menu:\n");
	printf("\t0 - Set bits\n");
	printf("\t1 - Invert\n");
	printf("\t2 - Right Rotate\n");
	printf("\t3 - Two's complement\n");

	printf("\nEnter option: ");
	scanf("%d", &option);

	printf("\nEnter number to operate on: ");
	scanf("%hd", &number);
	itob(number, binary_number);
	printf("%s\n", binary_number);

	switch(option)
	{
		case SET_BITS:
			break;
		case INVERT:
			break;
		case RIGHT_ROTATE:
			break;
		case TWOS_COMPLEMENT:
			break;
	}
}

void itob(unsigned short int number, char binary_number[])
{
	unsigned short int number_of_bits = sizeof(number) * BYTE_TO_BIT_CONVERSION_RATE;
	binary_number[number_of_bits] = '\0';

	for(short int i = number_of_bits - 1; i >= 0; i--, number>>=1)
	{
		binary_number[i] = number & 01 ? '1' : '0';
	}
}
