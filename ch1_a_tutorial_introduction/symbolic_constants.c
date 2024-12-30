#include <stdio.h>

/*
 * constants are good practice to avoid using magic numbers in your code.
 * this helps with the readability of the program for future engineers that
 * need to understand the code.
 */
#define LOWER 0
#define UPPER 300
#define STEP 20

/*
 * you can technically have any list of characters
 */
#define OPEN_BRACKET {
	
int main()
OPEN_BRACKET
	for(int fahr = UPPER; fahr >= LOWER; fahr = fahr-STEP)
	OPEN_BRACKET
		printf("%6d%10.2f\n", fahr, (5.0/9.0)*(fahr-32));
	}
	
	return 0;
}
