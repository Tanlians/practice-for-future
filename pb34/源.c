#define _CRT_SECURE_NO_WARNINGS 01
#include<stdio.h>
#define max 2540160

//int cheng(int a)
//{
//	int sum = 1;
//	for (int i = 1; i <= a; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//}
//
//int gcd(int b)
//{
//	int sum = 0;
//	int ac = b;
//	int m[10] = { 0 };
//	for (int i = 0; i < b; i++)
//	{
//		if (ac > 0)
//		{
//			m[i] = ac % 10;
//			ac = ac / 10;
//		}
//	}
//	for (int k = 0; m[k] != 0; k++)
//	{
//		sum += cheng(m[k]);
//	}
//	if (sum == b)
//		return b;
//	else
//		return 0;
//}
//
//int main()
//{
//	int aum = 0;
//	for (int l = 1; l < max; l++)
//	{
//		aum += gcd(l);
//	}
//	printf("%d", aum);
//	return 0;
//}




int Iscurious(int num, int* mul) {
	int store = num, sum = 0;
	while (num) {
		sum += mul[num % 10];
		num /= 10;
	}
	return store == sum;
}

int main() {
	int mul[10] = { 0 };
	mul[0] = 1;
	for (int i = 1; i < 10; i++) {
		mul[i] = mul[i - 1] * i;
		printf("%d\n", mul[i]);
	}

	int sum = 0;
	for (int i = 3; i < max; i++) {
		if (Iscurious(i, mul)) sum += i;
	}
	printf("%d\n", sum);
	return 0;
}
