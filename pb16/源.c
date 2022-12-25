//#define _CRT_SECURE_NO_WARNINGS 01
//#include<stdio.h>
//#include<inttypes.h>
//#define num 1000
//
//
//int main()
//{
//	int T = 1;
//	for (int i = 1; i <= num; i++)
//	{
//		T = T * 2;
//	}
//	printf("%d\n", T);
//	int sum = 0;
//	while (T!= 0)
//	{
//		sum += (T % 10);
//		T = T / 10;
//	}
//	printf("%d", sum);
//}

#include<stdio.h>
int main()
{
	int mu[400] = { 0 };
	mu[0] = mu[1] = 1;
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 1; j <= mu[0]; j++)
		{
			mu[j] *= 2;
		}
		for (int j = 1; j <= mu[0]; j++)
		{
			if (mu[j] < 10)
				continue;
			mu[j + 1] += mu[j] / 10;
			mu[j] %= 10;
			mu[0] += (mu[0] == j);
		}
	}
	int sum = 0;
	for (int i = 1; i <= mu[0]; i++)
	{
		sum += mu[i];
	}
	printf("%d", sum);
	return 0;
}