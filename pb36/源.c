#include<stdio.h>

#define max 1000000

int palindrome(int num, int base)
{
	int store = num, sum = 0;
	while (num) {
		sum = num % base + sum * base;
		num /= base;
	}
	return sum == store;
}

int main()
{
	int sum = 0;
	for (int i = 1; i < max; i++)
	{
		if (palindrome(i, 10) && palindrome(i, 2))
			sum += i;
	}
	printf("%d\n", sum);
	return 0;
}