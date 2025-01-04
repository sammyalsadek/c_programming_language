#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define TAB_STOP_LENGTH 4

void get_line(char line[], unsigned short int *line_length);
void entab(char line[], unsigned short int *line_length);

int main()
{
	unsigned short int line_length;
	char line[MAX_LINE_LENGTH];

	get_line(line, &line_length);
	entab(line, &line_length);
	printf("entabbed line = \"%s\"\n", line);
	printf("line length = %d\n", line_length);

	return 0;
}

void get_line(char line[], unsigned short int *line_length)
{
	for(char input_character; (input_character = getchar()) != '\n'; line[(*line_length)++] = input_character);
}

void entab(char line[], unsigned short int *line_length)
{
	unsigned short int concurrent_space_count = 0;
	unsigned short int new_line_length = 0;
	char new_line[MAX_LINE_LENGTH];

	for(unsigned short int i=0; i<(*line_length); i++)
	{
		if(line[i] != ' ')
		{
			for(unsigned char j=0; j<concurrent_space_count; j++, new_line_length++)
				new_line[new_line_length] = ' ';
			concurrent_space_count = 0;
			new_line[new_line_length++] = line[i];
			continue;
		}
		if(++concurrent_space_count==TAB_STOP_LENGTH)
		{
			new_line[new_line_length++] = '\t';
			concurrent_space_count = 0;
		}
	}

	for(unsigned char j=0; j<concurrent_space_count; j++, new_line_length++)
		new_line[new_line_length] = ' ';

	strcpy(line, new_line);
	*line_length = new_line_length;
}
