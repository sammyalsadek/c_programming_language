#include <stdio.h>

#define MAX_LINE_LENGTH 1000

int get_line(char line[], int max_line_length);
void copy_line(char to[], char from[]);

int main()
{
	int current_line_length = 0;
	int longest_line_length = 0;
	char current_line[MAX_LINE_LENGTH];
	char longest_line[MAX_LINE_LENGTH];

	while((current_line_length = get_line(current_line, MAX_LINE_LENGTH)) > 0)
	{
		if (current_line_length > longest_line_length)
		{
			longest_line_length = current_line_length;
			copy_line(longest_line, current_line);
		}
	}

	printf("Longest line length = %d\n", longest_line_length);
	printf("Line = \"%s\"\n", longest_line);

	return 0;
}

int get_line(char line[], int max_line_length)
{
	int line_length = 0;
	char character;

	while((character = getchar()) != '\n')
	{
		line[line_length] = character;
		line_length++;
	}

	line[line_length] = '\0';
	return line_length;
}

void copy_line(char to[], char from[])
{
	for(int i=0; (to[i] = from[i]) != '\0'; i++);
}
