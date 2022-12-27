#define _CRT_SECURE_NO_WARNINGS 01
#include<stdio.h>
#define m 100
int cul[500] = { 0 };
int main()
{
	cul[0] = cul[1] = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= cul[0]; j++)
		{
			cul[j] *= i;
		}
		for (int k = 1; k <= cul[0]; k++)
		{
			if (cul[k] < 10) continue;
			cul[k + 1] += cul[k] / 10;
			cul[k] = cul[k] % 10;
			cul[0] += (cul[0] == k);
		}
	}
	int sum = 0;
	for (int i = 1; i <= cul[0]; i++)
	{
		sum += cul[i];
	}
	printf("%d", sum);
	return 0;
}

