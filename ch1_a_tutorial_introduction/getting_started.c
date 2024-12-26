#include <stdio.h>

main()
{
	printf("hello, world\n");

	printf("hello, ");
	printf("world");
	printf("\n");

	printf("hello, world");
	
	/* 
	 * since the following is not a real escape sequence, the program
	 * will just end up printing the character 'c'
	 */
	printf("hello, world\c");

	/* 
	 * the following will produce and error as a newline character
	 * must be added by the \n and not by an actual newline in the code
	 *
	 * printf("hello, world
	 * ");
	 */
}
