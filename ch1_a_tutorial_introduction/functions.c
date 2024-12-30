#include <stdio.h>

#define UPPER_TEMP 300
#define LOWER_TEMP 0
#define STEP 20

float convert_fahr_to_cels(float fahr);

int main()
{
	printf("fahr\tcels\n");
	printf("----\t----\n");
	for(float fahr=LOWER_TEMP; fahr<UPPER_TEMP; fahr+=STEP)
	{
		printf("%4.1f\t%4.1f\n", fahr, convert_fahr_to_cels(fahr));
	}
	return 0;
}

float convert_fahr_to_cels(float fahr)
{
	return (5.0/9.0)*(fahr-32);
}
