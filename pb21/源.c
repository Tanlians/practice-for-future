#define _CRT_SECURE_NO_WARNINGS 01
#define max 10000
#include<stdio.h>
int check(int a)
{
	int b=0,c=0,d=0;
	for (int i = 1; i < a; i++)
	{
		if (a % i == 0)
			b += i;
	}
	for (int j = 1; j < b; j++)
	{
		if (b % j == 0)
			c += j;
	}
	d = b + c;
	if (a == c && a != b)
		return c;
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
	printf("%d", sum / 2);
	return 0;
}

//#include <stdio.h>
//
//#define max 10000
//
//int prime[max + 5] = { 0 };
//int Sum_factor[max + 5] = { 0 };
//int isprime[max + 5] = { 0 };
//
//int main() {
//	Sum_factor[1] = 0;
//	for (int i = 2; i <= max; i++) {//素数筛框架；
//		if (!isprime[i]) {
//			prime[++prime[0]] = i;
//			Sum_factor[i] = i + 1;//如果是素数的话，因子和为i+1；Eg:3的因子和=1 + 3;
//			isprime[i] = i;
//		}
//		for (int j = 1; j <= prime[0]; j++) {
//			if (prime[j] * i > max) break;
//			if (i % prime[j] == 0) {
//				isprime[i * prime[j]] = isprime[i] * prime[j];//isprime[i]存放i的最小因子项的幂次值；
//				Sum_factor[i * prime[j]] = Sum_factor[i] * (isprime[i] * prime[j] * prime[j] - 1) / (isprime[i] * prime[j] - 1);//F(B)=F(A)*(p1^(a1+2) - 1)/(p1^(a1+1)-1);
//				break;
//			}
//			else {
//				isprime[i * prime[j]] = prime[j];
//				Sum_factor[i * prime[j]] = Sum_factor[i] * Sum_factor[prime[j]];//i与prime[j]互质，那么用公式F(A*B)=F(A)*F(B);
//			}
//		}
//	}
//	for (int i = 0; i <= max; i++) {
//		Sum_factor[i] -= i;
//	}
//	int ans = 0;
//	for (int i = 1; i <= max; i++) {
//		if (Sum_factor[Sum_factor[i]] == i && Sum_factor[i] <= max && Sum_factor[i] != i) {
//			ans += i;
//		}
//	}
//	printf("%d\n", ans);
//	return 0;
//}