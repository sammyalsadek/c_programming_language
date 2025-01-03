#include <stdio.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000
#define LONG_LINE_LENGTH 15

int get_line(void);
void copy_line(char to[], char from[]);
void remove_trailing_whitespaces(void);
void reverse_string(void);

int current_line_length;
int longest_line_length;
int long_lines_count;
char current_line[MAX_LINE_LENGTH];
char longest_line[MAX_LINE_LENGTH];
char long_lines[MAX_LINES][MAX_LINE_LENGTH];

int main()
{
	/* 
	 * extern is not necessarily needed since the declaration is is the
	 * same file at the top
	 */
	extern int longest_line_length;
	extern int long_lines_count;

	longest_line_length = 0;
	long_lines_count = 0;

	while(get_line() > 0)
	{
		remove_trailing_whitespaces();
		reverse_string();
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

int get_line()
{
	current_line_length = 0;
	char character;

	while((character = getchar()) != '\n')
	{
		current_line[current_line_length] = character;
		current_line_length++;
	}

	current_line[current_line_length] = '\0';
	return current_line_length;
}

void copy_line(char to[], char from[])
{
	for(int i=0; (to[i] = from[i]) != '\0'; i++);
}

void remove_trailing_whitespaces()
{
	for(int i = (current_line_length - 1); i >= 0 && (current_line[i] == ' ' || current_line[i] == '\t'); i--)
	{
		current_line[i] = '\0';
		current_line_length--;
	}
}

void reverse_string()
{
	char temp;
	for(int i=0, j=current_line_length-1; i<j; i++, j--)
	{
		temp = current_line[i];
		current_line[i] = current_line[j];
		current_line[j] = temp;
	}
}
