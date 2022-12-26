#define _CRT_SECURE_NO_WARNINGS 01
#include<stdio.h>
int num1[20] = { 0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8 };
int num2[10] = { 0,0,6,6,5,5,5,7,6,6 };

int len(int num)
{
	if (num < 20)
	{
		return num1[num];
	}
	else if(num>=20&&num<100)
	{
		return num1[num % 10] + num2[num / 10];
	}
	else if (num >= 100 && num < 1000)
	{
		if (num % 100 == 0)
		{
			return num1[num / 100] + 7;
		}
		else
		{
			return num1[num / 100] + len(num % 100) + 10;
		}
	}
	else {
		return 11;
	}
}

int main()
{
	int sum = 0;
	for (int i = 1; i <= 1000; i++)
	{
		sum += len(i);
	}
	printf("%d", sum);
	return 0;
}