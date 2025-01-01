#include <stdio.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000
#define LONG_LINE_LENGTH 15

int get_line(char line[], int max_line_length);
void copy_line(char to[], char from[]);
void remove_trailing_whitespaces(char line[], int *line_length);
void reverse_string(char line[], int line_length);

int main()
{
	int current_line_length = 0;
	int longest_line_length = 0;
	int long_lines_count = 0;
	char current_line[MAX_LINE_LENGTH];
	char longest_line[MAX_LINE_LENGTH];
	char long_lines[MAX_LINES][MAX_LINE_LENGTH];

	while((current_line_length = get_line(current_line, MAX_LINE_LENGTH)) > 0)
	{
		remove_trailing_whitespaces(current_line, &current_line_length);
		reverse_string(current_line, current_line_length);
		if (current_line_length >= LONG_LINE_LENGTH) copy_line(long_lines[long_lines_count++], current_line);
		if (current_line_length > longest_line_length)
		{
			longest_line_length = current_line_length;
			copy_line(longest_line, current_line);
		}
	}

	printf("Longest line length = %d\n", longest_line_length);
	printf("Line = \"%s\"\n", longest_line);
	printf("Lines longer than %d characters:\n", LONG_LINE_LENGTH);
	for (int i = 0; i < long_lines_count; i++)
	{
		printf("\t=\"%s\"\n", long_lines[i]);
	}

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

void remove_trailing_whitespaces(char line[], int *line_length)
{
	for(int i = (*line_length - 1); i >= 0 && (line[i] == ' ' || line[i] == '\t'); i--)
	{
		line[i] = '\0';
		(*line_length)--;
	}
}

void reverse_string(char line[], int line_length)
{
	char temp;
	for(int i=0, j=line_length-1; i<j; i++, j--)
	{
		temp = line[i];
		line[i] = line[j];
		line[j] = temp;
	}
}
