#include <stdio.h>

#define ARRAY_SIZE 10
#define OUTSIDE_WORD 0
#define INSIDE_WORD 1

int main()
{
	int whitespace_count, other_count;
	int digit_count[ARRAY_SIZE];
	int word_lengths[ARRAY_SIZE];

	whitespace_count = other_count = 0;

	/* 
	 * initialize the array with 0's
	 */
	for (int i=0; i < ARRAY_SIZE; i++)
		digit_count[i] = 0;

	char input_character;
	int word_state = OUTSIDE_WORD;
	int word_count = -1;
	while ((input_character = getchar()) != 'q')
	{
		if (input_character == ' ' || input_character == '\t' || input_character == '\n')
		{
			word_state = OUTSIDE_WORD;
			whitespace_count++;
		}
		else if (input_character >= '0' && input_character <= '9')
		{
			if (word_state == OUTSIDE_WORD)
			{
				word_count++;
				word_lengths[word_count] = 1;
			}
			else
				word_lengths[word_count]++;
			word_state = INSIDE_WORD;
			digit_count[input_character - '0']++;
		}
		else
		{
			if (word_state == OUTSIDE_WORD)
			{
				word_count++;
				word_lengths[word_count] = 1;
			}
			else
				word_lengths[word_count]++;
			word_state = INSIDE_WORD;
			other_count++;
		}
	}

	printf("digit counts =");
	for (int i=0; i < ARRAY_SIZE; i++)
		printf(" %d", digit_count[i]);
	printf(", whitespace count = %d, other count = %d\n", whitespace_count, other_count);

	/*
	 * create a histogram with the number of occurences of characters and
	 * word lenghts
	 */
	printf("whitespace count\t");
	for (int i=0; i<whitespace_count; i++)
		putchar('o');
	putchar('\n');

	printf("other count\t\t");
	for (int i=0; i<other_count; i++)
		putchar('o');
	putchar('\n');

	for (int j=0; j<ARRAY_SIZE; j++)
	{
		printf("%d count\t\t\t", j);
		for (int i=0; i<digit_count[j]; i++)
			putchar('o');
		putchar('\n');
	}

	for (int j=0; j<=word_count; j++)
	{
		printf("%d word\t\t\t", j+1);
		for (int i=0; i<word_lengths[j]; i++)
			putchar('o');
		putchar('\n');
	}

	return 0;
}
