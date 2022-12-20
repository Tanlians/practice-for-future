#include<stdio.h>
#include<stdlib.h>
#define max 2000000

int Find(int a)
{
	if (a < 2)
		return 0;
	else if (a == 2)
		return a;
	else
	{
		for (int i = 2; i < a; i++)
		{
			if (a % i == 0)
				return 0;
		}
	}
	return a;
}

int main()
{
	int u; int sum=0;
	for (int j = 2; j < max; j++)
	{
		u = Find(j);
		sum += u;
	}
	printf("%d", sum);
	return 0;
}
//#include <stdio.h>
//#include <inttypes.h>
//
//#define max 2000000 
//
//int main() {
//	int32_t prime[max + 5] = { 0 };
//	int64_t sum = 0;
//	for (int64_t i = 2; i < max; i++) {
//		if (!prime[i]) { prime[++prime[0]] = i; sum += i; }
//		for (int64_t j = 1; j <= prime[0]; j++) {
//			if (i * prime[j] > max) break;
//			prime[i * prime[j]] = 1;
//			if (i % prime[j] == 0) break;
//		}
//	}
//	printf("%"PRId64"\n", sum);
//
//	return 0;
//}