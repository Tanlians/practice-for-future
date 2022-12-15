#include<stdio.h>
#define U 100
int main()
{
	int sum1 = 0, sum2 = 0;
	int i;
	for (i = 1; i <= U; i++)
	{
		int a = 0;
		a = i * i;
		sum1 += a;
	}
	for (i = 1; i <= U; i++)
	{
		sum2 += i;
	}
	sum2 *= sum2;
	printf("%d", sum2 - sum1);
}