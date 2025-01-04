#include <stdio.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 20

void get_lines(char lines[][MAX_LINE_LENGTH], unsigned short int *line_count);

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
	char temp_lines[];
	unsigned short int character_count = 0;
	unsigned short int last_blank_space_index = 0;
	unsigned short int not_in_space = 0;

	while((input_character = getchar()) != '\n')
	{
		if(character_count == MAX_LINE_LENGTH - 1)
		{
			lines[*line_count][character_count] = '\0';
			(*line_count)++;
			character_count = 0;
		}
		if(input_character == ' ' || input_character == '\t') && not_in_space)
		{
			last_blank_space_index = character_count;
			not_in_space = 1;
		}
		else
		{
			lines[*line_count][character_count++] = input_character;
		}
	}
	if(character_count > 0) (*line_count)++;
}
