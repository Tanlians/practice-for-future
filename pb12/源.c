#include<stdio.h>
#include<stdlib.h>
int form(int n)
{
	int count = 0;
	for (int i = 1; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i * i == n)
				count++;
			else
				count += 2;
		}
	}
	return count;
}

int main()
{
	int num = 0;
	for (int k = 1;; k++)
	{
		num+=k;
		if (form(num) > 500)
		{
			printf("%d", num);
			break;
		}
	}
	return 0;
}