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
//	for (int i = 2; i <= max; i++) {//Sum_factor��ŵ��Ǹ������Ӻͣ�
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
//	Sum_factor[0] = 0;//Sum_factor[0]��ŵ��ǳ�ԣ���ĸ�����
//	for (int i = 0; i <= max; i++) {
//		Sum_factor[i] -= i;
//		if (Sum_factor[i] > i) Sum_factor[++Sum_factor[0]] = i;//Sum_factor[i]�д�ŵ��ǵ�i�����ǳ�ԣ������֮ǰ������ɸһ����
//	}
//	for (int i = 1; i <= Sum_factor[0]; i++) {
//		for (int j = i; j <= Sum_factor[0]; j++) {
//			if (Sum_factor[i] + Sum_factor[j] > max) break;
//			num[Sum_factor[i] + Sum_factor[j]] = 1;//����ʹ������ԣ����͵������Ϊ1��
//		}
//	}
//	int sum = 0;
//	for (int i = 0; i <= max; i++) {
//		if (!num[i]) sum += i;//δ����ǵ����Ϳ����ۼ���������
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
