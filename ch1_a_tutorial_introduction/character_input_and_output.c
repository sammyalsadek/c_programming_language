#include <stdio.h>

#define OUTSIDE_WORD 0
#define INSIDE_WORD 1

int main()
{
	/*
	 * count the number of character read. newlines are counted as a
	 * seperate character.
	 */
	double count;
	for(count = 0; getchar() != 'q'; count++);
	printf("%.0f\n", count);

	/*
	 * count the number of lines. this simply counts the number of newline
	 * characters read and input.
	 */
	double line_count;
	char character;
	for(line_count = 0; (character = getchar()) != 'q'; (character == '\n') && ++line_count);
	printf("%.0f\n", line_count);

	/*
	 * program that counts blanks, tabs, and newlines
	 */
	double btn_count;
	for(btn_count = 0; (character = getchar()) != 'q'; (character == '\n' || character == ' ' || character == '\t') && ++btn_count);
	printf("%.0f\n", btn_count);

	/*
	 * program that coverts all consecutive ' 's with a single blank
	 */
	int c;
	char was_blank = 0;
	while((c = getchar()) != 'q')
	{
		if (c == ' ')
		{
			if(was_blank) continue;
			was_blank = 1;
		}
		else
		{
			was_blank = 0;
		}
		putchar(c);
	}
	printf("\n");

	/*
	 * program that counts the number of words and outputs the words in the
	 * format of one word per line.
	 */
	int word_count;
	char state=OUTSIDE_WORD;
	for(word_count=0; (c=getchar()) != 'q';)
	{
		if(c == ' ' || c == '\n' || c == '\t')
		{
			if(state == INSIDE_WORD)
				putchar('\n');
			state=OUTSIDE_WORD;
		}
		else if(state == OUTSIDE_WORD)
		{
			state=INSIDE_WORD;
			word_count++;
			putchar(c);
		}
		else
			putchar(c);
	}
	printf("%d\n", word_count);

	/*
	 * program that takes inputs such and backspace and tabs and replaces
	 * them with a text version such and \b and \t.
	 */
	while((c = getchar()) != 'q')
	{
		if (c == '\b')
		{
			printf("\\b");
		}
		else if (c == '\t')
		{
			printf("\\t");
		}
		else
		{
			putchar(c);
		}
	}
	printf("\n");

	printf("%d\n", EOF);
	while((c = getchar()) != EOF)
	{
		putchar(c);
		printf("\n");
	}

	return 0;
}
