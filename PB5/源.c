//#include<stdio.h>
//#define N 20
//int g(int a, int b)
//{
//	int i, t;
//	if (a < b)
//	{
//		t = a; a = b; b = t;
//	}
//	for (i = a;; i += a)
//	{
//		if (i % a == 0 && i % b == 0)
//			return i;
//	}
//}
//int main()
//{
//	int i, k,a[N];
//	for (i = 0; i < N; i++)
//	{
//		a[i] = i + 1;
//	}
//	k = 1;
//	for (i = 0; i < N; i++)
//	{
//		k = g(k, a[i]);
//	}
//	printf("%d", k);
//	return 0;
//}
#include<stdio.h>
int is_val(int n)
{
	for (int i = 1; i <= 20; i++)
	{
		if (!(n % i == 0)) return 0;
	}
	return 1;
}
int main()
{
	int i = 2520;
	while (!(is_val(i)))
	{
		i++;
	}
	printf("%d", i);
	return 0;
}