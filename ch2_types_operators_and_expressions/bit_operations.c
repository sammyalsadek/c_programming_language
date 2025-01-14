/* this program will contain a list of programs a user can select to
 * perform a specific bit operation on a number value.
 */
#include <stdio.h>

#define BYTE_TO_BIT_CONVERSION_RATE 8

typedef enum menu_option {SET_BITS, INVERT, RIGHT_ROTATE, BIT_COUNT} menu_option;

void itob(unsigned short int number, char binary_number[]);
void set_bits(unsigned short int *number, unsigned short int position_1, unsigned short int number_of_bits, unsigned short int position_2);
void invert(unsigned short int *number, unsigned short int position, unsigned short int number_of_bits);
void right_rotate(unsigned short int *number, unsigned short int number_of_bits);
unsigned short int bit_count(unsigned short int number);

int main()
{
	menu_option option;
	unsigned short int number;
	char binary_number[(sizeof(number) * BYTE_TO_BIT_CONVERSION_RATE) + 1];

	printf("Menu:\n");
	printf("\t0 - Set bits\n");
	printf("\t1 - Invert\n");
	printf("\t2 - Right rotate\n");
	printf("\t3 - Bit count\n");

	printf("\nEnter option: ");
	scanf("%d", &option);

	printf("\nEnter number to operate on: ");
	scanf("%hd", &number);

	itob(number, binary_number);
	printf("%s\n", binary_number);

	switch(option)
	{
		case SET_BITS:
			{
				unsigned short int position_1;
				unsigned short int position_2;
				unsigned short int number_of_bits;

				printf("\nEnter the first position: ");
				scanf("%hd", &position_1);
				printf("\nEnter the second position: ");
				scanf("%hd", &position_2);
				printf("\nEnter the number of bits to alter: ");
				scanf("%hd", &number_of_bits);

				set_bits(&number, position_1, number_of_bits, position_2);
				break;
			}
		case INVERT:
			{
				unsigned short int position;
				unsigned short int number_of_bits;

				printf("\nEnter the position: ");
				scanf("%hd", &position);
				printf("\nEnter the number of bits to alter: ");
				scanf("%hd", &number_of_bits);

				invert(&number, position, number_of_bits);
				break;
			}
		case RIGHT_ROTATE:
			{
				unsigned short int number_of_bits;

				printf("\nEnter the number of bits to rotate: ");
				scanf("%hd", &number_of_bits);

				right_rotate(&number, number_of_bits);
				break;
			}
		case BIT_COUNT:
			{
				unsigned short int number_of_bits = bit_count(number);
				printf("Number of bits = %d\n", number_of_bits);
				break;
			}
	}

	itob(number, binary_number);
	printf("%s\n", binary_number);
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

void set_bits(unsigned short int *number, unsigned short int position_1, unsigned short int number_of_bits, unsigned short int position_2)
{
	if(position_1 == position_2) return;

	unsigned short int position_1_region_mask = (~0 << ((sizeof(*number) * BYTE_TO_BIT_CONVERSION_RATE) - number_of_bits));
	position_1_region_mask >>= position_1;

	unsigned short int position_2_region_mask = (~0 << ((sizeof(*number) * BYTE_TO_BIT_CONVERSION_RATE) - number_of_bits));
	position_2_region_mask >>= position_2;
	unsigned short int position_2_region_shifted = *number & position_2_region_mask;
	if(position_1 > position_2)
		position_2_region_shifted >>= position_1 - position_2;
	else
		position_2_region_shifted <<= position_2 - position_1;

	*number = (*number & ~position_1_region_mask) ^ position_2_region_shifted;
}

void invert(unsigned short int *number, unsigned short int position, unsigned short int number_of_bits)
{
	unsigned short int mask = (~0 << ((sizeof(*number) * BYTE_TO_BIT_CONVERSION_RATE) - number_of_bits));
	mask >>= position;
	unsigned short int flipped_region = (~*number & mask);
	unsigned short int unaltered_region = (*number & ~mask);
	*number = flipped_region ^ unaltered_region;
}

void right_rotate(unsigned short int *number, unsigned short int number_of_bits)
{
	number_of_bits %= sizeof(*number) * BYTE_TO_BIT_CONVERSION_RATE;
	*number = (*number << ((sizeof(*number) * BYTE_TO_BIT_CONVERSION_RATE) - number_of_bits)) ^ (*number >> number_of_bits);
}

unsigned short int bit_count(unsigned short int number)
{
	unsigned short int bit_count;
	for(bit_count = 0; number != 0; number &= number - 1, bit_count++);
	return bit_count;
}
