#include <stdio.h>

int main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("fahr\tcelc\n");
	printf("================================\n");

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}

	/*
	 * you can format the printed string by adding numbers for the width,
	 * which also right justifies the string
	 */
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr-32) / 9;
		printf("%3d%10d\n", fahr, celsius);
		fahr = fahr + step;
	}

	/*
	 * printf also support %o and %x, which correspond to print the octal
	 * and hexidecimal versions of the value
	 */
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr-32) / 9;
		printf("%3o%10x\n", fahr, celsius);
		fahr = fahr + step;
	}

	/*
	 * the following example uses float types which provide a more accurate
	 * calculation with decimal point values. the formatting used states
	 * that the width will be 3 and 6; however, the number after the '.'
	 * declares the number of decimal values the print.
	 */
	float fahr_f, celsius_f;
	float lower_f, upper_f, step_f;

	lower_f = 0.0;
	upper_f = 300.0;
	step_f = 20.0;

	fahr_f = lower_f;
	while (fahr_f <= upper_f)
	{
		celsius_f = (5.0/9.0) * (fahr_f-32.0);
		printf("%3.0f%10.1f\n", fahr_f, celsius_f);
		fahr_f = fahr_f + step_f;
	}

	return 0;

}
