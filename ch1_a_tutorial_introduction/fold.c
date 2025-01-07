#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 20
#define MAX_LINE_LENGTH_TMP 10000

void get_lines(char lines[][MAX_LINE_LENGTH], unsigned short int *line_count);
void copy_substring(char destination[], char source[], unsigned short int start_index, unsigned short int end_index);

int main()
{
	unsigned short int line_count = 0;
	char lines[MAX_LINES][MAX_LINE_LENGTH];

	get_lines(lines, &line_count);

	for(int i=0; i<line_count; i++)
	{
		printf("%s\n", lines[i]);
	}

	return 0;
}

void get_lines(char lines[][MAX_LINE_LENGTH], unsigned short int *line_count)
{
	char input_character;
	char temp_line[MAX_LINE_LENGTH_TMP];
	unsigned short int temp_line_count = 0;
	unsigned short int start_index = 0;
	unsigned short int end_index = 0;

	while((input_character = getchar()) != '\n')
	{
		temp_line[temp_line_count++] = input_character;
	}
	temp_line[temp_line_count] = '\n';

	for(int i=0; i<temp_line_count; i++)
	{
		if(temp_line[i] == ' ' || temp_line[i] == '\t')
		{
			end_index = i;
		}

		if(((i-start_index)==(MAX_LINE_LENGTH-1)) && (end_index == start_index))
		{
			end_index = i;
			copy_substring(lines[(*line_count)++], temp_line, start_index, end_index);
			start_index = end_index;
		}
		else if(((i-start_index)==(MAX_LINE_LENGTH-1)) && (end_index != start_index))
		{
			copy_substring(lines[(*line_count)++], temp_line, start_index, end_index);
			start_index = end_index;
		}
	}

	if(temp_line_count != start_index)
	{
		copy_substring(lines[(*line_count)++], temp_line, start_index, temp_line_count);
	}
}

void copy_substring(char destination[], char source[], unsigned short int start_index, unsigned short int end_index)
{
	for(int i=0; i<(end_index-start_index); i++)
	{
		destination[i] = source[start_index+i];
	}
	destination[end_index-start_index] = '\0';
}
