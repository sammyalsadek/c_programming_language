#include <stdio.h>

int main()
{
	printf("char\tbits:%6lu\tbytes:%6lu\n",sizeof(char)*8, sizeof(char));
	printf("uchar\tbits:%6lu\tbytes:%6lu\n",sizeof(unsigned char)*8, sizeof(unsigned char));

	printf("short\tbits:%6lu\tbytes:%6lu\n",sizeof(short)*8, sizeof(short));
	printf("ushort\tbits:%6lu\tbytes:%6lu\n",sizeof(unsigned short)*8, sizeof(unsigned short));

	printf("int\tbits:%6lu\tbytes:%6lu\n",sizeof(int)*8, sizeof(int));
	printf("uint\tbits:%6lu\tbytes:%6lu\n",sizeof(unsigned int)*8, sizeof(unsigned int));

	printf("long\tbits:%6lu\tbytes:%6lu\n",sizeof(long)*8, sizeof(long));
	printf("ulong\tbits:%6lu\tbytes:%6lu\n",sizeof(unsigned long)*8, sizeof(unsigned long));

	printf("llong\tbits:%6lu\tbytes:%6lu\n",sizeof(long long)*8, sizeof(long long));
	printf("ullong\tbits:%6lu\tbytes:%6lu\n",sizeof(unsigned long long)*8, sizeof(unsigned long long));

	printf("float\tbits:%6lu\tbytes:%6lu\n",sizeof(float)*8, sizeof(float));

	printf("double\tbits:%6lu\tbytes:%6lu\n",sizeof(double)*8, sizeof(double));
	printf("ldouble\tbits:%6lu\tbytes:%6lu\n",sizeof(long double)*8, sizeof(long double));

	return 0;
}
