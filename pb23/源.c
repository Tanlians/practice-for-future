#define _CRT_SECURE_NO_WARNINGS 01
#include <stdio.h>

#define max 28123

//int prime[max + 5] = { 0 };
//int isprime[max + 5] = { 0 };
//int Sum_factor[max + 5] = { 0 };
//int num[max + 5] = { 0 };
//
//int main() {
//	Sum_factor[1] = 0;
//	for (int i = 2; i <= max; i++) {//Sum_factor存放的是各个因子和；
//		if (!isprime[i]) {
//			isprime[i] = i;
//			prime[++prime[0]] = i;
//			Sum_factor[i] = i + 1;
//		}
//		for (int j = 1; j <= prime[0]; j++) {
//			if (i * prime[j] > max) break;
//			if (i % prime[j] == 0) {
//				isprime[i * prime[j]] = isprime[i] * prime[j];
//				Sum_factor[i * prime[j]] = Sum_factor[i] * (isprime[i] * prime[j] * prime[j] - 1) / (isprime[i] * prime[j] - 1);
//				break;
//			}
//			else {
//				isprime[i * prime[j]] = prime[j];
//				Sum_factor[i * prime[j]] = Sum_factor[i] * Sum_factor[prime[j]];
//			}
//		}
//	}
//	Sum_factor[0] = 0;//Sum_factor[0]存放的是充裕数的个数；
//	for (int i = 0; i <= max; i++) {
//		Sum_factor[i] -= i;
//		if (Sum_factor[i] > i) Sum_factor[++Sum_factor[0]] = i;//Sum_factor[i]中存放的是第i个数是充裕数；与之前的线性筛一样；
//	}
//	for (int i = 1; i <= Sum_factor[0]; i++) {
//		for (int j = i; j <= Sum_factor[0]; j++) {
//			if (Sum_factor[i] + Sum_factor[j] > max) break;
//			num[Sum_factor[i] + Sum_factor[j]] = 1;//把能使两个充裕数求和的数标记为1；
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i <= max; i++) {
//		if (!num[i]) sum += i;//未被标记的数就可以累加起来啦；
//	}
//	printf("%d\n", sum);
//	return 0;
//}

#include<stdio.h>
int check(int a)
{
	int b = 0;
	for (int i = 1; i < a; i++)
	{
		if (a % i == 0)
			b += i;
	}
	if (a < b&&max%(2*b)!=0)
		return b;
	else
		return 0;
}

int main()
{
	int sum = 0;
	for (int i = 1; i < max; i++)
	{
		sum += check(i);
	}
	printf("%d", sum);
	return 0;
}
